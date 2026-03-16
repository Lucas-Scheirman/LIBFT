*Ce projet a été créé dans le cadre du cursus 42 par lscheirm.*

# Libft

## Description

Libft est une bibliothèque écrite en C, créée dans le cadre du cursus 42.
L'objectif est de recoder soi-même des fonctions de la bibliothèque standard C, ainsi que des fonctions utilitaires supplémentaires.
Cette bibliothèque sera réutilisée dans les projets suivants du cursus.

## Instructions

Compiler la bibliothèque :

    make

Utiliser la bibliothèque dans un projet :

    cc votre_fichier.c -L. -lft -o votre_programme

Autres commandes :

    make clean   supprime les fichiers objets
    make fclean  supprime les fichiers objets et libft.a
    make re      recompile tout depuis zéro

## Description de la bibliothèque

Partie 1 — Fonctions de la libc (réimplémentations de fonctions standard du C)

    ft_isalpha   vérifie si un caractère est une lettre
    ft_isdigit   vérifie si un caractère est un chiffre
    ft_isalnum   vérifie si un caractère est une lettre ou un chiffre
    ft_isascii   vérifie si un caractère est dans la table ASCII
    ft_isprint   vérifie si un caractère est imprimable
    ft_strlen    retourne la longueur d'une chaîne
    ft_memset    remplit une zone mémoire avec un octet
    ft_bzero     met une zone mémoire à zéro
    ft_memcpy    copie une zone mémoire
    ft_memmove   copie une zone mémoire en gérant les chevauchements
    ft_strlcpy   copie une chaîne avec une limite de taille
    ft_strlcat   concatène deux chaînes avec une limite de taille
    ft_toupper   convertit un caractère en majuscule
    ft_tolower   convertit un caractère en minuscule
    ft_strchr    trouve la première occurrence d'un caractère dans une chaîne
    ft_strrchr   trouve la dernière occurrence d'un caractère dans une chaîne
    ft_strncmp   compare deux chaînes sur n caractères
    ft_memchr    recherche un octet dans une zone mémoire
    ft_memcmp    compare deux zones mémoire
    ft_strnstr   trouve une sous-chaîne dans une chaîne, limité à n caractères
    ft_atoi      convertit une chaîne de caractères en entier
    ft_calloc    alloue une zone mémoire initialisée à zéro
    ft_strdup    duplique une chaîne en allouant la mémoire nécessaire

Partie 2 — Fonctions supplémentaires (absentes de la libc ou sous forme différente)

    ft_substr      extrait une sous-chaîne d'une chaîne
    ft_strjoin     concatène deux chaînes en une nouvelle chaîne
    ft_strtrim     supprime des caractères en début et fin de chaîne
    ft_split       découpe une chaîne selon un délimiteur, retourne un tableau
    ft_itoa        convertit un entier en chaîne de caractères
    ft_strmapi     applique une fonction à chaque caractère, retourne une nouvelle chaîne
    ft_striteri    applique une fonction à chaque caractère d'une chaîne en place
    ft_putchar_fd  affiche un caractère sur un descripteur de fichier
    ft_putstr_fd   affiche une chaîne sur un descripteur de fichier
    ft_putendl_fd  affiche une chaîne suivie d'un saut de ligne sur un descripteur de fichier
    ft_putnbr_fd   affiche un entier sur un descripteur de fichier

Partie 3 — Listes chaînées (manipulation de listes avec la structure t_list)

    ft_lstnew        crée un nouveau nœud
    ft_lstadd_front  ajoute un nœud au début de la liste
    ft_lstsize       retourne le nombre de nœuds dans la liste
    ft_lstlast       retourne le dernier nœud de la liste
    ft_lstadd_back   ajoute un nœud à la fin de la liste
    ft_lstdelone     libère le contenu et le nœud lui-même
    ft_lstclear      libère tous les nœuds de la liste
    ft_lstiter       applique une fonction au contenu de chaque nœud
    ft_lstmap        crée une nouvelle liste en appliquant une fonction à chaque nœud

## Ressources

Pages man C : https://man7.org/linux/man-pages/
Norminette 42 : https://github.com/42School/norminette
AddressSanitizer : https://clang.llvm.org/docs/AddressSanitizer.html
Guide Markdown : https://www.markdownguide.org

## Utilisation de l'IA

L'IA (Claude) a été utilisée uniquement après avoir écrit le code de façon indépendante, pour relire la logique des fonctions, analyser les erreurs ASan et clarifier des concepts.
L'IA n'a pas été utilisée pour écrire les fonctions à ma place.
