/*
 * This file is part of INAV.
 *
 * INAV is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * INAV is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with INAV.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <stdbool.h>
#include <platform.h>
#include "drivers/io.h"
#include "drivers/pwm_mapping.h"
#include "drivers/timer.h"

timerHardware_t timerHardware[] = {
//  Port LED is disconnected as it was broken
//  Port S11 function is replaced to be LED. The same timer is used with different channel
    DEF_TIM(TIM4,   CH2, PB7,  TIM_USE_OUTPUT_AUTO,   1, 0), // S1 D(1,3,2)   PB7                              TIM4_CH2
    DEF_TIM(TIM4,   CH1, PB6,  TIM_USE_OUTPUT_AUTO,   1, 0), // S2 D(1,0,2)   PB6                              TIM4_CH1
    DEF_TIM(TIM3,   CH3, PB0,  TIM_USE_OUTPUT_AUTO,   1, 0), // S3 D(1,7,5)   PB0 tim1_CH2n           TIM3_CH3           tim8_CH2n
    DEF_TIM(TIM3,   CH4, PB1,  TIM_USE_OUTPUT_AUTO,   1, 0), // S4 D(1,2,5)   PB1 tim1_CH3n           TIM3_CH4           tim8_CH3n
    DEF_TIM(TIM8,   CH3, PC8,  TIM_USE_OUTPUT_AUTO,   1, 0), // S5 D(2,4,7)   PC8                     tim3_CH3           TIM8_CH3
    DEF_TIM(TIM8,   CH4, PC9,  TIM_USE_OUTPUT_AUTO,   1, 0), // S6 D(2,7,7)   PC9                     tim3_CH4           TIM8_CH4
    DEF_TIM(TIM8,  CH2N, PB14, TIM_USE_OUTPUT_AUTO,   1, 0), // S7            PB14 tim1_CH2n                             TIM8_CH2n  tim12_CH1
    DEF_TIM(TIM2,   CH1, PA15, TIM_USE_OUTPUT_AUTO,   1, 0), // S8            PA15           TIM2_CH1
    DEF_TIM(TIM2,   CH3, PB10, TIM_USE_OUTPUT_AUTO,   1, 0), // S9            PB10           TIM2_CH3
    DEF_TIM(TIM2,   CH4, PB11, TIM_USE_OUTPUT_AUTO,   1, 0), // S10           PB11           TIM2_CH4
//  DEF_TIM(TIM12,  CH2, PB15, TIM_USE_OUTPUT_AUTO,   1, 0), // S11           PB15 tim1_CH3n                             tim8_CH3n  TIM12_CH2
    DEF_TIM(TIM1,   CH3N, PB15,  TIM_USE_LED,   0, 0), //2812LED  D(1,5,3)
//  DEF_TIM(TIM1,   CH1, PA8,  TIM_USE_LED,   0, 0), //2812LED  D(1,5,3)      PA8  TIM1_CH1

    DEF_TIM(TIM5,   CH3, PA2,  TIM_USE_ANY,   0, 0), //TX2  softserial1_Tx
};

const int timerHardwareCount = sizeof(timerHardware) / sizeof(timerHardware[0]);
