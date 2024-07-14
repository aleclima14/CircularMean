# Como usar

### 1 - Adicione os arquivos CircularMean.c e CircularMean.h ao seu projeto

Basta copiar os arquivos para a pasta do seu projeto. Se estiver desenvolvendo para Arduino, talvez precise renomear o arquivo CircularMean.c para CircularMean.cpp (vai dependender da sua IDE).

Inclua o arquivo .h ao arquivo que deseja usar as funções:

      #include "CircularMean.h"

O tamanho do buffer é definido no arquivo .h, através do define:
      
      #define BUFFER_SIZE 5

Em um projeto Arduino, descomente o seguinte trecho no arquivo .h:

      /* INCLUDES */
      #include <stdio.h>
      #include <stdlib.h>
      #include <stdint.h>
      // #include <Arduino.h> <-- descomente esse item
### 2 - Inicializando
Primeiro, deve ser instanciado o buffer da seguinte maneira:

      CircularBuffer Mean;

Aqui foi nomeado como "Mean", mas pode ser usado qualquer outro nome. 

A função InitCircularBuffer deve chamada antes de começar usar o Buffer:
      
      InitCircularBuffer(&Mean);

Em um projeto Arduino, ela pode ser usada na função Setup.

      void setup ()
      {
         InitCircularBuffer(&Mean);
      }

### 3 - Usando a função
Como parametro a função CalculateMean recebe o endereço do buffer criado e o valor uint32_t da leitura. Pode ser usado o valor de uma leitura ADC, por exemplo. A funcão retorna o valor float com a média calculada.

      float media = CalculateMean(&Mean, leitura);

Lembrando que é um buffer circular e precisa "encher" o vetor para calcular a média corretamente. Por padrão há 5 "espaços", então precisa de no minimo 5 valores para a média ser calculada corretamente (fique atento caso mude esse valor).

O buffer inicia com valores zeros em todos as suas posições. Quando recebe um valor maior que seu tamanho, começa a sobrepor os valores mais antigos. A tabela exemplifica:

| Posição       | 0  | 1 | 2 | 3 | 4 | Média |
|---------------|----|---|---|---|---|-------|
| Valor inicial | 0  | 0 | 0 | 0 | 0 | 0.00  |
| Recebe 10     | 10 | 0 | 0 | 0 | 0 | 2.00  |
| Recebe 8      | 10 | 8 | 0 | 0 | 0 | 3.60  |
| Recebe 3      | 10 | 8 | 3 | 0 | 0 | 4.20  |
| Recebe 8      | 10 | 8 | 3 | 8 | 0 | 5.80  |
| Recebe 2      | 10 | 8 | 3 | 8 | 2 | 6.20  |
| Recebe 7      | 7  | 8 | 3 | 8 | 2 | 5.60  |




