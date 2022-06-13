#include <iostream>
#include <string>
#include <conio.h> // getch
#include <vector>  // estructura de datos para guardar los usuarios.

// Se setean variables globales que se utilizaran durante todo el programa.
#define ENTER 13
#define BACKSPACE 8
#define INTENTOS 3

using namespace std;


//Funcion de delay alternativa.
void sleep(unsigned long int a){
    while (a) a--;
}

//Funcion para mostrar las secuencias en numeros binarios.

void printBin (unsigned char dato){
  for (unsigned char mask = 128; mask > 0; mask>>=1)
    {
        if (dato&mask)
        {
            std::cout<<"*";
        }
        else {
            std::cout<<"_";
        }
    }
}

// Luces del auto fantastico
void fantastic_car(){
    
    for( int x=0; x<8; x++ ){
        for( int i=0; i<8; i++ ){
            if (x==i)
            {
               std::cout << "*"; 
            }
            else{
                std::cout << "-";
            }
        }
        sleep(5000000);
        system("cls");
        //system("clear");
    }
    for( int x=8; x>0; x-- ){
        for( int i=0; i<8; i++){
            if (x==i) {
                std::cout << "*";  
            }
            else{
                std::cout << "-";
            }        
        }
        sleep(5000000);
        system("cls");
    }
}

//Barra de carga que falla al 99%, es un meme de internet.
void Loadbarerror(){
    for( int v=0; v<6; v++ ){
        for( int x=0; x<8; x++ ){
            for( int i=0; i<8; i++ ){
                if (x+v>=i&& i>=x)
                {
                    std::cout << "*"; 
                
                }
                else{
                    std::cout << "-";
                }
            }    
            sleep(5000000); 
            system("cls");
        }
    }
}

//Pelota rebotando, esta experiencia deberia hacerce con las luces en vertical.
void BouncingBall(){
unsigned long int secuencia[]={0x80,0x40,0x20,0x10,0x08,0x04,0x02,0x01};
    for( int x=0; x<8; x=x+2){  
        for( int i=x; i<8; i++){
            printBin(secuencia[i]);
            sleep(5000000);
            system("cls");
        } 
        for( int z=7; z>=x+2; z=z-1){
            printBin(secuencia[z]);
            sleep(5000000);
            system("cls");
        }
    }
}

//Acelerador de particulas, se puede ver como va tomando velocidad.
void aceleradordeparticulas(){
for(  int v=200; v>0; v=v-50){
    for( int x=0; x<8; x++){
        for( int i=0; i<8; i++){
            if (x==i)
                {
                std::cout << "*"; 
                }
                else{
                std::cout << "-";
                }
        }
        sleep(v); 
        system("cls");
        }
    }
}

//Experiencia de choque, (realmente los unos se atraviesan.)
void choque(){           
    unsigned long int secuencia[]={0x81,0x42,0x24,0x18,0x18,0x24,0x42,0x81};

    for( int x=0; x<8; x++ ){
        printBin(secuencia[x]);
        sleep(5000000);
        system("cls");
    }
}

int main(){

    // Logica del LOGIN

    vector<string> usuarios;
    vector<string> claves;

    // Seteamos USUARIOS y PASSWORDS
    // Se añaden nombres de usuario         
    usuarios.push_back("admin");

    // Se añaden claves a los usuario.
    claves.push_back("admin");

    string usuario, password;

    int contador = 0;
    bool ingresa = false;

    //Empieza la logica del login

    do
    {
        system("cls");     //Comando limpiar terminal.
        //system("clear"); //Depende de la terminal con la que se ejecute.
        std::cout << "\t\t\t LOGIN DE USUARIO" << endl;
        std::cout << "\t\t\t ----------------" << endl;
        std::cout << "\n\n\t Usuario: ";
        getline(cin, usuario);

        char caracter;

        std::cout << "\t Password: ";
        caracter = getch();

        password = "";
        while (caracter != ENTER)
        {

            if (caracter != BACKSPACE)
            {
                password.push_back(caracter);
                std::cout << "*";
            }
            else
            {
                if (password.length() > 0)
                {
                    std::cout << "\b \b";
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
            std::cout << "\n\n\t El usuario y/o password son incorrectos" << endl;
            sleep(200000);
            contador++; //aumenta el contador que controla los intentos
        }

    } while (ingresa == false && contador < INTENTOS);  // Se controla que mientras el login sea fallido 
                                                        // o el contador no llegue al limite de intentos
                                                        // se siga ejecutando el login.



    //MENU + LOGICA DE CLAVE VALIDADA.



    if (ingresa == false)
    {
        std::cout << "\n\t Usted no pudo ingresar al sistema." << endl;
    }
    else
    {
        system("cls");
        //system("clear"); Depende con la terminal que se ejecute.
        std::cout << "\n\n\t Bienvenido al sistema" << endl;
    
        int option = 0;

        // Menu

        do
        {
            system("cls");
            std::cout << "\n\n\t ----- Menu -----" << endl;
            std::cout << "\n\n\t 1 - HELLO WORLD " << endl;
            std::cout << "\n\n\t 2 - FANTASTIC CAR " << endl;
            std::cout << "\n\n\t 3 - CRASH " << endl;
            std::cout << "\n\n\t 4 - LA KONGA" << endl;
            std::cout << "\n\n\t 5 - ACELERADOR DE PARTICULAS" << endl;
            std::cout << "\n\n\t 6 - BOUNCING BALL" << endl;
            std::cout << "\n\n\t 0 - EXIT " << endl;
            std::cout << "\n\n\t -->"; std::cin  >> option;
            
            switch (option) 
            {
            case 1:
                system("cls");
                std::cout<<"\n\n\t Hello World!."<<endl;
                std::cout<<"\n\n\t Fin de ejecucion."<<endl;
                sleep(10000);
                break;

            case 2:
                system("cls");
                for (int i = 0; i < 3; i++){
                    fantastic_car();
                }
                std::cout<<"\n\n\t Fin de ejecucion."<<endl;
                sleep(10000);	
                break;

            case 3:
                system("cls");
                 for (int i = 0; i < 3; i++){
                    choque();
                }
                
                std::cout<<"\n\n\t Fin de ejecucion."<<endl;
                sleep(10000);	
                break;

            case 4:
                system("cls");
                for (int i = 0; i < 3; i++){
                Loadbarerror();
                }
                
                std::cout<<"\n\n\t Fin de ejecucion."<<endl;
                sleep(10000);	
                break;
            case 5:
                system("cls");
                for (int i = 0; i < 3; i++){
                aceleradordeparticulas();
                }
                
                std::cout<<"\n\n\t Fin de ejecucion."<<endl;
                sleep(10000);	
                break;

            case 6:
                system("cls");
                for (int i = 0; i < 3; i++){
                BouncingBall();
                }
                
                std::cout<<"\n\n\t Fin de ejecucion."<<endl;
                sleep(10000);	
                break;
            default:
                system("cls");
                std::cout<<"\n\n\t La opcion "<< option;
                std::cout<<"\n\n\t No pertenece a una instruccion valida."<<endl;
                break;
            }
        }while(option != 0);
    }
}
 