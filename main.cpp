// LIFAP6 - Automne 2017 - R. Chaine

#include <cstdio>
using namespace std;

//Table de hashage / Contenu de la cellule
#include "table.h"

int main()
{
    HashTable hashtable = HashTable();
    Hashnode newHashnode = Hashnode(3,4654.0);
    Hashnode newHashnode2 = Hashnode(4,45646.0);
    hashtable.ajoutLineaire(newHashnode);
    hashtable.ajoutLineaire(newHashnode2);
    printf("Fonction de hashage\n");
    printf("Veuillez choisir la méthode :");
    hashtable.displayInformation(3);

    return 0;
}
