#include <stdio.h>
#include <stdlib.h>

typedef struct nodo {
  int value;
  struct nodo *next;
} NODO;

typedef NODO *LISTA_S;

void newList(LISTA_S *);
int size(LISTA_S);
void insert(LISTA_S *, int, int);
void delete(LISTA_S *, int);
void destroy(LISTA_S *);
void printList(LISTA_S);

int main(void) {
  LISTA_S LISTA;
  newList(&LISTA);
  insert(&LISTA, 10, 1);
  insert(&LISTA, 20, 1);
  insert(&LISTA, 30, 1);
  insert(&LISTA, 40, 2);
  insert(&LISTA, 100, 1);
  printList(LISTA);
  delete (&LISTA, 4);
  printList(LISTA);
  destroy(&LISTA);
  printList(LISTA);
}

void newList(LISTA_S *L) { (*L) = NULL; }

int size(LISTA_S L) {
  int count = 0;
  while (L) {
    count++;
    L = L->next;
  }
  return count;
}

void insert(LISTA_S *L, int val, int pos) {
  if (pos < 1 || pos > size(*L) + 1) {
    printf("Posicao invalida!\n");
  } else {
    NODO *new = (NODO *)malloc(sizeof(NODO));
    new->value = val;
    if (pos == 1) {
      new->next = (*L);
      (*L) = new;
    } else {
      NODO *aux = *L;
      while (--pos != 1)
        aux = aux->next;
      new->next = aux->next;
      aux->next = new;
    }
  }
}

void delete(LISTA_S *L, int pos) {
  if (pos < 1 || pos > size(*L) + 1) {
    printf("Posicao invalida!\n");
  } else {
    NODO *rem;
    if (pos == 1) {
      rem = *L;
      (*L) = (*L)->next;
      free(rem);
    } else {
      NODO *aux = (*L);
      while (--pos != 1)
        aux = aux->next;
      rem = aux->next;
      aux->next = aux->next->next;
      free(rem);
    }
  }
}

void destroy(LISTA_S *L) {
  while (*L)
    delete (L, 1);
}

void printList(LISTA_S L) {
  int cont = 0;
  printf("\n--- LISTA ---\n");
  if (!L) {
    printf("LISTA VAZIA!\n");
  } else {
    while (L) {
      printf("%d. %d\n", ++cont, L->value);
      L = L->next;
    }
  }
  printf("-------------\n\n");
}
