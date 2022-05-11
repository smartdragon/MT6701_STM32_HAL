//
// Created by HCl on 2022/5/11.
//

#include "main.h"

#ifndef MT6701_MT6701_H
#define MT6701_MT6701_H

#define SlaveAddress    0X0C        //MT6701 地址
#define ReadAddress1    0X03        //数据高位寄存器地址
#define ReadAddress2    0X04        //数据低位寄存器地址

uint32_t ReadAngleIIC(void);

#endif //MT6701_MT6701_H
