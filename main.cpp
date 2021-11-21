#include <iostream>
#include <time.h>
#include "lib_a.h"
#include <iomanip>
using namespace std;

int main(){
	int contaB=0; //conta bandiere
	bool gioco=true; //Bool che gestisce il while per giocare
	int sel; //variabile generica per selezioni durante il gioco, per scegliere modalit�
	int riga=0,colonna=0; //variabili per input di coordinate nel gioco
	char h; //variabile per continuare dopo cout regole
	int campo[DIM][DIM]; //campo=matrice per il campo da gioco
	int casScoperte[DIM][DIM]; //casScoperte=matrice che indica le caselle coperte, scoperte e le bandiere posizionate
	bool check=true; //Variabile booleana che indica quando interrompere il programma
	srand(time(NULL));
	while(check){
		benvenuto(); //funzione in radicchi.h
		do{
			cin>>sel;
		}while(sel!=1 && sel!=2); //controllo selezione
		switch(sel){
			case 1:{
				system("clear");
				regole();
				cout<<"Inserisci un qualunque valore numerico per cominciare: ";
	 			cin>>sel;
	 			system("clear");
				break;
			}
		 	case 2:{
		 		cout<<"Hai scelto l'opzione gioca. Inserisci un qualunque valore numerico per cominciare: ";
	 			cin>>sel;
	 			system("clear");
	 			for(int i=0;i<DIM;i++){ //inizializzazione matrici con 0
	 				for(int c=0;c<DIM;c++){
	 					campo[i][c]=0;
	 					casScoperte[i][c]=0;
					 }
				 }
				stampaCampo(campo,casScoperte); //funzione in radicchi.h
				cout<<"Inserisci la posizione da cui cominciare, inserendo la riga: ";
				cin>>riga; 
				cout<<"Ora inserisci la colonna: ";
				cin>>colonna;
				system("clear");
				iniziale(riga,colonna,campo,casScoperte);
				inizCampo(campo,casScoperte); //documentazione in librerie
				casScoperte[riga][colonna]=1;
				selScopri(campo,casScoperte);
				stampaCampo(campo,casScoperte);
				while(gioco){ //ciclo che ripete gioco per riga e colonna
					cout<<endl<<endl<<"Inserisci la posizione che vuoi scoprire oppure in cui vuoi posizionare una bandiera. Inserisci la riga: ";
					cin>>riga;
					cout<<"Inserisci la colonna: ";
					cin>>colonna;
					system("clear");
					do{
						cout<<"Inserisci opzione desiderata: \n1- Scopri \n2- Imposta bandiera \n3- Rimuovi bandiera\n";
						cin>>sel;
						if(sel==1 || sel==2 || sel==3){
							posiziona(riga,colonna,sel,campo,gioco,casScoperte,contaB);
							if(!gioco){
								perso(casScoperte,campo);
								stampaCampo(campo,casScoperte);
								break;	
							} 
							stampaCampo(campo,casScoperte);
						} 
						else cout<<"Selezione non valida, riprova"<<endl;
					}while(sel!=1 && sel!=2 && sel!=3);
				}
				gioco=true; //ripristino per un nuovo gioco
				break;
			}
			default:{
				cout<<"Selezione non valida."<<endl;
				break;
			}
		}	
	}
	return 0;
}
