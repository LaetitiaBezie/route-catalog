CPPFLAGS= -ansi -pedantic -Wall -std=c++11 -g
EXE = sejours
OBJETS = Trajet.o TrajetSimple.o Element.o ListeTrajets.o TrajetCompose.o Catalogue.o


$(EXE) : $(OBJETS) $(EXE).o
	@echo "Édition des liens de sejours"
	g++ -o $@ $^

%.o : %.cpp
	@echo "Compilation de $<"
	g++ -c $< $(CPPFLAGS)

clean:
	@echo "Suppresion des fichiers compilés"
	rm *.o sejours

memoryCheck:
	make clean
	@echo "Vérification de la gestion de mémoire"
	make CPPFLAGS='$(CPPFLAGS) -DMAP -g'
	valgrind ./sejours --track-origins=yes