#include<stdio.h>
#define TAMANHO 10

//Merge funcionando XXXX
//Não realizar a operação merge caso a coleção já esteja ordenada XXXX
//Utilizar Insertsort em partes pequenas do array
//Eliminar a cópia para um array ayxiliar
//Aproveitar trechos pré-ordenados

void imprimir_vetor(int vetor[]) {
	int contador = 0;
	printf("(");
	for(contador; contador < TAMANHO-1; contador++) {
		printf("%d, ", vetor[contador]);
	}
	printf("%d)\n", vetor[TAMANHO-1]);
}

void merge(int vetor[], int l, int m, int r)
{

    int i, j, k, contador;
    int esquerda = m - l + 1;
    int direita = r - m;

    int vetorEsquerda[esquerda], vetorDireita[direita];               // Vetor temporario
  
    for (i = 0; i < esquerda; i++)
        vetorEsquerda[i] = vetor[l + i];        // Copiando itens
    for (j = 0; j < direita; j++)
        vetorDireita[j] = vetor[m + 1 + j];     // Copiando itens
        
    i = 0;
    j = 0;
    k = l;
    while (i < esquerda && j < direita) {
        if (vetorEsquerda[i] <= vetorDireita[j]) {
            vetor[k] = vetorEsquerda[i];
            i++;
        }
        else {
            vetor[k] = vetorDireita[j];
            j++;
        }
        k++;
    }
  
    while (i < esquerda) {
        vetor[k] = vetorEsquerda[i];
        i++;
        k++;
    }

    while (j < direita) {
        vetor[k] = vetorDireita[j];
        j++;
        k++;
    }
    printf("\nSeparacao\n");
    imprimir_vetor(vetor);
}

void merge_sort(int vetor[], int l, int r)
{
    if (l < r) {
        int m = l + (r - l) / 2;                 // SEPARANDO NO MEIO
        merge_sort(vetor, l, m);                  // vai trabalhar com a parte ESQUERDA,  função recursiva, vai ficando cada vez menor
        merge_sort(vetor, m + 1, r);              // vai trabalhar com a parte DIREITA,  função recursiva, vai ficando cada vez menor
        if(vetor[m] <= vetor[m+1]) {          // impedir merge caso já esteja ordenado
			return;
		}
		merge(vetor, l, m, r);
    }
}

int main()
{
	int vetor[10] = {3, 1, 9, 5, 2, 6, 8, 4, 0, 7};
	//int vetor[20] = {16, 1, 2, 13, 4, 14, 17, 9, 8, 12, 10, 11, 6, 3, 5, 15, 0, 7, 18, 19};
	
	imprimir_vetor(vetor);
	
	merge_sort(vetor, 0, TAMANHO - 1);
	
	imprimir_vetor(vetor);
	
	return 0;
}

