/*
 * Copyright (C) 2004-2010 NXP Software
 * Copyright (C) 2010 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "BIQUAD.h"
#include "BQ_2I_D16F32Css_TRC_WRA_01_Private.h"

/*-------------------------------------------------------------------------*/
/* FUNCTION:                                                               */
/*   BQ_2I_D16F32Css_TRC_WRA_01_Init                                       */
/*                                                                         */
/* DESCRIPTION:                                                            */
/*   These functions initializes a BIQUAD filter defined as a cascade of   */
/*   biquadratic Filter Sections.                                          */
/*                                                                         */
/* PARAMETERS:                                                             */
/*   pInstance    - output, returns the pointer to the State Variable      */
/*                   This state pointer must be passed to any subsequent   */
/*                   call to "Biquad" functions.                           */
/*   pTaps         - input, pointer to the taps memory                     */
/*   pCoef         - input, pointer to the coefficient structure           */
/*   N             - M coefficient factor of QM.N                          */
/* RETURNS:                                                                */
/*   void return code                                                      */
/*-------------------------------------------------------------------------*/
void BQ_2I_D16F32Css_TRC_WRA_01_Init(Biquad_FLOAT_Instance_t* pInstance,
                                     Biquad_2I_Order2_FLOAT_Taps_t* pTaps,
                                     BQ_FLOAT_Coefs_t* pCoef) {
    LVM_FLOAT temp;
    PFilter_State_FLOAT pBiquadState = (PFilter_State_FLOAT)pInstance;
    pBiquadState->pDelays = (LVM_FLOAT*)pTaps;
    temp = pCoef->A2;
    pBiquadState->coefs[0] = temp;
    temp = pCoef->A1;
    pBiquadState->coefs[1] = temp;
    temp = pCoef->A0;
    pBiquadState->coefs[2] = temp;
    temp = pCoef->B2;
    pBiquadState->coefs[3] = temp;
    temp = pCoef->B1;
    pBiquadState->coefs[4] = temp;
}
/*-------------------------------------------------------------------------*/
/* End Of File: BQ_2I_D16F32Css_TRC_WRA_01_Init                              */
