#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "CircularMean.h"

CircularBuffer Mean;

int main ()
{
   InitCircularBuffer(&Mean);

   while(1)
   {
      uint32_t leitura;
      printf("Digite um valor: ");
      scanf("%u", &leitura);
      printf("Media: %.2f\n\r", CalculateMean(&Mean, leitura));
   }
   
   return 0;
}