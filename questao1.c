#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef int lado;
#define cara 0
#define coroa 1

lado lancarMoeda(){
    lado lancamento = rand()%2;
    return lancamento;
}

int main(void){
    setlocale(LC_ALL, "portuguese");

    int i;
    float contC=0, contK=0;
    lado moeda;

    srand(time(NULL));

    printf("O objetivo deste programa �: \n1) Lan�ar 1000x uma moeda\n2) Contar quantas vezes cada lado � sorteado\nPressione qualquer tecla para come�ar...");
    getch();

    for(i=0; i<1000; i++){
            moeda=lancarMoeda();
            if(moeda==cara){
                printf("Moeda lan�ada: cara  |");
                contC++;

            } else
            if(moeda==coroa){
                printf("Moeda lan�ada: coroa |");
                contK++;

            }
          if(i%4==0)
            printf("\n");
        }
    printf("\n");
    printf("O resultado foi cara %.0f vezes (%.2f%% das vezes)\n", contC, (contC/1000)*100);
    printf("O resultado foi coroa %.0f vezes (%.2f%% das vezes)\n", contK, (contK/1000)*100);

    return 0;
}
