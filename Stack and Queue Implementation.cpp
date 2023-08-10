/*

PILA
a) El programa permite almacenar 10 valores en la estructura, validando que sean valores positivos, pares e irrepetibles.
b) El programa muestra el valor junto con la posición de valor a buscar. De lo contrario indica que el valor no existe.
c) El programa muestra el valor más pequeño en la estructura de tipo pila.
d) El programa muestra el valor más grande en la estructura de tipo pila.
e) El programa permite emplear el método LIFO mostrando la posición de cada valor ingresado en la estructura.
f) El programa indica cuando la pila está llena o vacía.

*/

#include <iostream>
#include <limits>
#include <stack>
#include <string>
#include <vector>
#include <queue>

std::stack<int> pila_nums;
std::queue<int> cola_nums;

// Declaración del prototipo de la función "menu()"
int menu();
int pila();
void continuar();
bool esNumero();
void pushtoPila(std::stack<int>& pila_nums);
bool numRepetido(std::stack<int>& pila_nums, int numeroRepe);
void buscarPila(std::stack<int>& pila_nums);
void menorPila(std::stack<int>& pila_nums);
void mayorPila(std::stack<int>& pila_nums);
void popPila(std::stack<int>& pila_nums);
int cola();
void encolar();
bool numRepetidoC(std::queue<int>& cola_nums, int numeroRepe);
void buscarCola(std::queue<int>& cola_nums);
void menorCola(std::queue<int>& cola_nums);
void mayorCola(std::queue<int>& cola_nums);
void popCola(std::queue<int>& cola_nums);

int main()
{
    // Bucle para mostrar el menú repetidamente
    while (true)
    {
        int opcion = menu();
      

        switch (opcion)
        {
            case 1:

                system("cls");
                pila();
                break;
            case 2:
                cola();
                break;
            case 3:
                std::cout << "Saliendo del programa.\n";
                return 0; // Sale del programa si el usuario elige la opción 3
            default:
                std::cout << "Opción inválida.\n";
                break;
        }
    }

    return 0;
}

// Definición de la función "menu()"
int menu()
{
    int opcion;
    std::cout << "**** MENÚ DE OPCIONES ****\n\n";
    std::cout << "1.- Pila\n";
    std::cout << "2.- Cola\n";
    std::cout << "3.- Salir\n";

    std::cout << "\nElige una opción: ";
    
    while (!(std::cin >> opcion)) // Verificar si la entrada es un número
    {
        std::cout << "Entrada inválida. Intente nuevamente: ";
        std::cin.clear(); // Restaurar el estado del stream de entrada
        while (std::cin.get() != '\n')
            continue;
    }

    return opcion;
}

// Definición de la función "pila()"
int pila()
{
    

    int opcion2;
    do {
        system("cls");
        std::cout << "**** ESTRUCTURA DE TIPO PILA ****\n\n";
        std::cout << "1.- Apilar valor\n";
        std::cout << "2.- Buscar valor en la pila\n";
        std::cout << "3.- Valor más pequeño\n";
        std::cout << "4.- Valor más grande\n";
        std::cout << "5.- Desapilar\n";
        std::cout << "6.- Regresar al menú principal\n";

        std::cout << "\nElige una opción: ";

        while (!(std::cin >> opcion2)) // Verificar si la entrada es un número
        {
            std::cout << "Entrada inválida. Intente nuevamente: ";
            std::cin.clear(); // Restaurar el estado del stream de entrada
            while (std::cin.get() != '\n')
                continue;
        }

        switch (opcion2)
        {
            case 1:
                pushtoPila(pila_nums);
                break; 
            
            case 2:
                
                buscarPila(pila_nums);
                break;

            case 3:
                menorPila(pila_nums);
                break;
            case 4:
                mayorPila(pila_nums);
                break;
            case 5:
                popPila(pila_nums);
                break;
            case 6:
                std::cout << "Regresando al menú principal.\n";
                system("cls");
                break;
            default:
                std::cout << "Opción inválida.\n";
                break;
        }


    } while (opcion2 != 6);
    
    return opcion2;
}

