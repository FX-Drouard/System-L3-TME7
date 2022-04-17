#include "tas_malloc.h"
#include <stdio.h>
#include <errno.h>
char *tas_malloc(unsigned int taille) {
  zone_allouee* za;
  if (taille > TAILLE_MALLOC) fprintf(stderr, "la capacité du tas est insuffisante\n");
  zone_allouee * = {
    .TD = taille,
    .donnee_elle_meme = NULL
  };
  nv_liste_zone_allouee * = {
    .za = zone_alloue,
    .lza = NULL
  };
  liste_zone_allouee->lza = nv_liste_zone_allouee;
  za->TD = taille;
  if (za == MAP_FAILED) {
    perror("mmaap error");
    fprintf(stderr, "mmap() failed\n");
    exit(EXIT_FAILURE);
	    }
  za->donnee_elle_meme[0] = 'c';
  za->donnee_elle_meme[1] = 'd';
  return (char *) za->donnee_elle_meme;
}
int size(liste_zone_allouee * lza) {
  if (lza->lza == NULL) return 1;
  return 1 + size(lza);
}
liste_zone_allouee * get_chainon(liste_zone_allouee * lza, i) {
  if (i == 0) return lza;
  return get_chainon(lza->lza, i - 1);
}
zone_allouee * supprimer_chainon(liste_zone_allouee * lza, int i) {
  if (i > size(lza)) fprintf(stderr, "i plus grand que la taille de la liste\n");
  if (i == 1) {
    liste_zone_allouee * precedent = lza;
    liste_zone_allouee * a_supprimer = lza->lza;
    if (!a_supprimer) fprintf(stderr, "pas de chaînon à supprimer\n");
    liste_zone_allouee * suivant = lza->lza->lza;
    precedent->lza = suivant;
    char * za = a_supprimer->za;
    free(a_supprimer);
    return za;
  }
}
void inserer_chainon(liste_zone_libre * lzl, zone_allouee * za) {
  zone_libre * zl = {
    .TL = za->TD,
    .indice_debut_zone_libre_suivante = -1
  };
  liste_zone_libre * nv_chainon = {
    .zl = zl,
    .lzl = NULL
  };
  if (!lzl->lzl) {
    lzl->lzl = nv_chainon;
  }
  if (za->donnee_elle_meme < lzl->lzl->zl->indice_debut_zone_libre_suivante) {
    liste_zone_libre * pivot = lzl->lzl;
    lzl->lzl = nv_chainon;
    nv_chainon->lzl = pivot;
  }
}
int tas_free(char *ptr) {
  int trouve = 0;
  int i = 0;
  int taille_lza = size(LZA);
  liste_zone_allouee * cpy_lza = LZA;
  while (!trouve && i < taille_lza) {
    char * ptr_za = cpy_lza->za->donne_elle_meme;
    if (ptr == ptr_za) {
      trouve = 1;
      char * za = supprimer_chainon(LZA, i);
      inserer_chainon(LZL, za);
    } else {
      i++;
      cpy_lza = cpy_lza->lza;
    }
  }
  return -1;
}
