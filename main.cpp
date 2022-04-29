//Implementar la busqueda de un elemento en la lista enlazada
//Si la encuentra tiene que imprimir la dirección de memoría donde esta este elemento.

#include<iostream>
#include<conio.h>
using namespace std;

struct Nodo{
	int dato;
	Nodo *siguiente;
};

//prototipo de funciones
void insertarLista(Nodo *&,int);
void buscarLista(Nodo *,int);

int main(){
	Nodo *lista = NULL;

	int dato, n;

	cout<<"\tsolo puedes ingresar datos menores a 5 si es mayor o igual sera el ultimo en insertarse: "<<endl;

	do{
        cout<<"Digite un numero: ";
        cin>>dato;
        insertarLista(lista,dato);
	}
	while(dato < 5);

	do{
        cout<<"Digitar elemento a buscar"<<endl;
        cin>>dato;
        buscarLista(lista,dato);
	}
	while(dato !=0);

	getch();
	return 0;
}

void insertarLista(Nodo *&lista,int n){
	Nodo *nuevo_nodo = new Nodo();
	nuevo_nodo->dato = n;

	Nodo *aux1 = lista;
	Nodo *aux2;

	while((aux1 !=NULL) && (aux1->dato < n)){
		aux2 = aux1;
		aux1 = aux1->siguiente;
	}

	if(lista ==aux1){
		lista = nuevo_nodo;
	}
	else{
		aux2->siguiente = nuevo_nodo;
	}

	nuevo_nodo->siguiente = aux1;

	cout<<"\tElemento "<<&n<<" insertado a lista correctamente\n";
}

void buscarLista(Nodo *lista,int n){
	bool band =false;

	Nodo *actual = new Nodo();
	actual =lista;

	while((actual !=NULL) && (actual->dato <=n)){
		if(actual->dato == n){
			band = true;
		}
		actual = actual->siguiente;
	}
	if(band == true){
		cout<<"Elemento "<<n<<" SI a sido encontrado en lista"<<endl;
		cout<< &n <<endl;

	}
	else{
		cout<<"Elemento "<<n<<" NO a sido encontrado en lista"<<endl;
	}
}
