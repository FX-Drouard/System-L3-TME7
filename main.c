#include "tas_malloc.h"
int main() {
    char * p1;
    p1 = (char *) tas_malloc(3);
    strcpy(p1, "ab");
}