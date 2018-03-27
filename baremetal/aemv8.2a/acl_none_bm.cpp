/*
 * Copyright (c) 2017-2018 ARM Limited.
 *
 * SPDX-License-Identifier: MIT
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to
 * deal in the Software without restriction, including without limitation the
 * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
 * sell copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */
#include "arm_compute/core/Types.h"
#include "arm_compute/runtime/NEON/NEFunctions.h"
#include "utils/Utils.h"

#include <cstdlib>

using namespace arm_compute;
using namespace utils;


#if 1

void acl_none_bm(int argc, const char **argv)
{
	Image   src0;
	src0.allocator()->init(TensorInfo(TensorShape(20U, 28U), 1, DataType::F32));
}

int main(int argc, const char **argv)
{
	acl_none_bm(argc, argv);
	while(1) {
	}
	return 1;
}

#else

class NEGEMMLowpExample : public Example
{
public:
    void do_setup(int argc, char **argv) override
    {
        if(argc < 4)
        {
            // Print help
            std::cout << "./build/neon_gemmlowp M N K\n\n";
            std::cout << "Too few or no input_matrices provided. Using M=7, N=3, K=5, alpha=1.0f and beta=0.0f\n\n";
        }
            src0.allocator()->init(TensorInfo(TensorShape(5U, 7U), 1, DataType::QASYMM8));
            src1.allocator()->init(TensorInfo(TensorShape(3U, 5U), 1, DataType::QASYMM8));

        init_sgemm_output(dst, src0, src1, DataType::S32);

        // Configure function
        sgemm.configure(&src0, &src1, &dst);

        fill_random_tensor(src0, -1.f, 1.f);
        fill_random_tensor(src1, -1.f, 1.f);
        
		// Allocate all the tensors
        src0.allocator()->allocate();
        src1.allocator()->allocate();
        dst.allocator()->allocate();
    }
    void do_run() override
    {
        // Execute the function
        sgemm.run();
    }
    void do_teardown() override
    {
    }

private:
    Tensor    src0{}, src1{}, dst{};
    NEGEMMLowpMatrixMultiplyCore      sgemm{};
};

/** Main program for sgemm test
 *
 * @param[in] argc Number of arguments
 * @param[in] argv Arguments ( [optional] M, [optional] N [optional] K )
 */
int main(int argc, char **argv)
{
    return utils::run_example<NEGEMMLowpExample>(argc, argv);
}

#endif