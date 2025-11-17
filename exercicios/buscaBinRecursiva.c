#include <stdio.h>

void bubbleSort(int vet[], int n) {
	int i, j;
	// O laco externo controla o numero de passagens
	for (i = 0; i < n - 1; i++) {
		// O laco interno faz a comparacao e a troca
		for (j = 0; j < n - i - 1; j++) {
			// Compara elementos adjacentes
			if (vet[j] > vet[j + 1]) {
				// Troca se estiverem na ordem errada
				int temp = vet[j];
				vet[j] = vet[j + 1];
				vet[j + 1] = temp;
			}
		}
	}
}

int buscaBinaria(int num_secreto, int esq, int dir, int vet[]){ // conferir se funciona*
    /*
    int esq = 0;
    int dir = n - 1;
    int meio;
    */
    
    if(dir == esq) return -1;
    
    int meio = (esq + dir)/2;
    if(num_secreto == meio) return meio;
    if(num_secreto > meio){
        return buscaBinaria(num_secreto, vet, meio + 1, dir);
        buscaBinaria(num_secreto, vet, esq, meio - 1)
    }
}

int main() {
	int vet[] = {4, 3, 76, 35, 99, 21, 1, 6, 8, 33, 27}; // 11 elementos
	int n = sizeof(vet) / sizeof(vet[0]);

	bubbleSort(vet, n);
	for(int i = 0; i < n; i++) {
		printf("%d ", vet[i]);
	}
	printf("\n");
	// neste ponto o vetor esta ordenado
	
	int indice_achou = buscaBinaria(8, n, vet);
	if(indice_achou < 0){
	    printf("achou nao papae");
	}else{
	    printf("indice do numero secreto: %d", indice_achou);
	}
    
	return 0;
}