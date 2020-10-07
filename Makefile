BIN=`pwd`/libs/cross-compiler/compiler/bin/
TARGET=i686-elf
GCC=$(BIN)$(TARGET)-gcc
AS=$(BIN)$(TARGET)-as
NASM=nasm
.PHONY: repo_download
repo_download:
	rm -rf libs
	rm -rf src
	rm -rf assets
	rm -rf output
	git clone https://github.com/TINA-OS/libs
	git clone https://github.com/TINA-OS/src
	git clone https://github.com/TINA-OS/assets
	
#Install all requirements
.PHONY: install
install:
	sudo apt install nasm build-essential bison flex libgmp3-dev libmpc-dev libmpfr-dev texinfo qemu-kvm qemu-system-i386 xorriso curl
#Are we making the cross compiler?
.PHONY: cross-compiler
cross-compiler:
	cd libs/cross-compiler && make all
.PHONY: tinaos
tinaos:
	rm -rf "output"
	echo "Building TINAOS bootstrap..."
	mkdir -p "output"
	python compile.py
.PHONY: qemu
qemu:
	make tinaos
	qemu-system-i386  -hda output/TINAOS.iso -serial stdio
.PHONY: all
all:
	make repo_download
	make install
	make cross-compiler
	make tinaos
.PHONY: update
update:
	git pull
	cd libs && git pull
	cd src && git pull
	cd assets && git pull
