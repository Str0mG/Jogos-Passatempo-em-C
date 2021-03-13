#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>


int main(){
    int player,escolha;
    char nome1[50];
    char nome2[50];
    int cartas[21],cartas2[21];
    int i,aux=1,aux2=1,e=1;
  
    int resultado1=0, resultado2=0;
	
    printf("---Bem vindo ao Black Jack-----");

    printf("\nDigite o nick do jogador:");
    scanf("%s",&nome1);
    srand(time(NULL));
    
        while(e){
        for(i=0;i<21;i++){
            cartas[i] = rand() % 10;
            if (cartas[i]==0)
                cartas[i]=10;
        }
        for(i=0;i<21;i++){
            cartas2[i] = rand() % 10;
            if (cartas2[i]==0)
                cartas2[i]=10;
        }
		e=0;
    }
    system("cls");
    while(escolha){
 		resultado1=0;
		resultado2=0;
		aux2+=1;
    	printf("Computador:");

    	for(i=0;i<aux;i++){
        	printf("%d",cartas2[i]);
        	resultado2= resultado2 + cartas2[i];
    	}
    	printf("  Total: %d",resultado2);
    	printf("\n%s:",nome1);
    	for(i=0;i<aux2;i++){
       		printf("%d ",cartas[i]);
        	resultado1= resultado1 + cartas[i];
    	}
    	printf("Total: %d\n",resultado1);
	
		if(resultado1<22){
    		printf("Deseja mais uma carta ou parar (0-Parar 1-Uma carta)");
    		scanf("%d",&escolha);
		}
		else{
			printf("\nOps passou de 21");
			escolha=0;
		}
    	system("cls");
	}
	
    if(resultado1>21){
    	resultado1=0;
		resultado2=0;
    	printf("VEZ DO COMPUTADOR:");
    	printf("\n%s:",nome1);
    	for(i=0;i<aux2;i++){
        	printf("%d ",cartas[i]);
        	resultado1= resultado1 + cartas[i];
    	}
    	printf("Total: %d\n",resultado1);
    	printf("Computador:");
		aux=2;
    	for(i=0;i<aux;i++){
        	printf("%d ",cartas2[i]);
  	      Sleep(1000);
        	resultado2= resultado2 + cartas2[i];
    	}
    	printf("  Total: %d",resultado2);
    
    	printf("\n\nVoce perdeu!!! O computador ganhou!!!!");
    	return 0;
    }

    while(resultado2<resultado1 || resultado2==resultado1 && resultado2<22 ){
    	system("cls");
    	resultado1=0;
		resultado2=0;
    	printf("VEZ DO COMPUTADOR:");
    	printf("\n%s:",nome1);
    	for(i=0;i<aux2;i++){
        	printf("%d ",cartas[i]);
        	resultado1= resultado1 + cartas[i];
    	}
    	printf("Total: %d\n",resultado1);
    	printf("Computador:");
		aux+=1;
    	for(i=0;i<aux;i++){
        	printf("%d ",cartas2[i]);
        	
        	resultado2= resultado2 + cartas2[i];
    	}
    	printf("  Total: %d",resultado2);
	}
    if(resultado1>resultado2 && resultado1<22)
        printf("\n%c Ganhouu",nome1);
    if(resultado2>21)
        printf("\n%s Ganhouu",nome1);
    else{
        printf("\nVoce perdeu!!! O computador ganhou!!!!");
        	return 0;
	}

}
