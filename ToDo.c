#include <stdio.h>
#include <string.h>
#include <time.h>

typedef struct  {
    int jour, mois, year;
} deadline;

typedef struct  {
    int id;
    char titre[20];
    char descp[255];
    char status[11];
    deadline dline;
} tache;

tache tch[100];
int Id = 0;
int dm = 0;

void AjouterTache(tache tch[]) {
    int chx;
    tch[dm].id = Id + 1;
    printf("\t\ttitre : ");
    scanf(" %[^\n]", tch[dm].titre); 
    printf("\t\tdescription : ");
    scanf(" %[^\n]", tch[dm].descp);
    do {
        printf("\t\tStatus du tache :\n \t1- A realiser | 2- En cours | 3- Finalisee  : ");
        scanf("%d", &chx);
    } while (chx <= 0 || chx >= 4);
    switch (chx) {
        case 1:
            strcpy(tch[dm].status, "A realiser");
            break;
        case 2:
            strcpy(tch[dm].status, "En cours");
            break;
        case 3:
            strcpy(tch[dm].status, "Finalisee");
            break;
        default:
            printf("valeur invalide.\n");
    }
    do {
        printf("\t\tsaisir le deadline (jour/mois/annee) :");
        scanf("%d/%d/%d", &tch[dm].dline.jour, &tch[dm].dline.mois, &tch[dm].dline.year);
        printf("\n");
    } while (tch[dm].dline.jour <= 0 || tch[dm].dline.jour >= 32 || tch[dm].dline.mois <= 0 || tch[dm].dline.mois >= 13 || tch[dm].dline.year <= 0);
    dm++;
    Id++;
}

void AjouterPlusTache(tache tch[]) {
    int nbr, plus;
    printf("\t\tcombien vous voulez ajouter :");
    scanf("%d", &nbr);
    printf("\n");
    plus = nbr + dm;
    for (int i = dm; i < plus; i++) {
        AjouterTache(tch);
    }
}

void AfficherTache(tache tch[]){
    printf("****** Affichages les Taches ******\n\n");
    for (int i = 0; i < dm; i++) {
        printf("\t\t Id : %d \n",tch[i].id);
        printf("\t\t Tache : %s \n",tch[i].titre);
        printf("\t\t description : %s \n",tch[i].descp);
        printf("\t\t DeadLine : %d - %d - %d\n\n",tch[i].dline.jour,tch[i].dline.mois,tch[i].dline.year);
        
    }
    printf("*******************************************************\n\n");
}

void triAlphab() {
    tache h[100], tmp;
    for (int i = 0; i < dm; i++) {
        h[i] = tch[i];
    }
for (int i = 0; i < dm - 1; i++) {
        for (int j = i + 1; j < dm; j++) {
            if (strcmp(h[i].titre, h[j].titre) > 0) {
                tmp = h[i];
                h[i] = h[j];
                h[j] = tmp;
            }
        }
    }
    printf("******* Les taches triees alphabitique ********* \n\n");
    AfficherTache(h);
    printf("*******************************************************\n\n");
}
int main() {
    int choix;
    do {
        printf("\n\n******* Menu principal *******\n");
        printf("\t1. Ajouter une tache\n");
        printf("\t2. Ajouter plusieurs taches\n");
        printf("\t3. Afficher les taches\n");
        printf("\t4. Trier les taches par ordre alphabetique\n");
        printf("\t0. Quitter\n");
        printf("*******************************************************\n\n");
        printf("Choisissez une option : ");
        scanf("%d", &choix);
        printf("\n");

        switch (choix) {
            case 1:
                AjouterTache(tch);
                break;
            case 2:
                AjouterPlusTache(tch);
                break;
            case 3:
                AfficherTache(tch);
                break;
            case 4:
                triAlphab();
                break;
            case 0:
                printf("Au revoir !\n");
                break;
            default:
                printf("Option invalide.\n");
        }
    } while (choix != 0);

    return 0;
}
