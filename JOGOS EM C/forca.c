#include <stdio.h>
#include <string.h>
#include <windows.h>

void forca(int erro){
	if(erro==0){
		printf("--------\n");
		printf("|      |\n");
		printf("|       \n");
		printf("|     \n");
		printf("|     \n");
		printf("|\n");
		printf("__________\n");
			}

    if(erro==1){
		printf("--------\n");
		printf("|      |\n");
		printf("|      o\n");
		printf("|     \n");
		printf("|     \n");
		printf("|\n");
		printf("__________\n");

    }
    if(erro==2){
		printf("--------\n");
		printf("|      |\n");
		printf("|      o\n");
		printf("|     /\n");
		printf("|     \n");
		printf("|\n");
		printf("__________\n");

    }
    if(erro==3){
		printf("--------\n");
		printf("|      |\n");
		printf("|      o\n");
		printf("|     /|\n");
		printf("|     \n");
		printf("|\n");
		printf("__________\n");

    }
    if(erro==4){
		printf("--------\n");
		printf("|      |\n");
		printf("|      o\n");
		printf("|     /|\\\n");
		printf("|     \n");
		printf("|\n");
		printf("__________\n");

    }
    if(erro==5){
		printf("--------\n");
		printf("|      |\n");
		printf("|      o\n");
		printf("|     /|\\\n");
		printf("|     / \n");
		printf("|\n");
		printf("__________\n");

    }
    if(erro==6){
		printf("--------\n");
		printf("|      |\n");
		printf("|      o\n");
		printf("|     /|\\\n");
		printf("|     / \\\n");
		printf("|\n");
		printf("__________\n");

    }
	return;
}

int main() {
	char nome1[10],nome2[10],tema[10],palavra[50],demonstracao[50],letra,lista[50];
	int i,e=6,aux=0,erro=0;
	printf("           Bem Vindo ao jogo da forca");
	printf("\n");
	printf("--------\n");
	printf("|      |\n");
	printf("|      o\n");
	printf("|     /|\\\n");
	printf("|     / \\\n");
	printf("|\n");
	printf("__________\n");

	printf("E necessario 2 playes, prontos?");
	
	printf("\nDigite o jogador que vai escolher a palavra:\n");
	scanf("%s",&nome1);
	printf("Agora digite o nick do player que vai advinhar:\n");
	scanf("%s",&nome2);
	printf("Digite o tema %s:\n", nome1);
	scanf("%s",&tema);
	printf("AGORA O %s NAO PODE OLHAR\n", nome2);
	Sleep(1000);
	
	printf("Agora digite a palavra %s:\n",nome1);
	fflush(stdin);
	gets(palavra);
	
	int s = strlen(palavra);
	int ganho=0,q=0;
	
	
	system("cls");

	for (i=0;i<s;i++){
        if(palavra[i]== palavra[i] && palavra[i]!= ' '){
            demonstracao[i]='_';
            q++;
        }
        if(palavra[i]==' '){
            demonstracao[i]=' ';
        }
    }

	while(e){

		printf("             Jogo da forca\n");
		forca(erro);
		printf("Letras que ja foram usadas:");
		printf("%s",lista);
		printf("\nTema:%s\n",tema);
		printf("%s advinhe a palavra abaixo!!\n",nome2);
		for (i=0;i<s;i++)
		        printf("%c ",demonstracao[i]);
		printf("\nDigite uma letra:");
		scanf(" %c",&letra);
		strncat(lista,&letra,1);
		system("cls");
		for (i=0;i<s;i++){
		        if(letra==palavra[i] && letra!=demonstracao[i]){
		           demonstracao[i]=letra;
		           aux++;
		           ganho++;
		        }
		}
		if(aux==0){
		    erro++;
		    e--;
		}
		aux=0;
		if(ganho==q){
			printf("Voce ganhou parabens");
			return 0;
		}
		if (erro==6){
		    printf("vc perdeu sinto muito");
		    return 0;
		}
		}
}
