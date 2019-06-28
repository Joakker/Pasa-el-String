#include  <stdio.h>
#include  <stdlib.h>
#include  "lib/dict_lib.h"

int main(){
  int numEntr =  count_entries();
  Entrada* database;
  Apuntador* myApuntador = (Apuntador*) malloc(sizeof(Apuntador[numEntr]) *26);
  read_diccionary(numEntr, database);

  for (int i = 0 ; i < numEntr ; i++){
    for (int j = 0 ; database[i].palabra[j] != '\0'; j++) {
        myApuntador[database[i].palabra[j] - 'a'].apuntada = &database[i]
        if (j == 0) {
          myApuntador[database[i].palabra[j] - 'a'].contiene = 0;
        } else myApuntador[database[i].palabra[j] - 'a'].contiene = 1;
    }
  }
  return 0;
}
