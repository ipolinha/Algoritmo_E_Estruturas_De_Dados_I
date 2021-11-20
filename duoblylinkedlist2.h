#include <stdlib.h>
#include <stdio.h>

struct no {
    struct no* ant;
    int val;
    struct no* prox;
};

struct doublylinkedlist {
    struct no* cabeca;
    struct no* cauda;
    int qtdade;
};

struct doublylinkedlist* inicializar() {
    struct doublylinkedlist* lista = (struct doublylinkedlist*)malloc(sizeof(struct doublylinkedlist));
    lista->cabeca = NULL;
    lista->cauda = NULL;
    lista->qtdade = 0;

    return lista;
}

struct no* alocarNovoNo(int valor) {
    struct no* proxno = (no*)malloc(sizeof(no));
    proxno->val = valor;
    proxno->ant = NULL;
    proxno->prox = NULL;

    return proxno;
}

void inserirElementoNoInicio(struct doublylinkedlist* lista, int valor) {
    struct no* proxno1 = alocarNovoNo(valor);

    if (lista->cabeca != NULL) {
        struct no* proxno2 = lista->cabeca;

        proxno2->ant = proxno1;
        proxno1->prox = proxno2;
        lista->cabeca = proxno1;
        lista->qtdade++;
    }
    else {
        lista->cabeca = proxno1;
        lista->cauda = proxno1;
        lista->qtdade++;
    }
}

void inserirElementoNoFim(struct doublylinkedlist* lista, int valor) {
    struct no* proxno1 = alocarNovoNo(valor);
    struct no* proxno2 = lista->cabeca;

    if (lista->qtdade == 0) {
        lista->cabeca = proxno1;
        lista->qtdade++;
    }
    else {
        while (proxno2->prox != NULL) {
            proxno2 = proxno2->prox;
        }

        proxno2->prox = proxno1;
        proxno1->ant = proxno2;
        lista->cauda = proxno1;
        lista->qtdade++;
    }
}

void inserirElementoEmPosicao(struct doublylinkedlist* lista, int valor, int posicao) {
    struct no* proxno1 = alocarNovoNo(valor);

    if (posicao == 0) {
        inserirElementoNoInicio(lista, valor);
    }
    else if (posicao > lista->qtdade - 1) {
        inserirElementoNoFim(lista, valor);
    }
    else {
        struct no* proxno2 = lista->cabeca;

        for (int i = 0; i < posicao - 1; i++) {
            proxno2 = proxno2->prox;
        }

        proxno1->ant = proxno2;
        proxno1->prox = proxno2->prox;
        struct no* proxno3 = proxno2->prox;
        proxno3->ant = proxno1;
        proxno2->prox = proxno1;

        lista->qtdade++;
    }
}

int obterElementoEmPosicao(struct doublylinkedlist* lista, int posicao) {
    if (posicao >= 0 && lista->cabeca != NULL) {
        struct no* proxno1 = lista->cabeca;

        for (int i = 0; i < posicao; i++) {
            if (proxno1->prox == NULL) {
                return proxno1->val;
            }

            proxno1 = proxno1->prox;
        }

        return proxno1->val;
    }
}

void removerElementoEmPosicao(struct doublylinkedlist* lista, int posicao) {
    struct no* proxno1 = lista->cabeca;
    struct no* proxno3 = lista->cauda;
    struct no* proxno2 = proxno1;

    if (posicao == 0) {
        lista->cabeca = lista->cabeca->prox;
        proxno2->ant = lista->cabeca;
        
        free(proxno1);
        lista->qtdade--;
    }
    else if (posicao >= lista->qtdade - 1) {
        lista->cauda = proxno3->ant;
        proxno2 = proxno3->ant;
        proxno2->prox = NULL;

        free(proxno3);
        lista->qtdade--;
    }
    else {
        for (int i = 0; i < posicao - 1; i++) {
           proxno1 = proxno1->prox;
        }

        proxno2 = proxno1->prox;
        proxno3 = proxno2->prox;
        proxno1->prox = proxno3;
        proxno3->ant = proxno1;
        free(proxno2);
        lista->qtdade--;
    }
}

void imprimirLista(struct no** cabeca) {
    //usamos o aux para percorrer a lista
    if ((*cabeca) != NULL) {
        struct no* aux = (*cabeca);
        //navega partindo da cabeça até chegar NULL
        printf("[");
        do {
            printf("%d", aux->val);
            aux = aux->prox;
            if (aux != NULL) {
                printf(", ");
            }
        } while (aux != NULL);
        printf("]");
    }
    else {
        printf("A lista está vazia!");
    }
}
