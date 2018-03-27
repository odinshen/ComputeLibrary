cd ..\elf\aemv8.2a\elf
ren neon_gemm_int8_bm.elf neon_gemm_int8_bm.elf.old
cd ..\..\..

if exist baremetal\aemv8.2a\elf\neon_gemm_int8_bm.elf echo "Success"

cd baremetal\win_build_batch
