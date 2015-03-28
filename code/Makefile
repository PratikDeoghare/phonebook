
all: test.cc PhoneBook.o
	g++ -Wall test.cc -o test

bitset.o : bitset.h bitset.cc
	g++ -Wall -c bitset.cc

PhoneBook.o: PhoneBook.h PhoneBook.tpp PhoneBook.cc bitset.o
	g++ -Wall -c PhoneBook.cc 

clean:
	- rm *.o test

