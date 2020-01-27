/******************************************************************************
                                    JOGO DA VELHA
*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
void board(char celulai[3][3]){
    system("clear");
    printf("\t %c | %c | %c \n", celulai[0][0],celulai[0][1], celulai[0][2]);
    printf("\t -----------\n");
    printf("\t %c | %c | %c \n", celulai[1][0],celulai[1][1], celulai[1][2]);
    printf("\t -----------\n");
    printf("\t %c | %c | %c \n", celulai[2][0],celulai[2][1], celulai[2][2]);
}
int main(){
    char celula[3][3]={{'a','b','c'},{'d','e','f'},{'g','h','i'}};
    char new;
    int quant, linha, coluna, jogador=0, m, n;
    do{
        quant = 1;
        for(m=0; m<=2; m++){
            for(n=0; n<=2; n++){
                celula[m][n]= ' ';
            }
        }
        do {
            board(celula);
            if(jogador%2==0){printf("jogador O\n");}
            else{printf("jogador X\n");}
            printf("Digite a linha correspondente: ");
            scanf("%i", &linha);
            printf("Digite a coluna correspondente: ");
            scanf("%i", &coluna);
            if(linha<1 || coluna<1||linha>3 || coluna>3){
                linha=0;
                coluna=0;
            }else if(celula[linha-1][coluna-1] != ' '){
                linha=0;
                coluna=0;
            }else{
                if(jogador%2==0){celula[linha-1][coluna-1] = 'O';}
                else{celula[linha-1][coluna-1] = 'X';}
                jogador++;
                quant++;
            }
            if(celula[0][0]=='X' && celula[0][1]=='X' && celula[0][2]=='X'){quant = 20;}
            if(celula[0][2]=='X' && celula[1][1]=='X' && celula[2][0]=='X'){quant = 20;}
            if(celula[1][0]=='X' && celula[1][1]=='X' && celula[1][2]=='X'){quant = 20;}
            if(celula[2][0]=='X' && celula[2][1]=='X' && celula[2][2]=='X'){quant = 20;}
            if(celula[1][0]=='X' && celula[2][0]=='X' && celula[0][0]=='X'){quant = 20;}
            if(celula[1][1]=='X' && celula[2][1]=='X' && celula[0][1]=='X'){quant = 20;}
            if(celula[1][2]=='X' && celula[2][2]=='X' && celula[0][2]=='X'){quant = 20;}
            if(celula[1][1]=='X' && celula[2][2]=='X' && celula[0][0]=='X'){quant = 20;}
            
            if(celula[0][0]=='O' && celula[0][1]=='O' && celula[0][2]=='O'){quant = 30;}
            if(celula[1][0]=='O' && celula[1][1]=='O' && celula[1][2]=='O'){quant = 30;}
            if(celula[2][0]=='O' && celula[2][1]=='O' && celula[2][2]=='O'){quant = 30;}
            if(celula[0][2]=='X' && celula[1][1]=='X' && celula[2][0]=='X'){quant = 30;}
            if(celula[1][0]=='O' && celula[2][0]=='O' && celula[0][0]=='O'){quant = 30;}
            if(celula[1][1]=='O' && celula[2][1]=='O' && celula[0][1]=='O'){quant = 30;}
            if(celula[1][2]=='O' && celula[2][2]=='O' && celula[0][2]=='O'){quant = 30;}
            if(celula[1][1]=='O' && celula[2][2]=='O' && celula[0][0]=='O'){quant = 30;}

        }while(quant<=9);
        board(celula);
        if(quant==10){printf("Deu velha!\n");}
        if(quant==20){printf("X venceu!\n");}
        if(quant==30){printf("O venceu!\n");}
        printf("Jogar novamente? [S-N]\n");
        scanf("%s",&new);
    }while(new=='s');

}


