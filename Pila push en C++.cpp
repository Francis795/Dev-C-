// Francis Josefina, matrícula 17-3579
// Pila en C++
// (C) Enero 2022, La Vega


#include <iostream>
using namespace std;

class nodo {
	public: 
	nodo(int v, nodo *sig = NULL)
	{
	  valor = v; 
	  siguiente = sig;		
	}
	
	private: 
	int valor;
	nodo *siguiente; 
	
	friend class pila; 
};
	
	typedef nodo *pnodo; 
	
class pila {
	public:
	pila() : ultimo(NULL) {}
	~pila();
	
	void Push(int v);
	int Pop();
	
	private: 
    pnodo ultimo;
};
	
pila::~pila()	
{
   pnodo aux; 
   
   while(ultimo) {
		aux = ultimo;
		ultimo = ultimo ->siguiente;
		delete aux;
	
	}		
}
	 
	
void pila::Push(int v)	
{
	pnodo nuevo; 
	
	/* Crear un nodo nuevo */
	nuevo = new nodo(v, ultimo);
	/* Ahora, el comienzo de nuestra pila es un nuevo nodo */
	ultimo = nuevo;
	
}	
	
	
	int pila::Pop()	
{
	
	pnodo nodo;  /* variable auxiliar para manipular nodo */
	int v;       /* variable auxiliar para retorno */
	
	if(!ultimo) return 0; /* Si no hay nodos en la pila retornamos 0 */
	/* Nodo apunta al primer elemento de la pila */
	nodo = ultimo;
	/* Asignamos a pila toda la pila menos el primer elemento */ 
	ultimo = nodo->siguiente; 
	/* Guardamos el valor de retorno */
	v = nodo->valor;
	/* Borrar el nodo */
	delete nodo; 
	return v;	
	
}

	
int main()	
{
	pila Pila; 
	
	Pila.Push(25);
	cout << "Push(25)" << endl;
	Pila.Push(9);
	cout << "Pop() = "  << Pila.Pop() << endl; 
	Pila.Push(45);
	cout << "Push(45)"  << endl; 
	Pila.Push(35);
	cout << "Push(35)"  << endl;
	cout << "Pop() = "  << Pila.Pop() << endl;
	cout << "Pop() = "  << Pila.Pop() << endl;
	Pila.Push(95);
	cout << "Push(95)"  << endl;
	cout << "Pop() = "  << Pila.Pop() << endl;
	cout << "Pop() = "  << Pila.Pop() << endl; 
	
	cin.get();
	return 0; 
		
	
}
		
	
	
	

