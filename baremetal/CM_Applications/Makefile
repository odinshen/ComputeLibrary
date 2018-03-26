#-------------------------------------------------------------------------------
# The confidential and proprietary information contained in this file may
# only be used by a person authorised under and to the extent permitted
# by a subsisting licensing agreement from ARM Limited or its affiliates.
#
#            (C) COPYRIGHT 2013-2016 ARM Limited or its affiliates.
#                ALL RIGHTS RESERVED
#
# This entire notice must be reproduced on all copies of this file
# and copies of this file may only be made by a person if such person is
# permitted to do so under the terms of a subsisting license agreement
# from ARM Limited or its affiliates.
#
#            Release Information : CORINTH-MP090-dev-20160525
#
#-------------------------------------------------------------------------------

# Include user configuration file
include ./make.cfg


################################################################################
# Toolchains
################################################################################

# Toolchain names
ifeq ($(findstring +bigend, $(PLUSARGS) ), +bigend)
GCC_TOOLCHAIN_AARCH32 := armeb-none-eabi
GCC_TOOLCHAIN_AARCH64 := aarch64_be-none-elf
else
GCC_TOOLCHAIN_AARCH32 := arm-none-eabi
GCC_TOOLCHAIN_AARCH64 := aarch64-none-elf
endif

# AArch32 toolchain executables
AS32      := $(GCC_TOOLCHAIN_AARCH32)-as
GCC32     := $(GCC_TOOLCHAIN_AARCH32)-gcc
LD32      := $(GCC_TOOLCHAIN_AARCH32)-ld
OBJCOPY32 := $(GCC_TOOLCHAIN_AARCH32)-objcopy

# AArch64 toolchain executables
AS64      := $(GCC_TOOLCHAIN_AARCH64)-as
GCC64     := $(GCC_TOOLCHAIN_AARCH64)-gcc
LD64      := $(GCC_TOOLCHAIN_AARCH64)-ld
OBJCOPY64 := $(GCC_TOOLCHAIN_AARCH64)-objcopy


################################################################################
# Processor options
################################################################################

# CPU and architecture
CPU  = cortex-a53
ARCH = armv8-a

# FPU types
FPU_NONE      :=
FPU_V8        := -mfpu=neon-fp-armv8
FPU_V8_CRYPTO := -mfpu=crypto-neon-fp-armv8

# Active FPU, can be overridden by tests
FPU = $(FPU_V8)


################################################################################
# Commands and command options
################################################################################

# Assembler setup
ASM32            = $(AS32)
ASM64            = $(AS64)
ifeq ($(findstring +bigend, $(PLUSARGS) ), +bigend)
ASM_OPTS_AARCH32 = -march=$(ARCH) $(FPU) --defsym BIGEND=1 -mbig-endian
ASM_OPTS_AARCH64 = -march=$(ARCH) --defsym BIGEND=1 -mbig-endian
else
ASM_OPTS_AARCH32 = -march=$(ARCH) $(FPU) --defsym EXEC_CPU=$(EXEC_CPU)
ASM_OPTS_AARCH64 = -march=$(ARCH) --defsym EXEC_CPU=$(EXEC_CPU)
endif

# C compiler setup
CC32             = $(GCC32)
CC64             = $(GCC64)
ifeq ($(findstring +bigend, $(PLUSARGS) ), +bigend)
CC_OPTS_AARCH32  = -march=$(ARCH) -mtune=$(CPU) $(FPU) -c -DGCC -falign-functions=16 -fno-common -falign-jumps=8 -falign-loops=8 -fomit-frame-pointer -funroll-loops -g -mbig-endian
CC_OPTS_AARCH64  = -march=$(ARCH) -mtune=$(CPU)        -c -DGCC -falign-functions=16 -falign-jumps=8 -falign-loops=8 -fomit-frame-pointer -funroll-loops -g -mbig-endian
else
CC_OPTS_AARCH32  = -march=$(ARCH) -mtune=$(CPU) $(FPU) -c -DGCC -falign-functions=16 -fno-common -falign-jumps=8 -falign-loops=8 -fomit-frame-pointer -funroll-loops -g
CC_OPTS_AARCH64  = -march=$(ARCH) -mtune=$(CPU)        -c -DGCC -falign-functions=16 -falign-jumps=8 -falign-loops=8 -fomit-frame-pointer -funroll-loops -g
endif

