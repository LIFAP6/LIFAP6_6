#ifndef table
#define table
#define M 16

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

            //Constructors
            Hashnode(Key objectId, double price);
            Hashnode();

            //Display infos
            void displayInformations();
    };

    class HashTable{
        private:
            Hashnode tableHashage [M]; //Key -> IdProduct+beginProductIndex+arriveNumber
            int currentIndex;
            int beginProductIndex;
        public:
            //Constructeur
            HashTable();
            //Destructeur
            ~HashTable();

            //Ajout d'une donnée
            void addingElement(Hashnode newCellToAdd);
            int generateHashKey(Hashnode elem, std::string hashkey);
            int getProductIdLastUsedSlot(int productId);

            //Mise à jour des données
            void update(Key key, double newPrice);

            //Vérification si l'objet est présent dans la table
            int checkIfIndexIsAdded(Key index);
            int fetchIndex(Key key);

            //Only for test!
            void displayInformation(Key index);
            void displayHashtable();
    };

#endif