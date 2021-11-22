#include <iostream>
#include <cstdlib>
#include <iomanip>
using namespace std;
const int DIM=16; //Dimensione del campo da gioco
const int NMINE=40; //Numero di mine

void benvenuto(){
	//system("color 3");
	
	cout<<" _ __                   _____              "<<endl;
	//Sleep(100);
	cout<<"' )  )        _/_        /  '         _/_  "<<endl;
	//Sleep(100);
	cout<<" /--'__  __.  /  __   ,-/-,o __ __  o /  __"<<endl;
	//Sleep(100);
	cout<<"/   / (_(_/|_<__(_)  (_/  <_(_)/ (_<_<__(_)"<<endl<<endl<<endl;
	//Sleep(100);
	cout<<"Inserisci l'opzione desiderata: "<<endl<<endl;
	//Sleep(100);
	cout<<"1- Regole"<<endl;
	cout<<"2- Gioca"<<endl;
}

void regole(){
	cout<<"Regole prato fiorito: \n"<<endl;
	cout<<"Il campo e' composto da 256 posizioni. In modo randomico vengono posizionate 40 mine. \nAll'inzio del gioco, inserisci una posizione, tramite riga e colonna. Verrano indicate le distanze tra i vari punti scoperti delle bombe vicine. \nDopo aver selezionato la posizione, potrai scegliere se scoprire la casella o inserire una bandiera, in presenza di una bomba. \n\nLo scopo del gioco e' scoprire tutto il campo senza scoprire le mine."<<endl;
}
bool confronto(int v[], int pos){ //Funzione che verifica che il nuovo numero dell'array non sia gi� comparso
	if(pos==0) return true; //Se la posizione vale 0 viene ritornato il valore true
	else{ //Se no parte un ciclo for che va a confrontare tutti i precedenti numeri con l'ultimo
		for(int i=pos-1; i>=0; i--){
			if(v[i]==v[pos]) return false;
		}
		return true;
	}
}

