derivative.o: derivative.c
	gcc -c derivative.c 
exe: derivative.o
	gcc -o exe derivative.o
	rm derivative.o
	./exe
