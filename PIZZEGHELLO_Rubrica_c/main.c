#include <stdio.h>
#include <string.h>

#define CONTATTI 100

struct Contatto {
    char nome[30];
    char cognome[30];
    char telefono[15];
};

void aggiungiContatto(struct Contatto rubrica[], int *n);
void mostraContatti(struct Contatto rubrica[], int n);
void cercaContatto(struct Contatto rubrica[], int n);
void eliminaContatto(struct Contatto rubrica[], int *n);

int main() {
    struct Contatto rubrica[CONTATTI];
    int n = 0;
    int scelta;

    do {
        printf(" RUBRICA\n");
        printf("1-Aggiungi contatto\n");
        printf("2-Mostra contatti\n");
        printf("3-Cerca per cognome\n");
        printf("4-Elimina per cognome\n");
        printf("5-Esci\n");
        scanf("%d", &scelta);

        if (scelta == 1) aggiungiContatto(rubrica, &n);
        else if (scelta == 2) mostraContatti(rubrica, n);
        else if (scelta == 3) cercaContatto(rubrica, n);
        else if (scelta == 4) eliminaContatto(rubrica, &n);

    } while (scelta != 5);

    return 0;
}

void aggiungiContatto(struct Contatto rubrica[], int *n) {
    if (*n >= CONTATTI) return;
    scanf("%29s", rubrica[*n].nome);
    scanf("%29s", rubrica[*n].cognome);
    scanf("%14s", rubrica[*n].telefono);
    (*n)++;
}

void mostraContatti(struct Contatto rubrica[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d) %s %s - %s\n", i+1,
               rubrica[i].nome,
               rubrica[i].cognome,
               rubrica[i].telefono);
    }
}

void cercaContatto(struct Contatto rubrica[], int n) {
    char cerca[30];
    int trovato = 0;
    scanf("%29s", cerca);
    for (int i = 0; i < n; i++) {
        if (strcmp(rubrica[i].cognome, cerca) == 0) {
            printf("%s %s - %s\n",
                   rubrica[i].nome,
                   rubrica[i].cognome,
                   rubrica[i].telefono);
            trovato = 1;
        }
    }
    if (!trovato) printf("Non trovato\n");
}

void eliminaContatto(struct Contatto rubrica[], int *n) {
    char elimina[30];
    int pos = -1;
    scanf("%29s", elimina);
    for (int i = 0; i < *n; i++) {
        if (strcmp(rubrica[i].cognome, elimina) == 0) {
            pos = i;
            break;
        }
    }
    if (pos != -1) {
        for (int i = pos; i < *n - 1; i++) {
            rubrica[i] = rubrica[i+1];
        }
        (*n)--;
    }
}