# Linker setup
LINK32           = $(LD32)
LINK64           = $(LD64)

ifeq ($(findstring +bigend, $(PLUSARGS) ), +bigend)
LINK_OPTS_32     = -EB --be8
LINK_OPTS_64     = -EB
else
LINK_OPTS_32     =
LINK_OPTS_64     =
endif

LINK_OPTS_NOBOOT_AARCH32 = $(LINK_OPTS_32)               -T link_noboot.ld
LINK_OPTS_NOBOOT_AARCH64 = $(LINK_OPTS_64)               -T link_noboot.ld
LINK_OPTS_ASM_AARCH32    = $(LINK_OPTS_32)               -T link_asm_aarch32.ld
LINK_OPTS_ASM_AARCH32_MP = $(LINK_OPTS_32)               -T link_asm_aarch32_mp.ld
LINK_OPTS_ASM_AARCH64    = $(LINK_OPTS_64)               -T link_asm_aarch64.ld
LINK_OPTS_ASM_AARCH64_MP = $(LINK_OPTS_64)               -T link_asm_aarch64_mp.ld

ifeq ($(findstring +bigend, $(PLUSARGS) ), +bigend)
LINK_OPTS_CSRC_AARCH32   = $(LINK_OPTS_32:-%=-Wl,-%) -Wl,-T link_csrc_aarch32.ld  -mbig-endian
LINK_OPTS_CSRC_AARCH64   = $(LINK_OPTS_64:-%=-Wl,-%) -Wl,-T link_csrc_aarch64.ld  -mbig-endian
else
LINK_OPTS_CSRC_AARCH32   = $(LINK_OPTS_32:-%=-Wl,-%) -Wl,-T link_csrc_aarch32.ld
LINK_OPTS_CSRC_AARCH64   = $(LINK_OPTS_64:-%=-Wl,-%) -Wl,-T link_csrc_aarch64.ld
endif


################################################################################
# Makefile variables
################################################################################

# Names of defined tests for AArch32 and AArch64
aarch32_tests = 
aarch64_tests = dhrystone

# Add in opional FPU and crypto tests where required
ifeq ($(strip $(CRYPTO_TESTS)), yes)
  aarch32_tests += crypto
  aarch64_tests += crypto
endif
ifeq ($(strip $(FPU_TESTS)), yes)
  aarch32_tests += saxpy
  aarch64_tests += saxpy
endif

# Directories for shared code
aarch32_shared := aarch32/shared
aarch64_shared := aarch64/shared
common_shared  := common/shared

# Shared sources and objects
aarch32_bootcode := $(aarch32_shared)/bootcode_mp.s $(aarch32_shared)/bootcode.s $(aarch32_shared)/pagetables.s $(aarch32_shared)/stackheap.s $(aarch32_shared)/vectors.s
aarch64_bootcode := $(aarch64_shared)/bootcode_mp.s $(aarch64_shared)/bootcode.s $(aarch64_shared)/pagetables.s $(aarch64_shared)/stackheap.s $(aarch64_shared)/vectors.s
aarch32_bootobj  := $(aarch32_shared)/bootcode.o $(aarch32_shared)/pagetables.o $(aarch32_shared)/stackheap.o $(aarch32_shared)/vectors.o
aarch64_bootobj  := $(aarch64_shared)/bootcode.o $(aarch64_shared)/pagetables.o $(aarch64_shared)/stackheap.o $(aarch64_shared)/vectors.o
aarch64_bootobj_mp  := $(aarch64_shared)/bootcode_mp.o $(aarch64_shared)/pagetables.o $(aarch64_shared)/stackheap.o $(aarch64_shared)/vectors.o
aarch32_bootobj_mp  := $(aarch32_shared)/bootcode_mp.o $(aarch32_shared)/pagetables.o $(aarch32_shared)/stackheap.o $(aarch32_shared)/vectors.o
aarch64_bootobj_mp_o  := $(aarch64_shared)/bootcode_mp.o
aarch32_bootobj_mp_o  := $(aarch32_shared)/bootcode_mp.o

