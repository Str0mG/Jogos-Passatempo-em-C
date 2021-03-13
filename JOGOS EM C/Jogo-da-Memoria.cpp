#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

int main(){
    int g=3,sec=4;
    int dificult=10;
    int round=1,e=1;
    int i,resposta[g-1],aux=0;
    printf("---------------Bem vindo ao jogo da memoria-----------------\n\n");
    srand(time(NULL));
    while(e){
        int fase[g-1];
        printf("%d Round---       ",round);
        for(i=0;i<g;i++)
            fase[i]= rand() % dificult;
        for(i=0;i<g;i++)
            printf("%d    ",fase[i]);
        Sleep(2000);
        printf("\n\nVoce tem %d segundos para memorizar: ",sec);
        for(i=sec;i>0;i--){
            printf("%d ",i);
            Sleep(1000);
        }
        system("cls");
        printf("Seu tempo acabou!!!\nAgora digite os numeros que voce memorizou:\n");
        for(i=0;i<g;i++)
            scanf("%d",&resposta[i]);
        /*for(i=0;i<g;i++)
            printf("%d",resposta[i]);
            printf("\n");
            for(i=0;i<g;i++)
            printf("---%d----",fase[i]);
            */

        for(i=0;i<g;i++){
            if(resposta[i]!=fase[i])
                aux++;
        }
        /*
		printf("%d",g);
		printf("%d",aux);
		*/
        if(aux==0){
            printf("Parabens voce acertou todos pronto para o proximo nivel (0-Nao 1-Sim)");
            scanf("%d",&e);
            g+=2;
            dificult+=40;
            sec+=2;
        }
        else{
            printf("Voce errou Sinto muito. Tente outra vez");
            e=1;
            Sleep(2000);
        }
        system("cls");
        }
}
