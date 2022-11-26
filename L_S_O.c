#include <stdio.h>
#include <stdlib.h>

typedef struct nodo {
  int value;
  struct nodo *next;
} NODO;

typedef NODO *LISTA;

void newList(LISTA *);
int size(LISTA);
void insert(LISTA *, int);
void removeFirst(LISTA *, int);
void removeAll(LISTA *, int);
void destroy(LISTA *);
void printList(LISTA);

int main(void) {
  LISTA L;
  newList(&L);
  insert(&L, 30);
  insert(&L, 100);
  insert(&L, 40);
  insert(&L, 10);
  insert(&L, 10);
  insert(&L, 20);
  insert(&L, 100);
  insert(&L, 20);
  printList(L);
  destroy(&L);
  printList(L);
}

void newList(LISTA *L) { (*L) = NULL; }

int size(LISTA L) {
  int count = 0;
  while (L) {
    count++;
    L = L->next;
  }
  return count;
}

void insert(LISTA *L, int val) {
  NODO *new = (NODO *)malloc(sizeof(NODO));
  new->value = val;
  if (!(*L) || (val < (*L)->value)) {
    new->next = (*L);
    (*L) = new;
  } else {
    NODO *aux = *L;
    while (aux->next && aux->next->value < val)
      aux = aux->next;
    new->next = aux->next;
    aux->next = new;
  }
}

void removeFirst(LISTA *L, int val) {
  if ((*L)->value == val) {
    NODO *rem = (*L);
    (*L) = (*L)->next;
    free(rem);
  } else {
    NODO *aux = (*L);
    while (aux->next && aux->next->value < val)
      aux = aux->next;
    if (aux->next->value == val) {
      NODO *rem = aux->next;
      aux->next = aux->next->next;
      free(rem);
    } else {
      printf("O elemento %d nao foi encontrado!\n", val);
    }
  }
}

// deletar todas ocorrencias
void removeAll(LISTA *L, int val) {
  if ((*L) && (*L)->value == val) {
    while ((*L) && (*L)->value == val) {
      NODO *rem = (*L);
      (*L) = (*L)->next;
      free(rem);
    }
  } else {
    NODO *aux = *L;
    while (aux && aux->next && aux->next->value < val)
      aux = aux->next;
    if (aux && aux->next && aux->next->value == val) {
      while (aux->next && aux->next->value == val) {
        NODO *rem = aux->next;
        aux->next = aux->next->next;
        free(rem);
      }
    } else {
      printf("O elemento %d nao foi encontrado!\n", val);
    }
  }
}

void destroy(LISTA *L) {
  while ((*L)) {
    NODO *rem = (*L);
    (*L) = (*L)->next;
  }
}

void printList(LISTA L) {
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