# Each test has its own Makefile for compiling and linking
sub_makefiles = $(foreach test, $(aarch32_tests), aarch32/$(test)/Makefile.inc) \
                $(foreach test, $(aarch64_tests), aarch64/$(test)/Makefile.inc) \

# List of test directories and basenames for linked ELFs and objects.
# The basename for each test is <arch>/<test>/<test>
testdirs32  = $(foreach test, $(aarch32_tests), aarch32/$(test))
testdirs64  = $(foreach test, $(aarch64_tests), aarch64/$(test))
basenames32 = $(foreach test, $(aarch32_tests), aarch32/$(test)/$(test))
basenames64 = $(foreach test, $(aarch64_tests), aarch64/$(test)/$(test))

# Names of elf files
elfs32 = $(addsuffix .elf, $(basenames32))
elfs64 = $(addsuffix .elf, $(basenames64))


################################################################################
# Default target: make all
################################################################################

.PHONY: all force
all: $(elfs32) $(elfs64)


as_options:	force
	@echo '$(ASM_OPTS_AARCH32) $(ASM_OPTS_AARCH64)' | cmp -s - $@ || echo '$(ASM_OPTS_AARCH32) $(ASM_OPTS_AARCH64)' > $@

################################################################################
# Include sub-Makefiles
#
#   Each sub-Makefile defines how to compile and link the test
################################################################################

include $(sub_makefiles)


################################################################################
# Rules for shared sources
################################################################################

# AArch32 shared ASM
$(aarch32_bootobj): %.o: %.s as_options
	@echo " [ASM ] $<"
	@$(ASM32) $(ASM_OPTS_AARCH32) -I$(common_shared) $< -o $@

# AArch32 shared ASM MP variant
$(aarch32_bootobj_mp_o): %.o: %.s as_options
	@echo " [ASM ] $<"
	@$(ASM32) $(ASM_OPTS_AARCH32) -I$(common_shared) $< -o $@

# AArch64 shared ASM
$(aarch64_bootobj): %.o: %.s as_options
	@echo " [ASM ] $<"
	@$(ASM64) $(ASM_OPTS_AARCH64) -I$(common_shared) $< -o $@

# AArch64 shared ASM MP variant
$(aarch64_bootobj_mp_o): %.o: %.s as_options
	@echo " [ASM ] $<"
	@$(ASM64) $(ASM_OPTS_AARCH64) -I$(common_shared) $< -o $@

################################################################################
# Symbolic test names
################################################################################

.PHONY: $(testdirs32) $(testdirs64)
$(foreach test, $(aarch32_tests), $(eval aarch32/$(test): aarch32/$(test)/$(test).vhx))
$(foreach test, $(aarch64_tests), $(eval aarch64/$(test): aarch64/$(test)/$(test).vhx))


################################################################################
# Clean and tidy
#
#   clean: removes everything that can be rebuilt
#   tidy:  preserves ELF and memory initialisation files, cleans everything else
################################################################################

.PHONY: tidy
tidy:
	@rm -f $(aarch32_bootobj)
	@rm -f $(aarch64_bootobj)
	@rm -f $(aarch32_bootobj_mp)
	@rm -f $(aarch64_bootobj_mp)
	@rm -f $(aarch64_shared_c_obj)
	@rm -f $(foreach test, $(aarch32_tests), aarch32/$(test)/*.o)
	@rm -f $(foreach test, $(aarch64_tests), aarch64/$(test)/*.o)

.PHONY: clean
clean: tidy
	@rm -f $(elfs32) $(elfs64)
