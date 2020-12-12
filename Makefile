main:	main.o Contact.o
		g++ -o main main.o Contact.o

main.o:	main.cpp Contact.h

Contact.o:	Contact.cpp Contact.h

