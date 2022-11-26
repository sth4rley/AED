#include <stdio.h>
#include <stdlib.h>

typedef struct nodo {
  int value;
  struct nodo *next;
} NODO;

typedef NODO *LISTA_NC;

void createList(LISTA_NC *);
int size(LISTA_NC);
void insert(LISTA_NC, int, int);
int recup(LISTA_NC, int);
void erase(LISTA_NC, int);
void destroy(LISTA_NC *);
void printList(LISTA_NC L);

int main() {
  LISTA_NC LISTA;
  createList(&LISTA);
  printList(LISTA);
  insert(LISTA, 10, 1);
  insert(LISTA, 20, 2);
  insert(LISTA, 30, 1);
  printList(LISTA);
  destroy(&LISTA);
  printList(LISTA);
}

void createList(LISTA_NC *L) {
  NODO *new = (NODO *)malloc(sizeof(NODO));
  (*L) = new;
  (*L)->next = NULL;
  (*L)->value = 0;
}

int size(LISTA_NC L) { return L->value; }

void insert(LISTA_NC L, int val, int pos) {
  if (pos < 1 || pos > size(L) + 1) {
    printf("Posicao invalida!\n");
  } else {
    NODO *new = (NODO *)malloc(sizeof(NODO));
    new->value = val;
    L->value++;
    while (pos-- != 1)
      L = L->next;
    new->next = L->next;
    L->next = new;
  }
}

int recup(LISTA_NC L, int pos) {
  if (pos < 1 || pos > size(L)) {
    printf("Posicao invalida!\n");
    return -1;
  } else {
    while (pos--)
      L = L->next;
    return L->value;
  }
}

void erase(LISTA_NC L, int pos) {
  if (pos < 1 || pos > size(L)) {
    printf("Posicao invalida!\n");
  } else {
    L->value--;
    // ir ate o anterior
    while (pos-- != 1)
      L = L->next;
    NODO *rem = L->next;
    L->next = L->next->next;
    free(rem);
  }
}

void destroy(LISTA_NC *L) {
  while ((*L)->next)
    erase(*L, 1);
}

void printList(LISTA_NC L) {
  int tam = size(L);
  printf("\n++++++ LISTA ++++++\n");
  printf("Tamanho da lista %d\n", L->value);
  for (int i = 0; i < tam; i++)
    printf("%d. %d\n", i + 1, recup(L, i + 1));
  printf("+++++++++++++++++++\n");
}