void riempimento(int campo[][DIM], int riga, int col){ //Funzione di assegnazione dei numeri alle caselle
	if(riga==0){ //Caso in cui la casella sia nella prima riga
		if(col==0){ //Caso dell'angolo in alto a sinistra
			if(campo[riga][col]==9){ //Se su una casella c'� una mina(9) viene incrementato di 1 il valore di tutte le caselle adiacenti non mine
				if(campo[riga][col+1]!=9) campo[riga][col+1]++;
				if(campo[riga+1][col+1]!=9) campo[riga+1][col+1]++;
				if(campo[riga+1][col]!=9) campo[riga+1][col]++;
			}
		}
		else if(col==DIM-1){ //Caso dell'angolo in alto a destra
			if(campo[riga][col]==9){ //Se su una casella c'� una mina(9) viene incrementato di 1 il valore di tutte le caselle adiacenti non mine
				if(campo[riga+1][col]!=9) campo[riga+1][col]++;
				if(campo[riga+1][col-1]!=9) campo[riga+1][col-1]++;
				if(campo[riga][col-1]!=9) campo[riga][col-1]++;
			}
		}
		else{
			if(campo[riga][col]==9){ //Se su una casella c'� una mina(9) viene incrementato di 1 il valore di tutte le caselle adiacenti non mine
				if(campo[riga][col+1]!=9) campo[riga][col+1]++;
				if(campo[riga+1][col+1]!=9) campo[riga+1][col+1]++;
				if(campo[riga+1][col]!=9) campo[riga+1][col]++;
				if(campo[riga+1][col-1]!=9) campo[riga+1][col-1]++;
				if(campo[riga][col-1]!=9) campo[riga][col-1]++;
			}
		}
	}
	else if(riga==DIM-1){ //Caso in cui la riga sia l'ultima
		if(col==0){ //Caso dell'angolo in basso a sinistra
			if(campo[riga][col]==9){ //Se su una casella c'� una mina(9) viene incrementato di 1 il valore di tutte le caselle adiacenti non mine
				if(campo[riga-1][col]!=9) campo[riga-1][col]++;
				if(campo[riga-1][col+1]!=9) campo[riga-1][col+1]++;
				if(campo[riga][col+1]!=9) campo[riga][col+1]++;
			}
		}
		else if(col==DIM-1){ //Caso dell'angolo in basso a destra
			if(campo[riga][col]==9){ //Se su una casella c'� una mina(9) viene incrementato di 1 il valore di tutte le caselle adiacenti non mine
				if(campo[riga-1][col]!=9) campo[riga-1][col]++;
				if(campo[riga][col-1]!=9) campo[riga][col-1]++;
				if(campo[riga-1][col-1]!=9) campo[riga-1][col-1]++;
			}
		}
		else{
			if(campo[riga][col]==9){ //Se su una casella c'� una mina(9) viene incrementato di 1 il valore di tutte le caselle adiacenti non mine
				if(campo[riga-1][col]!=9) campo[riga-1][col]++;
				if(campo[riga-1][col+1]!=9) campo[riga-1][col+1]++;
				if(campo[riga][col+1]!=9) campo[riga][col+1]++;
				if(campo[riga][col-1]!=9) campo[riga][col-1]++;
				if(campo[riga-1][col-1]!=9) campo[riga-1][col-1]++;
			}
		}
	}
	else if(col==0){ //Caso in cui la colonna sia la prima
		if(campo[riga][col]==9){ //Se su una casella c'� una mina(9) viene incrementato di 1 il valore di tutte le caselle adiacenti non mine
			if(campo[riga-1][col]!=9) campo[riga-1][col]++;
			if(campo[riga-1][col+1]!=9) campo[riga-1][col+1]++;
			if(campo[riga][col+1]!=9) campo[riga][col+1]++;
			if(campo[riga+1][col+1]!=9) campo[riga+1][col+1]++;
			if(campo[riga+1][col]!=9) campo[riga+1][col]++;
		}
	}
	else if(col==DIM-1){ //Caso in cui la colonna sia l'ultima
		if(campo[riga][col]==9){ //Se su una casella c'� una mina(9) viene incrementato di 1 il valore di tutte le caselle adiacenti non mine
			if(campo[riga-1][col]!=9) campo[riga-1][col]++;
			if(campo[riga+1][col]!=9) campo[riga+1][col]++;
			if(campo[riga+1][col-1]!=9) campo[riga+1][col-1]++;
			if(campo[riga][col-1]!=9) campo[riga][col-1]++;
			if(campo[riga-1][col-1]!=9) campo[riga-1][col-1]++;
		}
	}
	else{ //Caso in cui la casella sia centrale
		if(campo[riga][col]==9){ //Se su una casella c'� una mina(9) viene incrementato di 1 il valore di tutte le caselle adiacenti non mine
			if(campo[riga-1][col]!=9) campo[riga-1][col]++;
			if(campo[riga-1][col+1]!=9) campo[riga-1][col+1]++;
			if(campo[riga][col+1]!=9) campo[riga][col+1]++;
			if(campo[riga+1][col+1]!=9) campo[riga+1][col+1]++;
			if(campo[riga+1][col]!=9) campo[riga+1][col]++;
			if(campo[riga+1][col-1]!=9) campo[riga+1][col-1]++;
			if(campo[riga][col-1]!=9) campo[riga][col-1]++;
			if(campo[riga-1][col-1]!=9) campo[riga-1][col-1]++;
		}
	}
}

void inizCampo(int campo[][DIM], int casScoperte[][DIM]){ //Funzione che genera il campo iniziale
	int mine[NMINE];
	for(int i=0; i<DIM; i++){ //Inizializzazione di tutte le caselle al valore 0
		for(int j=0; j<DIM; j++) campo[i][j]=0;
	}
	for(int i=0; i<NMINE; i++){ //Generazione delle posizioni delle mine
		do{
			mine[i]=rand()%(DIM*DIM);
		}while(confronto(mine,i)==false || casScoperte[mine[i]/DIM][mine[i]%16]==3);
	}
	for(int i=0; i<NMINE; i++) campo[mine[i]/DIM][mine[i]%DIM]=9; //Assegnazione delle mine(9) nelle relative posizioni
	for(int i=0; i<DIM; i++){ //Ciclo che ripete la funzione di riempimento su tutte le caselle
		for(int j=0; j<DIM; j++) riempimento(campo,i,j);
	}
	for(int i=0; i<DIM; i++){ //Ciclo che inizializza tutte le caselle della matrice casScoperte a 0(casella coperta)
		for(int j=0; j<DIM; j++) casScoperte[i][j]=0;
	}
}

