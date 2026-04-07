#ifndef GLOBALDATA_H
#define GLOBALDATA_H

#include <stdint.h>

typedef struct
{
    volatile uint16_t Milisecon;
    volatile uint16_t DebounceMs;
    volatile uint16_t Pulse_Count;

    volatile uint16_t AnalogValue;
    volatile uint16_t Digital_Out;

    volatile uint8_t rx_data;

    volatile unsigned char rx_flag		: 1;
    volatile unsigned char output_flag  : 1;
    volatile unsigned char OneMsFlag    : 1;
    volatile unsigned char OneSeconFlag	: 1;

    unsigned char Digital1_In		: 1;
    unsigned char Digital1_Data		: 1;
    unsigned char Digital1_Stable	: 1;
    unsigned char Digital2_In		: 1;
    unsigned char Digital2_Data		: 1;
    unsigned char Digital2_Stable	: 1;
    unsigned char Pulse_In		    : 1;
    unsigned char Pulse_Data		: 1;
    unsigned char Digital_out		: 1;


} Data_t;

extern Data_t Data;

#define STATE_IDLE 0
#define STATE_WAIT_DATA 1

#endif
