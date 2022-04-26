#include <stdio.h>
#include <stdlib.h>

int setmatriz(int linhas, int colunas, int **matriz, char nome){
   printf("matriz %c ", nome);
   printf("\n");
   
   matriz = malloc(linhas * sizeof(int*));
   
   for(int i = 0; i < linhas; i++){
        matriz[i] = malloc(colunas * sizeof(int));
    }
   for(int i = 0; i < linhas; i++) {
		for(int j = 0; j < colunas; j++) {
			printf("Digite o valor de [%d,%d] da matriz\n", i, j);
			scanf("%d", &matriz[i][j]);
		}
		printf("\n"); 
	}

  return matriz;
}

void freematriz(int **matriz,int linhas,int colunas){

  for(int i = 0; i < colunas; i++){
        free(matriz[i]);
    }
  free(matriz);
}

void trocamatriz(int **matrizx, int **matrizy, int linhas, int colunas){
   int tmp;

   for(int i = 0; i < linhas; i++) {
		for(int j = 0; j < colunas; j++) {
			tmp = matrizx[i][j];  matrizx[i][j] = matrizy[i][j]; matrizy[i][j] = tmp;	
		}
	}
}

void imprimematriz(int **matriz, int linhas, int colunas, char nome){
   printf("matriz %c ", nome);
   printf("\n");
   for(int i = 0; i < linhas; i++) {        
		for(int j = 0; j < colunas; j++){
			printf("%d ", matriz[i][j]);
		}
		printf("\n\n");
	}
}

int main() {
   int **matrizx, **matrizy;
   char nomex = 'x';
   char nomey = 'y';
   int linhas = 4;
   int colunas = 4;

   matrizx = setmatriz(linhas, colunas, matrizx, nomex);
   matrizy = setmatriz(linhas, colunas, matrizy, nomey);
   
   imprimematriz(matrizx, linhas, colunas, nomex);
   imprimematriz(matrizy, linhas, colunas, nomey);

   trocamatriz(matrizx, matrizy, linhas, colunas);

   imprimematriz(matrizx, linhas, colunas, nomex);
   imprimematriz(matrizy, linhas, colunas, nomey);

   freematriz(matrizx, linhas, colunas);
   freematriz(matrizy, linhas, colunas);
   return 0;
}




