#ifndef DICT_LIB_H_INCLUDED
#define DICT_LIB_H_INCLUDED

#include "incl_lib.h"

typedef struct {
        char    palabra[25];
        char    definicion[500];
        bool    used;
} Entrada;

typedef struct {
        Entrada*      entrada;
        unsigned int  letras;
} Directorio;

#define bin(N)  1 << (tolower(N) - 'a')

int     count_entries() {
  FILE  * diccionario = fopen("txt/diccionario.txt", "r");
  char    c = getc(diccionario);
  int     numEntr = 0;

  while (c != EOF) {
    if (c == '\n')  numEntr++;
    c = getc(diccionario);
  }

  fclose(diccionario);
  return  numEntr;
}

void    read_dictionary(int numEntr, Entrada  * database) {
        FILE  * diccionario = fopen("txt/diccionario.txt", "r");
        int aux;
        for (int i = 0; i < numEntr; ++i) {
                fscanf(diccionario, "%[^:]", database[i].palabra);
                getc(diccionario);
                aux = getc(diccionario);
                while (isspace(aux)) aux = getc(diccionario);
                ungetc(aux, diccionario);
                fscanf(diccionario,"%[^\n]", database[i].definicion);
                getc(diccionario);
        }
        fclose(diccionario);

        for (int i = 0; i < numEntr; i++) {
                database[i].used = false;
        }

}

Entrada*search(int numEntr, Entrada* database, char c) {

        int n, m;

        do {
                n = rand() % numEntr;
                m = rand() % strlen(database[n].palabra);
        } while (tolower(database[n].palabra[m]) != c);

        return &database[n];
}

bool    compare(char* s1, char* s2) {
        for (int i = 0 ; s1[i] != '\0' && s2[i] != '\0' ; ++i)
                if (tolower(s1[i]) != tolower(s2[i]))
                        return false;
        return true;
}

#endif // DICT_LIB_H_INCLUDED
