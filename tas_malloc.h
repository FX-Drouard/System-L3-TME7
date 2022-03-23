#include <sys/mman.h>
#define TAILLE_MALLOC 128
typedef struct s_zone_allouee {
    char TD;
    char * donnee_elle_meme;
} zone_allouee;
typedef struct s_zone_libre {
    char TL;
    char indice_debut_zone_libre_suivante;
} zone_libre;
char libre = 0;
char * tas_malloc(unsigned int taille);
int tas_free(char * ptr);