C:\ARM\aarch64-elf\gcc-linaro-7.2.1-2017.11-i686-mingw32_aarch64-elf\bin\aarch64-elf-g++ baremetal/aemv8.2a/pagetables.s -o baremetal/aemv8.2a/pagetables.o -c -specs=nosys.specs -g

C:\ARM\aarch64-elf\gcc-linaro-7.2.1-2017.11-i686-mingw32_aarch64-elf\bin\aarch64-elf-g++ baremetal/aemv8.2a/vectors.s  -o baremetal/aemv8.2a/vectors.o -c -specs=nosys.specs -g

C:\ARM\aarch64-elf\gcc-linaro-7.2.1-2017.11-i686-mingw32_aarch64-elf\bin\aarch64-elf-g++ baremetal/aemv8.2a/bootcode.s -o baremetal/aemv8.2a/bootcode.o -c -specs=nosys.specs -g

C:\ARM\aarch64-elf\gcc-linaro-7.2.1-2017.11-i686-mingw32_aarch64-elf\bin\aarch64-elf-g++ -c baremetal/aemv8.2a/output_trickbox.c -o baremetal/aemv8.2a/output_trickbox.o -specs=nosys.specs -g

C:\ARM\aarch64-elf\gcc-linaro-7.2.1-2017.11-i686-mingw32_aarch64-elf\bin\aarch64-elf-g++ -c baremetal/aemv8.2a/retarget-gcc.c -o baremetal/aemv8.2a/retarget-gcc.o -specs=nosys.specs -g

C:\ARM\aarch64-elf\gcc-linaro-7.2.1-2017.11-i686-mingw32_aarch64-elf\bin\aarch64-elf-g++ baremetal/aemv8.2a/stackheap.s -o baremetal/aemv8.2a/stackheap.o -c -specs=nosys.specs -g

C:\ARM\aarch64-elf\gcc-linaro-7.2.1-2017.11-i686-mingw32_aarch64-elf\bin\aarch64-elf-g++ -c baremetal/aemv8.2a/neon_gemm_fp16_bm.cpp -o baremetal/aemv8.2a/neon_gemm_fp16_bm.o -march=armv8.2-a -I. -Iinclude -std=c++11 -larm_compute-static -larm_compute-core-static  -Lbuild-arm64-v8.2a  -fPIC -DNO_MULTI_THREADING -DBARE_METAL -specs=nosys.specs -g

C:\ARM\aarch64-elf\gcc-linaro-7.2.1-2017.11-i686-mingw32_aarch64-elf\bin\aarch64-elf-g++ baremetal/aemv8.2a/vectors.o baremetal/aemv8.2a/stackheap.o baremetal/aemv8.2a/retarget-gcc.o baremetal/aemv8.2a/pagetables.o baremetal/aemv8.2a/output_trickbox.o baremetal/aemv8.2a/neon_gemm_fp16_bm.o baremetal/aemv8.2a/bootcode.o -o baremetal/aemv8.2a/neon_gemm_fp16_bm_v82a.elf -I. -Lbuild-arm64-v8.2a -larm_compute-static -larm_compute_core-static -T baremetal/aemv8.2a/link_csrc_aarch64.ld -march=armv8.2-a -specs=nosys.specs -fstack-protector -g
