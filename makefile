make: patron.o libraryitem.o loan.o loans.o patrons.o libraryitems.o main.o audioCd.o book.o dvd.o 
	g++ -o make patron.o patrons.o libraryitem.o libraryitems.o loan.o loans.o main.o audioCd.o book.o dvd.o

main.o: main.cpp libraryitem.h loan.h patron.h loans.h libraryitems.h patrons.h audioCd.h book.h dvd.h 
	g++ -c main.cpp

libraryitem.o: libraryitem.cpp libraryitem.h 
	g++ -c libraryitem.cpp

patron.o: patron.cpp patron.h
	g++ -c patron.cpp

loan.o: loan.cpp loan.h
	g++ -c loan.cpp

libraryitems.o: libraryitems.cpp libraryitem.h libraryitems.h
	g++ -c libraryitems.cpp

loans.o: loans.cpp loan.h loans.h 
	g++ -c loans.cpp

patrons.o: patrons.cpp patron.h patrons.h
	g++ -c patrons.cpp

audioCd.o: audioCd.cpp audioCd.h
	g++ -c audioCd.cpp

book.o: book.cpp book.h
	g++ -c book.cpp

dvd.o: dvd.cpp dvd.h
	g++ -c dvd.cpp
