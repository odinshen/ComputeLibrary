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

//-----------------------------------------------------------------------------
// Purpose:
//   This file contains definitions that are used by multiple files.  It is
//   loaded by files that require these symbols using the ".include" directive.
//-----------------------------------------------------------------------------

// Stack definitions.  Each CPU gets a chunk of the global stack space.
.equ CPU_STACK_SIZE, 1024
.equ STACK_SIZE,     CPU_STACK_SIZE*4
.equ HEAP_SIZE,      1024*4

