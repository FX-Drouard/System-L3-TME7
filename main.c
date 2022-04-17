#include <string.h>
#include <stdio.h>
#include "tas_malloc.h"
void mon_printf(char * string) {
  int i = 0;
  while (string[i]) {printf("%c", string[i]);i++;}
  printf("\n");
}
int main() {
    char * p1;
    p1 = (char *) tas_malloc(5);
    printf("adresse pointeur tas: %d\n", *p1);
    printf("testo\n");
    //    strcpy(p1, "ab");
    printf("p1: %c\n", p1[1]);
    printf(p1);
    mon_printf(p1);
    printf("testo\n");
}
