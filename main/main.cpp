#include <iostream>
#include <cmath>
#include <string>
using namespace std;
int menu();
void ejercicio1(string);
double ejercicio2(int, int, double);
int ejercicio3(string, int, int);
int main(int argc, char** argv) {
	int op = menu();
	while(op != 4){
		switch(op){
			case 1:{
				string numero = "";
				cout <<"Ingrese un numero de 4 cifras: "<<endl;
				cin >> numero;
				while(numero.size() != 4){
					cout<<"¡Debe ingresar un numero de solamente 4 cifras!"<<endl;
					cout <<"Ingrese un numero de 4 cifras: "<<endl;
					cin >> numero;
					
				}
				ejercicio1(numero);
				break;
			}
							
			case 2:{
				int n;
				cout<<"Ingrese un valor de n: "<<endl;
				cin>> n;
				while (n <= 1){
                cout << "¡El valor de n no puede ser menor a 2!" << endl;
                cout << "Ingrese un valor de n: ";
                cin >> n;
            	}   
				cout << "S(" << n << ") = " << ejercicio2(n, 2, 0.0) << endl;
				break;
			}
			
			case 3:{
				string palabra;
				cout<<"Ingrese una palabra: "<<endl;
				cin>> palabra;
				cout << palabra << " = " << ejercicio3(palabra, 0, 0) << endl;
				break;
			}
			
			default: {
				cout<<"Opcion invalida"<< endl;
				menu();
				break;
			}
		}
		op = menu();
		cout << endl;
	}
	return 0;
}
int menu(){
	int opcion = 0;
	cout<<"********** Menu **********"<<endl;
	cout<<"* 1. Ejercicio 1         *"<<endl;
	cout<<"* 2. Ejercicio 2         *"<<endl;
	cout<<"* 3. Ejercicio 3         *"<<endl;
	cout<<"* 4. Salir               *"<<endl;
	cout<<"**************************"<<endl;
	cout<<"Elija una opcion: "<<endl;
	cin>> opcion;
	return opcion;
}
void ejercicio1(string numero_ingresado){
	 string numero_mayor = "", numero_menor = "";
    numero_mayor = numero_menor = numero_ingresado;
    for (int k = 0; k < numero_mayor.size(); k++) {
        for (int i = 0; i < numero_mayor.size() - 1; i++) {
            if (numero_mayor[i] < numero_mayor[i + 1]) {
                char temp = '0';
                temp = numero_mayor[i];
                numero_mayor[i] = numero_mayor[i + 1];
                numero_mayor[i + 1] = temp;
            }//fin if mayor
            if (numero_menor[i] > numero_menor[i + 1]) {
                char temp = '0';
                temp = numero_menor[i];
                numero_menor[i] = numero_menor[i + 1];
                numero_menor[i + 1] = temp;
            }//fin if menor
        }// fin for j
    }// fin for k
    cout << "mayor " << numero_mayor << endl;
    cout << "menor " << numero_menor << endl;
}
double ejercicio2(int n, int x, double resultado) {
    // Variables Auxiliares
    double binomio1_numerador = 0.0, // 2x - 1
            binomio2_numerador = 0.0, // x + 3
            binomio_denominador = 0.0; // x^2 - 1
    binomio1_numerador = (2 * x) - 1;
    binomio2_numerador = x + 3;
    binomio_denominador = (x * x) - 1;
    if (x == n) {
        return resultado += (binomio1_numerador * binomio2_numerador) / (binomio_denominador * x);
    } else {
        resultado += (binomio1_numerador * binomio2_numerador) / (binomio_denominador * x);
        return ejercicio2(n, x+1, resultado);
    }
}
int ejercicio3(string palabra_ingresada, int contador, int frecuencia){
    if (contador == palabra_ingresada.size()) {
        return frecuencia;
    } else {
        if(palabra_ingresada[contador] == 97){
            frecuencia++;
        }
        return ejercicio3(palabra_ingresada, contador+1, frecuencia);
    }
}