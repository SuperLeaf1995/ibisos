cmake_minimum_required(VERSION 3.17)
project(IbisOS)

enable_language(CXX)
enable_language(ASM_NASM)

file(GLOB LINKER_SCRIPT "boot/linker.ld")
file(GLOB_RECURSE CXX_SOURCE "*.cpp")
file(GLOB_RECURSE ASM_NASM_SOURCE "*.asm")

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_COMPILER "clang")
set(CMAKE_CXX_FLAGS "-ffreestanding -O2 -Wall -fno-exceptions -fno-rtti --target=i686-pc-none-elf -march=i686")
set(CMAKE_ASM_NASM_OBJECT_FORMAT "elf32")
set(CMAKE_ASM_NASM_COMPILE_OBJECT "<CMAKE_ASM_NASM_COMPILER> -f ${CMAKE_ASM_NASM_OBJECT_FORMAT} -o <OBJECT> <SOURCE>")

add_executable(${PROJECT_NAME}.bin PROPERTIES LINK_FLAGS "-T ${LINKER_SCRIPT}")

target_include_directories(${PROJECT_NAME}.bin PRIVATE "include")