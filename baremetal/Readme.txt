Baremetal CL

Step 1)
	Pre-build the library

Step 2)
	Copy to build/ folder

Step 3)
	Apply CPU initial code inot baremetal\aemv8a
	Copy boot_defs.hs into root folder

Step 4)
	Apply any example code form example/

Step 5)
	Setup compiler script (neon_cnn_baremetal_aem.bat)

Step 6)
	Setup FVP or other board

	

Note:
	Library build version:
		gcc-linaro-6.3.1-2017.05-x86_64_aarch64-elf
		
		

CA55 FVP Streamline:
	-C bp.secure_memory=false -C cache_state_modelled=1 -a cluster0.cpu0="C:\Git\ArmVirtualPlatformCNN\ArmMLVP_MNIST\ArmMLVP_MNIST.axf" --plugin st="C:\Program Files\DS-5 v5.28.0\sw\models\bin\FastlineTrace.dll" -C TRACE.st.config="C:\Git\ArmVirtualPlatformCNN\ArmMLVP_MNIST\Fastline\FastlineConfig\CA55-system-config.json" -C TRACE.st.counters-config-file="C:\Git\ArmVirtualPlatformCNN\ArmMLVP_MNIST\Fastline\FastlineConfig\CA55-counter-config.json" -C TRACE.st.output-directory="C:\Git\ArmVirtualPlatformCNN\ArmMLVP_MNIST\Fastline\FastlineReport" -C TRACE.st.apc-capture=ArmMLVP_CA55x1_MNIST_O3_Conv2 --cpi-file="C:\Git\ArmVirtualPlatformCNN\ArmMLVP_MNIST\cpi_file.txt"


AEM FVP Streamline:
	-C bp.secure_memory=false 
	-C cache_state_modelled=1 
	-a cluster0.cpu0="C:\Users\odishe01\OneDrive - ARM\Projects\ACL_Profiling\ComputeLibrary_Profiling\baremetal\aemv8a\neon_cnn_bm_example_v8a.elf" 
	--plugin st="C:\Program Files\DS-5 v5.28.0\sw\models\bin\FastlineTrace.dll" 
	-C TRACE.st.config="C:\Users\odishe01\OneDrive - ARM\Projects\ACL_Profiling\ComputeLibrary_Profiling\streamline\system-config.json" 
	-C TRACE.st.counters-config-file="C:\Users\odishe01\OneDrive - ARM\Projects\ACL_Profiling\ComputeLibrary_Profiling\streamline\counter-config.json" 
	-C TRACE.st.output-directory="C:\Users\odishe01\OneDrive - ARM\Projects\ACL_Profiling\ComputeLibrary_Profiling\streamline" 
	-C TRACE.st.apc-capture=ACL18.3_BM__AEMv8a__NEON_CNN
	
https://community.arm.com/tools/b/blog/posts/using-streamline-with-fast-models-and-fixed-virtual-platforms-an-update

-C bp.secure_memory=false -C cache_state_modelled=1 -a cluster0.cpu0="C:\Users\odishe01\OneDrive - ARM\Projects\ACL_Profiling\ComputeLibrary_Profiling\baremetal\aemv8a\neon_cnn_bm_example_v8a.elf" --plugin st="C:\Program Files\DS-5 v5.28.0\sw\models\bin\FastlineTrace.dll" -C TRACE.st.config="C:\Users\odishe01\OneDrive - ARM\Projects\ACL_Profiling\ComputeLibrary_Profiling\streamline\system-config.json" -C TRACE.st.counters-config-file="C:\Users\odishe01\OneDrive - ARM\Projects\ACL_Profiling\ComputeLibrary_Profiling\streamline\counter-config.json" -C TRACE.st.output-directory="C:\Users\odishe01\OneDrive - ARM\Projects\ACL_Profiling\ComputeLibrary_Profiling\streamline\" -C TRACE.st.apc-capture=ACL18.3_BM__AEMv8a__NEON_CNN
	


### ComputeLibrary_BareMetal\17.9\ComputeLibrary-17.09-BareMetal ###
-C bp.secure_memory=false 
-C cache_state_modelled=1 
-a cluster0.cpu0="C:\Users\odishe01\OneDrive - ARM\Projects\ComputeLibrary_BareMetal\17.9\ComputeLibrary-17.09-BareMetal\baremetal\aemv8a\neon_cnn_bm_example.elf" 
--plugin st="C:\Program Files\DS-5 v5.28.0\sw\models\bin\FastlineTrace.dll" 
-C TRACE.st.config="C:\Users\odishe01\OneDrive - ARM\Projects\ComputeLibrary_BareMetal\17.9\ComputeLibrary-17.09-BareMetal\streamline\system-config.json" 
-C TRACE.st.counters-config-file="C:\Users\odishe01\OneDrive - ARM\Projects\ComputeLibrary_BareMetal\17.9\ComputeLibrary-17.09-BareMetal\streamline\counter-config.json" 
-C TRACE.st.output-directory="C:\Users\odishe01\OneDrive - ARM\Projects\ComputeLibrary_BareMetal\17.9\ComputeLibrary-17.09-BareMetal\streamline" 
-C TRACE.st.apc-capture=CL17.9_BM_AEM__NEON_CNN
	

	


