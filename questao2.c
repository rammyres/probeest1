#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <locale.h>
#include <unistd.h>

typedef int ladoMoeda;
#define cara 0
#define coroa 1

ladoMoeda lancarMoeda(){
    ladoMoeda lancamento = rand()%2;
    return lancamento;
}

int lancarDado(){
    int ladoD = (rand()%6)+1;

    return ladoD;
}

int imprime_grafico(float entrada[]){
    int i, j;
    for(i=0; i<11; i++){
      printf("        %2d|", i+2);
      for(j=0; j<((entrada[i]/36000)*100)*4-1; j++)
        printf("=");
      printf(" %.2f\n", (entrada[i]/36000)*100);

    }

    printf("          |________________________________________________________________________________\n");
    printf("Ocorrência|      02      04      06      08      10      12      14      16      18      20\n");

    return 0;
}

int questao1(void){

int i;
    float contC=0, contK=0;
    ladoMoeda moeda;

    printf("O objetivo desta questão é: \n1) Lançar 1000x uma moeda\n2) Contar quantas vezes cada lado é sorteado\nPressione qualquer tecla para começar...");
    getch();

    for(i=0; i<1000; i++){
            moeda=lancarMoeda();
            if(moeda==cara){
                printf("Moeda lançada: cara  |");
                contC++;

            } else
            if(moeda==coroa){
                printf("Moeda lançada: coroa |");
                contK++;

            }
          if(i%4==0)
            printf("\n");
        }
    printf("\n");
    printf("O resultado foi cara %.0f vezes (%.2f%% das vezes)\n", contC, (contC/1000)*100);
    printf("O resultado foi coroa %.0f vezes (%.2f%% das vezes)\n", contK, (contK/1000)*100);
    printf("Pressione ENTER para voltar ao menu...\n");
    getch();
    return 0;

}

int questao2(void){
    int i, resultado;
    float dado1, dado2, dados[11];

    for(i=0; i<12 ; i++)
        dados[i]=0;

    printf("O objetivo desta questão é:\n1) Rolar dois dados aletoriamente 36000x\n2) Coletar os dados dos lançamentos\n3) Montar o gráfico da distribuição das ocorrências\n");
    printf("Pressione qualquer tecla para rolar os dados...");
    getch();
    printf("\n");
    printf("Rolando os dados\n|");


    for(i=0; i<36000;i++){
        dado1=lancarDado();
        dado2=lancarDado();
        resultado=dado1+dado2;

        switch(resultado){
            case 2 : dados[0]++;
                     break;
            case 3 : dados[1]++;
                     break;
            case 4 : dados[2]++;
                     break;
            case 5 : dados[3]++;
                     break;
            case 6 : dados[4]++;
                     break;
            case 7 : dados[5]++;
                     break;
            case 8 : dados[6]++;
                     break;
            case 9 : dados[7]++;
                     break;
            case 10 : dados[8]++;
                     break;
            case 11 : dados[9]++;
                     break;
            case 12 : dados[10]++;
                     break;
        }
        if(i%360==0){
            printf("=");
            usleep(1000);
        }

    }

    printf("|\n");

    for(i=0; i<11; i++)
        printf("%2d foi sorteado %6.2f%% das vezes\n", i+2, (dados[i]/36000)*100);

    printf("Pressione qualquer tecla para imprimir o gráfico da distribuição das probabilidades\n");
    getch();
    imprime_grafico(dados);
    printf("Pressione ENTER para voltar ao menu...\n");
    getch();

}

int main(void){
    setlocale(LC_ALL, "portuguese");
    int escolha=0;
    srand(time(NULL));

    while(escolha!=3){
        printf("Bem vindo ao trabalho computacional de probabilidade e estatistica 1\n");
        printf("Digite 1 para executar a questão 1 (sorteio aleatório de moedas)\n");
        printf("Digite 2 para executar a questão 2 (rolagem de dados)\n");
        printf("Digite 3 para encerrar o programa\n");
        printf("Digite sua escolha: ");
        scanf("%d", &escolha);

        if(escolha==1)
            questao1();
        else
        if(escolha==2)
            questao2();
        else
            break;
    }

    return 0;
}
