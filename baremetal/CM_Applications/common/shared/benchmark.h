//------------------------------------------------------------------------------
// The confidential and proprietary information contained in this file may
// only be used by a person authorised under and to the extent permitted
// by a subsisting licensing agreement from ARM Limited or its affiliates.
//
//            (C) COPYRIGHT 2013-2016 ARM Limited or its affiliates.
//                ALL RIGHTS RESERVED
//
// This entire notice must be reproduced on all copies of this file
// and copies of this file may only be made by a person if such person is
// permitted to do so under the terms of a subsisting license agreement
// from ARM Limited or its affiliates.
//
//            Release Information : CORINTH-MP090-dev-20160525
//
//------------------------------------------------------------------------------

#ifndef BENCHMARK_H
#define BENCHMARK_H

#include <stdio.h>

#define MAINSTART
#define MAINEND

#define TUBE_ADDRESS ((volatile char *) 0x13000000u)
#define BENCHSTART
#define BENCHFINISHED benchmark_finish();
#define LOOPSTART
#define LOOPEND

#define ITERATIONS 700

// This function writes characters directly rather the use printf so that
// it can work when printf is not available.
static void benchmark_finish()
{
  char  p[] = "** TEST PASSED OK **\n";

  int i = 0;

  while (i < 21)
    output_char(p[i++]);
}

#endif
