/* HTU21.h */

#ifndef SRC_HTU21_H_
#define SRC_HTU21_H_

#include "stm32f4xx_hal.h"

/* External I2C Handle */
extern I2C_HandleTypeDef hi2c1;

/* Default I2C Address for HTU21D */
#define HTU21_I2CADDR     (0x80)

/* Commands */
#define HTU21_READTEMP    (0xF3)
#define HTU21_READHUM     (0xF5)
#define HTU21_WRITEREG    (0xE6)
#define HTU21_READREG     (0xE7)
#define HTU21_RESET       (0xFE)

#ifdef __cplusplus
extern "C" {
#endif

char  HTU21_Init(void);
float HTU21_GetTemp(void);
float HTU21_GetHum(void);
void  HTU21_Reset(void);

#ifdef __cplusplus
}
#endif

#endif /* SRC_HTU21_H_ */
