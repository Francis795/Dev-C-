//Yorman suares
//14-0850
// Cola con prioridad:
// Añadir con prioridad
//Eliminar elemento de mayor prioridad
#include <iostream>
#include <stdlib.h>
#include<conio.h>
using namespace std;

struct nodo
{
    char dato;
    int priori; 
	int nro;      
    struct nodo *sgte;
};
struct cola
{
    nodo *delante;
    nodo *atras  ;
};
struct nodo *crearNodo( char x, int pr)
{
    struct nodo *nuevoNodo = new(struct nodo);
    nuevoNodo->dato = x;
    nuevoNodo->priori = pr;
    return nuevoNodo;
}
int desencolar( struct cola &q )
{
     int num ;
     struct nodo *aux ;
     
     aux = q.delante;      
     num = aux->nro;
     q.delante = (q.delante)->sgte;
     delete(aux);         
     
     return num;
}
void encolar( struct cola &q, char valor, int priori )
{
     
     struct nodo *aux = crearNodo(valor, priori);
     aux->sgte = NULL;
     
     if( q.delante == NULL)
         q.delante = aux;  
     else
         (q.atras)->sgte = aux;

     q.atras = aux;       
}
void muestraCola( struct cola q )
{
     struct nodo *aux;
     
     aux = q.delante;
     
     cout << " Caracter  Prioridad " << endl;
     cout << " ------------------- " << endl;
          
     while( aux != NULL )
     {
            cout<<"    "<< aux->dato << "     |   " << aux->priori << endl;
            aux = aux->sgte;
     }    
}
void ordenarPrioridad( struct cola &q )
{
     struct nodo *aux1, *aux2;
     int p_aux;
     char c_aux;
     
     aux1 = q.delante;
     
     while( aux1->sgte != NULL)
     {
            aux2 = aux1->sgte;
            
            while( aux2 != NULL)
            {
                   if( aux1->priori > aux2->priori )
                   {
                       p_aux = aux1->priori;
                       c_aux = aux1->dato;
                       
                       aux1->priori = aux2->priori;
                       aux1->dato   = aux2->dato;
                       
                       aux2->priori = p_aux;
                       aux2->dato   = c_aux;
                   }
                   
                   aux2 = aux2->sgte;
            }
            
            aux1 = aux1->sgte;
     }
}
void insertar( struct cola &q, char c, int pr )
{

     encolar( q, c, pr );

     ordenarPrioridad( q ); 
}
void vaciaCola( struct cola &q)
{
     struct nodo *aux;
     
     while( q.delante != NULL)
     {
            aux = q.delante;
            q.delante = aux->sgte;
            delete(aux);
     }
     q.delante = NULL;
     q.atras   = NULL;
     
}
void menu()
{
    cout<<"\n\t COLAS CON PRIORIDAD EN C++ \n\n";
    cout<<" 1. ENCOLAR                           "<<endl;
    cout<<" 2. MOSTRAR                           "<<endl;
    cout<<" 3. Eliminar                          "<<endl;
	cout<<" 4. SALIR                             "<<endl;

    cout<<"\n INGRESE OPCION: ";
}

int main()
{
    struct cola q;
    
    q.delante = NULL;
    q.atras   = NULL;

    char c ;     
    int pr;      
    int op;      
    int x ;      
    
    do
    {
        menu();  cin>> op;

        switch(op)
        {
            case 1:

                 cout<< "\n Ingrese caracter: ";
                 cin>> c;
                 
                 cout<< "\n Ingrese prioridad: ";   
                 cin>> pr;
                 
                 insertar( q, c, pr );
                 
                 cout<<"\n\n\t\tCaracter '" << c << "' encolado...\n\n";
            break; 
                  
            case 2:

                 cout << "\n\n MOSTRANDO COLA DE PRIORIDAD\n\n";
                 
                 if(q.delante!=NULL)
                     muestraCola( q );
                 else   
                    cout<<"\n\n\tCola vacia...!"<<endl;
            break;
             
                  case 3:
			      x = desencolar( q );
                  cout<<"\n\n\t\t*Numero de mayor prioridad desencolado...*\n\n";
            break;
            
            default:
                    cout<<"\n\tOpcion incorecta..!"<<endl;
                    system("pause");
                    exit(0);
         }

        cout<<endl<<endl;
        system("pause");  system("cls");

    }while(op!=4);
    
    return 0;
}

