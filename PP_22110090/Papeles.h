#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string>
#include <time.h>
using namespace std;

class Pasaporte{
public:
	Pasaporte();
	void Get();
	string aux;
	string datosp[8][10];
	int z; int k; int q; int i; int j;
	string temp; string texto;
	string case1(string temp, int ronda);
	string case3(string temp, int ronda);
	string case4(string temp, int ronda);
};
Pasaporte::Pasaporte(){	
	z = 0; k = 0; q = 0; i = 0; j = 0;
}

void Pasaporte::Get() {
	i = 0; j = 0;
	ifstream archivo;
	archivo.open("Datos.txt", ios::in);
	if (archivo.fail()) {
		std::cout << "ERROR al abrir el archivo" << endl;
		std::system("pause");
		exit(0);
	}
	while (!archivo.eof()) {
		getline(archivo, texto);
		datosp[i][j] = texto;
		i++;
		if (i == 7) { i = 0; j++; }
	}
	archivo.close();
}
string Pasaporte::case1(string temp, int ronda) {
	temp = datosp[z][ronda];
	z++;
	if (z == 7) { z = 0; }
	return string(temp);
}
string Pasaporte::case3(string temp, int ronda) {
	if (z==0){
		srand(time(NULL));
		int dato2 = 0 + rand() % (3);
		k = dato2;
		srand(time(NULL));
		int dato25 = 1 + rand() % (9);
		q = dato25;
	}
	if (z != k) {temp = datosp[z][ronda];
	}if(z==k) {	temp = datosp[z][q];
	}
	z++;
	if (z == 7) { z = 0; }
	return string(temp);
}
string Pasaporte::case4(string temp, int ronda) {
	if (z==0){
		srand(time(NULL));
		int dato3 = 0 + rand() % (6);
		k = dato3;
		srand(time(NULL));
		int dato35 = 1 + rand() % (9);
		q = dato35;
	}
	if (z != k) {	temp = datosp[z][ronda];
	}else {	temp = datosp[z][q];
	}
	z++;
	if (z == 7) { z = 0; }
	return string(temp);
}

class INE{
public:
	INE();
	void lectura();
	string send(string temp, int ronda);
	string datos[8][10];
	string texto;
	int i;
	int j;
	int z;
};
INE::INE(){i = 0; j = 0; z = 0;}
void INE::lectura() {
	i = 0; j = 0;
	ifstream archivo;
	archivo.open("Datos.txt", ios::in);
	if (archivo.fail()) { 
		std::cout << "ERROR al abrir el archivo" << endl;
		std::system("pause");
		exit(0);
	}
	while (!archivo.eof()) {
		getline(archivo, texto);
		datos[i][j] = texto;
		i++;
		if (i == 7) { i = 0; j++; }
	}
	archivo.close();
}

string INE::send(string temp,int ronda) {	
	temp = datos[z][ronda];
	z++;
	if (z == 7) { z = 0; }
	return string(temp);
}