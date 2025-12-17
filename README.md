Questions d’analyse (5 pts)

Après implémentation, répondez à ces questions :

    Performance : Quelle version est la plus rapide ? Pourquoi ?
    La version parallele est plus rapide parce que les calculs sont independant.

    Mesurez : Différentes valeurs pour MULTIPLICATEUR, jusqu’a à 10000000 et observez la différence
    Résultats : Les résultats sont-ils identiques entre les versions ? Les Resultats sont identiques 
    Pourquoi n’y a-t-il pas de race condition ?
    chaques sthread ecrit dans sa propre structure
    
    Vous pouvez écrire les résultats dans un fichiers au format csv (simple)
    Scalabilité : Testez avec différents nombres de threads.
    Combien de coeur a votre machine virtuel ? vous pouvez regarder dans /proc/cpuinfo
    16

    Que se passe-t-il si vous créez 100 threads pour 10 valeurs ?
    Proposé un graphique telque visible ci-dessous (bonus)