void stampaCampo(int campo[][DIM], int casScoperte[][DIM]){ //Funzione che stampa il campo
	cout<<"    ";
	for(int i=1;i<=DIM;i++) cout<<setw(4)<<i;
	cout<<endl;
	for(int i=0; i<DIM; i++){ //Stampa del campo
		cout<<setw(4)<<i+1;
		for(int j=0; j<DIM; j++){
			cout<<" | ";
			if(casScoperte[i][j]==2) cout<<"F"; //Se lamatrice casScoperte nelle relative coordinate vale 2(bandiera) stampa la bandiera
			else if(casScoperte[i][j] == 1 && campo[i][j] == 0) cout<<"X"; //se casScoperte è 1 (casella scoperta) e campo è 0 (nessuna bomba vicina) stampa X
			else if((casScoperte[i][j]==1) && campo[i][j]!=0) cout<<campo[i][j]; //Altrimenti se vale 1(casella scoperta) e nella casella in campo non c'� 0
			else if(casScoperte[i][j]==9) cout<<"B";
			else cout<<" "; //Altrimenti stampa una casella vuota
		}
		cout<<" | "<<endl<<endl;
	}
}

void scopri(int casScoperte[][DIM], int riga, int col){
	if(riga==0){ //Caso in cui la casella sia nella prima riga
		if(col==0){ //Caso dell'angolo in alto a sinistra
			casScoperte[riga][col+1]=1;
			casScoperte[riga+1][col+1]=1;
			casScoperte[riga+1][col]=1;
		}
		else if(col==DIM-1){ //Caso dell'angolo in alto a destra
			casScoperte[riga+1][col]=1;
			casScoperte[riga+1][col-1]=1;
			casScoperte[riga][col-1]=1;
		}
		else{
			casScoperte[riga][col+1]=1;
			casScoperte[riga+1][col+1]=1;
			casScoperte[riga+1][col]=1;
			casScoperte[riga+1][col-1]=1;
			casScoperte[riga][col-1]=1;
		}
	}
	else if(riga==DIM-1){ //Caso in cui la riga sia l'ultima
		if(col==0){ //Caso dell'angolo in basso a sinistra
			casScoperte[riga-1][col]=1;
			casScoperte[riga-1][col+1]=1;
			casScoperte[riga][col+1]=1;
		}
		else if(col==DIM-1){ //Caso dell'angolo in basso a destra
			casScoperte[riga-1][col]=1;
			casScoperte[riga][col-1]=1;
			casScoperte[riga-1][col-1]=1;
		}
		else{
			casScoperte[riga-1][col]=1;
			casScoperte[riga-1][col+1]=1;
			casScoperte[riga][col+1]=1;
			casScoperte[riga][col-1]=1;
			casScoperte[riga-1][col-1]=1;
		}
	}
	else if(col==0){ //Caso in cui la colonna sia la prima
		casScoperte[riga-1][col]=1;
		casScoperte[riga-1][col+1]=1;
		casScoperte[riga][col+1]=1;
		casScoperte[riga+1][col+1]=1;
		casScoperte[riga+1][col]=1;
	}
	else if(col==DIM-1){ //Caso in cui la colonna sia l'ultima
		casScoperte[riga-1][col]=1;
		casScoperte[riga+1][col]=1;
		casScoperte[riga+1][col-1]=1;
		casScoperte[riga][col-1]=1;
		casScoperte[riga-1][col-1]=1;
	}
	else{ //Caso in cui la casella sia centrale
		casScoperte[riga-1][col]=1;
		casScoperte[riga-1][col+1]=1;
		casScoperte[riga][col+1]=1;
		casScoperte[riga+1][col+1]=1;
		casScoperte[riga+1][col]=1;
		casScoperte[riga+1][col-1]=1;
		casScoperte[riga][col-1]=1;
		casScoperte[riga-1][col-1]=1;
	}
}

