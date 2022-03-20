//Practica 3-LETN 307
//1)Calculadora de Matrices
//Univ. Luis Mauricio Averanga Vergara
//Univ. Kehizzy Jacqueline Griffiths Alba

#include <time.h>
#include <cstdlib>
#include <list>
#include <iostream>
#include <fstream>

using namespace std;

string toStr(int n) {
    switch (n) {
        case 0:
            return "0";
        case 1:
            return "1";
        case 2:
            return "2";
        case 3:
            return "3";
        case 4:
            return "4";
        case 5:
            return "5";
        case 6:
            return "6";
        case 7:
            return "7";
        case 8:
            return "8";
        case 9:
            return "9";
        default:
            return "ERROR";
    }
}
 
string tokenToStr(short int left, short int right) {
    string str = "|" + toStr(left) + "-" + toStr(right) + "|";
    return str;
}

bool canPutLeft(string board, short int tokenN1, short int tokenN2) {
    return (board[1]-0x30==tokenN2);
}

bool canPutRight(string board, short int tokenN1, short int tokenN2) {
    return (board[board.size()-2]-0x30==tokenN1);
}

string putTokenLeft(string board, short int tokenN1, short int tokenN2) {
    return tokenToStr(tokenN1, tokenN2) + board;
}

string putTokenRight(string board, short int tokenN1, short int tokenN2) {
    return board + tokenToStr(tokenN1, tokenN2);
}

void showBoard(short int tokenN1, short int tokenN2, string board, int numCounter, int numStolen) {
	cout <<"\n              JUEGO DEL DOMINO"<<endl;
    cout << board << endl;
    cout << "Fichas colocadas: " << numCounter << " - Fichas robadas: " << numStolen << endl;
    cout << "Ficha jugador: " << tokenToStr(tokenN1, tokenN2) << endl;
    return;
}

int showMenu() {
    int chooseOption = 0;
    
    while (chooseOption < 1 || chooseOption > 3) {
        cout << "Opciones"<< endl;
        cout << "1. Colocar ficha por la izquierda" << endl;
        cout << "2. Colocar ficha por la derecha" << endl;
        cout << "3. Robar ficha nueva" << endl;
        
        cout << "Elija opcion: ";
        cin >> chooseOption;
    }
    
    return chooseOption;
}

short int aleat(int n) {

    return rand()%(n+1);
}

short int chooseMax() {
    int chooseMax = 6;
    return chooseMax;
}

int main(int argc, const char * argv[]) {
    int counter = 0;
    int stolen = 0;
    int max;
    int tokenN1;
    int tokenN2;
    string board;
    srand(time(NULL));

        max = chooseMax();

        tokenN1 = aleat(max);
        tokenN2 = aleat(max);
        board = tokenToStr(aleat(max), aleat(max));
    

    for (int option = 0; option != 4;) {
        showBoard(tokenN1, tokenN2, board, counter, stolen);
        option = showMenu();
        switch(option){
            case 1:
                if (canPutLeft(board, tokenN1, tokenN2)) {
                    board = putTokenLeft(board, tokenN1, tokenN2);
                    tokenN1 = aleat(max);
                    tokenN2 = aleat(max);
                    counter++;
                } else if (canPutLeft(board, tokenN2, tokenN1)) {
                    board = putTokenLeft(board, tokenN2, tokenN1);
                    tokenN1 = aleat(max);
                    tokenN2 = aleat(max);
                    counter++;
                } else {
                    cout << " Error" << endl;
                }
                break;
            case 2:
                if (canPutRight(board, tokenN1, tokenN2)) {
                    board = putTokenRight(board, tokenN1, tokenN2);
                    tokenN1 = aleat(max);
                    tokenN2 = aleat(max);
                    counter++;
                } else if (canPutRight(board, tokenN2, tokenN1)) {
                    board = putTokenRight(board, tokenN2, tokenN1);
                    tokenN1 = aleat(max);
                    tokenN2 = aleat(max);
                    counter++;
                } else {
                    cout << " Error " << endl;
                }
                break;
            case 3:
                tokenN1 = aleat(max);
                tokenN2 = aleat(max);
                stolen++;
                break;
        }
    } 
    return 0;
}