#include <stdio.h>
#include <stdlib.h>

struct arraylist {
    int* vetor;
    int qtdade;
    int capacidade;
};

struct arraylist* inicializar(int capacidade) {
    struct arraylist* lista = (struct arraylist*)malloc(sizeof(struct arraylist));
    lista->vetor = (int*)calloc(capacidade, sizeof(int));
    lista->qtdade = 0; //quantidade de elementos
    lista->capacidade = capacidade; //tamanho do array
    return lista;
}

//obter elemento a fun��o retonar o elemento na posi��o x;
/*pra essa fun��o � necessario criarmos uma condi��o onde a posi��o � maior que zero e menor
que a quantidade de elementos*/
int obterElementoEmPosicao(struct arraylist* lista, int posicao) {
    if (posicao >= 0 && posicao < lista->qtdade) {
        return lista->vetor[posicao];
    }
    return 0;
}

void duplicarCapacidade(struct arraylist* lista) {
    lista->vetor = (int*)realloc(lista->vetor, 2 * lista->capacidade * sizeof(int));
    lista->capacidade = 2 * lista->capacidade;
}

void inserirElementoNoFim(struct arraylist* lista, int valor) {
    if (lista->qtdade == lista->capacidade) {
        duplicarCapacidade(lista);
    }
    lista->vetor[lista->qtdade] = valor;
    lista->qtdade++;
}

void inserirElementoEmPosicao(struct arraylist* lista, int valor, int posicao) {
    if (posicao >= 0 && posicao <= lista->qtdade) {
        if (lista->qtdade == lista->capacidade) {
            duplicarCapacidade(lista);
        }
        int i = lista->qtdade;
        while(i> posicao) {
            lista->vetor[i] = lista->vetor[i-1];
            i--;
        }
        lista->vetor[posicao] = valor;
        lista->qtdade++;
    }
}

void atualizarElemento(struct arraylist* lista, int valor, int posicao) {
    if (posicao >= 0 && posicao < lista->qtdade) {
        lista->vetor[posicao] = valor;
    }
}
//como � o elemento do fim a gente so precisa decrementar a quantidade que ele remove o ultimo elemento
void removerElementoNoFim(struct arraylist* lista) {
    lista->qtdade--;
}
/*para remover um elemento em uma determinada posi��o � necessario
verificar a posi��o remover aquele elemento */
void removerElementoEmPosicao(struct arraylist* lista, int posicao) {
    if (posicao >= 0 && posicao < lista->qtdade) {
        while (posicao < lista->qtdade - 1) {
            lista->vetor[posicao] = lista->vetor[posicao + 1];
            posicao++;
        }
        lista->qtdade--;
    }
}

void exibirLista(struct arraylist* lista) {
    printf("[");
    for (int i = 0; i < lista->qtdade; i++) {
        printf("%d", lista->vetor[i]);
        if (i < lista->qtdade - 1) {
            printf(", ");
        }
    }
    printf("]");
}