#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct
{
    int jour, mois, year;
} deadline;

typedef struct
{
    int id;
    char titre[20];
    char descp[255];
    char status[11];
    deadline dline;
} tache;

tache tch[100];
int Id = 0;
int dm = 0;

void AjouterTache(tache tch[])
{
    int chx;
    tch[dm].id = Id + 1;
    printf("\t\ttitre : ");
    scanf(" %[^\n]", tch[dm].titre);
    printf("\t\tdescription : ");
    scanf(" %[^\n]", tch[dm].descp);
    do
    {
        printf("\t\tStatus du tache :\n \t1- A realiser | 2- En cours | 3- Finalisee  : ");
        scanf("%d", &chx);
    } while (chx <= 0 || chx >= 4);
    switch (chx)
    {
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
    do
    {
        printf("\t\tsaisir le deadline (jour-mois-annee) :");
        scanf("%d-%d-%d", &tch[dm].dline.jour, &tch[dm].dline.mois, &tch[dm].dline.year);
        printf("\n");
    } while (tch[dm].dline.jour <= 0 || tch[dm].dline.jour >= 32 || tch[dm].dline.mois <= 0 || tch[dm].dline.mois >= 13 || tch[dm].dline.year <= 0);
    dm++;
    Id++;
}

void AjouterPlusTache(tache tch[])
{
    int nbr, plus;
    printf("\t\tcombien vous voulez ajouter :");
    scanf("%d", &nbr);
    printf("\n");
    plus = nbr + dm;
    for (int i = dm; i < plus; i++)
    {
        AjouterTache(tch);
    }
}

void AfficherTache(tache tch[])
{
    printf("****** Affichages les Taches ******\n\n");
    for (int i = 0; i < dm; i++)
    {
        printf("\t\t Id : %d \n", tch[i].id);
        printf("\t\t Tache : %s \n", tch[i].titre);
        printf("\t\t description : %s \n", tch[i].descp);
        printf("\t\t DeadLine : %d - %d - %d\n\n", tch[i].dline.jour, tch[i].dline.mois, tch[i].dline.year);
    }
    printf("*******************************************************\n\n");
}

void triAlphab()
{
    tache h[100], tmp;
    for (int i = 0; i < dm; i++)
    {
        h[i] = tch[i];
    }
    for (int i = 0; i < dm - 1; i++)
    {
        for (int j = i + 1; j < dm; j++)
        {
            if (strcmp(h[i].titre, h[j].titre) > 0)
            {
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

time_t dateToSeconds(deadline d)
{
   
    time_t result;
    struct tm time_info = {0};

    time_info.tm_year = d.year - 1900; 
    time_info.tm_mon = d.mois - 1;     
    time_info.tm_mday = d.jour;        

    result = mktime(&time_info);
    return result;
}
void triDeadline()
{
    tache h[100], tmp;
    for (int i = 0; i < dm; i++)
    {
        h[i] = tch[i];
    }
    for (int i = 0; i < dm - 1; i++)
    {
        for (int j = i + 1; j < dm; j++)
        {
            if (difftime(dateToSeconds(h[i].dline),dateToSeconds(h[i+1].dline))>0)
            {
                tmp = h[i];
                h[i] = h[j];
                h[j] = tmp;
            }
        }
    }
    printf("******* Les taches triees DeadLiine ********* \n\n");
    AfficherTache(h);
    printf("*******************************************************\n\n");
}
int 
void supprimTache(tache tch[])
{
    int d;
    printf("\t\t Entrer ID de la tache a supprimer : ");
    scanf("%d", &d);
    if (d <= 0 || d > dm)
    {
        printf("\t\t Tache non trouve.\n");
        return;
    }
    for (int i = d - 1; i < dm - 1; i++)
    {
        tch[i] = tch[i + 1];
    }
    dm--;
    printf("\t\t Tache supprimer avec succes .\n");
}
void ModifieTache(tache tch[])
{
    int d, chx, indx;
    printf("\t\t Entrer ID de la tache a Modifier : ");
    scanf("%d", &d);
    if (d <= 0 || d > dm)
    {
        printf("\t\t Tache non trouve.\n");
        return;
    }
    indx = d - 1;
    printf("\t\tNouvelle description : ");
    scanf(" %[^\n]", tch[indx].descp);
    do
    {
        printf("\t\t nouveau Status du tache :\n \t1- A realiser | 2- En cours | 3- Finalisee  : ");
        scanf("%d", &chx);
    } while (chx <= 0 || chx >= 4);
    switch (chx)
    {
    case 1:
        strcpy(tch[indx].status, "A realiser");
        break;
    case 2:
        strcpy(tch[indx].status, "En cours");
        break;
    case 3:
        strcpy(tch[indx].status, "Finalisee");
        break;
    default:
        printf("valeur invalide.\n");
    }
    do
    {
        printf("\t\tsaisir nouveau deadline (jour-mois-annee) :");
        scanf("%d-%d-%d", &tch[indx].dline.jour, &tch[indx].dline.mois, &tch[indx].dline.year);
        printf("\n");
    } while (tch[indx].dline.jour <= 0 || tch[indx].dline.jour >= 32 || tch[indx].dline.mois <= 0 || tch[indx].dline.mois >= 13 || tch[indx].dline.year <= 0);
    printf("\t\t Tache modifie avec succes .\n");
}
void statistique(tache tch[])
{
}
int main()
{
    int choix;
    do
    {
        printf("\n\n******* Menu principal *******\n");
        printf("\t1. Ajouter une tache.\n");
        printf("\t2. Ajouter plusieurs taches.\n");
        printf("\t3. Afficher les taches.\n");
        printf("\t4. Trier les taches par ordre alphabetique.\n");
        printf("\t5. Trier les taches par ordre Deadline.\n");
        printf("\t6. Supprimer une Tache.\n");
        printf("\t7. Modifier une Tache.\n");
        printf("\t0. Quitter.\n");
        printf("*******************************************************\n\n");
        printf("Choisissez une option : ");
        scanf("%d", &choix);
        printf("\n");

        switch (choix)
        {
        case 1:
            system("cls");
            AjouterTache(tch);
            break;
        case 2:
            system("cls");
            AjouterPlusTache(tch);
            break;
        case 3:
            system("cls");
            AfficherTache(tch);
            break;
        case 4:
            system("cls");
            triAlphab();
            break;
        case 5:
            system("cls");
            triDeadline();     
        case 6:
            system("cls");
            supprimTache(tch);
            break;
        case 7:
            system("cls");
            ModifieTache(tch);
        case 0:
            printf("Au revoir !\n");
            break;
        default:
            printf("Option invalide.\n");
        }
    } while (choix != 0);

    return 0;
}
