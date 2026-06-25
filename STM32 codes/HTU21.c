#include "HTU21.h"
extern I2C_HandleTypeDef hi2c1;

/* Reset Sensor */
void HTU21_Reset()
{
    uint8_t Data = HTU21_RESET;
    HAL_Delay(15);

    HAL_I2C_Master_Transmit(&hi2c1, HTU21_I2CADDR, &Data, 1, 1000);
    HAL_Delay(15);
}

/* Initialize Sensor */
char HTU21_Init()
{
    uint8_t check;
    uint8_t Data = HTU21_READREG;

    HAL_I2C_Master_Transmit(&hi2c1, HTU21_I2CADDR, &Data, 1, 1000);
    HAL_I2C_Master_Receive(&hi2c1, HTU21_I2CADDR, &check, 1, 1000);

    return check;
}

/* Read Temperature */
float HTU21_GetTemp()
{
    uint8_t Temp_Data[3];
    uint8_t Data = HTU21_READTEMP;

    if(HAL_I2C_Master_Transmit(&hi2c1, HTU21_I2CADDR, &Data, 1, 1000) != HAL_OK)
        return -100;

    HAL_Delay(50);

    if(HAL_I2C_Master_Receive(&hi2c1, HTU21_I2CADDR, Temp_Data, 3, 1000) != HAL_OK)
        return -100;

    uint16_t Raw_Temp = (Temp_Data[0] << 8) | (Temp_Data[1] & 0xFC);

    float temp = Raw_Temp;
    temp = -46.85f + (175.72f * temp / 65536.0f);

    return temp;
}

/* Read Humidity */
float HTU21_GetHum()
{
    uint8_t Hum_Data[3];
    uint8_t Data = HTU21_READHUM;

    if(HAL_I2C_Master_Transmit(&hi2c1, HTU21_I2CADDR, &Data, 1, 1000) != HAL_OK)
        return -1;

    HAL_Delay(50);

    if(HAL_I2C_Master_Receive(&hi2c1, HTU21_I2CADDR, Hum_Data, 3, 1000) != HAL_OK)
        return -1;

    uint16_t Raw_Hum = (Hum_Data[0] << 8) | (Hum_Data[1] & 0xFC);

    float hum = Raw_Hum;
    hum = -6.0f + (125.0f * hum / 65536.0f);

    return hum;
}
