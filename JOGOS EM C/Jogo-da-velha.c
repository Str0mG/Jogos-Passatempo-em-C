#include <stdio.h>
#include <stdlib.h>

void exibicao_x(char matriz[][200],int tam){
    int i,j;
    printf("-Jogo Da velha-\n");
    for(i=0;i<tam;i++){
        for(j=0;j<tam;j++){
            printf("|    %c    |",matriz[i][j]);
        }
        printf("\n");
    }
}
void exibicao_o(char matriz[][200],int tam){
    int i,j;
    printf("-Jogo Da velha-\n");
    for(i=0;i<tam;i++){
        for(j=0;j<tam;j++){
                printf("|    %c    |",matriz[i][j]);
        }
        printf("\n");
    }
    return;
}
//funcao para analisar se o vetor da completo de 1, para ver se completou e retornar positivo
int arrumar(int vetor[],int tam){
    int i;
    int cont=0;
    for(i=0; i<tam; i++){
        if(vetor[i]==1)
            cont++;
    }
    if(cont==tam)
        return 1;
    else
        return 0;
}
//verificacao das possibilidades para O
int verificacao_o(char matriz[][200],int tam){
    int vetor[tam],result=0;
    int i,j,k;
    for(i=0; i<tam; i++){
        for(j=0; j<tam; j++){
            if(matriz[i][j]=='O')
                vetor[j]=1;
            else
                vetor[j]=0;
        }
        result = arrumar(vetor,tam);
        if(result==1)
            return 1;
    }
    for(j=0; j<tam; j++){
        for(i=0; i<tam; i++){
            if(matriz[i][j]=='O')
                vetor[i]=1;
            else
                vetor[i]=0;

        }
        result= arrumar(vetor,tam);
        if(result==1)
            return 1;
    }
    k=0;
    for(i=0; i<tam; i++){
        for(j=0; j<tam; j++){
            if(i==j){
                if(matriz[i][j]=='O')
                    vetor[k]=1;
                else
                    vetor[k]=0;
            k++;
            }
        }

    }
    result=arrumar(vetor,tam);
    if(result==1)
        return 1;

    k=0;
    for(i=0;i<tam;i++){
        for(j=0;j<tam;j++){
            if(i+j==tam-1){
                if(matriz[i][j]=='O')
                    vetor[k]=1;
                else if(matriz[i][j]!='O')
                    vetor[k]=0;
                k++;
            }
        }
    }
    result = arrumar(vetor,tam);
    if(result==1)
        return 1;
    else
        return 0;
}
                //verificacao das possibilidades para O
int verificacao_x(char matriz[][200],int tam){
    int vetor[tam],result=0;
    int i,j,k;
    for(i=0; i<tam; i++){
        for(j=0; j<tam; j++){
            if(matriz[i][j]=='X')
                vetor[j]=1;
            else
                vetor[j]=0;
        }
    result = arrumar(vetor,tam);
    if(result==1)
        return 1;
    }
    for(j=0; j<tam; j++){
        for(i=0; i<tam; i++){
            if(matriz[i][j]=='X')
                vetor[i]=1;
            else
                vetor[i]=0;
        }
        result= arrumar(vetor,tam);
        if(result==1)
            return 1;
    }
    k=0;
    for(i=0; i<tam; i++){
        for(j=0; j<tam; j++){
            if(i==j){
                if(matriz[i][j]=='X')
                    vetor[k]=1;
                else
                    vetor[k]=0;
                k++;
            }
        }
    }
    result=arrumar(vetor,tam);
    if(result==1)
        return 1;


    k=0;
    for(i=0;i<tam;i++){
        for(j=0;j<tam;j++){
            if(i+j==tam-1){
                if(matriz[i][j]=='X')
                    vetor[k]=1;
                else if(matriz[i][j]!='X')
                    vetor[k]=0;
                    k++;
                }
            }
        }
    result = arrumar(vetor,tam);
    if(result==1)
        return 1;
    else
        return 0;
}

