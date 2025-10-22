#include <stdio.h>
#include <stdlib.h>

#define TAM 5  

struct Pilha {
    int dados[TAM];
    int topo;
};
void inicializar(struct Pilha *p) {
    p->topo = -1;
}
int isEmpty(struct Pilha *p) {
    return (p->topo == -1);
}
int isFull(struct Pilha *p) {
    return (p->topo == TAM - 1);
}

void push(struct Pilha *p, int valor) {
    if (isFull(p)) {
        printf("A pilha está cheia! Não é possível empilhar.\n");
    } else {
        p->topo++;
        p->dados[p->topo] = valor;
        printf("Valor %d empilhado com sucesso!\n", valor);
    }
}
void pop(struct Pilha *p) {
    if (isEmpty(p)) {
        printf("A pilha está vazia! Nada para desempilhar.\n");
    } else {
        int removido = p->dados[p->topo];
        p->topo--;
        printf("Valor %d removido da pilha.\n", removido);
    }
}

void topo(struct Pilha *p) {
    if (isEmpty(p)) {
        printf("A pilha está vazia!\n");
    } else {
        printf("Topo da pilha: %d\n", p->dados[p->topo]);
    }
}

void mostrar(struct Pilha *p) {
    if (isEmpty(p)) {
        printf("A pilha está vazia!\n");
    } else {
        printf("Elementos da pilha:\n");
        for (int i = p->topo; i >= 0; i--) {
            printf("| %d |\n", p->dados[i]);
        }
    }
}

int main() {
    struct Pilha p;
    inicializar(&p);

    int opcao, valor;

    do {
        printf("\n=== MENU PILHA ===\n");
        printf("1 - Empilhar (push)\n");
        printf("2 - Desempilhar (pop)\n");
        printf("3 - Mostrar topo\n");
        printf("4 - Mostrar pilha\n");
        printf("5 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite um valor: ");
                scanf("%d", &valor);
                push(&p, valor);
                break;
            case 2:
                pop(&p);
                break;
            case 3:
                topo(&p);
                break;
            case 4:
                mostrar(&p);
                break;
            case 5:
                printf("Saindo do programa...\n");
                break;
            default:
                printf("Opcao invalida!\n");
        }
    } while (opcao != 5);

    return 0;
}

