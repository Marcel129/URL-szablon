
TRGDIR=./
OBJ=./obj
CPPFLAGS= -c -g -Iinc -Wall -pedantic -std=c++17

__start__: ${TRGDIR}/URL_szablon
	${TRGDIR}/URL_szablon

${TRGDIR}/URL_szablon: ${OBJ} ${OBJ}/main.o ${OBJ}/LZespolona.o ${OBJ}/Wektor.o
	g++ -o ${TRGDIR}/URL_szablon ${OBJ}/main.o ${OBJ}/LZespolona.o ${OBJ}/Wektor.o

${OBJ}:
	mkdir ${OBJ}

${OBJ}/main.o: src/main.cpp inc/LZespolona.hh inc/Wektor.hh
	g++ -c ${CPPFLAGS} -o ${OBJ}/main.o src/main.cpp

${OBJ}/LZespolona.o: src/LZespolona.cpp inc/LZespolona.hh
	g++ -c ${CPPFLAGS} -o ${OBJ}/LZespolona.o src/LZespolona.cpp

${OBJ}/Wektor.o: src/Wektor.cpp inc/Wektor.hh inc/rozmiar.h
	g++ ${CPPFLAGS} -o ${OBJ}/Wektor.o src/Wektor.cpp


clear:
	rm -f ${TRGDIR}/URL_szablon ${OBJ}/*