bool cond(int casScoperte[][DIM], int riga, int col){
	if(casScoperte[riga][col]==1 || casScoperte[riga][col]==3){
		if(riga==0){ //Caso in cui la casella sia nella prima riga
			if(col==0){ //Caso dell'angolo in alto a sinistra
				if(casScoperte[riga][col+1]!=1 && casScoperte[riga][col+1]!=3) return true;
				if(casScoperte[riga+1][col+1]!=1 && casScoperte[riga+1][col+1]!=3) return true;
				if(casScoperte[riga+1][col]!=1 && casScoperte[riga+1][col]!=3) return true;
			}
			else if(col==DIM-1){ //Caso dell'angolo in alto a destra
				if(casScoperte[riga+1][col]!=1 && casScoperte[riga+1][col]!=3) return true;
				if(casScoperte[riga+1][col-1]!=1 && casScoperte[riga+1][col-1]!=3) return true;
				if(casScoperte[riga][col-1]!=1 && casScoperte[riga][col-1]!=3) return true;
			}
			else{
				if(casScoperte[riga][col+1]!=1 && casScoperte[riga][col+1]!=3) return true;
				if(casScoperte[riga+1][col+1]!=1 && casScoperte[riga+1][col+1]!=3) return true;
				if(casScoperte[riga+1][col]!=1 && casScoperte[riga+1][col]!=3) return true;
				if(casScoperte[riga+1][col-1]!=1 && casScoperte[riga+1][col-1]!=3) return true;
				if(casScoperte[riga][col-1]!=1 && casScoperte[riga][col-1]!=3) return true;
			}
		}
		else if(riga==DIM-1){ //Caso in cui la riga sia l'ultima
			if(col==0){ //Caso dell'angolo in basso a sinistra
				if(casScoperte[riga-1][col]!=1 && casScoperte[riga-1][col]!=3) return true;
				if(casScoperte[riga-1][col+1]!=1 && casScoperte[riga-1][col+1]!=3) return true;
				if(casScoperte[riga][col+1]!=1 && casScoperte[riga][col+1]!=3) return true;
			}
			else if(col==DIM-1){ //Caso dell'angolo in basso a destra
				if(casScoperte[riga-1][col]!=1 && casScoperte[riga-1][col]!=3) return true;
				if(casScoperte[riga][col-1]!=1 && casScoperte[riga][col-1]!=3) return true;
				if(casScoperte[riga-1][col-1]!=1 && casScoperte[riga-1][col-1]!=3) return true;
			}
			else{
				if(casScoperte[riga-1][col]!=1 && casScoperte[riga-1][col]!=3) return true;
				if(casScoperte[riga-1][col+1]!=1 && casScoperte[riga-1][col+1]!=3) return true;
				if(casScoperte[riga][col+1]!=1 && casScoperte[riga][col+1]!=3) return true;
				if(casScoperte[riga][col-1]!=1 && casScoperte[riga][col-1]!=3) return true;
				if(casScoperte[riga-1][col-1]!=1 && casScoperte[riga-1][col-1]!=3) return true;
			}
		}
		else if(col==0){ //Caso in cui la colonna sia la prima
			if(casScoperte[riga-1][col]!=1 && casScoperte[riga-1][col]!=3) return true;
			if(casScoperte[riga-1][col+1]!=1 && casScoperte[riga-1][col+1]!=3) return true;
			if(casScoperte[riga][col+1]!=1 && casScoperte[riga][col+1]!=3) return true;
			if(casScoperte[riga+1][col+1]!=1 && casScoperte[riga+1][col+1]!=3) return true;
			if(casScoperte[riga+1][col]!=1 && casScoperte[riga+1][col]!=3) return true;
		}
		else if(col==DIM-1){ //Caso in cui la colonna sia l'ultima
			if(casScoperte[riga-1][col]!=1 && casScoperte[riga-1][col]!=3) return true;
			if(casScoperte[riga+1][col]!=1 && casScoperte[riga+1][col]!=3) return true;
			if(casScoperte[riga+1][col-1]!=1 && casScoperte[riga+1][col-1]!=3) return true;
			if(casScoperte[riga][col-1]!=1 && casScoperte[riga][col-1]!=3) return true;
			if(casScoperte[riga-1][col-1]!=1 && casScoperte[riga-1][col-1]!=3) return true;
		}
		else{ //Caso in cui la casella sia centrale
			if(casScoperte[riga-1][col]!=1 && casScoperte[riga-1][col]!=3) return true;
			if(casScoperte[riga-1][col+1]!=1 && casScoperte[riga-1][col+1]!=3) return true;
			if(casScoperte[riga][col+1]!=1 && casScoperte[riga][col+1]!=3) return true;
			if(casScoperte[riga+1][col+1]!=1 && casScoperte[riga+1][col+1]!=3) return true;
			if(casScoperte[riga+1][col]!=1 && casScoperte[riga+1][col]!=3) return true;
			if(casScoperte[riga+1][col-1]!=1 && casScoperte[riga+1][col-1]!=3) return true;
			if(casScoperte[riga][col-1]!=1 && casScoperte[riga][col-1]!=3) return true;
			if(casScoperte[riga-1][col-1]!=1 && casScoperte[riga-1][col-1]!=3) return true;
		}
	}
	return false;
}

