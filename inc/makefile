a.out: main.o phonebook.o operations.o
	gcc main.o phonebook.o operations.o -o a.out

main.o: main.c phone_book.h
	gcc -c main.c

phonebook.o: phonebook.c phone_book.h
	gcc -c phonebook.c

operations.o: operations.c phone_book.h
	gcc -c operations.c

clean:
	rm -f *.o a.out
