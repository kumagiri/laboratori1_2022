#include <iostream>
#include <cmath>
#include <cstring>
#include <conio.h>
#include <stdlib.h>
using namespace std;

//prototipos funciones

    //prototipo punto 2
void Cantidad  (int* ptrn,int arr[]);
    //prototipos punto 15
void llenar_matriz();
void mostrar_matriz(int**,int,int);
void izqui(int**,int,int);
void derecha(int**,int,int);
void abajo(int**,int,int);
void arriba(int**,int,int);

    //problema decodificador

int decodePermits(const string& permits);
int decopermisos(string *ptrper);
int opciones();

//variables
int ** puntero_matriz, nfilas,ncolumnas;

int main()
{
    /*2.BILLETES
    int n=0;
    int an[]={50000,20000,10000,5000,2000,1000,500,200,100,50};

    cout<<"ingrese por favor la cantidad de dinero: ";
    cin>>n;
    while(n>=50){

        Cantidad(&n,an);
    }*/



    /*5 ASTERISCOS

    int n;
       cout << " Bienvenido ingrese un numero impar : " ;
       cin >> n ;
       int r=n%2;
       int medio=0;
       if (r==1){
           for(int i=1;n/2>=i;i++){
               for(int j=n/2;j>=i;j--){
                   cout<<' ';
               }
               for(int k=1;(2*i)-1>=k;k++){
                   cout<<'*';
               }
               cout<<endl;
           }
           for(int i=(n/2)+1;0<i;i--){
               medio++;
               for (int j=1;j<medio;j++){
                   cout<<' ';
               }
               for(int k=0;k<(2*i)-1;k++){
                   cout<<'*';
               }
               cout<<endl;
           }
           cout<<'\n'<<endl;
           system("pause");
           return 0;
       }
       else{
           cout<<"no es un numero impar"<<endl;
       }*/



    /*15 MATRIZ ESPIRAL

    llenar_matriz();
    mostrar_matriz(puntero_matriz,nfilas,ncolumnas);
    //liberacion
    for(int i=0; i<nfilas;i++){
         delete[] puntero_matriz[i];
     }
     delete[] puntero_matriz;*/


    /*PROBLEMA PROPUESTO DECODIFICADOR*/


        int j=0;
        string permisos[9],usuario, grupo, otro;



                 cout<<"los permisos son los siguientes \n w=escribir r=leer y x=ejecucion";
                 cout<< " A continuacion ingrese los permisos sin repetir asignacion y si no desea dar uno de los "<<
                        "permisos solo ponga - donde corresponde \n";
                 cout<<"ingrese los permisos para el usuario: \n";
                 cin>>usuario;
                 cout<<"ingrese los permisos para el grupo de usuario: \n";
                 cin>>grupo;
                 cout<<"ingrese los permisos para otros usuarios: \n";
                 cin>>otro;

                 for(int i=0;i<9;i++){

                     if(i<3){

                         permisos[i]=usuario[j];
                         j++;
                     }
                     if(j==3)j=0;
                     else if(i>2 and i<6){

                         permisos[i]=grupo[j];
                         j++;

                     }
                     if(j==3)j=0;
                     else if(i>5 and i<9){

                         permisos[i]=otro[j];
                         j++;

                     }

                 }

                 cout<<"u: "<<usuario<<"| g : "<<grupo<<"| o: "<<otro<<endl;
                 cout<<"permisos: ";
                 for(int i=0;i<9;i++){
                     cout<<permisos[i];


                 }
                 cout<<endl;
                 cout<<"Permiso dado por el usuario es: "<<decopermisos(permisos)<<endl;



    getch();
    return 0;
}

        //cuerpo funciones

//problema 2

void Cantidad(int* ptrn,int arr[]){
    int a=0;
    for(int i=0;i<10;i++){



        a=floor(*ptrn/arr[i]);
        *ptrn-=(a*arr[i]);
        cout<<"De "<<arr[i]<<"="<<a<<endl;

    }
    if(*ptrn<50) cout<<"Faltante = "<<*ptrn<<endl;

}


//problema 15

void llenar_matriz(){

   int k=1,e=2,c=0,a=0,b=0;
    cout<<"Por favor ingrese un numero impar: ";
    cin>>nfilas;

    if(nfilas%2==0) cout<<"el numero es par \n";

    else{
    ncolumnas=nfilas;
    c=floor(nfilas/2);
    puntero_matriz = new int*[nfilas];
    for(int i=0;i<nfilas;i++){
        puntero_matriz[i] = new int[ncolumnas];
    }
    a=nfilas-(c+1);
    b=nfilas-(c+1);

    while(k<(nfilas*nfilas)){
         //centro e iniciales de 1 movimiento
        if (k==1){

            *(*(puntero_matriz+a)+b)=k;
            k++,b++;

            *(*(puntero_matriz+a)+b)=k;
            k++,a++;

            *(*(puntero_matriz+a)+b)=k;
            k++;


        }
         //movimiento izquierdo

         for(int i=0;i<e;i++){
           if(k<=(nfilas*nfilas)){
             b--;
             *(*(puntero_matriz+a)+b)=k;
             k++;

         }
         }

        //movimiento arriba

         for(int i=0;i<e;i++){
             if(k<=(nfilas*nfilas)){
             a--;
             *(*(puntero_matriz+a)+b)=k;
             k++;

         }
         }
         //movimiento derecha

         for(int i=0;i<(e+1);i++){
             if(k<=(nfilas*nfilas)){
             b++;
             *(*(puntero_matriz+a)+b)=k;
             k++;

         }
         }
         //movimiento abajo

         for(int i=0;i<(e+1);i++){
            if(k<=(nfilas*nfilas)){
             a++;
             *(*(puntero_matriz+a)+b)=k;
             k++;

         }
         }
         e+=2;
    }
}
}
void mostrar_matriz(int** puntero_matriz,int nfilas,int ncolumnas){
    cout<<"La matriz es: \n";
    int s=0;
    for(int i=0;i<nfilas;i++){
            for(int j=0;j<ncolumnas;j++){
                if(*(*(puntero_matriz+i)+j)<10){
                cout<<"0"<<*(*(puntero_matriz+i)+j)<<"-";
            }
                else{
                cout<<*(*(puntero_matriz+i)+j)<<"-";
                }
                if(i==j){
                    s+=*(*(puntero_matriz+i)+j);

                }
            }

            cout<<endl;


        }

    int j=(nfilas-1);
    for(int i=0;i<nfilas;i++){
        if(i!=j){
        s+=*(*(puntero_matriz+i)+j);
        j--;
    }
        else j--;
    }
    cout<<"La suma de los numeros en la diagonal es igual a: "<<s<<endl;
}

//problema decodificador



int decopermisos(string *ptrper){

    int s=0;
    for(int i=0;i<9;i++){

        if(*(ptrper+i)=="r"){
           s+=4;
           if(i==2 or i==5){
               s*=10;
           }


         }
        if(*(ptrper+i)=="w"){
           s+=2;
           if(i==2 or i==5){
               s*=10;
           }

         }



        if(*(ptrper+i)=="x"){
           s+=1;
           if(i==2 or i==5){
               s*=10;
           }
        }

        if(*(ptrper+i)=="-"){
           s+=0;
           if(i==2 or i==5){
               s*=10;
           }
        }

}
    return s;
}



