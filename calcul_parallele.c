#include <stdio.h>
#include <stdint.h>
#include <time.h>
#include <pthread.h>
#include <unistd.h>

#define TAILLE_DONNEES 10
#define MULTIPLICATEUR 1000

static const int DONNEES[TAILLE_DONNEES] = {1,2,3,4,5,6,7,8,9,10};

typedef struct {
    int valeur;
    int64_t resultat;
} args_t;

void* calcul_thread(void* arg) {
    args_t* args = (args_t*)arg;
    int64_t res = 0;

    for (int j = 0; j < MULTIPLICATEUR; j++) {
    res += args->valeur * args->valeur + args->valeur;
    usleep(20);
 }

    args->resultat = res;
    printf("Traitement de %d terminé : %ld\n", args->valeur, res);
    return NULL;
}

int main(void) {
     printf("=== Calcul Parallèle ===\n");

    struct timespec debut, fin;
     clock_gettime(CLOCK_MONOTONIC, &debut);

     pthread_t threads[TAILLE_DONNEES];
     args_t args[TAILLE_DONNEES];

    for (int i = 0; i < TAILLE_DONNEES; i++) {
       args[i].valeur = DONNEES[i];
       pthread_create(&threads[i], NULL, calcul_thread, &args[i]);
 }

     int64_t somme_total = 0;
     for (int i = 0; i < TAILLE_DONNEES; i++) {
        pthread_join(threads[i], NULL);
        somme_total += args[i].resultat;
 }
     clock_gettime(CLOCK_MONOTONIC, &fin);
     long duree = (fin.tv_sec - debut.tv_sec) * 1000 +
    (fin.tv_nsec - debut.tv_nsec) / 1000000;

    printf("Résultat total : %ld\n", somme_total);
    printf("Durée : %ld ms\n", duree);

    return 0;
}