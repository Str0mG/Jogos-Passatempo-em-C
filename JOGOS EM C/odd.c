
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){

    float aposta,dinheiro,odd_maior,odd_menor;
    int n1,n2,escolha,e;

    printf("Digite a quantidade de dinheiro:\n");
    scanf("%f",&dinheiro);

    while(e){
        system("cls");
        printf("---------ROLETA------------\n");
        printf("Voce possui:%.2f reais\n",dinheiro);
        srand(time(NULL));
        n1=rand() % 100;
        printf("\n");
        printf("Numero principal:%d",n1);
        odd_maior =(100/((100-(float)n1)/100)/100);
        odd_menor =(100/((float)n1/100)/100);
        printf("\n");
        printf("Odd para maior:%.2f",odd_maior);
        printf("\n");
        printf("Odd para menor:%.2f",odd_menor);
        printf("\n");
        printf("Digite a quantidade que quer apostar:");
        scanf("%f",&aposta);
        printf("\n");
        printf("O numero a seguir vai ser maior ou menor: (Menor=1 Maior=2)");
        scanf("%d",&escolha);
        printf("\n");
        n2= rand() % 100;
        printf("O numero sorteado foi:%d",n2);
        if(escolha==1 && n1>n2){
            printf("\n");
            printf("Parabens. Voce acertou\n");
            dinheiro = dinheiro + aposta * odd_menor;
            dinheiro= dinheiro - aposta;
            printf("\n");
            printf("Voce tem um total de %.2f",dinheiro);

        }
        if(escolha==2 && n1<n2){
            printf("\n");
            printf("Parabens. Voce acertou\n");
            dinheiro = dinheiro +  aposta * odd_maior;
            dinheiro= dinheiro - aposta;
            printf("\n");
            printf("Voce tem um total de %.2f",dinheiro);

        }
        if(escolha==1 && n1<n2){
            printf("\n");
            printf("Voce errou. Sinto muito\n");
            dinheiro= dinheiro - aposta;
             printf("\n");
            printf("Voce tem um total de %.2f",dinheiro);

        }
        if(escolha==2 && n1>n2){
            printf("Voce errou. Sinto muito\n");
            dinheiro= dinheiro - aposta;
            printf("\n");
            printf("Voce tem um total de %.2f",dinheiro);

        }
        if(dinheiro==0){
            system("cls");
            printf("Voce perdeu tudo, foi mal");
            return 0;
        }

        printf("\n");
        printf("\nRodar mais uma vez Sim=1 Nao=0\n");
        scanf("%d",&e);
    }
}
