//Practica 3-LETN 307
//1)Calculadora de Matrices
//Univ. Luis Mauricio Averanga Vergara
//Univ. Kehizzy Jacqueline Griffiths Alba

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <windows.h>
#include <cstdlib>
#include <cmath>
using namespace std;
COORD coord;

void gotoxy(int x, int y)
{
	coord.X=x;
	coord.Y=y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

 int main (){
	int MT2[100][100],MT3[100][100],MT4[100][100],L[100][100],U[100][100];
	int f1, c1,f2,c2,opc,u,k,n,m,a,z;
	float aux, pivote, pivote1,deter=1;
	float MA [100][100],I[100][100],MB[100][100],MT[100][100];
	float auxi,pivotei;
	cout <<"Dada la matriz A mXn"<<endl;
	cout <<"Introduzca el numero de filas: ";
	cin >>f1;
	cout <<"Introduzca el numero de columnas: ";
	cin >>c1;
	
	cout <<"Introduzca el valor para los puestos en la matriz:"<<endl;
	for (int i=0; i<f1;i++){
		for (int j=0;j<c1;j++){
			gotoxy(4+j*4,5+i);
			cin>>a;
			MA[i][j]=a; 
		
		}
	}
	
	cout <<"\nQue operacion desea calcular:\n"<<endl;
	cout <<"1. aXb"<<endl;
	cout <<"2. bXa"<<endl;
	cout <<"3. a+b"<<endl;
	cout <<"4. a-b"<<endl;
	cout <<"5. Determinante de A"<<endl;
	cout <<"6. Matriz inversa"<<endl;
	cout <<"7. Matriz transpuesta"<<endl;
	cout <<"8. Division de matrices (A*B^-1)"<<endl;
	cout <<"9. Multiplicar por k"<<endl;
	cout <<"10. Matriz elevada a n"<<endl;
	cout <<"11. Matriz triangular"<<endl;
	cout <<"\nCual opcion desea elegir: ";
	cin >>opc;
	cout <<"\n";
	switch (opc){
		case 1:{
			cout <<"Dada la matriz B jXk"<<endl;
			cout <<"Introduzca el numero de filas: ";
			cin >>f2;
			cout <<"Introduzca el numero de columnas: ";
			cin >>c2;
			cout <<"Introduzca el valor para los puestos en la matriz:"<<endl;
			for (int i=0; i<f2;i++){
			for (int j=0;j<c2;j++){
			gotoxy(4+j*4,30+i);
			cin>>a;
			MB[i][j]=a;	
				}
			}
		
			if (c1==f2){
				for (int i=0; i<f1;i++){
				for (int j=0; j<c2;j++){
					MT[i][j]=0;
					}
				}
				u=c1;
				for (int i=0; i<f1;i++){
				for (int j=0; j<c2;j++){
				for (int k=0; k<u;k++){
				MT[i][j] += MA[i][k]*MB[k][j];
						}
					}
				}
				cout<<"\n La matriz resultante sera:\n";
				for (int i=0; i<f1;i++){
				for (int j=0;j<c2;j++){
				cout <<"    "<< MT [i][j]<<"  ";
					}
				cout <<"\n";	
					}
				}
			else {
				cout<<"Las matrices A y B son de tamaños distintos, no pueden multiplicarse";
			}
			break;
			}
		case 2:{
			cout <<"Dada la matriz B jXk"<<endl;
			cout <<"Introduzca el numero de filas: ";
			cin >>f2;
			cout <<"Introduzca el numero de columnas: ";
			cin >>c2;
			cout <<"Introduzca el valor para los puestos en la matriz:"<<endl;
			for (int i=0; i<f2;i++){
			for (int j=0;j<c2;j++){
			gotoxy(4+j*4,30+i);
			cin>>a;
			MB[i][j]=a;	
				}
			}
		
			if (c2==f1){
				for (int i=0; i<f2;i++){
				for (int j=0; j<c1;j++){
					MT[i][j]=0;
					}
				}
				u=c2;
				for (int i=0; i<f2;i++){
				for (int j=0; j<c1;j++){
				for (int k=0; k<u;k++){
				MT[i][j] += MB[i][k]*MA[k][j];
						}
					}
				}
				cout<<"\n La matriz resultante sera: \n";
				for (int i=0; i<f2;i++){
				for (int j=0;j<c1;j++){
				cout <<"    "<< MT [i][j]<<"  ";
					}
				cout <<"\n";	
					}
				}
			else {
				cout<<"Las matrices A y B son de tamaños distintos, no pueden multiplicarse";
			}
			break;
			}
		case 3:{
			cout <<"Dada la matriz B jXk"<<endl;
			cout <<"Introduzca el numero de filas: ";
			cin >>f2;
			cout <<"Introduzca el numero de columnas: ";
			cin >>c2;
			cout <<"Introduzca el valor para los puestos en la matriz:"<<endl;
			for (int i=0; i<f2;i++){
			for (int j=0;j<c2;j++){
			gotoxy(4+j*4,30+i);
			cin>>a;
			MB[i][j]=a;	
				}
			}
			if (f1==f2){
				if (c1==c2){
						n=f1;
						m=c1;
					for (int i=0; i<n;i++){
					for (int j=0;j<m;j++){
					MT[i][j]=MA[i][j]+MB[i][j];
						}
					}
					cout<<"\n La matriz resultante sera: \n";
					for (int i=0; i<n;i++){
					for (int j=0;j<m;j++){
					cout <<"    "<< MT [i][j]<<"  ";
						}
					cout <<"\n";	
						}
					}
				else {
					cout<<"Las matrices A y B son de tamaños distintos, no pueden sumarse";
				}
				}
			else {
				cout<<"Las matrices A y B son de tamaños distintos, no pueden sumarse";
			}
			break;
			}
		case 4:{
			cout <<"Dada la matriz B jXk"<<endl;
			cout <<"Introduzca el numero de filas: ";
			cin >>f2;
			cout <<"Introduzca el numero de columnas: ";
			cin >>c2;
			cout <<"Introduzca el valor para los puestos en la matriz:"<<endl;
			for (int i=0; i<f2;i++){
			for (int j=0;j<c2;j++){
			gotoxy(4+j*4,30+i);
			cin>>a;
			MB[i][j]=a;	
				}
			}
			if (f1==f2){
				if (c1==c2){
						n=f1;
						m=c1;
					for (int i=0; i<n;i++){
					for (int j=0;j<m;j++){
					MT[i][j]=MA[i][j]-MB[i][j];
						}
					}
					cout<<"\n La matriz resultante sera: \n";
					for (int i=0; i<n;i++){
					for (int j=0;j<m;j++){
					cout <<"    "<< MT [i][j]<<"  ";
						}
					cout <<"\n";	
						}
					}
				else {
					cout<<"Las matrices A y B son de tamaños distintos, no pueden sumarse";
				}
				}
			else {
				cout<<"Las matrices A y B son de tamaños distintos, no pueden sumarse";
			}
			break;
			}
		case 5:{
			if (f1==c1){ 
				for (int i=0; i<f1; i++){
				pivote=MA[i][i];
				for (int j=i+1; j<c1; j++){
				pivote1=MA[j][i];  
			    aux=pivote1/pivote;  
			    for (k=0; k<c1; k++){
				MA[j][k]=MA[j][k]-aux*MA[i][k];  
			   			}
		    		}
	    		}
				for (int i=0; i<f1; i++){
				for (int j=0; j<c1; j++){
			    cout<<MA[i][j]<<"    ";
						}
					cout <<"\n";
	    		}
				for (int i=0; i<f1; i++) 
				{
				deter*=MA[i][i];  
	    		}
				cout<<"\n\nLa determinante de la matriz es: "<<deter<<endl;	
				}
			else{
				cout<<"\nLa matriz no es cuadrada por lo que no tiene determinante "<<endl;
				}	
				break;
			}
		case 6:{
			if (f1==c1)	{
				for (int i=0; i<f1; i++){
				for (int j=0; j<c1; j++){
				I[i][j]=0;
				if (i==j){
					I[i][j]=1;
						}
					}
				}
				for(int i=0; i<f1; i++){
				pivotei=MA[i][i];
				for (k=0; k<c1; k++){
				MA[i][k]=MA[i][k]/pivotei;
				I[i][k]=I[i][k]/pivotei;
				}
				for (int j=0; j<c1; j++){
				if(i!=j){
					auxi=MA[j][i];
					for (int k=0; k<c1; k++){
					MA[j][k]=MA[j][k]-auxi*MA[i][k];
					I[j][k]=I[j][k]-auxi*I[i][k];
							}	
						}
					}
				}
				for (int i=0; i<f1; i++){
				for (int j=0; j<c1; j++){
				cout<<"    "<<I[i][j]<<" ";
				}
				cout <<"\n";
				}
				}
			else{
				cout<<"\nLa matriz no es cuadrada por lo que no tiene inversa "<<endl;	
			}	
			break;
			}
		case 7:{
			for (int i=0; i<f1;i++){
			for (int j=0; j<c1;j++){
			MT[j][i]=MA[i][j];
				}
			}
			cout<<"\nLa matriz transpuesta sera: \n";
			for (int i=0; i<c1;i++){
			for (int j=0;j<f1;j++){
			cout <<"    "<< MT [i][j]<<"  ";
				}
			cout <<"\n";	
					}
			break;
			}
		case 8:{
				cout <<"Dada la matriz B jXk"<<endl;
				cout <<"Introduzca el numero de filas: ";
				cin >>f2;
				cout <<"Introduzca el numero de columnas: ";
				cin >>c2;
				cout <<"Introduzca el valor para los puestos en la matriz:"<<endl;
				for (int i=0; i<f2;i++){
				for (int j=0;j<c2;j++){
				gotoxy(4+j*4,30+i);
				cin>>a;
				MB[i][j]=a;	
					}
				}
			if (f2==c2)	{
				for (int i=0; i<f2; i++){
				for (int j=0; j<c2; j++){
				I[i][j]=0;
				if (i==j){
					I[i][j]=1;
						}
					}
				}
				for(int i=0; i<f2; i++){
				pivotei=MB[i][i];
				for (k=0; k<c2; k++){
				MB[i][k]=MB[i][k]/pivotei;
				I[i][k]=I[i][k]/pivotei;
				}
				for (int j=0; j<c2; j++){
				if(i!=j){
					auxi=MB[j][i];
					for (int k=0; k<c2; k++){
					MB[j][k]=MB[j][k]-auxi*MB[i][k];
					I[j][k]=I[j][k]-auxi*I[i][k];
							}	
						}
					}
				}
				cout <<"La matriz inversa de B sera:"<<endl;
				for (int i=0; i<f2; i++){
				for (int j=0; j<c2; j++){
				cout<<"    "<<I[i][j]<<" ";
				}
				cout <<"\n";
				}
				}
			else{
				cout<<"\nLa matriz no es cuadrada por lo que no tiene inversa "<<endl;	
			}	
			if (c1==f2){
				for (int i=0; i<f1;i++){
				for (int j=0; j<c2;j++){
					MT[i][j]=0;
					}
				}
				u=c1;
				for (int i=0; i<f1;i++){
				for (int j=0; j<c2;j++){
				for (int k=0; k<u;k++){
				MT[i][j] += MA[i][k]*I[k][j];
						}
					}
				}
				cout<<"\n La matriz resultante sera:\n";
				for (int i=0; i<f1;i++){
				for (int j=0;j<c2;j++){
				cout <<"    "<< MT [i][j]<<"  ";
					}
				cout <<"\n";	
					}
				}
			else {
				cout<<"Las matrices A y B son de tamaños distintos, no pueden multiplicarse";
			}
			break;
			}
		case 9:{
			cout <<"Introducir el valor de k: ";
			cin >>k; 
			for (int i=0; i<f1;i++){
			for (int j=0;j<c1;j++){
			MA[i][j]= k*MA[i][j];
				}
			}
			for (int i=0; i<f1;i++){
			for (int j=0;j<c1;j++){
			cout << MA [i][j]<<"    ";
			}
			cout <<"\n";
			}
			break;
			}
		case 10:{
			if (f1==c1){
				cout <<"Introduzca el valor de n: ";
				cin >>n;
				switch (n){
					case 1:{		
						cout<<"\nLa matriz elevada a "<<n<<" sera: \n"<<endl;
						for (int i=0; i<f1;i++){
						for (int j=0;j<c1;j++){
						cout << MA [i][j]<<"    ";
							}
						cout <<"\n";	
							}
						break;
						}
					case 2:{		
						for (int i=0; i<c1;i++){
						for (int j=0; j<f1;j++){
						MT[i][j]=0;
							}
						}
						u=c1;
						for (int i=0; i<f1;i++){
						for (int j=0; j<c1;j++){
						for (int k=0; k<u;k++){
						MT[i][j] += MA[i][k]*MA[k][j];
								}
							}
						}
						cout<<"\nLa matriz elevada a "<<n<<" sera: \n"<<endl;
						for (int i=0; i<f1;i++){
						for (int j=0;j<c1;j++){
						cout << MT [i][j]<<"    ";
							}
						cout <<"\n";	
							}
						break;
						}
					case 3:{		
						for (int i=0; i<c1;i++){
						for (int j=0; j<f1;j++){
						MT[i][j]=0;
							}
						}
						u=c1;
						for (int i=0; i<f1;i++){
						for (int j=0; j<c1;j++){
						for (int k=0; k<u;k++){
						MT[i][j] += MA[i][k]*MA[k][j];
								}
							}
						}
						for (int i=0; i<f1;i++){
						for (int j=0; j<c1;j++){
						for (int k=0; k<u;k++){
						MT2[i][j] += MT[i][k]*MA[k][j];
								}
							}
						}
						cout<<"\nLa matriz elevada a "<<n<<" sera: \n"<<endl;
						for (int i=0; i<f1;i++){
						for (int j=0;j<c1;j++){
						cout << MT2 [i][j]<<"    ";
							}
						cout <<"\n";	
							}
						break;
						}
					case 4:{		
						for (int i=0; i<c1;i++){
						for (int j=0; j<f1;j++){
						MT[i][j]=0;
							}
						}
						u=c1;
						for (int i=0; i<f1;i++){
						for (int j=0; j<c1;j++){
						for (int k=0; k<u;k++){
						MT[i][j] += MA[i][k]*MA[k][j];
								}
							}
						}
						for (int i=0; i<f1;i++){
						for (int j=0; j<c1;j++){
						for (int k=0; k<u;k++){
						MT2[i][j] += MT[i][k]*MA[k][j];
								}
							}
						}
						for (int i=0; i<f1;i++){
						for (int j=0; j<c1;j++){
						for (int k=0; k<u;k++){
						MT3[i][j] += MT2[i][k]*MA[k][j];
								}
							}
						}
						cout<<"\nLa matriz elevada a "<<n<<" sera: \n"<<endl;
						for (int i=0; i<f1;i++){
						for (int j=0;j<c1;j++){
						cout << MT3 [i][j]<<"    ";
							}
						cout <<"\n";	
							}
						break;
						}
					case 5:{		
						for (int i=0; i<c1;i++){
						for (int j=0; j<f1;j++){
						MT[i][j]=0;
							}
						}
						u=c1;
						for (int i=0; i<f1;i++){
						for (int j=0; j<c1;j++){
						for (int k=0; k<u;k++){
						MT[i][j] += MA[i][k]*MA[k][j];
								}
							}
						}
						for (int i=0; i<f1;i++){
						for (int j=0; j<c1;j++){
						for (int k=0; k<u;k++){
						MT2[i][j] += MT[i][k]*MA[k][j];
								}
							}
						}
						for (int i=0; i<f1;i++){
						for (int j=0; j<c1;j++){
						for (int k=0; k<u;k++){
						MT3[i][j] += MT2[i][k]*MA[k][j];
								}
							}
						}
						for (int i=0; i<f1;i++){
						for (int j=0; j<c1;j++){
						for (int k=0; k<u;k++){
						MT4[i][j] += MT3[i][k]*MA[k][j];
								}
							}
						}
						cout<<"\nLa matriz elevada a "<<n<<" sera: \n"<<endl;
						for (int i=0; i<f1;i++){
						for (int j=0;j<c1;j++){
						cout << MT4 [i][j]<<"    ";
							}
						cout <<"\n";	
							}
						break;
						}
					}
				}
			else {
				cout<<"Debe ser una matriz cuadrada para realizar la operacion";
			}
			break;
			}
		case 11:{
				if (f1==c1){ 
				for (int i=0; i<f1; i++){
				pivote=MA[i][i];
				for (int j=i+1; j<c1; j++){
				pivote1=MA[j][i];  
			    aux=pivote1/pivote;  
			    for (k=0; k<c1; k++){
				MA[j][k]=MA[j][k]-aux*MA[i][k];  
			   			}
		    		}
	    		}
	    		cout <<"La Matriz triangular sera:"<<endl;
				for (int i=0; i<f1; i++){
				for (int j=0; j<c1; j++){
			    cout<<MA[i][j]<<"    ";
						}
					cout <<"\n";
	    		}
	    	}
			else{
				cout<<"\nLa matriz no es cuadrada  "<<endl;
				}	
				break;
		}
		}	 	 	
 }
