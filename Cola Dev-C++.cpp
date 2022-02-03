// Francis Josefina, matrícula 17-3579
// Cola en C++
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
        
   friend class cola;
};
 
typedef nodo *pnodo;
 
class cola {
   public:
    cola() : primero(NULL), ultimo(NULL) {}
    ~cola();
    
    void Anadir(int v);
    int Leer();

   private:
    pnodo primero, ultimo;
};
 
cola::~cola()
{
   while(primero) Leer();
}

void cola::Anadir(int v)
{
   pnodo nuevo;

   /* Crear un nodo nuevo */
   /* Este será el último nodo, no debe tener siguiente */
   nuevo = new nodo(v);
   /* Si la cola no estaba vacía, añadimos el nuevo a continuación de ultimo */
   if(ultimo) ultimo->siguiente = nuevo;
   /* Ahora, el último elemento de la cola es el nuevo nodo */
   ultimo = nuevo;
   /* Si primero es NULL, la cola estaba vacía, ahora primero apuntará también al nuevo nodo */
   if(!primero) primero = nuevo;
}

int cola::Leer()
{
   pnodo nodo; /* variable auxiliar para manipular nodo */
   int v;      /* variable auxiliar para retorno */
   
   /* Nodo apunta al primer elemento de la pila */
   nodo = primero;
   if(!nodo) return 0; /* Si no hay nodos en la pila retornamos 0 */
   /* Asignamos a primero la dirección del segundo nodo */
   primero = nodo->siguiente;
   /* Guardamos el valor de retorno */
   v = nodo->valor; 
   /* Borrar el nodo */
   delete nodo;
   /* Si la cola quedó vacía, ultimo debe ser NULL también*/
   if(!primero) ultimo = NULL;
   return v;
}

int main()
{
   cola Cola;

   Cola.Anadir(19);
   cout << "Añadir(19)" << endl;
   Cola.Anadir(5);
   cout << "Añadir(5)" << endl;
   cout << "Leer: " << Cola.Leer() << endl;
   Cola.Anadir(47);
   cout << "Añadir(47)" << endl;
   Cola.Anadir(35);
   cout << "Añadir(35)" << endl;
   cout << "Leer: " << Cola.Leer() << endl;
   cout << "Leer: " << Cola.Leer() << endl;
   Cola.Anadir(85);
   cout << "Añadir(85)" << endl;
   cout << "Leer: " << Cola.Leer() << endl;
   cout << "Leer: " << Cola.Leer() << endl;

   cin.get();
   return 0;
}