int main(){
    char regras;
    int w;
    while(w){
        printf("----------------------------JOGO DA VELHA-------------------------------------------\n");

        printf("                   O MELHOR JOGO DA VELHA DA UTFPR-CP\n!Atencao!\n-Nao pode jogar duas vezes no mesmo lugar\n-Nao vale jogar na vez do adversario\n-E ultima regra mais importante: DIVIRTA-SE");
        printf("\n\nVoce esta preparado\nS-Sim N-Nao\n");
        scanf("%c",&regras);
        if(regras=='S' || regras=='s')
            w=0;
        else{
            system("cls");
            printf("Como assim nao esta preparado. Leia dnv as regra com atencao!\n\n");
            w=1;//para ate que entenda e da continuaidade no jogo
        }
    }
    system("cls");
    char usuario1[50];
    char usuario2[50];
    printf("                       CADASTRO DO PLAYER 1\n");
    printf("Digite o Nick do primeiro jogador:\n");
    scanf("%s",&usuario1);
    system("cls");
    printf("                       CADASTRO DO PLAYER 2\n");
    printf("Digite o Nick do segundo jogador:\n");
    scanf("%s",&usuario2);
    system("cls");
    printf("                     QUE A SORTE ESTEJA COM VOCES");
    system("cls");
    int ganhou_x=0,ganhou_o=0;
    int cont;
    int tam,i,j,k;
    int n1,n2,n3,n4;
    printf("Digite um numero para as dimensoes:\n");
    scanf("%d",&tam);
    system("cls");
    char matriz[200][200];//colocamos esse tamanho na matriz para haver a possibilidade de mandar ela para um função, mas o usuario que coloca o tamanho ainda
//armazenando o caracter _ para da cara ao jogo, e nao deixando a matriz vazia
    for(i=0; i<tam; i++){
        for(j=0; j<tam; j++)
            matriz[i][j]='_';
    }//exibindo para o usuario o layout do campo de batalha(A matriz)
    printf("-Jogo Da velha-\n");
    for(i=0;i<tam;i++){
        for(j=0;j<tam;j++){
                printf("|    %c    |",matriz[i][j]);
        }
        printf("\n");
    }
    cont=0;
/*A logica abaixo funciona o seguinte: foi criado 3 funcoes e 2 procedimentos, esses 2 procedimentos realiza so o print do jogo
para o X e o O, isso foi usado para ter uma organizacao no programa principal e facilitar a leitura do codigo,as duas funcoes
chamada verificacao uma para X e outra para O funciona para analisar as possibilidades de vitoria, entao ela vai analisar
as linhas,as colunas, a diagonal principal e a diagonal secundaria, a partir disso, ela vai pegar ex: uma linha, ou coluna ou
as diagonais e vai armazenar em um vetor se tiver um letra no lugar armazena com 1 assim ela vai mandar para ultima funcao que chama
funcao arrumar que vai ver se o vetor todo tiver com 1(a letra analisada) ele vai retornar positivo ate chegar no prgrama
principal que vai encerrar falando que alguem ganhou, se nao vai repetir o processo todo, se nenhuma vez retornou positivo
e todas as jogadas foram feitas isso indica o empate*/
    for(i=0;i<tam;i++){
        for(j=0; j<tam; j++){
            if(cont%2==0){
                printf("Sua vez %s\nDigite a linha:",usuario1);
                scanf("%d",&n1);
                printf("Agora digite a coluna:");
                scanf("%d",&n2);
                system("cls");
                matriz[n1-1][n2-1]='X';
                exibicao_x(matriz,tam);//so exibindo para o usuario a matriz que ele colocou a cordenada
                ganhou_x=verificacao_x(matriz,tam);//a partir que ele colocou as cordenadas tem que haver a verificacao para uma possivel vitoria

                if(ganhou_x==1){//retornando positivo a verificacao
                    printf("\n******%s GANHOUUUUUUUUU*********",usuario1);
                    return 0;
                }

            }
            if (cont%2!=0){//usou um cont para haver a alternancia de jogadas(par e impar) uma vez de cada
            //vez do O
                printf("Sua vez %s\nDigite a linha:",usuario2);
                scanf("%d",&n3);
                printf("Agora digite a coluna:");
                scanf("%d",&n4);
                system("cls");
                matriz[n3-1][n4-1]='O';
                exibicao_o(matriz,tam);
                ganhou_o=verificacao_o(matriz,tam);
                if(ganhou_o==1){
                    printf("\n******%s Eh Campeaooooooooo******",usuario2);
                    return 0;
                }
            }
            cont++;
            if (cont==tam*tam){//a quantidade de casa a matriz tem e o cont atingiu o valor é empate
                printf("\nOs dois sao bons.O jogo deu empate");
                return 0;
            }

        }
    }


}

//E acabou o jogo :)