-C bp.secure_memory=false -C cache_state_modelled=1 -a cluster0.cpu0="C:\Users\odishe01\OneDrive - Arm\Projects\ACL_Profiling\ComputeLibrary_Profiling\baremetal\aemv8a\neon_cnn_bm_example_v8a.elf" --plugin st="C:\Program Files\DS-5 v5.28.0\sw\models\bin\FastlineTrace.dll" -C TRACE.st.config="C:\Users\odishe01\OneDrive - Arm\Projects\ACL_Profiling\ComputeLibrary_Profiling\streamline\system-config.json" -C TRACE.st.counters-config-file="C:\Users\odishe01\OneDrive - Arm\Projects\ACL_Profiling\ComputeLibrary_Profiling\streamline\counter-config.json" -C TRACE.st.output-directory="C:\Users\odishe01\OneDrive - Arm\Projects\ACL_Profiling\ComputeLibrary_Profiling\streamline" -C TRACE.st.apc-capture=ACL18.3_BM__AEMv8a__NEON_CNN


	
	


	
########################################################################
#17.9
Instruction #
				Start		End			Spend
CPU Init		0			836
CPP Init		836			51,265
tensor Init		51,265		102,138
Config			102,138		16,609,119	16,506,981
Alloc			16,609,119	26,326,491	 9,717,372
Execute
	conv0		26,326,491	42,283,428	15,956,937
	act0		42,283,428	43,277,979	   994,551
	pool0		43,277,979	45,829,874	 2,551,895
	conv1		45,829,874	53,853,451	 8,023,577
	act1		53,853,451	54,526,648	   673,197
	pool1		54,526,648	56,380,401	 1,853,753
	fc0			56,380,401	83,305,760	26,925,359
	act2		83,305,760	83,353,583	    47,823
	softmax		83,353,583	83,581,083	   227,500


CPUInit	0	836
CPPInit	836	51,265
tensorInit	51,265	102,138
Config	102,138	16,609,119	16,506,981
Alloc	16,609,119	26,326,491	 9,717,372
conv0	26,326,491	42,283,428	15,956,937
act0	42,283,428	43,277,979	   994,551
pool0	43,277,979	45,829,874	 2,551,895
conv1	45,829,874	53,853,451	 8,023,577
act1	53,853,451	54,526,648	   673,197
pool1	54,526,648	56,380,401	 1,853,753
fc0	56,380,401	83,305,760	26,925,359
act2	83,305,760	83,353,583	    47,823
softmax	83,353,583	83,581,083	   227,500

	


########################################################################	
ACL 18.3 v8a neon_cnn_old_code
			DURING
CPUInit	0	836	836
CPPInit	836	3,121	2285
tensorInit	3,121	27,632	24511
Config	27,632	155,968	128336
Alloc	155,968	179,341	23373
conv0	179,341	1,904,191	1724850
act0	1,904,191	1,953,770	49579
pool0	1,953,770	2,034,515	80745
conv1	2,034,515	2,534,376	499861
act1	2,534,376	2,577,011	42635
pool1	2,577,011	2,652,821	75810
fc0	2,652,821	3,658,277	1005456
act2	3,658,277	3,658,972	695
softmax	3,658,972	3,677,808	18836


########################################################################
ACL 18.3 v8.2a neon_cnn_old_code
			DURING
CPUInit	0	836	836
CPPInit	836	3109	2273
tensorInit	3,109	27617	24508
Config	27,617	157779	130162
Alloc	157,779	181366	23587
conv0	181,366	1905207	1723841
act0	1,905,207	1954825	49618
pool0	1,954,825	2050537	95712
conv1	2,050,537	2550407	499870
act1	2,550,407	2578012	27605
pool1	2,578,012	2653825	75813
fc0	2,653,825	3659299	1005474
act2	3,659,299	3659994	695
softmax	3,659,994	3678625	18631


########################################################################


Pre-build:
	Arm_Compute_Library_aarch64_bare_metal_build/ComputeLibrary/arm_compute/core/
	

Building for bare metal

For bare metal, the library was successfully built using linaros's latest (gcc-linaro-6.3.1-2017.05) bare metal toolchains:•arm-eabi for armv7a•aarch64-elf for arm64-v8a
Download linaro for armv7a and arm64-v8a.NoteMake sure to add the toolchains to your PATH: export PATH=$PATH:$MY_TOOLCHAINS/gcc-linaro-6.3.1-2017.05-x86_64_aarch64-elf/bin:$MY_TOOLCHAINS/gcc-linaro-6.3.1-2017.05-x86_64_arm-eabi/bin

	export PATH=$PATH:~/toolchain/gcc-linaro-6.3.1-2017.05-x86_64_aarch64-elf/bin:~/toolchain/gcc-linaro-6.3.1-2017.05-x86_64_arm-eabi/bin

 How to build the library ?

To cross-compile the library with NEON support for baremetal arm64-v8a: 
scons Werror=1 -j8 debug=0 neon=1 opencl=0 os=bare_metal arch=arm64-v8a build=cross_compile cppthreads=0 openmp=0 standalone=1

scons Werror=1 -j8 debug=0 neon=1 opencl=0 os=bare_metal arch=arm64-v8.2-a build=cross_compile cppthreads=0 openmp=0 standalone=1



