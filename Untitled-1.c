#include <stdio.h>
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

// Nombre maximum d'apprenants
#define MAX_APPRENANTS 10

// Tableau d'apprenants fixe
Apprenant apprenants[MAX_APPRENANTS];
int compteur = 0; // Compteur d'apprenant actuel

// Fonction pour créer un apprenant
void creerApprenant() {
    if (compteur >= MAX_APPRENANTS) {
        printf("Capacité maximale atteinte pour les apprenants.\n");
        return;
    }
    
    printf("Entrez le nom de l'apprenant: ");
    fgets(apprenants[compteur].nom, sizeof(apprenants[compteur].nom), stdin);
    apprenants[compteur].nom[strcspn(apprenants[compteur].nom, "\n")] = '\0'; 
    printf("Entrez le prénom de l'apprenant: ");
    fgets(apprenants[compteur].prenom, sizeof(apprenants[compteur].prenom), stdin);
    apprenants[compteur].prenom[strcspn(apprenants[compteur].prenom, "\n")] = '\0';

    printf("Entrez l'âge de l'apprenant: ");
    scanf("%d", &apprenants[compteur].age);
    getchar(); 

    printf("Entrez la note de l'apprenant: ");
    scanf("%f", &apprenants[compteur].note);
    getchar(); 

    printf("Entrez la rue de l'adresse: ");
    fgets(apprenants[compteur].adresse.rue, sizeof(apprenants[compteur].adresse.rue), stdin);
    apprenants[compteur].adresse.rue[strcspn(apprenants[compteur].adresse.rue, "\n")] = '\0';

    printf("Entrez la ville de l'adresse: ");
    fgets(apprenants[compteur].adresse.ville, sizeof(apprenants[compteur].adresse.ville), stdin);
    apprenants[compteur].adresse.ville[strcspn(apprenants[compteur].adresse.ville, "\n")] = '\0';

    printf("Entrez le code postal de l'adresse: ");
    fgets(apprenants[compteur].adresse.codePostal, sizeof(apprenants[compteur].adresse.codePostal), stdin);
    apprenants[compteur].adresse.codePostal[strcspn(apprenants[compteur].adresse.codePostal, "\n")] = '\0';

    compteur++; 
}

// Fonction pour afficher les informations d'un apprenant
void afficherApprenant(int index) {
    printf("\nNom: %s\n", apprenants[index].nom);
    printf("Prénom: %s\n", apprenants[index].prenom);
    printf("Âge: %d\n", apprenants[index].age);
    printf("Note: %.2f\n", apprenants[index].note);
    printf("Adresse: %s, %s, %s\n\n", apprenants[index].adresse.rue, apprenants[index].adresse.ville, apprenants[index].adresse.codePostal);
}

// Fonction pour afficher tous les apprenants
void afficherTousLesApprenants() {
    if (compteur == 0) {
        printf("Aucun apprenant à afficher.\n");
        return;
    }

    for (int i = 0; i < compteur; i++) {
        afficherApprenant(i);
    }
}

// Fonction pour mettre à jour un apprenant
void mettreAJourApprenant() {
    if (compteur == 0) {
        printf("Aucun apprenant à mettre à jour.\n");
        return;
    }

    int index;
    printf("Entrez l'indice de l'apprenant à mettre à jour (0 à %d): ", compteur - 1);
    scanf("%d", &index);
    getchar(); // Consomme le '\n' restant

    if (index >= 0 && index < compteur) {
        printf("Entrez le nouveau nom: ");
        fgets(apprenants[index].nom, sizeof(apprenants[index].nom), stdin);
        apprenants[index].nom[strcspn(apprenants[index].nom, "\n")] = '\0';

        printf("Entrez le nouveau prénom: ");
        fgets(apprenants[index].prenom, sizeof(apprenants[index].prenom), stdin);
        apprenants[index].prenom[strcspn(apprenants[index].prenom, "\n")] = '\0';

        printf("Entrez le nouvel âge: ");
        scanf("%d", &apprenants[index].age);
        getchar();

        printf("Entrez la nouvelle note: ");
        scanf("%f", &apprenants[index].note);
        getchar();

        printf("Entrez la nouvelle rue: ");
        fgets(apprenants[index].adresse.rue, sizeof(apprenants[index].adresse.rue), stdin);
        apprenants[index].adresse.rue[strcspn(apprenants[index].adresse.rue, "\n")] = '\0';

        printf("Entrez la nouvelle ville: ");
        fgets(apprenants[index].adresse.ville, sizeof(apprenants[index].adresse.ville), stdin);
        apprenants[index].adresse.ville[strcspn(apprenants[index].adresse.ville, "\n")] = '\0';

        printf("Entrez le nouveau code postal: ");
        fgets(apprenants[index].adresse.codePostal, sizeof(apprenants[index].adresse.codePostal), stdin);
        apprenants[index].adresse.codePostal[strcspn(apprenants[index].adresse.codePostal, "\n")] = '\0';
    } else {
        printf("Index invalide.\n");
    }
}

// Fonction pour supprimer un apprenant
void supprimerApprenant() {
    if (compteur == 0) {
        printf("Aucun apprenant à supprimer.\n");
        return;
    }

    int index;
    printf("Entrez l'indice de l'apprenant à supprimer (0 à %d): ", compteur - 1);
    scanf("%d", &index);
    getchar(); 

    if (index >= 0 && index < compteur) {
        apprenants[index].nom[0] = '\0';  // Vide le nom pour marquer comme supprimé
        printf("Apprenant supprimé.\n");

        // Déplace les apprenants restants pour combler le vide
        for (int i = index; i < compteur - 1; i++) {
            apprenants[i] = apprenants[i + 1];
        }
        compteur--;  
    } else {
        printf("Index invalide.\n");
    }
}

// Menu principal
int main() {
    int choix;

    while (1) {
        // Affichage du menu
        printf("\n1. Créer un apprenant\n");
        printf("2. Afficher les apprenants\n");
        printf("3. Mettre à jour un apprenant\n");
        printf("4. Supprimer un apprenant\n");
        printf("5. Quitter\n");
        printf("Votre choix: ");
        scanf("%d", &choix);
        getchar(); 

        switch (choix) {
            case 1:
                creerApprenant();
                break;

            case 2:
                afficherTousLesApprenants();
                break;

            case 3:
                mettreAJourApprenant();
                break;

            case 4:
                supprimerApprenant();
                break;

            case 5:
                printf("Au revoir!\n");
                return 0;

            default:
                printf("Choix invalide. Essayez encore.\n");
        }
    }

    return 0;
}
