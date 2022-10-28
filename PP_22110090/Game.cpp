#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "Papeles.h"

using namespace std;

class Game{
public:
	Game();
	void Menu();
	void Start();
	int pt;
    int ronda;
	int opc;
    int respuesta;
    string datosIne[8][10];
    string datosPass[8][10];
    string temp;
};
Game::Game(){
    pt = 0; opc = 0; ronda = 0; respuesta = 0;
}

void Game::Start() {
    string datoint;
    ronda = 0;
    INE ine;
    ine.lectura();   
    Pasaporte pas;
    pas.Get();

    while (ronda<10){
        std::cout << "Ronda: " << ronda + 1 << "\nPuntaje: "<<pt<<"\n" << endl;
        std::cout << "Papeles Por favor\n" << endl;
        std::cout << "INE"<< endl;
        for (int i = 0; i <= 6; i++) {
            datoint = ine.send(temp, ronda);
            datosIne[i][ronda] = datoint;
            std::cout << datoint << endl;
        }
        std::cout << "\n\nPasaporte"<< endl;

        srand(time(NULL));
        int dato = 1 + rand() % (4);
        
        if (dato == 1 || dato == 2 || dato == 5) {
            for (int i = 0; i <= 6; i++) {
                datoint = pas.case1(temp, ronda);
                datosPass[i][ronda] = datoint;
                std::cout << datoint << endl;
            }
        }else if (dato == 3) {
            for (int i = 0; i <= 6; i++) {
                datoint = pas.case3(temp, ronda);
                datosPass[i][ronda] = datoint;
                std::cout << datoint << endl;
            }
        }else if (dato == 4) {
            for (int i = 0; i <= 6; i++) {
                datoint = pas.case4(temp, ronda);
                datosPass[i][ronda] = datoint;
                std::cout << datoint << endl;
            }
        }
        
        std::cout << "\n1.-Sellar pasaporte\t\t\t\t\t2.-Denegar acceso" << endl;
        std::cin >> respuesta;
        
        if (respuesta==1 &&dato == 1 || dato == 2 || dato == 5) {
            std::system("cls");
            std::cout << "\n                   Respuesta correcta\n" << endl;
            pt += 100;
        }
        else if (respuesta == 1 && dato != 1 || dato != 2 || dato != 5) {
            std::system("cls");
            std::cout << "\n                   Respuesta incorrecta\n" << endl;
            pt = pt-100;
        }
        if (respuesta == 2) {
            std::cout << "\nSeleccione la razon del rechazo: \n1.-Nombre no coincide               2.-Apellido no coincide" << endl;
            std::cout << "3.-Domicilio no coincide            4.-CURP no coincide" << endl;
            std::cout << "5.-Fecha de nacimiento no coincide  6.-Sexo no coincide\n" << endl;
            std::cin >> respuesta;
            std::system("cls");
            if (datosIne[respuesta - 1][ronda] != datosPass[respuesta - 1][ronda]) { std::cout << "\n                   Respuesta correcta" << endl; pt += 100; }
            else { std::cout << "\n                   Respuesta incorrecta" << endl; pt = pt - 100; }
        }
        ronda++;
    }
    std::system("cls");
    std::cout << "\n\nGracias por jugar"<< endl;
    std::cout << "\n\nPuntaje final: "<<pt << endl;
}

void Game::Menu() {
    
    std::system("cls");
    std::cout << "......Papers, Please by Zavala......" << endl;
    std::cout << "................Menu................." << endl;
    std::cout << "1.-Jugar" << endl;
    std::cout << "2.-Salir" << endl;
    std::cin >> opc;
        do {
            std::system("cls");

        switch (opc) {
        case 1:std::cout << "\n\nA continuacion, para ganar puntos debera identificar las incongruencias entre la INE y el Pasaporte," << endl;
            std::cout << "si lo hace de forma correcta ganara puntos, mientras que si se equivoca al permitir el paso" << endl;
            std::cout << "de una persona con documentos falsos sera penalizada.\n\n\n" << endl;
            std::system("pause"); std::system("cls");
            Start();
            break;
        case 2: std::cout << "Hasta luego :D" << endl;
            exit(0);
            break;
        default: std::cout << "opcion no valida" << endl;
            break;
        }
        std::cout << "\n\nDesea jugar otra partida?" << endl;
        std::cout << "1.-Si :D" << endl;
        std::cout << "2.-No D:" << endl;
        std::cin >> opc;
    } while (opc == 1);
}

int main() {
	Game game;
	game.Menu();
	return 0;
}