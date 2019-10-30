// LIFAP6 - Automne 2017 - R. Chaine

#include <cstdio>
#include <string>
using namespace std;
#define TAB_MAX_SIZE 100

//Table de hashage / Contenu de la cellule
#include "table.h"

int main()
{
    int tableSize = 0;
    string userName;
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
    while (tableSize != (int)tableSize || tableSize<= 0 || tableSize>TAB_MAX_SIZE)
    {
        //cout << "Vous devez entrer un entier compris entre 1 et " << TAB_MAX_SIZE;
        scanf("%d",&tableSize);
        /* code */
    }
    
    printf("\nVeuillez entrer votre nom :");
    //cin >> userName;
    return 0;
}
