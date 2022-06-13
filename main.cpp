#include <iostream>
#include <string>
#include <conio.h> // getch
#include <Windows.h>
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
void Fantastic_Car(){ 
    unsigned long int vel = 150000000;   
    unsigned int bit = 0x80;
    while(1){
        for (int i = 0; i < 8; ++i) {
            cout<<"Showing >  Fantastic Car  <"<<endl;
            cout<<"Salir   >      ESC        <"<<endl;
            cout<<"Sleep   >  "<<vel<<"      <"<<endl;
            printBin(bit);
            bit >>= 1;
            sleep(vel);
            system("cls");

            if((vel - 5000000) > 1000000){ if(GetAsyncKeyState(VK_UP) & 0x0001){vel -= 5000000;}}
            
            if(GetAsyncKeyState(VK_DOWN) & 0x0001){vel += 5000000;}
            
            if(GetAsyncKeyState(VK_ESCAPE) & 0x0001){return;}
        }
        
        bit = 0x02;
    
        for (int i = 0; i < 6; ++i) {
            cout<<"Showing >  Fantastic Car  <"<<endl;
            cout<<"Salir   >      ESC        <"<<endl;
            cout<<"Sleep   >  "<<vel<<"      <"<<endl;
            printBin(bit);
            bit <<= 1;
            sleep(vel);
            system("cls");

            if ((vel - 5000000) > 1000000){ if(GetAsyncKeyState(VK_UP) & 0x0001){vel -= 5000000;}}

            if(GetAsyncKeyState(VK_DOWN) & 0x0001){vel += 5000000;}

            if(GetAsyncKeyState(VK_ESCAPE) & 0x0001){return;}
        }
    }   
}


//Baile de la Konga
void LaKonga(){
    unsigned long int vel = 150000000; 
    while(1){
        for( int v=0; v<6; v++ ){
            for( int x=0; x<8; x++ ){
                    cout<<"Showing >    La Konga    <"<<endl;
                    cout<<"Salir   >      ESC       <"<<endl;
                    cout<<"Sleep   > "<<vel<<"      <"<<endl;
                for( int i=0; i<8; i++ ){
                    if (x+v>=i&& i>=x)
                    {
                        std::cout << "*"; 
                    
                    }
                    else{
                        std::cout << "-";
                    }
                }
                sleep(vel);   
                system("cls");
            if((vel - 5000000) > 1000000){ if(GetAsyncKeyState(VK_UP) & 0x0001){vel -= 5000000;}}
            
            if(GetAsyncKeyState(VK_DOWN) & 0x0001){vel += 5000000;}
            
            if(GetAsyncKeyState(VK_ESCAPE) & 0x0001){return;}
            }
        }
    }
}

//Pelota rebotando, esta experiencia deberia hacerce con las luces en vertical.
void BouncingBall(){
unsigned long int vel = 150000000;
unsigned long int secuencia[]={0x80,0x40,0x20,0x10,0x08,0x04,0x02,0x01};
    while(1){
        for( int x=0; x<8; x=x+2){  
            for( int i=x; i<8; i++){
                cout<<"Showing >  BouncingBall  <"<<endl;
                cout<<"Salir   >      ESC       <"<<endl;
                cout<<"Sleep   > "<<vel<<"      <"<<endl;
                printBin(secuencia[i]);  // BL printBin
                sleep(vel);          // BL sleep
                system("cls");
                if((vel - 5000000) > 1000000){if(GetAsyncKeyState(VK_UP) & 0x0001){vel -= 5000000;}}
                if(GetAsyncKeyState(VK_DOWN) & 0x0001){vel += 5000000;}
                if(GetAsyncKeyState(VK_ESCAPE) & 0x0001){return;}
            } 
            for( int z=7; z>=x+2; z=z-1){
                cout<<"Showing >  BouncingBall  <"<<endl;
                cout<<"Salir   >      ESC       <"<<endl;
                cout<<"Sleep   > "<<vel<<"      <"<<endl;
                printBin(secuencia[z]);
                sleep(vel);
                system("cls");
                if((vel - 5000000) > 1000000){if(GetAsyncKeyState(VK_UP) & 0x0001){vel -= 5000000;}}
                if(GetAsyncKeyState(VK_DOWN) & 0x0001){vel += 5000000;}
                if(GetAsyncKeyState(VK_ESCAPE) & 0x0001){return;}
            }
        }
    }
}

//Acelerador de particulas, se puede ver como va tomando velocidad.
void AceleradorDeParticulas(){
unsigned long int vel = 150000000;
    while(1){
        for( int x=0; x<8; x++){
            cout<<"Showing > AceleradorDeParticulas <"<<endl;
            cout<<"Salir   >          ESC           <"<<endl;
            cout<<"Sleep   >     "<<vel<<"          <" <<endl;
            for( int i=0; i<8; i++){
                if (x==i){std::cout << "*"; } else{std::cout << "-";}
            }
            sleep(vel); 
            system("cls");
            if((vel - 5000000) > 1000000){if(GetAsyncKeyState(VK_UP) & 0x0001){vel -= 5000000;}}
            if(GetAsyncKeyState(VK_DOWN) & 0x0001){vel += 5000000;}
            if(GetAsyncKeyState(VK_ESCAPE) & 0x0001){return;}
        }
    }

}

//Experiencia de choque, (realmente los unos se atraviesan.)
void Crash(){      

    unsigned long int vel = 150000000;   
    unsigned long int secuencia[]={0x81,0x42,0x24,0x18,0x18,0x24,0x42,0x81};

    while(1){
        for (int i = 0; i < 7; ++i) {
            cout<<"Showing >     Crash     <"<<endl;
            cout<<"Salir   >      ESC      <"<<endl;
            cout<<"Sleep   > "<<vel<<"     <" <<endl;
            printBin(secuencia[i]);
            sleep(vel);
            system("cls");
            if ((vel - 5000000) > 1000000){if(GetAsyncKeyState(VK_UP) & 0x0001){vel -= 5000000;} }
            if(GetAsyncKeyState(VK_DOWN) & 0x0001){vel += 5000000;}
            if(GetAsyncKeyState(VK_ESCAPE) & 0x0001){return;}
        }
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
            std::cout << "\n\n\t -->  "; std::cin  >> option;
            
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
                    Fantastic_Car();
                }
                std::cout<<"\n\n\t Fin de ejecucion."<<endl;
                sleep(10000);	
                break;

            case 3:
                system("cls");
                 for (int i = 0; i < 3; i++){
                    Crash();
                }
                
                std::cout<<"\n\n\t Fin de ejecucion."<<endl;
                sleep(10000);	
                break;

            case 4:
                system("cls");
                for (int i = 0; i < 3; i++){
                LaKonga();
                }
                
                std::cout<<"\n\n\t Fin de ejecucion."<<endl;
                sleep(10000);	
                break;
            case 5:
                system("cls");
                for (int i = 0; i < 3; i++){
                AceleradorDeParticulas();
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
 