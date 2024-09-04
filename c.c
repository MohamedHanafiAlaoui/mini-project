# include <stdio.h>
#include <string.h>

void    ajouter(char titre[][100], char auteur[][100], float prix[], int quantite[], int count);
void    afficher(char titre[][100], char auteur[][100], float prix[], int quantite[], int count);
void    Rechercher (char titre[][100],char stre[],int count);
void    update(char titre[][100],char stre[], int quantite[10],int count);
void    Total(int quantite[10],int count);
void    Supprimer (char titre[][100], char auteur[][100], float prix[], int quantite[], char stre[],int count);
void  afich();

int main ()
{
    int c = 0;
    char titre[10][100];
    char auteur[10][100];
    float prix[10];
    int quantite[10];
    int choix;

  while(1){
        afich();
        printf("Entee votre choix: ");
        scanf("%d", &choix);
        switch (choix) {
            case 1:
                ajouter(titre, auteur, prix, quantite, c);
                c++;
                break;
            case 2:
                printf("Count: %d\n", c);
                afficher(titre, auteur, prix, quantite, c);
                break;
            case 3:
                char word[100];
                printf("Enter the titre: ");
                scanf("%s", word);
                update(titre, word, quantite, c);
                break;
            case 4:
                char mot[100];
                printf("Enter the titre to Supprimer: ");
                scanf("%s", mot);
                Supprimer(titre ,auteur, prix, quantite, mot, c);
                c--;
                break;
            case 5:
                Total(quantite, c);
                printf("%d",c);
                break;
            case 6:
                char wor[100];
                printf("Enter the titre: ");
                scanf("%s", wor);
                Rechercher(titre, wor, c);
                break;
            default:
                printf("Default!");
        }
    }
}

void afich()
{
    printf("===========================\n");
    printf("1=>ajouter\n");
    printf("2=>afficher\n");
    printf("3=>update\n");
    printf("4=>Supprimer\n");
    printf("5=>Total\n");
    printf("6=>Rechercher\n");
    printf("===========================\n");
}


void  ajouter(char titre[][100], char auteur[][100], float prix[], int quantite[], int count) 
{
    printf ("titre : ");
    scanf ("%s", &titre[count]);
    printf ("auteur : ");
    scanf ("%s", &auteur[count]);
    printf ("prix : ");
    scanf ("%f", &prix[count]);
    printf ("quantite : ");
    scanf ("%d", &quantite[count]);
}

void  afficher(char titre[][100], char auteur[][100], float prix[], int quantite[], int count) 
{
    for (int i = 0; i < count; i++)
    {
        printf ("\n==========%d==========\n",i+1);
        printf ("titre  : %s\t",titre[i]);
        printf ("auteur  : %s\t",auteur[i]);
        printf ("prix  : %.2f DH\t",prix[i]);
        printf ("quantite  : %d\n",quantite[i]);
    }
}

void Rechercher (char titre[][100],char stre[],int count)
{
    int r = 0;
    for (int i = 0; i < count; i++)
    {
        if (strcmp(titre[i] ,stre) == 0)
        {
             printf ("titre  : %s\n",titre[i] );
             r++;    
        }
    }
    if (r == 0)
    {
        printf("don");
    }
}

void update(char titre[][100],char stre[], int quantite[10],int count)
{
    int r;
    int n;
    for (int i = 0; i < count; i++)
    {
        if (strcmp(titre[i] ,stre) == 0)
        {
             printf ("titre  : %s",titre[i] );
             r = i;
        }
    }
    printf ("quantite : ");
    quantite[r] += scanf ("%d", &n);  
}

void Total(int quantite[10],int count)
{
    int s;

    s = 0;
    for (int i = 0; i < count; i++)
    {
          s +=quantite[i];
    }
    printf ("le Nombre Total de Livre est : %d\n",s);
}

void Supprimer (char titre[][100], char auteur[][100], float prix[], int quantite[], char stre[],int count)
{
    int i, j;
    for (i = 0; i < count; i++) {
        if (strcmp(titre[i], stre) == 0) {
            for (j = i; j < count - 1; j++) {
                strcpy(titre[j], titre[j + 1]);
                strcpy(auteur[j], auteur[j + 1]);
                prix[j] = prix[j + 1];
                quantite[j] = quantite[j + 1];
            }
            break;
        }
    }
}