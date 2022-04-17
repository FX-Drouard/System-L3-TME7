#include <stdlib.h>
#include <sys/mman.h>
#define TAILLE_MALLOC 128
typedef struct s_zone_allouee {
    char TD;
    char * donnee_elle_meme;
} zone_allouee;
typedef struct s_l_zone_allouee {
  zone_allouee* za;
  struct s_l_zone_allouee lza;
} liste_zone_allouee;
typedef struct s_zone_libre {
    char TL;
    char indice_debut_zone_libre_suivante;
} zone_libre;
typedef struct s_l_zone_libre {
  zone_libre* zl;
  struct s_l_zone_libre* lzl;
} liste_zone_libre;
int libre = 0;
void * tas = mmap(NULL, TAILLE_MALLOC * sizeof(char), PROT_READ|PROT_WRITE, MAP_ANONYMOUS, -1, 0);

zone_libre * premiere_zone_libre = {
  .TL = TAILLE_MALLOC - 1,
  .indice_debut_zone_libre_suivante = -1
};
liste_zone_libre * LZL = {
  .zl = premiere_zone_libre,
  .lzl = NULL
};
liste_zone_allouee * LZA = {
  .za = NULL,
  .lza = NULL
};
char * tas_malloc(unsigned int taille);
int tas_free(char * ptr);
