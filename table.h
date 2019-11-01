#ifndef table
#define table
#define M 16
#include <string>
#include <map>

    typedef int Key;

    class Hashnode{
        private:
            Key objectId;
            double price;
        public:
            //Getter
            double getPrice();
            Key getIndice();

            //Setter
            void setPrix(double newPrice);
            void setIndice(Key newIndice);

            //Constructors
            Hashnode(Key objectId, double price);
            Hashnode();

            //Display infos
            void displayInformations();

            bool operator==(const Hashnode& secondHashnode);
    };

    class HashTable{
        private:
            Hashnode tableHashage [M]; //Key -> IdProduct+firstIndex+arrivedNumber
            std::map<int,std::map<int,bool> > mapCount;
            int currentIndex;
            int firstIndex;
            int typeHashage;
            void (*hash)(Hashnode);

        public:
            //Constructeur
            HashTable();
            //Destructeur
            ~HashTable();

            //Ajout d'une donnée
            void addingElement(Hashnode newCellToAdd);
            int getProductIdLastUsedSlot(int productId);
            void quadraticHash(Hashnode newCellToAdd);
            void linearHash(Hashnode newCellToAdd);

            //Mise à jour des données
            void update(Key key, double newPrice);

            //Vérification si l'objet est présent dans la table
            int checkIfIndexIsAdded(Key index);
            int fetchIndex(Key key);
            Hashnode* research(Key productId, double price);
            void deleteProduct (Key productId, double price);

            //Only for test!
            void displayInformation(Key index);
            void displayHashtable();

            int getStockenProductKey(Key stockeProductKey);

            void removeElement(Key key);
    };

    /*class ProductId{
        private:
            int productId;
            int lastSlotUsed;

        public:
            int getLastSlotUsed();
            void addNewElement();
            void removeElement();

            ProductId(int productId);
    };*/

#endif