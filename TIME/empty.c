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

volatile bool gBlinkLED;
int main(void)
{
    SYSCFG_DL_init();
    //ʹ���ж�
    NVIC_EnableIRQ(TIMG0_INT_IRQn);
    gBlinkLED = true;
    //���LED��λ
    DL_GPIO_clearPins(GPIO_LED_PORT, GPIO_LED_USER_LED_PIN);
    //����ʱ��
    DL_TimerG_startCounter(TIMG0);

    //����ʱ��ʵ��LED��˸
    while (gBlinkLED == true) {
            DL_GPIO_togglePins(GPIO_LED_PORT, GPIO_LED_USER_LED_PIN);
            delay_cycles(16000000);
        }

    //�ر�LED
    DL_GPIO_setPins(GPIO_LED_PORT, GPIO_LED_USER_LED_PIN);

    //ʧ��ʱ��
    DL_TimerG_disableInterrupt(TIMG0, DL_TIMER_INTERRUPT_ZERO_EVENT);
    //�����ж�������Ӧ�ó�����ⷵ�ؿյ���Ӧ�ó���
    DL_SYSCTL_enableSleepOnExit();



    while (1) {
        __WFI();//�͹���ģʽ
    }
}

//ʱ���жϷ�����
void TIMG0_IRQHandler(void)
{
    switch (DL_TimerG_getPendingInterrupt(TIMG0)) {
        case DL_TIMERG_IIDX_ZERO:
            gBlinkLED = false;
            break;
        default:
            break;
    }
}

