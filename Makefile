# LIFAP6 - Automne 2017 - R. Chaine

main.ex : main.o
# L'executable main.ex doit être remis à jour si certains des fichiers 
# main.o liste.o et element.o sont plus rêcents
	g++ main.o

main_rec.ex : main.o
# L'executable main_rec.ex doit être remis à jour si certains des fichiers 
# main.o liste_rec.o et element.o sont plus rêcents
	g++ main.o

main.o : main.cpp
# Le fichier objet main.o doit être remis à jour si certains des fichiers
# main.cpp liste.h et element.h sont plus rêcents
	g++ -Wall -ansi -pedantic -c main.cpp

clean :
	-rm *.o *~

veryclean : clean 
	-rm *.ex

delete : veryclean
	- rm *.out