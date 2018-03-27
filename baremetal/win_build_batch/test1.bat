cd ..\..
ren baremetal/aemv8.2a/elf/neon_gemm_int8_bm.elf baremetal/aemv8.2a/elf/neon_gemm_int8_bm.elf.old

if exist baremetal/aemv8.2a/elf/neon_gemm_int8_bm.elf echo "Success"

cd baremetal\win_build_batch
