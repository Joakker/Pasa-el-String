#ifndef DICT_LIB_H_INCLUDED
#define DICT_LIB_H_INCLUDED

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>

typedef struct {
  char  palabra[25];
  char  definicion[500];
} Entrada;

typedef struct {
  Entrada*      entrada;
  unsigned int  letras;
} Directorio;

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

}

void    sort_dictionary(int numEntr, Entrada  * database, Directorio  ** dir, int* limites) {

  for (int i = 0 ; i < NLETRS ; i++)  limites[i] = 0;

  for (int i = 0 ; i < numEntr ; i++) {
    int n = database[i].palabra[0] - 'A';                                       //Calculates the index of the directory where the word will be stored
    dir[n][limites[n]].entrada = &database[i];                                  //allocates a pointer to the entry in the appropriate location
    limites[n]++;
  }
}

bool    compare(char* s1, char* s2) {
        for (int i = 0 ; s1[i] != '\0' && s2[i] != '\0' ; ++i)
                if (tolower(s1[i]) != tolower(s2[i]))
                        return false;
        return true;
}
#endif // DICT_LIB_H_INCLUDED
