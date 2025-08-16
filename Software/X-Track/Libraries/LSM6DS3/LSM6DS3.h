#ifndef __LSM6DS3_H
#define __LSM6DS3_H

#include "Arduino.h"

#define LSM6DS3_I2C_ADDRESS    0x6A

class LSM6DS3
{
public:
    LSM6DS3(){}
    ~LSM6DS3(){}

    bool Init(uint8_t addr = LSM6DS3_I2C_ADDRESS);

    bool IsConnected();
    void ConfigAcc(uint8_t acc_odr, uint8_t acc_scale);
    void ConfigGyr(uint8_t gyr_odr, uint8_t gyr_scale);
    void GetMotion6(
        int16_t* acc_x,
        int16_t* acc_y,
        int16_t* acc_z,
        int16_t* gyr_x,
        int16_t* gyr_y,
        int16_t* gyr_z
    );
    int16_t GetTemperature();
    void SoftReset();
    void EnableEMbeddedFunc();
    void DisableEMbeddedFunc();
    void EnableAWT(int16_t angle, int16_t Delay);
    void DisableAWT();
    void EnableTapDetection();
    void DisableTapDetection();
    void EnablePedometer(uint16_t debounce_time, uint8_t debounce_step);
    uint16_t GetCurrentStep();
    void ResetStepCounter();
    void DisablePedometer();

private:
    uint8_t Address;
    void WriteReg(uint8_t reg, uint8_t dat);
    uint8_t ReadReg(uint8_t reg);
    void ReadRegs(uint8_t reg, uint8_t* buf, uint16_t len);
    void SetRegisterBits(uint8_t reg, uint8_t data, bool setBits);
};

#endif
