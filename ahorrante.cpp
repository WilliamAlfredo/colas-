//PROGRAMA para almacenar el numero de tickets de loa ahorrantesz
//codigo hecho por:William Alfredo Vasquez Flores
//carnet:VF18003
//Docente:ING. Ligia Astrid Hernandez Bonilla 
#include <iostream> //libreria obligatoria
#include <string>//estandar del lenguaje de programacion
#include <windows.h>//
//cuerpo del programa
using namespace std;
class Dato {//estructura de clases
public: 
//declaracion de variables
    int ticket; 
    string edad;  
    Dato(){ 
        ticket = 0; 
        edad= "Unknow"; 

    }
}; 

class Nodo { public: //declaramos la clase nodo y la ponemos de tipo publica
    Dato dato; 
    Nodo *puntero; 
     
    Nodo(){ //Constructor de la clase
        puntero = NULL; 
    }
}; 

bool error(){//validacion de datos
	if(cin.fail())
	{
		cin.clear();
		cin.ignore();
		cout << endl << "El valor es incorrecto" << endl;
		return true;	
	}
	else
		return false;//retorna ra opcion si los datos son incorrectos
}

using namespace std; 
void Encolar( Nodo *&inicio, Nodo *&fin){ //Punteros enviados por referencia      
    Nodo *Elemento = new Nodo; //Creacion del nodo      
    if(inicio == NULL){ 
         
        inicio = fin = Elemento; //Le asigno la direccion del primer nodo          
        do{
		cout<<"N. ticket: "; cin>>Elemento->dato.ticket; 
        cout<<"edad: "; cin>>Elemento->dato.edad;  
        }while(error());
    }else{ 
         
        fin->puntero = Elemento; //Asigno el puntero del anterior elemento al nuevo

        fin = Elemento; //Cambio la direccion del ultimo nodo creado 
		do{
        cout<<"N. ticket: "; cin>>Elemento->dato.ticket; 
        cout<<"edad: "; cin>>Elemento->dato.edad; 
        }while(error());
         
    } 
     
     } 
	 
void Desencolar(Nodo *&inicio,int &largo){
	if(inicio != NULL){ 
    	largo--;
        cout<<"N. ticket: "<<inicio->dato.ticket<<endl; 
        cout<<"edad: "<<inicio->dato.edad<<endl; 
        inicio = inicio->puntero; // Cambio Inicio al siguiente nodo
    }else{ 
        cout<<"La cola se encuentra vacia"<<endl; 
    } } 
	
	int main (int argc, char *argv[]) { 
    Nodo *inicio = NULL , *fin = NULL; //Punteros libres para el manejo de la cola
    int opc = 0, respuesta = 0;
    int largo = 0;
    do{ //crecion del menu de opciones
        cout<<"1. LA COLA ESTA VACIA?"<<endl; 
        cout<<"2. AGREGAR"<<endl; 
        cout<<"3. ELIMINAR"<<endl; 
        cout<<"4. FINALIZAR"<<endl; 
        cout<<"Opcion: "; cin>>opc; 
        error();
         
        switch (opc){ 
        case 1 : 
            if( inicio == NULL) 
                cout<<"La cola se encuentra vacia"<<endl; 
            else 
                cout<<"Existe " << largo << " elemento(s) dentro de la cola"<<endl; 
            break; 
        case 2 : 
            Encolar(inicio,fin);
            largo++; 
            break; 
        case 3: 
            Desencolar(inicio,largo); 
            break ; 
             
        } 
        
    system("pause");
    system("cls");
    }while(opc != 4); 
     
     
    return 0; } 
