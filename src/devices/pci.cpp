#include <devices/pci.h>
#include <stdint.h>
#include <stddef.h>
#include <malloc/malloc.h>
//A list of all discovered pci devices
pci_device **discovered_devices;
uint32_t discovered_device_count = 0;

void register_pci_device(pci_device* device)
{
    //Add the device
    discovered_devices[discovered_device_count] = device;
    //Update device count
    discovered_device_count++;
}

uint16_t pci_config_read_word(uint8_t bus, uint8_t slot, uint8_t function, uint8_t offset)
{
    uint32_t address;
    uint32_t lbus = (uint32_t) bus;
    uint32_t lslot = (uint32_t) slot;
    uint32_t lfunc = (uint32_t) function;
    uint16_t temp = 0;
    //Create a config address
    address = (uint32_t) ((lbus << 16) | (lslot << 11) | (lfunc << 8) | (offset &0xFC) | ((uint32_t) 0x80000000));
    //Write the address
    outl(0xCF8, address);
    //Read the response and return it
    temp = (uint16_t)((inl(0xCFC) >> ((offset & 2) * 8)) & 0xFFFF);
    return (temp);
}

uint16_t pci_check_vendor(uint16_t bus, uint16_t slot)
{
    //Read the vendor data from the device
    return pci_config_read_word(bus, slot, 0, 0);
}

uint16_t pci_get_vendor(uint8_t bus, uint16_t slot, uint8_t function)
{
    //Read vendor data with the given function
    return pci_config_read_word(bus, slot, function, 0);
}

uint16_t pci_check_device(uint16_t bus, uint16_t slot, uint16_t function)
{
    //Read the device data from the device
    return pci_config_read_word(bus, slot, function, 2);
}

uint16_t pci_get_device(uint16_t bus, uint16_t slot, uint16_t function)
{
    //Return the found device
    return pci_check_device(bus, slot, function);
}

void initialize_pci_devices()
{
    //Set the devices
    discovered_devices = (pci_device**) malloc(sizeof(pci_device));
    //Loop through all 256 potential busses
    for(uint32_t bus = 0; bus < 256; bus++)
    {
        //Create a pci device
        pci_device* pci_connected_device = (pci_device*) malloc(sizeof(pci_device));
        //Loop through 32 slots
        for(uint32_t slot = 0; slot < 32; slot++)
        {
            //Loop through 8 functions
            for(uint32_t function = 0; function < 8; function++)
            {
                //Get the vendor of the pci device
                uint16_t vendor = pci_get_vendor(bus, slot, function);
                //Get the current device
                uint16_t device = pci_get_device(bus, slot, function);
                //Check if the vendor is nothing
                if(vendor == 0xFFFF || device  == 0xFFFF)
                    //Go on
                    continue;
                //Set the vendor
                pci_connected_device->vendor = vendor;
                //Set the device
                pci_connected_device->device = device;
                //Set the driver
                pci_connected_device->driver = 0;
                //Register the device
                register_pci_device(pci_connected_device);
            }
        }
    }
}