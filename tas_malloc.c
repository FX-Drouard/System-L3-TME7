#include "tas_malloc.h"

int libre = 0;

zone_libre premiere_zone_libre = {
  .TL = TAILLE_MALLOC - 1,
  .indice_debut_zone_libre_suivante = -1
};

liste_zone_libre LZL = {
  .zl = &premiere_zone_libre,
  .lzl = NULL
};

liste_zone_allouee LZA = {
  .za = NULL,
  .lza = NULL
};

void * tas;

void * create_shared_memory() {
  tas = mmap(NULL, TAILLE_MALLOC * sizeof(char), PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_ANON, MMAP_FILE_DESCRIPTOR, MMAP_OFFSET);
  if (tas == MAP_FAILED) {
    perror("mmap error\n");
    fprintf(stderr, "mmap() failed\n");
    exit(EXIT_FAILURE);
  }
  return tas;
}

char * tas_malloc(unsigned int taille) {
  if (taille > TAILLE_MALLOC) {
    fprintf(stderr, "la capacité du tas est insuffisante\n");
    exit(EXIT_FAILURE);
  }
  zone_libre * premiere_zone_libre = LZL.zl;
  if (premiere_zone_libre.TL >= taille) {
    premiere_zone_libre.TL -= taille;
    if (premiere_zone_libre.TL == 0) {
      supprimer_chainon(
    }
  }
  zone_allouee za = {
    .TD = taille,
    .donnee_elle_meme = (char *) tas
  };

  liste_zone_allouee nlza = {
    .za = &za,
    .lza = NULL
  };
  LZA.lza = &nlza;
  za.TD = taille;
  return (char *) za.donnee_elle_meme;
}

int size(liste_zone_allouee * lza) {
  if (lza->za == NULL) return 0;
  if (lza->lza == NULL) return 1;
  return 1 + size(lza);
}

liste_zone_allouee * get_chainon(liste_zone_allouee * lza, int i) {
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
    zone_allouee * za = a_supprimer->za;
    free(a_supprimer);
    return za;
  }
  return NULL;
}

zone_libre * supprimer_chainon(liste_zone_libre * lzl, int i) {
  if (i > size(lzl)) fprintf(sterr, "i pluus grand que la taille de la liste\n");
  if (i == 1)
}
 
void inserer_chainon(liste_zone_libre * lzl, zone_allouee * za) {
  zone_libre zl = {
    .TL = za->TD,
    .indice_debut_zone_libre_suivante = -1
  };
  liste_zone_libre nv_chainon = {
    .zl = &zl,
    .lzl = NULL
  };
  if (!lzl->lzl) {
    lzl->lzl = &nv_chainon;
  }
  if ((int) za->donnee_elle_meme < lzl->lzl->zl->indice_debut_zone_libre_suivante) {
    liste_zone_libre * pivot = lzl->lzl;
    lzl->lzl = &nv_chainon;
    nv_chainon.lzl = pivot;
  }
}

int tas_free(char *ptr) {
  int trouve = 0;
  int i = 0;
  int taille_lza = size(&LZA);
  liste_zone_allouee * cpy_lza = &LZA;

  while (!trouve && i < taille_lza) {
    char * ptr_za = cpy_lza->za->donnee_elle_meme;
    if (ptr == ptr_za) {
      trouve = 1;
      zone_allouee * za = supprimer_chainon(&LZA, i);
      inserer_chainon(&LZL, za);
    } else {
      i++;
      cpy_lza = cpy_lza->lza;
    }
  }
  return -1;
}

