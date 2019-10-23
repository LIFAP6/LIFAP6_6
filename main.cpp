// LIFAP6 - Automne 2017 - R. Chaine

#include <cstdio>
using namespace std;

//Table de hashage / Contenu de la cellule
#include "table.h"

int main()
{
    int tableSize = 0;
    char* userName;
    HashTable hashtable = HashTable();
    Hashnode newHashnode = Hashnode(3,4654.0);
    Hashnode newHashnode2 = Hashnode(4,45646.0);
    hashtable.addingElement(newHashnode);
    hashtable.addingElement(newHashnode2);
    hashtable.update(455,465464654);

    //Valid data
    hashtable.displayHashtable();

    printf("TP 6 - LIFAP6 - Hashtables\n");
    printf("Veuillez choisir une fonction pour l'ajout, la suppression et la modification des éléments du tableau\n");
    printf("Veuillez entrer une taille pour votre tableau : ");
    scanf("%d",&tableSize);
    printf("\nVeuillez entrer votre nom :");
    scanf("%s",&userName);

    printf("%s>",userName);
    return 0;
}
