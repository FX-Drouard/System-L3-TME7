#include <string.h>
#include <stdio.h>
#include "tas_malloc.h"

int main() {
  printf("main\n");
  char *p1, *p2, *p3, *p4, *p5;
  p1 = (char *) tas_malloc(10);
  printf("p1\n");
  p2 = (char *) tas_malloc(9);
  //exit(0);
  p3 = (char *) tas_malloc(5);
  
  strcpy(p1, "tp 1");
  exit(0);
  strcpy(p2, "tp 2");
  strcpy(p3, "tp 3");
  tas_free(p2);
  p4 = (char *) tas_malloc(8);
  strcpy(p4, "systeemee");
  printf("%s\n", p4);
  printf("fino main\n");
}
