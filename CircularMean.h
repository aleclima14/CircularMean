/**
 * @file CircularMean.c
 * @author aleclima14@gmail.com
 * @brief 
 * @version 0.1
 * @date 2024-07-14
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#ifndef __CircularMean_h__
#define __CircularMean_h__

/* INCLUDES */
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
// #include <Arduino.h>

/* DEFINES */
#define BUFFER_SIZE 5

/* STRUCTS */
typedef struct 
{
   uint32_t Data[BUFFER_SIZE];
   uint8_t Position;
}CircularBuffer;

/* PUBLIC FUNCTIONS */
void InitCircularBuffer(CircularBuffer *mean);
float CalculateMean(CircularBuffer *mean, uint32_t value);

#endif /*__CircularMean_h__*/