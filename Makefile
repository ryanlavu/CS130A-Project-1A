dictionary: dictionary.o
	gcc -o dictionary dictionary.o -lstdc++

clean:
	$(RM) dictionary dictionary.o

