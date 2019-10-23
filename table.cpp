#include "table.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdexcept>
#include <string>
//Table de hachage
HashTable::HashTable(){
    printf("Création d'une table de hashage vide avec une correspondant à %d!\n",M);
    currentIndex = 0;
}

void HashTable::addingElement(Hashnode newCellToAdd){
    if(checkIfIndexIsAdded(newCellToAdd.getIndice())==-1){
        tableHashage[currentIndex] = newCellToAdd;
        printf("Ajout de l'élément ayant pour clé %d à l'adresse suivante : %d\n",newCellToAdd.getIndice(),currentIndex);
        currentIndex++;
    }else{
        //Static table filled
        if(currentIndex==M){
            throw std::invalid_argument("Static table already filled");
        }else{

        }
    }
}

void HashTable::update(Key key, double newPrice){
    int productId = checkIfIndexIsAdded(key);
    if(productId != -1){
        tableHashage[productId].setPrix(newPrice);
    }else{
        printf("The key %d is invalid : missing from the hashtable!\n",key);
        //throw std::invalid_argument("The key"+key+" is not present in the hashtable!");
    }
}

int HashTable::checkIfIndexIsAdded(Key index){
    for(int i = 0;i<M;i++){
        if(tableHashage[i].getIndice() == index){
            return i;
        }
    }
    return -1;
}

void HashTable::displayInformation(Key productIndex){
    try{
        Hashnode currentProduct = tableHashage[fetchIndex(productIndex)];
        currentProduct.displayInformations();
    }catch(std::invalid_argument ia){
        printf("%s",ia.what());
    }
}

int HashTable::fetchIndex(Key key){
    for (int i = 0;i<M;i++){
        if(tableHashage[i].getIndice() == key){
            return i;
        }
    }
    throw std::invalid_argument("Unkown key : the product is missing from the table");
}

void HashTable::displayHashtable(){
    printf("Tableau de hashage, taille : %d, nombre d'element ajoutes : %d.\n",M,currentIndex);
    printf("-----------------Affichage des elements-----------------\n");
    for(int i = 0;i<currentIndex;i++){
        tableHashage[i].displayInformations();
    }
}

//Destructeur
HashTable::~HashTable(){
    printf("Suppression de la table de hashage disposant de %d objets!\n",currentIndex);
}

//Hashnode
/**
 *  Get the price of the product 
 */
double Hashnode::getPrice(){
    return price;
}
Key Hashnode::getIndice(){
    return objectId;
}
void Hashnode::setPrix(double newPrice){
    if(newPrice<0){
        throw std::invalid_argument("param entered is negative value!");
    }else{
        price = newPrice;
    }
}

void Hashnode::displayInformations(){
    printf("Code produit : %d Prix : %f\n",objectId,price);
}

//Constructor
Hashnode::Hashnode(Key newObjectId, double newPrice){
    objectId = newObjectId;
    price = newPrice;
}
Hashnode::Hashnode(){
    //Nothing here
}