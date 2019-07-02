#ifndef DICT_LIB_H_INCLUDED
#define DICT_LIB_H_INCLUDED


typedef struct {
  char  palabra[25];
  char  definicion[500];
} Entrada;

typedef struct {
  Entrada* apuntada;
  char     contiene;
} Apuntador;

int count_entries() {
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
    fscanf(diccionario, "%[^:] %[^\n]", database[i].palabra,
                                        database[i].definicion);
  }
  fclose(diccionario);

}

void sort_dictionary(int numEntr, Entrada* database, Apuntador** directorio) {
  /* code */
}
#endif // DICT_LIB_H_INCLUDED
