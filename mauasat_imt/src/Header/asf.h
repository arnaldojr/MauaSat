
#ifndef ASF_H
#define ASF_H

/*
 * This file includes all API header files for the selected drivers from ASF.
 * Note: There might be duplicate includes required by more than one driver.
 *
 * The file is automatically generated and will be re-written when
 * running the ASF driver selector tool. Any changes will be discarded.
 */

// From module: Common SAM compiler driver
#include <compiler.h>
#include <status_codes.h>

// From module: Delay routines
#include <delay.h>

// From module: Generic board support
#include <board.h>

// From module: Interrupt management - SAM implementation
#include <interrupt.h>

// From module: PMC - Power Management Controller
#include <pmc.h>
#include <sleep.h>

// From module: Part identification macros
#include <parts.h>

// From module: SAM FPU driver
#include <fpu.h>

// From module: SAMG53 startup code
#include <exceptions.h>

// From module: System Clock Control - SAMG implementation
#include <sysclk.h>

#endif // ASF_H
