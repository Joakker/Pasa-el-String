#include    <stdio.h>
#include    <stdlib.h>
#include    <string.h>
#include    <stdbool.h>

/*
  struct dog
  {
      char name[10];
      char breed[10];
      int age;
      char color[10];
  };

  void createDog(struct dog* ptr_dog[], int i) {
    printf("Dog's name: %s\n", ptr_dog[i]->name);
    printf("Dog's breed: %s\n", ptr_dog[i]->breed);
    printf("Dog's age: %d\n", ptr_dog[i]->age);
    printf("Dog's color: %s\n", ptr_dog[i]->color);
  }

  int main()
  {
      struct dog my_dogs[2];
      strcpy(my_dogs[0].name, "tyke");
      strcpy(my_dogs[0].breed, "Bulldog");
      my_dogs[0].age = 5;
      strcpy(my_dogs[0].color, "white");
      //struct dog my_dog = {"tyke", "Bulldog", 5, "white"}, my_dog2;
      struct dog *ptr_dog[2];
      ptr_dog[0] = &my_dogs[0];
      ptr_dog[1] = &my_dogs[1];
      strcpy(ptr_dog[1]->name, "Jake");

      createDog(ptr_dog, 0);
      // signal to operating system program ran fine
      return 0;
  }

*/

typedef struct {
    char name[20];
    char fcolor[20];
    int  age;
} person;

typedef struct {
    person* p;
    bool    isMinor;
} pperson;

void createPerson(pperson * ppeople, int n) {
  FILE* personas = fopen("personas.txt", "r");

  for (int i = 0 ; i < n ; i++)
    fscanf(personas, "%s %s %d", ppeople[i].p->name, ppeople[i].p->fcolor, &ppeople[i].p->age);

  fclose(personas);
}

void determineAge(pperson * ppeople, int n) {
  for (int i = 0 ; i < n ; i++) {
    if (ppeople[i].p->age < 18) {
      ppeople[i].isMinor = true;
    } else ppeople[i].isMinor = false;
  }

  for (int i = 0 ; i < n ; i++) {
    if (ppeople[i].isMinor == true) printf("%s es menor de edad\n", ppeople[i].p->name);
    else printf("%s es mayor de edad\n", ppeople[i].p->name);
  }
}

/*
void merge(pperson * ppeople, int n, pperson* p1, int n1, pperson* p2, int n2){
  int l = 0, r = 0;
  for ( int i = 0 ; i < n ; i++) {
    if ((l < n1) && (r == n2 || p1[l].p->age < p2[r].p->age)) {
      ppeople[i] = p1[l];
      l++;
    } else {
      ppeople[i] = p1[r];
      r++;
    }
  }
}
*/

/*
void mergeSort(pperson* ppeople, int n){
  if ( n <= 1 ) return;

  int n1 = n / 2;
  int n2 = n - n1;

  pperson* p1 = (pperson*) malloc(sizeof(pperson) * n1);
  pperson* p2 = (pperson*) malloc(sizeof(pperson) * n2);

  for (int i = 0 ; i < n1 ; i++) p1[i] = ppeople[i];
  for (int i = 0 ; i < n2 ; i++) p2[i] = ppeople[i + n1];

  merge(ppeople, n, p1, n1, p2, n2);

  free(p1);
  free(p2);

}
*/

int main(int argc, char const *argv[]) {
  int n = 3;
  person * people  = (person*)  malloc(sizeof(person) * n);
  pperson* ppeople = (pperson*) malloc(sizeof(pperson)* n);

  for (int i = 0 ; i < n ; i++) ppeople[i].p = &people[i];

  createPerson(ppeople, n);
  determineAge(ppeople, n);
  
  //mergeSort(ppeople, n);

  for (int i = 0; i < n ; i++ ) printf("%s\n", ppeople[i].p->name);

  free(people);
  return 0;
}
