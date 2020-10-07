import sys, os

def compile_asm(source_dir):
    #Loop through all items in source_dir
    for item in os.listdir(source_dir):
        #Get the item's path
        item_path = "%s/%s"%(source_dir, item)
        #Check if item is directory
        if(os.path.isdir(item_path)):
            #Look at this item_path path
            compile_asm(item_path)
        else:
            #The asm compile string
            asm_compile = "nasm -f elf32"
            #Check if item path ends with asm
            if(item_path.endswith(".asm")):
                #Get the item's name
                item_name = item_path.split("/")[len(item_path.split("/")) - 1]
                #Create an output name
                output_name = "output/%s"%(item_name.replace(".asm", ".o"))
                #We will compile this file to output
                print("Compiling %s to %s"%(item_path, item_name))
                #Update asm compile to include the source file and output
                asm_compile += " -s %s -o %s"%(item_path, output_name)
                print(asm_compile)
                #Compile the code
                os.system(asm_compile)
def compile_c(source_dir):
    for item in os.listdir(source_dir):
        item_path = "%s/%s"%(source_dir, item)
        if(os.path.isdir(item_path)):
            compile_c(item_path)
        else:
            if(item_path.endswith(".c")):
                c_compile = "libs/cross-compiler/compiler/bin/i686-elf-gcc"
                item_name = item_path.split("/")[len(item_path.split("/")) - 1].replace(".c++", "")
                output_name = "output/%s"%(item_name.replace(".c", ".o"))
                c_compile += " -c %s -o %s -Isrc/include -I`pwd`/libs/cross-compiler/compiler/bin/usr/local/i686-tinaos/include -I`pwd`/libs/cross-compiler/compiler/bin/usr/local/i686-tinaos/libs -ffreestanding -O2 -Wall -Wextra -fno-exceptions -fno-rtti"%(item_path, output_name)
                os.system(c_compile)
def compile_cpp(source_dir):
    #Loop through all items in source_dir
    for item in os.listdir(source_dir):
        #Get item path
        item_path = "%s/%s"%(source_dir, item)
        #Check if item is directory
        if(os.path.isdir(item_path)):
            #Loop through this directory
            compile_cpp(item_path)
        else:
            #The c compile string
            cpp_compile = "libs/cross-compiler/compiler/bin/i686-elf-g++"
            #Check if the given file is a C++ file
            if(item_path.endswith(".cpp")):
                #Get the item name
                item_name = item_path.split("/")[len(item_path.split("/")) - 1].replace(".c++", "")
                #Create an output name
                output_name = "output/%s"%(item_name.replace(".cpp", ".o"))
                #We will compile this file to output
                print("Compiling %s to output/%s.o"%(item_path, item_name))
                #Update cpp_compile with the given file
                cpp_compile += " -c %s -o %s -fpermissive -Isrc/include -I`pwd`/libs/cross-compiler/compiler/bin/usr/local/i686-tinaos/include -I`pwd`/libs/cross-compiler/compiler/bin/usr/local/i686-tinaos/libs -ffreestanding -O2 -Wall -Wextra -fno-exceptions -fno-rtti"%(item_path, output_name)
                #Compile the code
                os.system(cpp_compile)

def link_files(output_dir):
    #The output
    output = "output/kernel.o output/boot.o"
    #Go through output_dir
    for item in os.listdir(output_dir):
        #Get the item path and add item to it
        item_path = "%s/%s"%(output_dir, item)
        #Check if item is file and its path is not in output
        if(os.path.isfile(item_path) and (item_path not in output)):
            #Add the item to the output
            output += " %s"%(item_path)
    return output

def compile_linker(source_dir):
    #Loop through all items in source_dir
    for item in os.listdir(source_dir):
        #Get the item's path
        item_path = "%s/%s"%(source_dir, item)
        #Check if item is directory
        if(os.path.isdir(item_path)):
            #Loop through this directory
            compile_linker(item_path)
        else:
            #The c compile string
            cpp_compile = "libs/cross-compiler/compiler/bin/i686-elf-gcc"
            #Check if the given file is a linker file
            if(item_path.endswith(".ld")):
                #Get the item name
                item_name = "TINAOS.bin"
                #Get the output
                output = link_files("output")
                #Create an output name
                output_name = "output/%s"%(item_name)
                #We will link all files
                os.system("%s -T %s -o %s %s -ffreestanding -O2 -nostdlib -lgcc"%(cpp_compile, item_path, output_name, output))
                #Compile the goodies

def clear_output(output_dir):
    for item in os.listdir(output_dir):
        item_path = "%s/%s"%(output_dir, item)
        if(os.path.isdir(item_path)):
            clear_output(item_path)
            os.rmdir(item_path)
        else:
            os.remove(item_path)
def build_iso(output_dir):
    #Make necessary output paths
    if(os.path.exists(output_dir) is False):
        clear_output(output_dir)
    os.makedirs("output/isodir/boot/grub")
    os.system("cp src/boot/grub.cfg output/isodir/boot/grub/grub.cfg")
    os.system("cp output/TINAOS.bin output/isodir/boot/TINAOS.bin")
    os.system("grub-mkrescue -o output/TINAOS.iso %s/isodir"%(output_dir))
os.system("rm -rf output")
os.mkdir("output")
compile_asm("src")
compile_cpp("src")
compile_c("src")
compile_linker("src")
build_iso("output")