void continuar()
{
    // Mostrar mensaje "Presione ENTER para continuar..."
    std::cin.ignore(); // Esperar a que el usuario presione ENTER
    std::cout << "Presione ENTER para continuar...";
    std::cin.get(); // Capturar el ENTER
    system("cls");
}

bool esNumero(const std::string& str)
{
    if (str.empty())
    {
        return false;
    }

    size_t pos = 0;

    // Verificar si hay un signo negativo al inicio
    if (str[0] == '-')
    {
        if (str.size() == 1) // El signo negativo solo, no es un número válido
        {
            return false;
        }
        pos = 1; // Empezar a verificar desde el siguiente carácter
    }

    for (; pos < str.size(); ++pos)
    {
        if (!std::isdigit(str[pos]))
        {
            return false;
        }
    }

    return true;
}

void pushtoPila(std::stack<int>& pila_nums)
{
    system("cls");
    std::cout << "**** ESTRUCTURA DE TIPO PILA ****\n\n";
    std::cout << "**** Ingresando valores en una pila ****\n\n\n";

    int num; // Declarar 'num' antes del bucle

    for (int i = 0; i < 10; i++) {
        bool numValido = false;
        std::string input;

        while (!numValido)
        {
            // Solicitar al usuario un número positivo y par
            std::cout << "\n\nIngresa el valor número " << i + 1 << " en la posición [" << i << "]: ";
            std::cin >> input;

            // Verificar si la entrada es un número válido
            if (!esNumero(input))
            {
                std::cout << "Entrada inválida. Debes ingresar un número entero válido. Intente nuevamente.\n";

                // Limpiar el estado del stream de entrada y descartar la entrada inválida
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                continue; // Volver a solicitar al usuario
            }

            // Convertir la entrada a entero
            num = std::stoi(input);

            // Verificar si el número cumple con las condiciones requeridas
            if (num <= 0)
            {
                std::cout << "El número debe ser positivo. Intente nuevamente.\n";
            }
            else if (num % 2 != 0)
            {
                std::cout << "El número debe ser par. Intente nuevamente.\n";
            }
            else if (numRepetido(pila_nums, num))
            {
                std::cout << "El número ya está en la pila. Intente nuevamente.\n";
            }
            else
            {
                numValido = true; // El número ingresado es válido, salir del bucle
            }
        }

        pila_nums.push(num);
    }

    std::cout << "\nLa pila está llena y es: ";
    std::stack<int> pila_temp = pila_nums;
    while (!pila_temp.empty()) {
        std::cout << pila_temp.top();
        pila_temp.pop();

        if (!pila_temp.empty()) {
            std::cout << ", ";
        }
    }
    std::cout << std::endl;

    continuar();
    system("cls");
}

bool numRepetido(std::stack<int>& pila_nums, int numeroRepe)
{
    std::stack<int> pilaRepe = pila_nums;
    
    bool encontrado = false;

    while(!pilaRepe.empty())
    {
        int numActual = pilaRepe.top();
        pilaRepe.pop();

        if (numActual == numeroRepe)
        {
            encontrado = true;
            break;
        }
    }

    return encontrado;
}

