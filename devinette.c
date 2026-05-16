#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NB_MIN 1
#define NB_MAX 100
#define NB_SECRET_MAX 50



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

// Structure score
typedef struct {
  char nom[NB_SECRET_MAX];
  int nb_essais;
} score_t;

// PRE: score != NULL
// POST: demande le nom du joueur et initialise son score
void init_score(score_t *score) {
  printf("Quel est ton nom : ");
  scanf("%s", score->nom); // nom du joueur
  score->nb_essais = 0;  // nb_esssais = 0
}

// PRE: score != NULL
// POST: affiche le score du joueur
void afficher_score(score_t *score) {
  printf("Joueur : %s\n", score->nom); // affiche le nom du joueur
  printf("Essais : %d\n", score->nb_essais); // affiche le nombre essais
}

int main(void) {
  // Initialise le score
  score_t score;
  init_score(&score);

  // Generer le nombre secret
  int secret = generate_nombre();

  // Jouer et sauvegarde le score
  score.nb_essais = jouer(secret);

  // Affiche le score final
  afficher_score(&score);

  return 0;
}
