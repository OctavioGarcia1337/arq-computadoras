#include <iostream>
#include <string>
#include <cstdlib>
#include <conio.h> // getch
#include <vector>
//sleep function
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h> //for others os.
#endif
#include <cstdlib>


#define ENTER 13
#define BACKSPACE 8
#define INTENTOS 3

using namespace std;

void delay(int time)
{
   int i;
   unsigned int j;
   for(i=time; i>0; --i) /* repeat specified number of times */
      for(j=0; j<65535; ++j);
}

void disp_binary (int i)
{
   int t;
   for(t=128; t>0; t=t/2)
      if(i&t) printf("*");
      else printf("-");
   printf("\n");
}

void fantastic_car(){
    /*
    string secuencia[]={"1000000","01000000","00100000","00010000","00000100","00000010","00000001"};
    for( int x=0; x<8; x++ ){
        cout<<secuencia[x];
        Sleep(1000);
        system("cls");
    }*/
    
    for( int x=0; x<8; x++ ){
        for( int i=0; i<8; i++ ){
            if (x==i)
            {
                cout << "*"; 
            }
            else{
                cout << "-";
            }
        }
        delay(1000); 
        system("cls");
        //system("clear");
    }
    for( int x=8; x>0; x-- ){
        for( int i=0; i<8; i++){
            if (x==i) {
                cout << "*";  
            }
            else{
                cout << "-";
            }        
        }
        delay(5000);
        system("cls");
    }
}

/*
void cargaerrada(){
    for( int x=0; x<8; x++ ){
        for( int i=0; i<8; i++){
            
}}}*/

/*
void aceleradordeparticulas{

for( int x=8; x>0; x-- ){
        for( int i=0; i<8; i++){

}}}*/


void choque(){
   string secuencia[]={"10000001","01000010","00100100","00011000","00011000","00100100","01000010","10000001"};
    for( int x=0; x<8; x++ ){
        cout<<secuencia[x];
        Sleep(500);
        system("cls");
    }
/* 
    cout<<"ejecucion 2";
    Sleep(1000);
    system("cls");
    
    for( int x=0; x<8; x++ ){
        for( int i=0; i<8; i++ ){
            if (x==i || i==7-x){
                cout << "*"; 
            }
            else{
                cout << "-";
            }   
        }
        delay(5000);
        system("cls");
    }*/
}







int main()
{
    vector<string> usuarios;
    vector<string> claves;

    // Se añaden nombres de usuario
    usuarios.push_back("Pollo");
    usuarios.push_back("Benja");

    // Se añaden claves a los usuario.
    claves.push_back("1974");
    claves.push_back("admin");

    string usuario, password;

    int contador = 0;
    bool ingresa = false;

    do
    {
        system("cls");     //Comando limpiar terminal.
        //system("clear"); //Depende de la terminal con la que se ejecute.
        cout << "\t\t\tLOGIN DE USUARIO" << endl;
        cout << "\t\t\t----------------" << endl;
        cout << "\n\tUsuario: ";
        getline(cin, usuario);

        char caracter;

        cout << "\tPassword: ";
        caracter = getch();

        password = "";
        while (caracter != ENTER)
        {

            if (caracter != BACKSPACE)
            {
                password.push_back(caracter);
                cout << "*";
            }
            else
            {
                if (password.length() > 0)
                {
                    cout << "\b \b";
                    password = password.substr(0, password.length() - 1);
                }
            }

            caracter = getch();
        }

        for (int i = 0; i < usuarios.size(); i++)
        {
            if (usuarios[i] == usuario && claves[i] == password)
            {
                ingresa = true;
                break;
            }
        }

        if (!ingresa)
        {
            cout << "\n\n\tEl usuario y/o password son incorrectos" << endl;
            Sleep(2000);
            contador++;
        }

    } while (ingresa == false && contador < INTENTOS);

    if (ingresa == false)
    {
        cout << "\n\tUsted no pudo ingresar al sistema." << endl;
    }
    else
    {
        system("cls");
        //system("clear"); Depende con la terminal que se ejecute.
        cout << "\n\n\tBienvenido al sistema" << endl;
    
        int option = 0;
    
        do
        {
            system("cls");
            cout << "\n\n\t----- Menu -----" << endl;
            cout << "\n\n\t1 - HELLO WORLD " << endl;
            cout << "\n\n\t2 - FANTASTIC CAR " << endl;
            cout << "\n\n\t3 - CRASH " << endl;
            cout << "\n\n\t0 - EXIT " << endl;
            cin  >> option;
           
           
            switch (option) 
            {
            case 1:
                system("cls");
                cout<<"\n\n\tHello World!."<<endl;
                cout<<"\n\n\tFin de ejecucion."<<endl;
                Sleep(1000);	
                break;

            case 2:
                system("cls");
                for (int i = 0; i < 3; i++){
                    fantastic_car();
                }
                cout<<"\n\n\tFin de ejecucion."<<endl;
                Sleep(1000);	
                break;

            case 3:
                system("cls");
                 for (int i = 0; i < 3; i++){
                    choque();
                }
                
                cout<<"\n\n\tFin de ejecucion."<<endl;
                Sleep(1000);	
                break;
            
            default:
                system("cls");
                cout<<"\n\n\tLa opcion "<< option;
                cout<<" no pertenece a una instruccion valida."<<endl;
                break;
            }
        }while(option != 0);
    }
}
 