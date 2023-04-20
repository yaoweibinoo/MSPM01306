/*
 * Copyright (c) 2021, Texas Instruments Incorporated
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include "ti_msp_dl_config.h"
int pwm_count = 180; // 基于10%占空比的初始ccr计数
int dc = 10;          // 初始化为10%
int mode = 1; // 1 = up (增加dc), 0 = down (降低dc)
int main(void)
{
    SYSCFG_DL_init();
    //开启中断和时钟
    NVIC_EnableIRQ(TIMG0_INT_IRQn);
    DL_TimerG_startCounter(TIMG0);

    while (1) {
      __WFI();
    }
}


void TIMG0_IRQHandler(void) {
  switch (DL_TimerG_getPendingInterrupt(TIMG0)) {
  case DL_TIMER_IIDX_LOAD:
    if (dc <= 10) {
      mode = 1;
    }
    else if (dc >= 90) {
      mode = 0;
    }
    if (mode) {
      pwm_count -= 2;
      dc += 1;
    }
    if (!mode) {
      pwm_count += 2;
      dc -= 1;
    }
    DL_TimerG_setCaptureCompareValue(TIMG0, pwm_count,
                                     DL_TIMER_CC_1_INDEX); // update ccr1 value
    break;
  default:
    break;
  }
}

