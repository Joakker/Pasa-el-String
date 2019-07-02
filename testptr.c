#include  <stdio.h>
#include  <stdlib.h>
#include  "lib/dict_lib.h"

int main(){
  int numEntr =  count_entries();
  int guards[26];
  char dummie;
  Entrada*    database = (Entrada*) malloc(numEntr * sizeof(Entrada));
  Apuntador*  directorio[26];

  FILE* diccionario = fopen("txt/diccionario.txt", "r");
  for (int i = 0 ; i < numEntr; i++)
    fscanf(diccionario, "%[^:] %c %[^\n] %c", database[i].palabra, &dummie, database[i].definicion, &dummie);

  for (int i = 0; i < 26 ; ++i)
    directorio[i] = (Apuntador*) malloc(numEntr * sizeof(Apuntador));

  for (int i = 0; i < 26 ; ++i)
    guards[i] = 0;


  for (int i = 0; i < numEntr; ++i) {
    char lin = database[i].palabra[0] - 'A';
    printf("%c %d\n", database[i].palabra[0], lin);
  }

  for (int i = 0 ; i < 26 ; ++i)  free(directorio[i]);


  free(database);
  fclose(diccionario);

  return 0;
}
