// ========================================
// Copyright 2013 David Turnbull AE9RB
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
// ========================================

#include "FracN_api.h"
#include <device.h>

void FracN_Start2(uint8 dma) {
    uint8 td;
    
    FracN_Set(FracN_DEFAULT);

    td = CyDmaTdAllocate();
    CyDmaTdSetConfiguration(td, 1, td, 0);
    CyDmaTdSetAddress(td, LO16((uint32)FracN_PLL_P__STATUS_REG), LO16((uint32)&FASTCLK_PLL_P));
    CyDmaChSetInitialTd(dma, td);
    CyDmaChEnable(dma, 1);
}

void FracN_Set(uint16 frac) {
    CY_SET_REG8(FracN_FRAC_HI__CONTROL_REG, frac >> 8);
    CY_SET_REG8(FracN_FRAC_LO__CONTROL_REG, frac & 0xFF);
}
