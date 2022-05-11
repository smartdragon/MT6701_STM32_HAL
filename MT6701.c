//
// Created by HCl on 2022/5/11.
//

#include "MT6701.h"
#include "i2c.h"

/*
 * IIC 方式读取角度信息
 * 返回数据为 0 ~ 360 之间的整数
 * STM32 开启 IIC 高速模式
 */
uint32_t ReadAngleIIC(void)
{
    uint32_t angle = 0;
    uint8_t ReadBuffer1,ReadBuffer2;

    HAL_I2C_Mem_Read(&hi2c1,SlaveAddress,ReadAddress1,I2C_MEMADD_SIZE_8BIT,&ReadBuffer1,1,0XFF);
    angle = ReadBuffer1;
    angle <<= 8;
    HAL_I2C_Mem_Read(&hi2c1,SlaveAddress,ReadAddress2,I2C_MEMADD_SIZE_8BIT,&ReadBuffer2,1,0XFF);
    angle += ReadBuffer2;
    angle >>= 2;            //取数据高 14 位
    angle = (angle * 360) / 16384;

    return angle;
}