void selScopri(int campo[][DIM], int casScoperte[][DIM]){
	for(int i=0; i<DIM; i++){
		for(int j=0; j<DIM; j++){
			if(campo[i][j]==0 && cond(casScoperte,i,j)==true){
				scopri(casScoperte,i,j);
				selScopri(campo,casScoperte);
			}
		}
	}
}

void stampa(int matrice[][16]){ //funzione usata per debug
	for(int i=0;i<16;i++){
		for(int c=0;c<16;c++){
			cout<<matrice[i][c]<<" ";
		}
		cout<<endl;
	}
}

void iniziale(int &riga, int &colonna,int campo[][16],int casScoperte[][16]){ //definisce quadrato inziale
	while(riga <0 || riga>16 || colonna<0 || colonna>16){
		cout<<"Selezione non valida, inserisci riga: ";
		cin>>riga;
		cout<<"Inserisci colonna: ";
		cin>>colonna;
	}
	riga--;
	colonna--;
	if(riga-3<0) riga=2;
	if(colonna-3<0) colonna=2;	
	for(int i=0;i<4;i++){
		for(int c=0;c<4;c++){
			casScoperte[riga-i+1][colonna-c+1]=3;
		}
	}
}

void posiziona(int riga,int colonna,int sel,int campo[][16],bool &gioco,int casScoperte[][16],int &contaB){ //funzione per assegnare, secondo la selezione fatta, la bandiera o una casella scoperta nella posizione indicata
	riga--;
	colonna--;
	if(sel==1){
		if(casScoperte[riga][colonna]==3 || casScoperte[riga][colonna]==1){
			cout<<"Impossibile scoprire."<<endl;
		}
		else if(campo[riga][colonna]==9){ //se nella casella c'� una mina giocatore perde
			system("clear");
			//perso(casScoperte,campo);
			gioco=false;
		}
		else{
			cout<<"La posizione e' stata scoperta."<<endl; //altrimenti posizione scoperta
			casScoperte[riga][colonna]=1;
			selScopri(campo,casScoperte); //da sistemare
		}
	}
	else if(sel==2){
		if(contaB<40){
			casScoperte[riga][colonna]=2; //se possibile, aggiungo bandiera
			contaB++;
		}else cout<<"Numero massimo bandiere raggiunto."<<endl;
	}
	else if(sel==3){
		casScoperte[riga][colonna]=0; //se possibile, rimuovo bandiera
		contaB--;
	}
}

void perso(int casScoperte[][16],int campo[][16]){ //messaggio finale se gioc perde
	system("clear");
	cout<<"Hai perso."<<endl;
	for(int i=0;i<16;i++){
		for(int c=0;c<16;c++){
			if(campo[i][c]==9) casScoperte[i][c]=9;
		}
	}
}
