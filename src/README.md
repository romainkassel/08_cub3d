* TO DO LIST PARSING


- Parsing du fichier / de l'extension 
    --> Checker que le fichier existe (si argc != 2, return 1) > OK
    --> Checker que le fichier a la bonne extension .cub > OK 
    --> Checker que l'argument fourni ne correspond pas a un directory > OK 
    --> Checker que le fichier est "ouvrable" (= fichier existe et user a les permissions idoines) > OK 

- Parsing du fichier de config 
    --> Recuperer les texts > OK
    --> Verifier qu'il n'y a qu'un seul type de text (ex = pas deux fois NO) > OK 
    --> Recuperer les couleurs du floor et du ceiling et convertir en hexa --> TO DO 
        - Verifier qu'il n'y a aucun caractere different d'un chiffre, d'un espace ou d'une virgule > OK
        - Verifier qu'il y a trois chiffres > non mais je verifie les virgules et les espaces entre chiffres
        - A voir si c'est ok sur les caracteres de type white spaces
        - Verifier qu'il y a deux virgules > OK 
        - Verifier que le resultat final est bien compris entre 0 et 255 > OK 
        - Convertir et stocker le resultat en hexa > OK ; j'ai aussi conserve les valeurs RGB initiales dans un tableau de char * au cas ou, pour pouvoir ajuster la transparence 
    --> Verifier qu'on a pas une info qui n'a rien a voir avec les elements demandes > OK 
    --> Verifier qu'on a bien toutes les infos > OK
    --> Verifier que la map est bien en dernier > OK

    - Parsing de la map
    --> Verifier qu'on n'a que des caracteres autorises (partiellement OK)
    --> Flood fill ; technique de Taha > 
    Je fais tous les checks dabord
    Enfin je mets '9' partout dans mon tableau si le casier n'est pas '0' ou '1'
    mon tableau est un carre qui est cree en tenant compte de la ligne la plus longue
    du coup enfin il est compose de '0' '1' et '9'
    je lance le floodfill de chaque '0' jusquau '1' 
    s'il touche a un '9' ca veut dire que les '0's ne sont pas bien entourres par les '1's
    