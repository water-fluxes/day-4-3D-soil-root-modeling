#ifndef ROOTTYP1
#define ROOTTYP1

#define NBTYPMAX 13  /* Nbre maximal de types */
#define NBHORMAX 30 /* Nombre d'horizons de sol */
#define NBVAGMAX 12  /* Nombre maximal de vagues de r�it�ration */
#define MAXLINE 120  /* Longueur maxi de la ligne dans fichiers texte */

typedef double r2[2];  /* Tableau 2D */
typedef double r3[3];  /* Tableau 3D */

typedef struct sysrac *PTSysRac;
typedef struct axe *PTAxe;
typedef struct meristeme *PTMeristeme;
typedef struct noeud *PTNoeud;

typedef struct sysrac /* Ensemble d'axes */
{
  long int NbAxeForm;  /* Nombre d'axes form�s */
  long int NbAxeSup;   /* Nombre d'axes supprim�s */
  long int NbNoeudForm;    /* Nombre de noeuds form�s */
  int NumVReitCourante; /* Num�ro de vague de r�it�ration courante */
  int ReitPossible;     /* R�it�ration possible : 1 ou 0 */
  double AngDep; /* Orientation */
  r3 Origine; /* Position de l'origine */
  PTAxe PremAxe;       /* Premier axe du syst�me (acc�s � la liste) */
  PTAxe DernAxe;       /* Dernier axe produit */
} TSysRac ;

typedef struct meristeme /* M�rist�me apical, ou pointe de chaque racine */
{
  double DistPrimInit; /* Distance de l'apex au dernier primordium initi� */
  r3 Coord;           /* Coordonn�es de l'apex */
  r3 DirCroiss;       /* Direction de croissance */
  r3 DirInit;         /* Direction initiale */
  double Age;          /* Age du m�rist�me */
  double Diametre;     /* Diam�tre au niveau de la pointe */
  r2 PCroiss;         /* Caract�ristiques de croissance potentielle du m�rist�me */
  double PRamif;       /* Distance inter-ramif potentielle */
  int Type;           /* Type (�tat morphog�n�tique) de m�rist�me : de 0 a 7 */
  int TypeDest;       /* Type � faire appara�tre dans le fichier noeud de sortie */
  int Senile;         /* S�nile ?, ou actif ... */
  int Mature;         /* Mature ?, ou primordium ... */
} TMeristeme ;

typedef struct axe /* Ensemble constitu� d'un m�rist�me et liste de noeuds */
{
  long int Num;      /* Num�ro de l'axe */
  int NbNoeud;       /* Nombre de noeuds */
  PTMeristeme Meris; /* M�rist�me apical */
  PTAxe Suivant;     /* Suivant de la liste */
  PTAxe Precedent;   /* Precedent de la liste */
  PTAxe Pere;        /* Axe p�re, sur lequel celui-ci est branch� */
  PTNoeud PremNoeud; /* Premier noeud de l'axe, sa base */
  PTNoeud DernNoeud; /* Dernier noeud de l'axe, apical */
} TAxe ;

typedef struct noeud
{
  long int Num;      /* Num�ro d'ordre de cr�ation */
  int JourForm;      /* Date de formation (en jours) */
  double Diametre;   /* Diametre au niveau du noeud */
  double wc;         /* water content of the node (HH) */ 
  r3 Pos;            /* Position dans l'espace */
  PTNoeud SuivSPere; /* Suivant sur le p�re (quand branchement) */
  PTNoeud SuivSFils; /* Suivant sur le fils, axe d'appartenance */
  PTNoeud Prec;      /* Precedent */
  PTNoeud SuivSAxe;  /* Suivant sur l'axe */
  PTAxe Pere;        /* Axe p�re, pointe sur NULL quand non branchement */
  PTAxe Fils;        /* Axe fils, d'appartenance du noeud */
  int Necrose;       /* Necrose ? 0 : non; 1 : oui */
} TNoeud ;

typedef struct horizon
{
  float Croiss;  /* Coefficient de croissance, compris entre 0 et 1 */
  float Ramif;   /* Coefficient multiplicateur de distance inter-ramif  >1 */
  float ICMeca;  /* Intensit� de la contrainte m�canique */
  int OCMeca;    /* Orientation de la contrainte m�canique (O iso, ou 1 vert) */
} THorizon ;

typedef THorizon TSol[NBHORMAX];  /* Sol, tableau d'horizons */

/* Variables globales diverses */
extern int Temps;  /* Le temps, en jours */
extern r3 Orig;    /* Position d'origine de l'organe g�n�rateur */

extern PTSysRac SR;  /* Le syst�me racinaire */
extern TSol Sol;     /* Le sol */
#endif
