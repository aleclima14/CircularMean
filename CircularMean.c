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

/* INCLUDES */
#include "CircularMean.h"

/* PUBLIC FUNCTIONS */
/**
 * @brief Init buffer
 * 
 * @param mean 
 */
void InitCircularBuffer(CircularBuffer *mean)
{
   mean->Position = 0;

   for(uint8_t i = 0; i < BUFFER_SIZE; i++)
   {
      mean->Data[i] = 0;
   }
}

/**
 * @brief Return calculated mean
 * 
 * @param mean 
 * @param value 
 * @return float 
 */
float CalculateMean(CircularBuffer *mean, uint32_t value)
{
   float CalculatedMean = 0;

   mean->Data[mean->Position] = value;

   for(uint8_t i = 0; i < BUFFER_SIZE; i++)
   {
      CalculatedMean = CalculatedMean + mean->Data[i];
   }

   if(mean->Position >= (BUFFER_SIZE - 1))
   {
      mean->Position = 0;
   }
   else 
   {
      mean->Position++;
   }
   CalculatedMean = CalculatedMean / BUFFER_SIZE;

   return CalculatedMean;
}