void buscarPila(std::stack<int>& pila_nums)
{
    system("cls");

    // Solicitar que valor se buscará
    int valor;
    std::cout << "**** BUSCAR VALOR EN LA PILA ****\n\n";

    bool localizado = false;
    int posicion = 9;
    int counter = 9; // Inicializamos el contador en 0

    // Realizar la búsqueda en la pila
    std::stack<int> pila_temp = pila_nums;

    if (pila_nums.empty())
    {
        std::cout << "La pila está vacía!\n\n";
        continuar();
    }
    else
    {
        std::string input;
        bool entradaValida = false;

        do
        {
            std::cout << "Ingresa el valor a buscar en la pila: ";
            std::cin >> input;
            

            // Verificar si la entrada es un número válido
            if (esNumero(input))
            {
                // Realizar la búsqueda en la pila
                valor = std::stoi(input);

                std::stack<int> pila_temp = pila_nums;
                while (!pila_temp.empty())
                {
                    int valorActual = pila_temp.top();
                    pila_temp.pop();


                    if (valorActual == valor)
                    {
                        localizado = true;
                        posicion = counter;
                        break;
                    }


                
                    counter--;
                }

                if (localizado)
                {
                    std::cout << "El valor " <<valor<< " ha sido encontrado en la posición [" << posicion <<"].\n\n";
                }
                else
                {
                std::cout << "El valor " << valor << " no se localizó en la cola.\n\n";
                counter = 9;
                continuar();
                
                }

            }
            else
            {
                std::cout << "Entrada inválida. Intente nuevamente.\n";
                std::cin.clear(); // Limpiar el estado del flujo de entrada
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignorar caracteres hasta encontrar una nueva línea
            }
        } while (!localizado);

        
        continuar();
        }

}
    
void menorPila(std::stack<int>& pila_nums)
{
    system("cls");
    
    std::cout << "**** BUSCANDO EL VALOR MÁS PEQUEÑO ****\n\n";

    if (pila_nums.empty())
    {
        std::cerr << "La pila está vacía. \n";
    }
    else
    {
        std::stack<int> pila_temp = pila_nums;

        int peque = pila_temp.top();
        pila_temp.pop();

        int counter = 8;
        int posicion = 9;

        while (!pila_temp.empty())
        {
            int numActual = pila_temp.top();
            pila_temp.pop();

            if (numActual < peque)
            {
                peque = numActual;
                posicion = counter;
            }
            counter--;
        }

    std:: cout << "El valor más pequeno es el número " << peque << " y está en la posición [" << posicion << "].\n\n";
    }
    
    continuar();

}

void mayorPila(std::stack<int>& pila_nums)
{
    system("cls");
    
    std::cout << "**** BUSCANDO EL VALOR MÁS GRANDE ****\n\n";

    if (pila_nums.empty())
    {
        std::cerr << "La pila está vacía. \n";
    }
    else
    {
        std::stack<int> pila_temp = pila_nums;

        int mayor = pila_temp.top();
        pila_temp.pop();

        int counter = 8;
        int posicion = 9;

        while (!pila_temp.empty())
        {
            int numActual = pila_temp.top();
            pila_temp.pop();

            if (numActual > mayor)
            {
                mayor = numActual;
                posicion = counter;

            }

            counter--;
        }

    std:: cout << "El valor más grande es el número " << mayor << " y está en la posición [" << posicion << "].\n\n";
    }
    
    continuar();
}

void popPila(std::stack<int>& pila_nums)
{
    system("cls");
    std::cout << "Desapilando la estructura \n\n";

    std::stack<int> pila_temp = pila_nums;

    std::vector<std::string> numeros_ordinales = {
        "primer", "segundo", "tercero", "cuarto", "quinto",
        "sexto", "séptimo", "octavo", "noveno", "décimo"
    };


    int counter = 0;
    int posicion = 9;

    if (pila_temp.empty())
    {
        std::cout << "La pila está vacía!\n\n";
    }
    else
    {
        while (!pila_temp.empty())
        {
            int valorActual = pila_temp.top();

            std::cout << "El " << numeros_ordinales[counter] << " valor desapilado es el número " << valorActual << " en la posición [" << posicion << "]\n\n";
            
            pila_temp.pop();

            posicion--;
            counter++;

        }

        std::cout << "La pila está vacía!\n\n\n";
        
        pila_nums = pila_temp;

    }

    continuar();

    system("cls");
}

