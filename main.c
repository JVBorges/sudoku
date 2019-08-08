/* Integrantes do grupo: Felipe Aguiar     S.I  *
 *                       Jo�o Vitor Borges C.C  *
 *                                              *
 *                                              */

#include <stdio.h>
#include <stdbool.h>
#define LIN 9
#define COL 9
#define SOMA 285
#define SQR(x) ((x)*(x))

bool verifica_linha(int lin, int tab[][COL]);
bool verifica_coluna(int col, int tab[][COL]);
bool verifica_regiao(int reg, int tab[][COL]);

int main()
{
    int i, j, x, entrada, tab[LIN][COL], count = 0, instancia = 0;

    scanf("%d", &entrada);

    for (x = 0; x < entrada; x++) {
        for (i = 0; i < LIN; i++) {
            for (j = 0; j < COL; j++) {
                scanf("%d", &tab[i][j]);
            }
        }

        // Chamada das fun��es para verificar a som�toria de cada linha, coluna e regi�o
        // Caso a som�toria seja 285(1*1 + 2*2 + ... + 9*9)as fun��es retornam true e soma-se 1 ao contador
        for (i = 0; i < 9; i++){
            if ((verifica_linha(i, tab)) && (verifica_coluna(i, tab)) && (verifica_regiao(i, tab)) == true) {
                    count++;
            }else {
                break;
            }
        }

        instancia++;

        // Caso o contador seja 9 resulta que a somatoria de todas as linhas, colunas e regi�es foram iguais
        // a 285 sendo assim a solu��o do sudoku
        if (count == 9) {
            printf("Instancia %d\nSIM\n\n", instancia);
        }else {
            printf("Instancia %d\nNAO\n\n", instancia);
        }
    count = 0;
    }
    return 0;
}

bool verifica_linha(int lin, int tab[][COL])
{
    int j, soma_linha = 0;

    // La�o responsavel em fazer a som�toria das linhas
    for (j = 0; j < COL; j++) {
        soma_linha += SQR(tab[lin][j]);
    }

    //Verifica��o da soma da linha
    if (soma_linha == SOMA) {
        return true;
    }else {
        return false;
    }
}

bool verifica_coluna(int col, int tab[][COL])
{
    int i, soma_coluna = 0;

    // La�o responsavel em fazer a som�toria das colunas
    for (i = 0; i < LIN; i++) {
        soma_coluna += SQR(tab[i][col]);
    }

    //Verifica��o da soma da coluna
    if (soma_coluna == SOMA) {
        return true;
    }else {
        return false;
    }
}

bool verifica_regiao(int reg, int tab[][COL])
{
    int soma_reg[3][3] = {0};
    int i, j;

    // La�o responsavel em fazer a som�toria das regi�es
    for (i = 0; i < LIN; i++) {
        for (j = 0; j < COL; j++) {
            soma_reg[i/3][j/3] += SQR(tab[i][j]);
        }
    }

    //Verifica��o da soma da regi�o
    if (soma_reg[reg/3][reg%3] == SOMA) {
        return true;
    }else {
        return false;
    }
}

/*---------------------
       AVALIA��O
  ---------------------
  - Corretude...: 10.00
  - Legibilidade: 10.00
  - Nota........: 10.00
  ---------------------*/
