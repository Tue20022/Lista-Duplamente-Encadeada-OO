//Matheus Vianna Nunes - ED
#include <iostream>
#include <locale> //habilitar padrões de caracter de teclado PTb
#include "Lista.h"

void menu(){
	cout << endl;
	cout << "Menu - Escolha opção:\n" <<endl;
	cout << "1- Insere Ordenado" << endl;
	cout << "2- Remove Inicio" << endl;
	cout << "3- Remove fim" << endl;
	cout << "4- Remove elemento" << endl;
	cout << "5- Imprime inicio - fim" << endl;
	cout << "6- Imprime fim - inicio" << endl;
	cout << "7- Buscar elemento" << endl;
	cout << "Qualquer outra para sair\n";
	cout << "Opção: ";
}

float ler_numero(int i){
	float tmp;
	cout << "Informe um número: ";
	cin >> tmp;
	return tmp;
}

int main(int argc, char** argv) {
	setlocale(LC_ALL, "Portuguese");
	Lista l;
	int n;
	
	int op(0);
	do{
		menu();
		cin >> op;
		
		switch(op){
			case 1: //insere ordenado
				l.insere_ordenado(ler_numero(n));
				cout<< endl;
				break;
			
			case 2: //remove inicio
				l.remove_inicio();
				cout<< endl;
				break;
			
			case 3: //remove fim
				l.remove_fim();
				cout<< endl;
				break;
			
			case 4: //remove elemento
				l.remove_elemento(ler_numero(n));
				cout<<endl;
				break;
			
			case 5://imprime inicio - fim
				l.imprime_inic_fim();
				cout<< endl;
				break;
			
			case 6://imprime fim - inicio
				l.imprime_fim_inic();
				cout<< endl;
				break;
				
			case 7://buscar elemento 
				l.buscar_elemento(ler_numero(n));
				cout<< endl;
				break;		
			default: cout << "Opção inválida e fim de programa!\n";		
		}
	}while(op>=1 && op<=7);
	
	cout << "Fim de programa!\n";
	system("pause");
	return 0;
}