int cola()
{
    system("cls");
    int opcion3;

    do
    {
        std::cout << "**** ESTRUCTURA DE TIPO COLA ****\n\n";
        std::cout << "1.- Encolar valor\n2.- Buscar valor en la cola\n3.- Valor más pequeño\n4.-Valor mas grande\n5.-Desencolar estructura\n6- Regresar al menú principal\n";

        std::cout << "\nElige una opción: ";

        while (!(std::cin >> opcion3)) // Verificar si la entrada es un número
        {
            std::cout << "Entrada inválida. Intente nuevamente: ";
            std::cin.clear(); // Restaurar el estado del stream de entrada
            while (std::cin.get() != '\n')
                continue;
        }

        switch (opcion3)
        {
            case 1:
                encolar();
                break; 
            
            case 2:
                if (!cola_nums.empty()) // Verificar que la cola no esté vacía
                    buscarCola(cola_nums);
                else
                    std::cout << "La cola está vacía. Primero ingrese valores.\n\n";
                    continuar();
                break;

            case 3:
                menorCola(cola_nums);
                break;
            case 4:
                mayorCola(cola_nums);
                break;
            case 5:
                popCola(cola_nums);
                break;
            case 6:
                std::cout << "Regresando al menú principal.\n";
                system("cls");
                break;
            default:
                std::cout << "Opción inválida.\n";
                break;
        }
    } while (opcion3 != 6);
    
    return opcion3;

}    
    
void encolar()
{
    system("cls");
    std::cout << "**** ESTRUCTURA DE TIPO COLA ****\n\n";
    std::cout << "**** Ingresando valores en una cola ****\n\n\n";

    int num; // Declarar 'num' antes del bucle

    for (int i = 0; i < 10; i++) {
        bool numValido = false;
        std::string input;

        while (!numValido)
        {
            // Solicitar al usuario un número positivo y par
            std::cout << "\n\nIngresa el valor número " << i + 1 << " en la posición [" << i << "]: ";
            std::cin >> input;

            // Verificar si la entrada es un número válido
            if (!esNumero(input))
            {
                std::cout << "Entrada inválida. Debes ingresar un número entero válido. Intente nuevamente.\n";

                // Limpiar el estado del stream de entrada y descartar la entrada inválida
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                continue; // Volver a solicitar al usuario
            }

            // Convertir la entrada a entero
            num = std::stoi(input);

            // Verificar si el número cumple con las condiciones requeridas
            if (num <= 0)
            {
                std::cout << "El número debe ser positivo. Intente nuevamente.\n";
            }
            else if (num % 2 != 0)
            {
                std::cout << "El número debe ser par. Intente nuevamente.\n";
            }
            else if (numRepetidoC(cola_nums, num))
            {
                std::cout << "El número ya está en la pila. Intente nuevamente.\n";
            }
            else
            {
                numValido = true; // El número ingresado es válido, salir del bucle
            }
        }

        cola_nums.push(num);
    }

    std::cout << "\nLa cola está llena y es: ";
    std::queue<int> cola_temp = cola_nums;
    while (!cola_temp.empty()) {
        std::cout << cola_temp.front();
        cola_temp.pop();

        if (!cola_temp.empty()) {
            std::cout << ", ";
        }
    }
    std::cout << std::endl;

    continuar();
    system("cls");

}
    
bool numRepetidoC(std::queue<int>& cola_nums, int numeroRepe)
{
    std::queue<int> colaRepe = cola_nums;
    
    bool encontrado = false;

    while(!colaRepe.empty())
    {
        int numActual = colaRepe.front();
        colaRepe.pop();

        if (numActual == numeroRepe)
        {
            encontrado = true;
            break;
        }
    }

    return encontrado;
}

