#ifndef ATA_H
#define ATA_H
#include <stdint.h>
//Drive bus information
#define PRIMARY_BUS     0x00
#define SECONDARY_BUS   0x01
//Master and slave drive
#define MASTER_DRIVE    0x00
#define SLAVE_DRIVE     0x01
//Primary and secondary I/O
#define PRIMARY_IO      0x1F0
#define SECONDARY_IO    0x170
//Hard drive selection port
#define HD_SELECT_PORT  0x06
//I/O base registers
#define ATA_DATA            0x00
#define ATA_ERROR           0x01
#define ATA_FEATURES        0x01
#define ATA_SECTOR_COUNT_0  0x02
#define ATA_SECTOR_COUNT_1  0x08
#define ATA_LBA_LOW         0x03
#define ATA_LBA_0           0x03
#define ATA_LBA_1           0x04
#define ATA_LBA_2           0x05
#define ATA_LBA_MID         0x04
#define ATA_LBA_3           0x09
#define ATA_LBA_4           0x0A
#define ATA_LBA_5           0x0B
#define ATA_LBA_HIGH        0x05
#define ATA_COMMAND         0x07
#define ATA_STATUS          0x07
#define ATA_IDENTIFY        0xEC
//Registers offset from control
#define ATA_ALT_STATUS      0x0C
#define ATA_DEVICE_CONTROL  0x0C
#define ATA_DEVICE_ADDRESS  0x0D
//Status register
#define ATA_BSY     0x80
#define ATA_DRDY    0x40
#define ATA_DF      0x20
#define ATA_DSC     0x10
#define ATA_DRQ     0x08
#define ATA_CORR    0x04
#define ATA_IDX     0x02
#define ATA_ERR     0x01
//Error register
#define ADDRESS_MARKER_NOT_FOUND_ERROR  0x00
#define TRACK_ZERO_NOT_FOUND_ERROR      0x01
#define ABORTED_COMMAND_ERROR           0x02
#define MEDIA_CHANGE_REQUEST_ERROR      0x03
#define IDENTITY_NOT_FOUND_ERROR        0x04
#define MEDIA_CHANGED_ERROR             0x05
#define UNCORRECTABLE_DATA_ERROR        0x06
#define BAD_BLOCK_DETECTED_ERROR        0x07
//Drive head register
#define DRIVE_NUMBER_SELECT 0x04
#define DRIVE_LBA           0x06
#define NO_DRIVE    0xFFFF

#define ATA_WRITE_SECTORS_COMMAND   0x30
#define ATA_FLUSH_CACHE_COMMAND     0xE7
#define ATA_COMMAND_READ_PIO        0x20

#define ATA_MODEL   54

typedef struct
{
    //Drive name
    char *drive_name;
    //Drive id
    uint8_t drive_id;
    //Low linear block address
    uint8_t lba_low;
    //Medium linear block address
    uint8_t lba_med;
    //High linear block address
    uint8_t lba_high;
    //I/O for ata drive
    uint16_t io;
    //Read function
    uint8_t (*read)(uint8_t* buffer, uint32_t lba, uint32_t sector_count, ata_drive* drive);
    //Write function
    uint8_t (*write)(uint8_t* buffer, uint32_t offset, uint32_t buffer_size, ata_drive* drive);
} ata_drive;
#endif