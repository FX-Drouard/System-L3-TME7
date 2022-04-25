#include <string.h>
#include <stdio.h>
#include "tas_malloc.h"

int main() {
    char * p1;
    create_shared_memory();
    p1 = (char *) tas_malloc(3);
    printf("adresse pointeur tas: %d\n", *p1);
    strcpy(p1, "ab");
    printf(p1);
    printf("\n");
    tas_free(p1);
    p1 = (char *) tas_malloc(5);
    strcpy(p1, "bonjour");
    printf(p1);
    printf("\n");
}
