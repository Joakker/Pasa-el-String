#include  <stdio.h>
#include  <stdlib.h>
#include  "lib/dict_lib.h"

int main(){
  int numEntr =  count_entries();
  Entrada*    database = (Entrada*) malloc(numEntr * sizeof(Entrada));
  Apuntador*  directorio[26];

  FILE* diccionario = fopen("txt/diccionario.txt", "r");
  for (int i = 0 ; i < numEntr; i++)
    fscanf(diccionario, "%[^:] %[^\n]", database[i].palabra, database[i].definicion);

  for (int i = 0; i < 26 ; ++i)
    directorio[i] = (Apuntador*) malloc(numEntr * sizeof(Apuntador));

  printf("%s\n", database[0].definicion);

  for (int i = 0 ; i < 26 ; ++i)  free(directorio[i]);


  free(database);
  fclose(diccionario);

  return 0;
}
