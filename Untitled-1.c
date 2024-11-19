#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Définition de la structure Adresse
typedef struct {
    char rue[100];
    char ville[50];
    char codePostal[20];
} Adresse;

// Définition de la structure Apprenant
typedef struct {
    char nom[50];
    char prenom[50];
    int age;
    float note;
    Adresse adresse;
} Apprenant;

// Fonction pour créer un apprenant
void creerApprenant(Apprenant* apprenant) {
    printf("Entrez le nom de l'apprenant: ");
    fgets(apprenant->nom, sizeof(apprenant->nom), stdin);
    apprenant->nom[strcspn(apprenant->nom, "\n")] = '\0';  // Suppression du \n à la fin

    printf("Entrez le prénom de l'apprenant: ");
    fgets(apprenant->prenom, sizeof(apprenant->prenom), stdin);
    apprenant->prenom[strcspn(apprenant->prenom, "\n")] = '\0';

    printf("Entrez l'âge de l'apprenant: ");
    scanf("%d", &apprenant->age);
    getchar(); // Pour consommer le '\n' restant

    printf("Entrez la note de l'apprenant: ");
    scanf("%f", &apprenant->note);
    getchar();

    printf("Entrez la rue de l'adresse: ");
    fgets(apprenant->adresse.rue, sizeof(apprenant->adresse.rue), stdin);
    apprenant->adresse.rue[strcspn(apprenant->adresse.rue, "\n")] = '\0';

    printf("Entrez la ville de l'adresse: ");
    fgets(apprenant->adresse.ville, sizeof(apprenant->adresse.ville), stdin);
    apprenant->adresse.ville[strcspn(apprenant->adresse.ville, "\n")] = '\0';

    printf("Entrez le code postal de l'adresse: ");
    fgets(apprenant->adresse.codePostal, sizeof(apprenant->adresse.codePostal), stdin);
    apprenant->adresse.codePostal[strcspn(apprenant->adresse.codePostal, "\n")] = '\0';
}

// Fonction pour afficher les informations d'un apprenant
void afficherApprenant(Apprenant apprenant) {
    printf("\nNom: %s\n", apprenant.nom);
    printf("Prénom: %s\n", apprenant.prenom);
    printf("Âge: %d\n", apprenant.age);
    printf("Note: %.2f\n", apprenant.note);
    printf("Adresse: %s, %s, %s\n\n", apprenant.adresse.rue, apprenant.adresse.ville, apprenant.adresse.codePostal);
}

// Fonction pour mettre à jour un apprenant
void mettreAJourApprenant(Apprenant* apprenant) {
    printf("Entrez les nouvelles informations pour l'apprenant %s %s:\n", apprenant->nom, apprenant->prenom);
    printf("Entrez le nouveau nom: ");
    fgets(apprenant->nom, sizeof(apprenant->nom), stdin);
    apprenant->nom[strcspn(apprenant->nom, "\n")] = '\0';

    printf("Entrez le nouveau prénom: ");
    fgets(apprenant->prenom, sizeof(apprenant->prenom), stdin);
    apprenant->prenom[strcspn(apprenant->prenom, "\n")] = '\0';

    printf("Entrez le nouvel âge: ");
    scanf("%d", &apprenant->age);
    getchar(); // Consomme le '\n' restant

    printf("Entrez la nouvelle note: ");
    scanf("%f", &apprenant->note);
    getchar();

    printf("Entrez la nouvelle rue: ");
    fgets(apprenant->adresse.rue, sizeof(apprenant->adresse.rue), stdin);
    apprenant->adresse.rue[strcspn(apprenant->adresse.rue, "\n")] = '\0';

    printf("Entrez la nouvelle ville: ");
    fgets(apprenant->adresse.ville, sizeof(apprenant->adresse.ville), stdin);
    apprenant->adresse.ville[strcspn(apprenant->adresse.ville, "\n")] = '\0';

    printf("Entrez le nouveau code postal: ");
    fgets(apprenant->adresse.codePostal, sizeof(apprenant->adresse.codePostal), stdin);
    apprenant->adresse.codePostal[strcspn(apprenant->adresse.codePostal, "\n")] = '\0';
}

// Fonction pour supprimer un apprenant (en le marquant comme supprimé dans la liste)
void supprimerApprenant(Apprenant* apprenant) {
    apprenant->nom[0] = '\0';  // Vide le nom, ce qui "supprime" l'apprenant
}

// Menu principal
int main() {
    int choix;
    int compteur = 0;
    Apprenant* apprenants = malloc(sizeof(Apprenant) * 10);  // Tableau dynamique pour 10 apprenants (pour commencer)

    while (1) {
        // Affichage du menu
        printf("\n1. Créer un apprenant\n");
        printf("2. Afficher les apprenants\n");
        printf("3. Mettre à jour un apprenant\n");
        printf("4. Supprimer un apprenant\n");
        printf("5. Quitter\n");
        printf("Votre choix: ");
        scanf("%d", &choix);
        getchar();  // Consomme le '\n' restant après la saisie du choix

        switch (choix) {
            case 1:
                if (compteur < 10) {
                    creerApprenant(&apprenants[compteur]);
                    compteur++;
                } else {
                    printf("Capacité maximale atteinte pour les apprenants.\n");
                }
                break;

            case 2:
                if (compteur == 0) {
                    printf("Aucun apprenant à afficher.\n");
                } else {
                    for (int i = 0; i < compteur; i++) {
                        afficherApprenant(apprenants[i]);
                    }
                }
                break;

            case 3:
                if (compteur == 0) {
                    printf("Aucun apprenant à mettre à jour.\n");
                } else {
                    int index;
                    printf("Entrez l'indice de l'apprenant à mettre à jour (0 à %d): ", compteur - 1);
                    scanf("%d", &index);
                    getchar(); // Consomme le '\n' restant
                    if (index >= 0 && index < compteur) {
                        mettreAJourApprenant(&apprenants[index]);
                    } else {
                        printf("Index invalide.\n");
                    }
                }
                break;

            case 4:
                if (compteur == 0) {
                    printf("Aucun apprenant à supprimer.\n");
                } else {
                    int index;
                    printf("Entrez l'indice de l'apprenant à supprimer (0 à %d): ", compteur - 1);
                    scanf("%d", &index);
                    getchar(); // Consomme le '\n' restant
                    if (index >= 0 && index < compteur) {
                        supprimerApprenant(&apprenants[index]);
                        printf("Apprenant supprimé.\n");
                    } else {
                        printf("Index invalide.\n");
                    }
                }
                break;

            case 5:
                free(apprenants);  // Libère la mémoire allouée pour les apprenants
                printf("Au revoir!\n");
                return 0;

            default:
                printf("Choix invalide. Essayez encore.\n");
        }
    }

    return 0;
}
