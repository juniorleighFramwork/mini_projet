#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
  1. le choix du CPU + représenter les coups
  2. le choix du joueur (saisie + validation)
  3. La logique : qui gagne ?
  4. Boucle de matches + score
*/

/*
  Premiere choix de design: comment representer pierre, feuille, ciseaux dans le code ?
  On pourrait utiliser des chaines ("pierre", "feuille",...) mais comparer strings en C,
  c'est du lourd (strcmp). L'actuce classique : des entiers.
*/

/*
  #define PIERRE 0
  #define FEUILLE 1
  #define CISEAUX 2

  Pourquoi 0, 1, 2? Parce qu'avec ces nombres, rand() % 3 te donne directement un coup valide
  pour le CPU. Et la logique "qui gagne" devient un calcul mathématique tout propre.
*/

#define PIERRE 0
#define FEUILLE 1
#define CISEAUX 2

#define EGALITE 0
#define JOUEUR_GAGNE 1
#define CPU_GAGNE 2

// PRE: /
// POST: retrouve un coup aléatoire du CPU (PIERRE, FEUILLE ou CISEAUX)
int coup_cpu(void) {
  return rand() % 3; // 3 = nombre de coup possible
}

// PRE: /
// POST: retourne un coup valide saisi par le joueur (PIERRE, FEUILLE ou CISEAUX)
int coup_joueur(void) {

  int coup = -1;

  printf("Choisis : %d=Pierre %d=Feuille %d=Ciseaux\n", PIERRE, FEUILLE, CISEAUX);

  // TODO: tant que coup n'est pas valide, redemande la saisie
  //       (un coup valide est compris entre PIERRE et CISEAUX)
  while (coup < PIERRE || coup > CISEAUX) {
    printf("Coup : \n");
    scanf("%d", &coup);
  }
  return coup;
}

// PRE: joueur et cpu des coups valide (PIERRE, FEUILLE ou CISEAUX)
// POST: retourne EGALITE, JOUEUR_GAGNE ou CPU_GAGNE
int determine_gagnant(int joueur, int cpu) {

  if (joueur == cpu) return EGALITE;
  if (joueur == (cpu + 1) % 3) return JOUEUR_GAGNE;
  return CPU_GAGNE;
}

// PRE: coup est un coup valide (PIERRE, FEUILLE ou CISEAUX)
// POST: retourne le nom du coup sous forme de texte
const char* nom_coup(int coup) {
    if (coup == PIERRE)  return "Pierre";
    if (coup == FEUILLE) return "Feuille";
    return "Ciseaux";
}

int main(void) {
  srand(time(NULL)); // Initialise le hasard une seule fois

  int score_joueur = 0; // avant la boucle
  int score_cpu = 0; // sinon remis à 0 chque manche
  int rejouer;

  do {

  // 1. Les deux coup
  int joueur = coup_joueur();
  int cpu = coup_cpu();

  // 2. Affiche ce que chacun a joué
  printf("Toi : %s\n", nom_coup(joueur));
  printf("CPU : %s\n", nom_coup(cpu));

  // 3. Détermine le resultat
  int resultat = determine_gagnant(joueur, cpu);

    // TODO 4: afficher le verdict selon 'resultat'
    if (resultat == EGALITE) {
      printf("Égalité !\n");
    } else if (resultat == JOUEUR_GAGNE) {
      printf("Tu gagnes !\n");
      score_joueur++;
    } else {
      printf("Le CPU gagne !\n");
      score_cpu++;
    }

    // incrémenter le bon score 'resultat'
    // rien à faire si EGALITE

    printf("Rejouer ? 1=Oui  0=Non : ");
    scanf("%d", &rejouer);
  } while (rejouer == 1);
  // --- bilan final ---
  printf("\n=== Score final ===\n");
  printf("Toi : %d CPU : %d\n", score_joueur, score_cpu);

  // affiche qui gagne globalement
  if (score_joueur > score_cpu) {
    printf("Tu remportes la partie !\n");
  } else if (score_cpu > score_joueur) {
    printf("Le CPU remporte la partie !\n");
  } else {
    printf("Match nul !\n");
  }
  return 0;
}
