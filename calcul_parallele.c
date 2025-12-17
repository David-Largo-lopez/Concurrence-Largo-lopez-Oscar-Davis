#include <pthread.h>


int main(void) {
    printf("=== Calcul Parallèle ===\n");

    struct timespec debut, fin;
    clock_gettime(CLOCK_MONOTONIC, &debut);

    // TODO: Créer un tableau de pthread_t
    pthread_t thread[TAILLE_DONNEES] = {1,2,3,4,5,6,7,8,9,10};
    // TODO: Créer un tableau de structures d'arguments
    struct arg {
        int valeur;
        int64_t resultat;
    } args[TAILLE_DONNEES];
    // TODO: Créer et démarrer tous les threads
        // TODO : Créer tous les threads
    for (int i = 0; i < TAILLE_DONNEES; i++) {
        args[i].valeur = DONNEES[i];
        pthread_create(&thread[i], NULL, traitement_thread, &args[i]);
    }
    // TODO: Attendre tous les threads
    // TODO: Agréger les résultats

    clock_gettime(CLOCK_MONOTONIC, &fin);
    long duree = (fin.tv_sec - debut.tv_sec) * 1000 + (fin.tv_nsec - debut.tv_nsec) / 1000000;

    printf("Résultat total : %ld\n", somme_total);
    printf("Durée : %ld ms\n", duree);

    return 0;
}