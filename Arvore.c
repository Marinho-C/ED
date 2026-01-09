#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int dado;
    struct no *esq;
    struct no *dir;
} No;

typedef struct arv {
    No* raiz;
} Arv;

Arv* criar_arv() {
    Arv* arv = (Arv*) malloc(sizeof(Arv));
    if (arv == NULL) {
        printf("Erro ao alocar arvore\n");
        exit(1);
    }
    arv->raiz = NULL;
    return arv;
}

No* criar_no(int dado) {
    No* novo = (No*) malloc(sizeof(No));
    if (novo == NULL) {
        printf("Erro ao alocar no\n");
        exit(1);
    }
    novo->dado = dado;
    novo->esq = NULL;
    novo->dir = NULL;
    return novo;
}

No* inserir(No* raiz, int dado) {
    if (raiz == NULL) {
        return criar_no(dado);
    }

    if (dado < raiz->dado) {
        raiz->esq = inserir(raiz->esq, dado);
    } else if (dado > raiz->dado) {
        raiz->dir = inserir(raiz->dir, dado);
    }

    return raiz;
}

void imprimir_inordem(No* raiz) {
    if (raiz != NULL) {
        imprimir_inordem(raiz->esq);
        printf("%d ", raiz->dado);
        imprimir_inordem(raiz->dir);
    }
}

int main() {
    Arv* arv = criar_arv();
    int num;

    printf("Digite 10 numeros inteiros:\n");

    for (int i = 0; i < 10; i++) {
        printf("Numero %d: ", i + 1);
        scanf("%d", &num);
        arv->raiz = inserir(arv->raiz, num);
    }

    printf("\nElementos em ordem crescente:\n");
    imprimir_inordem(arv->raiz);
    printf("\n");

    return 0;
}
