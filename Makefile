CFLAGS=-Wall -Werror -Wfatal-errors

life: life.o
	g++ -o life life.o

life.o: life.cpp cell.h alivecell.h deadcell.h
	g++ -c $(CFLAGS) -I./ncurses-6.2/install/include/ -L./ncurses-6.2/install/lib/ life.cpp -lncurses

clean:
	rm -rf *.o life