void buscarCola(std::queue<int>& cola_nums)
{
    system("cls");

    // Solicitar que valor se buscará
    int valor;
    std::cout << "**** BUSCAR VALOR EN LA COLA ****\n\n";

    bool localizado = false;
    int posicion = 0;
    int counter = 0; 

    // Realizar la búsqueda en la pila
    std::queue<int> cola_temp = cola_nums;

    if (cola_nums.empty())
    {
        std::cout << "La cola está vacía!\n\n";
        continuar();
    }
    else
    {
        std::string input;
        bool entradaValida = false;

        do
        {
            std::cout << "Ingresa el valor a buscar en la cola: ";
            std::cin >> input;
            

            // Verificar si la entrada es un número válido
            if (esNumero(input))
            {
                // Realizar la búsqueda en la pila
                valor = std::stoi(input);

                std::queue<int> cola_temp = cola_nums;
                while (!cola_temp.empty())
                {
                    int valorActual = cola_temp.front();
                    cola_temp.pop();


                    if (valorActual == valor)
                    {
                        localizado = true;
                        posicion = counter;
                        break;
                    }


                
                    counter++;
                }

                if (localizado)
                {
                    std::cout << "El valor " <<valor<< " ha sido encontrado en la posición [" << posicion <<"].\n\n";
                }
                else
                {
                std::cout << "El valor " << valor << " no se localizó en la cola.\n\n";
                counter = 0;
                continuar();
                
                }

            }
            else
            {
                std::cout << "Entrada inválida. Intente nuevamente.\n";
                std::cin.clear(); // Limpiar el estado del flujo de entrada
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignorar caracteres hasta encontrar una nueva línea
            }
        } while (!localizado);

        
        continuar();
        }

}

void menorCola(std::queue<int>& cola_nums)
{
    system("cls");
    
    std::cout << "**** BUSCANDO EL VALOR MÁS PEQUEÑO ****\n\n";

    if (cola_nums.empty())
    {
        std::cerr << "La cola está vacía. \n";
    }
    else
    {
        std::queue<int> cola_temp = cola_nums;

        int peque = cola_temp.front();
        cola_temp.pop();

        int counter = 1;
        int posicion = 0;

        while (!cola_temp.empty())
        {
            int numActual = cola_temp.front();
            cola_temp.pop();

            if (numActual < peque)
            {
                peque = numActual;
                posicion = counter;
            }
            counter--;
        }

    std:: cout << "El valor más pequeno es el número " << peque << " y está en la posición [" << posicion << "].\n\n";
    }
    
    continuar();
}

void mayorCola(std::queue<int>& cola_nums)
{
    system("cls");
    
    std::cout << "**** BUSCANDO EL VALOR MÁS GRANDE ****\n\n";

    if (cola_nums.empty())
    {
        std::cerr << "La cola está vacía. \n";
    }
    else
    {
        std::queue<int> cola_temp = cola_nums;

        int mayor = cola_temp.front();
        cola_temp.pop();

        int counter = 1;
        int posicion = 0;

        while (!cola_temp.empty())
        {
            int numActual = cola_temp.front();
            cola_temp.pop();

            if (numActual > mayor)
            {
                mayor = numActual;
                posicion = counter;
            }
            counter++;
        }

    std:: cout << "El valor más grande es el número " << mayor << " y está en la posición [" << posicion << "].\n\n";
    }
    
    continuar();
}

void popCola(std::queue<int>& cola_nums)
{
    system("cls");
    std::cout << "Desencolando la estructura \n\n";

    std::queue<int> cola_temp = cola_nums;

    std::vector<std::string> numeros_ordinales = {
        "primer", "segundo", "tercero", "cuarto", "quinto",
        "sexto", "séptimo", "octavo", "noveno", "décimo"
    };


    int counter = 0;
    int posicion = 0;

    if (cola_temp.empty())
    {
        std::cout << "La cola está vacía!\n\n";
    }
    else
    {
        while (!cola_temp.empty())
        {
            int valorActual = cola_temp.front();

            std::cout << "El " << numeros_ordinales[counter] << " valor extraído es el número " << valorActual << " en la posición [" << posicion << "]\n\n";
            
            cola_temp.pop();

            posicion++;

            counter++;

        }

        std::cout << "La cola está vacía!\n\n\n";
        
        cola_nums = cola_temp;
    }

    continuar();

    system("cls");
}
