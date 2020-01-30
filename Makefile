CFLAGS = -g -O2 -ansi -Wall -Werror `pkg-config --cflags MLV`
LDLIBS = `pkg-config --libs MLV`

pvc: ville.o graphique.o  visite.o fichier.o algorithmique.o  test.o main.o  
	gcc  -o pvc ville.o graphique.o visite.o fichier.o algorithmique.o test.o main.o  $(CFLAGS) $(LDLIBS)
ville.o: ville.c ville.h
	gcc -c ville.c $(CFLAGS)
visite.o: visite.c visite.h ville.h
	gcc -c visite.c $(CFLAGS) 
graphique.o: graphique.c graphique.h ville.h visite.h
	gcc -c graphique.c $(CFLAGS) $(LDLIBS)
fichier.o: fichier.c fichier.h visite.h ville.h
	gcc -c fichier.c $(CFLAGS)
algorithmique.o: algorithmique.c algorithmique.h visite.h
	gcc -c algorithmique.c $(CFLAGS)
test.o :test.c test.h ville.h graphique.h visite.h fichier.h algorithmique.h
	gcc -c test.c $(CFLAGS)	
main.o: main.c visite.h ville.h graphique.h fichier.h algorithmique.h test.h
	gcc -c main.c $(CFLAGS)$(LDLIBS)

clean :
	rm -rf *.o

mrproper: clean
	rm -rf pvc