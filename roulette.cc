#include <iostream>
#include <random>
#include <ctime>

using namespace std;

int nombre_aleatoire (int fin = 50) {
	srand(time(nullptr));
	return rand() % fin ;
	
}

bool nombre_egaux(int nb_aleatoire, int nombre) {
	if (nb_aleatoire == nombre) {
		return true;
		
	}
	
	if (nb_aleatoire != nombre) {
		return false;
	}
	
}

bool est_pair (int nombre) {
	if (nombre % 2 == 0) {
		return true;
	}
	
	if (nombre % 2 != 0) {
		return false;
	}
}
	
bool meme_nature (int nb_aleatoire, int nombre) {
	if ((est_pair(nombre) and est_pair(nb_aleatoire)) or (est_pair(nombre) == false and est_pair(nb_aleatoire) == false)) {
		return true;
		
	 }
	 
	 if (not((est_pair(nb_aleatoire) and est_pair(nombre)) or not (est_pair(nb_aleatoire) and est_pair(nombre)))){
		return false;
		
	 }
 }
 

int main () {
	int i (1);
	int round (0);
	int argent (100);
	int mise;
	int nb_aleatoire ;
	int chiffre_choisi ;
	int meme_chiffre (0) ;
	char rester;
	int meme_case(0);
	
	while (i == 1) {
		round = 1;
		
		cout << "Bienvenue au jeu de la roulette !" << endl ;
		cout << "Les regles sont simples : - Tirer un chiffre entre 0 et 50 et decider de l argent à miser" << endl ;
		cout << "                          - La roulette va tourner et decider aleatoirement d'un nombre aussi entre 0 et 50" << endl ;
		cout << "                          - Si le chiffre que vous avez choisi est le meme que celui decide aleatoirement, alors bravo, vous triplez votre mise !" << endl ;
		cout << "                          - Si votre chiffre est pair, et que celui tire par la roulette l est aussi et reciproquement avec un chiffre impair, alors vous gagnez 50% de votre mise en plus de celle-ci" << endl ;
		cout << "                          - Enfin, si votre nombre ne correspond a aucun de ces tests, alors le casino prend votre mise." << endl;
		cout << "Vous etes pret ? Alors c est parti !" << endl ;
		cout << endl;
		cout << "Vous commencez avec " << argent << " euros." << endl;
		
		while(round == 1) {
			nb_aleatoire = nombre_aleatoire();
			meme_chiffre = 0;
			meme_case = 0;
			
			cout << endl ;
			
			do {
				cout << "Nous vous rappelons que votre mise ne doit ni etre nulle, ni negative, ni superieure a l argent que vous possedez" << endl ;
				cout << "Combien voulez vous miser ? : " ;
				cin >> mise ;
				
			} while (mise <= 0 or mise > argent) ;
			
			do {
				cout << "Nous vous rappelons que votre chiffre ne doit ni etre nul, ni negatif, ni superieur a 50" << endl ;
				cout << "Quel chiffre choisissez vous ? : " ;
				cin >> chiffre_choisi ;
				
			} while (chiffre_choisi <= 0 or chiffre_choisi > 50) ;
			
			cout << "Bien, vous avez mise : " << mise << " euros" << endl;
			
			if (mise == argent) {
				cout << "TAPIS ! Vous etes sur de votre coup ???" << endl ;
			}
			
			if (mise + 10 > argent and mise != argent) {
				cout << "C est une grande somme !" << endl;
			}
			
			
			cout << endl ;
			
			cout << "La roue tourne tourne tourne ..." << endl ;
			
			cout << endl ;
			
			cout << "Le chiffre est le " << nb_aleatoire << endl ;
			
			if (nombre_egaux(nb_aleatoire, chiffre_choisi)) {
				cout << "Felicitations !!! Vous avez touve le bon chiffre !" << endl;
				meme_chiffre = 1;
				argent += mise * 2;
			}
				
			if (meme_nature(nb_aleatoire, chiffre_choisi) and meme_chiffre == 0) {
				cout << "Bravo ! Vous avez touve un des chiffres ayant la meme couleur de case que le chiffre aleatoire !" << endl ;
				argent += mise/2 ;
				meme_case = 1;
			}
			
			if (meme_chiffre == 0 and meme_case == 0) {
				cout << "Zut, ce chiffre ne correspond a aucun critere !" << endl ;
				argent -= mise;
			}
		
			
			
			if (argent == 0) {
				cout << "Nous sommes desoles de vous annoncer que vous devez quitter le Casino, vous n avez plus d argent." << endl;
				round = 0;
				i = 0;
				
			}
			
			
			
			if (argent > 0) {
				cout << "Vous avez actuellement " << argent << " euros. Voulez-vous continuer a jouer ou bien partir avec cet argent (o = oui je veux partir, n = non je veux rester) ? : " ;
				cin >> rester ;
				
			}
			
			if (rester == 'o') {
				cout << "D accord, a plus tard !" << endl ;
				round = 0;
				i = 0;
				
				
			}
			
			if (rester == 'n') {
				cout << "Tres bien, continuons a jouer ! " << endl ;
				
				
			}
			
			
			
		}
	}	
	return 0;
}


