TRGDIR=./
OBJ=./obj
CPPFLAGS= -c -g -Iinc -Wall -pedantic -std=c++17

__start__: ${TRGDIR}/URL_szablon
	${TRGDIR}/URL_szablon

${TRGDIR}/URL_szablon: ${OBJ} ${OBJ}/main.o ${OBJ}/LZespolona.o ${OBJ}/def_szab.o
	g++ -o ${TRGDIR}/URL_szablon ${OBJ}/main.o ${OBJ}/LZespolona.o ${OBJ}/def_szab.o

${OBJ}:
	mkdir ${OBJ}

${OBJ}/main.o: src/main.cpp inc/LZespolona.hh inc/Wektor.hh inc/Macierz.hh inc/rozmiar.h inc/UkladRownanLiniowych.hh
	g++ -c ${CPPFLAGS} -o ${OBJ}/main.o src/main.cpp

${OBJ}/LZespolona.o: src/LZespolona.cpp inc/LZespolona.hh
	g++ -c ${CPPFLAGS} -o ${OBJ}/LZespolona.o src/LZespolona.cpp

${OBJ}/def_szab.o: src/def_szab.cpp src/Wektor.cpp inc/Wektor.hh src/Macierz.cpp inc/Macierz.hh inc/rozmiar.h inc/LZespolona.hh inc/UkladRownanLiniowych.hh src/UkladRownanLiniowych.cpp
	g++ ${CPPFLAGS} -o ${OBJ}/def_szab.o src/def_szab.cpp



clear:
	rm -f ${TRGDIR}/URL_szablon ${OBJ}/*


