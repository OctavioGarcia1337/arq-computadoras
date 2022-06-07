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
            cout << "\n\n\t0 - EXIT " << endl;
            cin  >> option;
           
           
            switch (option)
            {
            case 1:
                system("cls");
                cout<<"\n\n\tHello World!."<<endl;
                cout<<"\n\n\tFin de ejecucion."<<endl;
                Sleep(5000);	
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

