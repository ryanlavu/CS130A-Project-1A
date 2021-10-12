project1: dictionary.o
	gcc -o project1 dictionary.o -lstdc++ -lm -ldl

clean:
	$(RM) project1 dictionary.o

