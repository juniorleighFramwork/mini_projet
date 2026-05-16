#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NB_MIN 1
#define NB_MAX 100



/*
  1. L'ordi choisit un nombre secret (1 - 100)
  2. Le joueur devine
  3. L'ordi répond:
     -> "Trop grand!"
     -> "Trop petit!"
  4. On compte les essais
*/

// Comme on va se baser sur la devinette,
// On va essayer de comprendre comment on
// Peut avoir entre 1 à 100
// rand() % 100 donne le reste de la division par 100.
// Donc entre 0 et 99

/*
la formule:
  rand() % 100 + 1
  % 100 → entre 0 et 99
  + 1   → entre 1 et 100

  srand(time(NULL)); // initialise le RANDOM
*/

// PRE: /
// POST: retourne un nombre aléatoire entre NB_MIN et NB_MAX
int generate_nombre(void) {
  srand(time(NULL)); // initialise le hasard
  int random = rand() % NB_MAX + NB_MIN;
  return random;
}

// PRE: secret entre NB_MIN et NB_MAX
// POST: retourne le nombre d'essaie pour trouver
int jouer(int secret) {

  int essais = 0;
  int devine = 0;

  printf("Devine le nombre entre %d et %d !\n", NB_MIN, NB_MAX);

  // Boucle jusqu'a ce que le joueur trouve
  while(devine != secret) {
    printf("Ton essai : ");
    scanf("%d", &devine);
    essais++;

    if (devine < secret) {
      printf("Trop petit !\n");
    } else if (devine > secret) {
      printf("Trop grand !\n");
    } else {
      printf("Bravo ! Trouvé en %d essais \n", essais);
    }
  }
  return essais;
}


int main(void) {
  // Test - affiche le nombre secret
  // On genere une fois dans main
  int secret = generate_nombre();
  // on passe le meme nombre a jouer()
  jouer(secret);
  return 0;
}
