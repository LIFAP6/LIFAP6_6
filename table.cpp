#include "table.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdexcept>
#include <string>
#include <map>
#include <algorithm>

#define DEFAULT_HASH_KEY "LIFAP6 - Table de Hashage"
//Table de hachage
HashTable::HashTable()
{
    printf("Création d'une table de hashage vide avec une correspondant à %d!\n", M);
    currentIndex = 0;
    typeHashage = 0;
}

void HashTable::addingElement(Hashnode newCellToAdd)
{
    if (checkIfIndexIsAdded(newCellToAdd.getIndice()) == -1)
    {
        tableHashage[currentIndex] = newCellToAdd;
        printf("Ajout de l'élément ayant pour clé %d à l'adresse suivante : %d\n", newCellToAdd.getIndice(), currentIndex);
        currentIndex++;
    }
    else
    {
        //Static table filled
        if (currentIndex == M)
        {
            throw "Static table already filled";
        }
        else
        {
            hash(newCellToAdd);
        }
    }
}

void HashTable::quadraticHash(Hashnode newCellToAdd)
{
    //pas quadratique
    std::string key;
    int index = -1;
    bool placeFound = false;
    for (int i = 0; i < currentIndex; i++)
    {
        if (mapCount.find(i) != mapCount.end())
        { //Au moins un élément avec l'indice i
            for (unsigned int j = 0; j < mapCount.size() && !placeFound; i++)
            {
                index = j;
                if (mapCount[i][j] == true)
                {
                    placeFound = true;
                }
            }
        }
        if (placeFound)
        {
            key = std::to_string(newCellToAdd.getIndice()) + std::to_string(index);
            mapCount[stoi(key)][index] = false;
            tableHashage[newCellToAdd.getIndice()] = newCellToAdd;
            return;
        }
    }
    key = std::to_string(newCellToAdd.getIndice()) + "0";
    newCellToAdd.setIndice(stoi(key));
    mapCount[newCellToAdd.getIndice()][0] = false;
    tableHashage[newCellToAdd.getIndice()] = newCellToAdd;
    return;
}

Hashnode *HashTable::research(Key productId, double price){
    Hashnode *element = std::find(std::begin(tableHashage), std::end(tableHashage), Hashnode(productId,price));
    if (element == nullptr)
    {
        throw "Element not found!";
    }
    else
    {
        return element;
    }
}

void HashTable::deleteProduct(Key productId, double price){
    try{
        Hashnode *element = research(productId, price);
        std::string index = std::to_string(std::distance(tableHashage, element));
        index = index.substr(index.find(std::to_string(productId)));
        mapCount[productId][stoi(index)] = true;
        element = nullptr;
    }
    catch (const std::exception & exception)
    {
        printf(exception.what());
    }
}

bool Hashnode::operator==(const Hashnode &secondOperator)
{
    if (secondOperator.objectId == objectId && secondOperator.price == price)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void HashTable::linearHash(Hashnode newCellToAdd)
{
    std::string key;
    int index = -1;
    bool placeFound = false;
    for (int i = 0; i < currentIndex; i++)
    {
        if (mapCount.find(i) != mapCount.end())
        { //Au moins un élément avec l'indice i
            for (unsigned int j = 0; j < mapCount.size() && !placeFound; i++)
            {
                index = j;
                if (mapCount[i][j] == true)
                {
                    placeFound = true;
                }
            }
        }
        if (placeFound)
        {
            key = std::to_string(newCellToAdd.getIndice()) + std::to_string(index);
            mapCount[stoi(key)][index] = false;
            tableHashage[newCellToAdd.getIndice()] = newCellToAdd;
            return;
        }
    }
    key = std::to_string(newCellToAdd.getIndice()) + "0";
    newCellToAdd.setIndice(stoi(key));
    mapCount[newCellToAdd.getIndice()][0] = false;
    tableHashage[newCellToAdd.getIndice()] = newCellToAdd;
    return;
}

void HashTable::update(Key key, double newPrice)
{
    int productId = checkIfIndexIsAdded(key);
    if (productId != -1)
    {
        tableHashage[productId].setPrix(newPrice);
    }
    else
    {
        throw "The key" + std::to_string(key) + " is not present in the hashtable!";
    }
}

int HashTable::getStockenProductKey(Key productKey)
{
    return productKey + firstIndex;
}

int HashTable::getProductIdLastUsedSlot(int productId)
{
    return 0;
}

int HashTable::checkIfIndexIsAdded(Key index)
{
    for (int i = 0; i < M; i++)
    {
        if (tableHashage[i].getIndice() == index)
        {
            return i;
        }
    }
    return -1;
}

void HashTable::displayInformation(Key productIndex)
{
    try
    {
        Hashnode currentProduct = tableHashage[fetchIndex(productIndex)];
        currentProduct.displayInformations();
    }
    catch (std::invalid_argument ia)
    {
        printf("%s", ia.what());
    }
}

int HashTable::fetchIndex(Key key)
{
    for (int i = 0; i < M; i++)
    {
        if (tableHashage[i].getIndice() == key)
        {
            return i;
        }
    }
    throw "Unkown key : the product is missing from the table";
}

void HashTable::displayHashtable()
{
    printf("Tableau de hashage, taille : %d, nombre d'element ajoutes : %d.\n", M, currentIndex);
    printf("-----------------Affichage des elements-----------------\n");
    for (int i = 0; i < currentIndex; i++)
    {
        tableHashage[i].displayInformations();
    }
}

void HashTable::removeElement(Key key)
{
    for (int i = 0; i < currentIndex; i++)
    {
        if (tableHashage[i].getIndice() == key)
        {
            for (int j = i; j < currentIndex; j++)
            {
                tableHashage[j] = tableHashage[j + 1];
            }
            currentIndex--;
            break;
        }
    }
}

//Destructeur
HashTable::~HashTable()
{
    printf("Suppression de la table de hashage disposant de %d objets!\n", currentIndex);
}

//Hashnode
/**
 *  Get the price of the product 
 */
double Hashnode::getPrice()
{
    return price;
}
Key Hashnode::getIndice()
{
    return objectId;
}
void Hashnode::setPrix(double newPrice)
{
    if (newPrice < 0)
    {
        throw "param entered is negative value!";
    }
    else
    {
        price = newPrice;
    }
}

void Hashnode::displayInformations()
{
    printf("Code produit : %d Prix : %f\n", objectId, price);
}

void Hashnode::setIndice(Key newIndice)
{
    objectId = newIndice;
}

//Constructor
Hashnode::Hashnode(Key newObjectId, double newPrice)
{
    objectId = newObjectId;
    price = newPrice;
}
Hashnode::Hashnode()
{
    //Nothing here
}