#include <stdio.h>
#include <stdlib.h>

typedef struct nodo {
  int value;
  struct nodo *next;
} NODO;

typedef NODO *LISTA_C;

void createList(LISTA_C *L) { (*L) = NULL; }

int size(LISTA_C L) {
  NODO *aux = L;
  int count = 0;
  if (aux)
    do {
      count++;
      aux = aux->next;
    } while (aux != L);
  return count;
}

void insert(LISTA_C *L, int val, int pos) {
  if (pos < 1 || pos > size((*L)) + 1) {
    printf("Posicao de insercao invalida!\n");
  } else {

    NODO *new = (NODO *)malloc(sizeof(NODO));
    new->value = val;

    if (pos == size((*L)) + 1) {
      if ((*L)) {
        new->next = (*L)->next;
        (*L)->next = new;
        (*L) = new;
      } else {
        new->next = new;
        (*L) = new;
      }
    } else {
      NODO *aux = (*L);
      while (pos-- != 1)
        aux = aux->next;
      new->next = aux->next;
      aux->next = new;
    }
  }
}

void delete(LISTA_C *L, int pos) {
  if (pos < 1 || pos > size((*L)) + 1) {
    printf("Posicao para remocao invalida!\n");
  } else {
    NODO *rem;
    if (pos == size((*L))) {
      if (size((*L)) == 1) {
        free((*L));
        (*L) = NULL;
      } else {
        NODO *aux = *L;
        while (pos-- != 1)
          aux = aux->next;
        rem = aux->next;
        aux->next = aux->next->next;
        (*L) = aux;
        free(rem);
      }
    } else {
      NODO *aux = *L;
      while (pos-- != 1)
        aux = aux->next;
      rem = aux->next;
      aux->next = aux->next->next;
      free(rem);
    }
  }
}

int recup(LISTA_C L, int pos) {
  if (pos < 1 || pos > size(L) + 1) {
    printf("Posicao para consulta invalida!\n");
  } else {
    NODO *aux = L;
    while (pos-- != 1)
      aux = aux->next;
    return aux->next->value;
  }
  return -1;
}

void destroy(LISTA_C *L) {
  while ((*L))
    delete (L, 1);
}

void printList(LISTA_C L) {
  NODO *aux = L;
  int count = 0;
  printf("\n+++ LISTA +++\n");
  printf("Tamanho: %d\n", size(L));
  if (aux)
    do {
      ++count;
      printf("%d. %d\n", count, recup(L, count));
      aux = aux->next;
    } while (aux != L);
  else
    printf("Lista Vazia!\n");
  printf("+++++++++++++\n");
}

int main() {
  LISTA_C LISTA;
  createList(&LISTA);

  insert(&LISTA, 10, 1);
  printList(LISTA);

  insert(&LISTA, 20, 1);
  printList(LISTA);

  insert(&LISTA, 40, 3);
  printList(LISTA);

  destroy(&LISTA);
  printList(LISTA);
}
