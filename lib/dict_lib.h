#ifndef DICT_LIB_H_INCLUDED
#define DICT_LIB_H_INCLUDED


typedef struct {
  char  palabra[25];
  char  definicion[500];
} Entrada;

typedef struct {
  Entrada*  entrada;
  Uint32    letras;
} Directorio;

int   count_entries() {
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

void  read_dictionary(int numEntr, Entrada  * database) {
  FILE  * diccionario = fopen("txt/diccionario.txt", "r");
  for (int i = 0; i < numEntr; ++i) {
    fscanf(diccionario, "%[^:]", database[i].palabra);
    getc(diccionario);
    fscanf(diccionario,"%[^\n]", database[i].definicion);
    getc(diccionario);
  }
  fclose(diccionario);

}

void  sort_dictionary(int numEntr, Entrada  * database,
                      Directorio  ** dir, int* limites) {
  for (int i = 0 ; i < numEntr ; i++) {                                         //Selection sort, because god knows merge sort ain't working
    for (int j = 0 ; j < numEntr - 1 ; j++) {
      if (database[j].palabra[0] > database[j + 1].palabra[0]) {
        Entrada aux = database[j];
        database[j] = database[j + 1];
        database[j + 1] = aux;
      }
    }
  }

  for (int i = 0 ; i < NLETRS ; i++) {
    limites[i] = 0;
  }

  for (int i = 0 ; i < numEntr ; i++) {
    int n = database[i].palabra[0] - 'A';
    dir[n][limites[n]].entrada = &database[i];
    printf("%s\n", dir[n][limites[n]].entrada->palabra);
    limites[i]++;
  }
}

#endif // DICT_LIB_H_INCLUDED
