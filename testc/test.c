#include  <stdio.h>
#include  <stdlib.h>

typedef struct {
  char myString[25];
  char pista[100];
  int  myInt;
} entry;

typedef struct {
  char nombre[25];
  char aciertos;
  char desaciertos;
} jugador;

void main() {
  FILE* myfile = fopen("myText.txt", "r");
  entry** myArray = (entry**) malloc(sizeof(entry**) * 2);
  entry* myArray2 = (entry*) malloc(sizeof(entry) * 2);

  for (int i = 0; i < 2 ; i++){
    myArray[i] = &myArray2[i];
  }

  fscanf(myfile, "%s %d", myArray[0]->myString, &myArray[0]->myInt);
  fscanf(myfile, "%s %d", myArray[1]->myString, &myArray[1]->myInt);
  if( myArray[0]->myString[0] > myArray[1]->myString[0]){
    entry* aux = myArray[0];
    myArray[0] = myArray[1];
    myArray[1] = aux;
  }
  printf("%s\n", myArray[0]->myString);
  fclose(myfile);
}
