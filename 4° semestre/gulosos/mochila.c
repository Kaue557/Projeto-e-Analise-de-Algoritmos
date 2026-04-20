#include <stdio.h>
#define MAX 1000

/*
mochila fracionaria(w, v, n, W)
ordene w e v de tal forma que
v[1]/w[1] ≥ v[2]/w[2] ≥ · · · ≥ v[n]/w[n]
i ← 1

enquanto i ≤ n e W > 0 faça
    se w[i] ≤ W
        então x[i] ← 1 B coloca o objeto inteiro na mochila.
            W ← W − w[i]
            i ← i + 1
        senão x[i] ← W/w[i] B coloca fração do objeto na mochila W ← 0
retorne x
*/

typedef struct {
    int valor;
    int peso;
    float razao;
    int indice_original;
} Item;

// ordena em ordem decrescente (bubble sort simples)
void ordenarDecrescente(Item itens[], int tam) {
    for (int i = 0; i < tam - 1; i++) {
        for (int j = 0; j < tam - i - 1; j++) {
            if (itens[j].razao < itens[j + 1].razao) {
                Item temp = itens[j];
                itens[j] = itens[j + 1];
                itens[j + 1] = temp;
            }
        }
    }
}

int mochila_fracionaria(Item itens[], int n, int capacidade, float mochila[]){
    int i = 0;

    while(i < n && capacidade > 0){ // enquanto nao acessarmos todos os itens e ainda houver capacidade na mochila
        if(itens[i].peso <= capacidade){
            mochila[i] = 1;
            capacidade = capacidade - itens[i].peso; // diminui a capacidade total da mochila
            i++;
        }else{
            mochila[i] = (float)capacidade/itens[i].peso; // coloca a fração maxima daquele item na mochila
            capacidade = 0;
        }
    }
    return 1;
    
}

int main(){
    int n;
    int capacidade;

    printf("num. de itens: ");
    scanf("%d", &n);

    printf("capacidade da mochila: ");
    scanf("%d", &capacidade);
    

    Item itens[n];

    for(int i = 0; i <= n-1; i++){ // leitura de valor e peso de cada item
        printf("valor item %d: ", i+1);
        scanf("%d", &itens[i].valor);

        printf("peso item %d: ", i+1);
        scanf("%d", &itens[i].peso);

        printf("\n");

        itens[i].razao = (float)itens[i].valor / (float)itens[i].peso; // calculo da razao
        itens[i].indice_original = i; // guardando indice original para melhorar saida no print
    }
    
    ordenarDecrescente(itens, n);

    float mochila[MAX];
    for (int i = 0; i < n; i++) {
        mochila[i] = 0.0;
    }

    mochila_fracionaria(itens, n, capacidade, mochila);
    printf("fracoes:\n");
    for (int i = 0; i < n; i++) {
        printf("%.2f do item %d", mochila[i], itens[i].indice_original + 1);
        printf("\n");
    }
    printf("\n");
    

    return 0;
}