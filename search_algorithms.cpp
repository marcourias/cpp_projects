#include <iostream>
#include <list>

int menu();
int* agregarArray();
void mostrarArray(int arrayNums[], int tamano);
void continuar();
int busquedaLineal(int arrayNums[], int size, int buscado);
int validarNum();

void cambiarLugar(int& a, int&b);
int particionar(int arrayNums[], int bajo, int alto);
void quickSort(int arrayNums[], int bajo, int alto);
void ordenarArray();


int busquedaBinaria(int arrayNums[], int target);

int busquedaInterpolacion(int arrayNums[], int target);



int* arrayNums = agregarArray();

int buscado = 0;
int counter = 0;


int arrayOrdenado[10];



int main()
{
    
    mostrarArray(arrayNums, counter);
    continuar();
    

    

    int size = counter;

    
    


    while (true)
    {
        
        validarNum();

        int opcion = menu();

        switch (opcion)
        {
            case 1:
            {
                system("cls");

                int indice = busquedaLineal(arrayNums, size, buscado);
                if (indice != -1) {
                    std::cout << "El número " << buscado << " se encuentra en la posición " << indice << " del array.\n";
                    continuar();
                    system("cls");
                } else {
                    std::cout << "El número " << buscado << " no se encuentra en el array.\n";
                    continuar();
                    system("cls");
                }
            }
    
                break;
            case 2:
            {
               system("cls");

               ordenarArray();


               std::cout << "***** ORDENAMIENTO DE ARRAY *****\n\n\n";
               std::cout << "Para llevar a cabo la búsqueda binaria es necesario contar con un array ordenado (Khan Academy, 2022)\nPor lo tanto, se procede a ordenar el arreglo capturado:\n\n";

               std::cout << "\nArreglo original: \n\n";
               for (int i = 0; i < counter; i++)
               {
                std::cout << arrayNums[i] << " ";
               }
               std::cout << std::endl;

               std::cout << "\n\n\nArreglo ordenado: \n\n";
               for (int i= 0; i < counter; i++)
               {
                std::cout << arrayOrdenado[i] << " ";
               }
               std::cout << std::endl;

               continuar();
               system("cls");

               int indice = busquedaBinaria(arrayOrdenado, buscado);
               if(indice != -1)
               {
                    std::cout << "El número " << buscado << " se encuentra en la posición " << indice << " del array.\n\n";
                    continuar();
                    system("cls");
                } else {
                    std::cout << "El número " << buscado << " no se encuentra en el array.\n";
                    continuar();
                    system("cls");
                }
            }
            break;

            case 3:
            {
                system("cls");
                int indice = busquedaInterpolacion(arrayOrdenado, buscado);
                
                if(indice != -1)
                {
                    std::cout << "\nEl número " << buscado << " se encuentra en la posición " << indice << " del array.\n\n";
                    continuar();
                    system("cls");
                } else {
                    std::cout << "\nEl número " << buscado << " no se encuentra en el array.\n";
                    continuar();
                    system("cls");
                }
            }

            break;

            case 4:
            {
                std::cout << "Saliendo del programa.\n";
                return 0;
            }
                
            default:
                std::cout << "Opción inválida.\n";
                break;
        }
    }

    return 0;
}

int menu()
{
    int opcion;
    std::cout << "**** MENÚ DE OPCIONES ****\n\n";
    std::cout << "MÉTODOS DE BÚSQUEDA: \n";
    std::cout << "1. SECUENCIAL\n";
    std::cout << "2. BINARIA\n";
    std::cout << "3. INTERPOLACIÓN\n";
    std::cout << "4. SALIR DEL PROGRAMA\n";

    std::cout << "\nElige una opción: ";
    std::cin >> opcion;
    std::cin.ignore(); // Descartar el carácter de nueva línea
    return opcion;
}

int* agregarArray()
{
    int* arrayNums = new int[10];
    counter = 0;

    std::cout << "\n\n+++++ CREAR ARRAY +++++\n\n\nIngrese valores para agregar al array. Presione 'q' para finalizar.\n";

    while (counter < 10) {
        std::string entrada;
        std::cout << "Ingrese un número entero positivo par: ";
        std::getline(std::cin, entrada);

        if (entrada == "q" || entrada == "Q") {
            break;
        }

        try {
            int num = std::stoi(entrada);

            if (num > 0 && num % 2 == 0) {
                bool numeroRepetido = false;

                for (int i = 0; i < counter; ++i) {
                    if (arrayNums[i] == num) {
                        numeroRepetido = true;
                        break;
                    }
                }

                if (numeroRepetido) {
                    std::cout << "El número " << num << " ya está en el array.\n";
                    std::cout << "Este valor es inválido, no se ha agregado al array.\n\n";
                } else {
                    arrayNums[counter] = num;
                    std::cout << "El valor ingresado para la posición " << counter << " es " << num <<".\n\n";
                    ++counter;
                }
            } else {
                std::cout << "El número " << num << " es inválido. Debe ser positivo y par.\n\n";
            }
            
        
        } catch (const std::invalid_argument&) {
            std::cout << "Entrada inválida. Intente nuevamente.\n";
        }
        
    }

    return arrayNums;
}

void mostrarArray(int arrayNums[], int tamano)
{
    std::cout << "Los elementos agregados al array son:\n\n";
    for (int i = 0; i < tamano; ++i) {
        std::cout << "Posición [" << i << "]: " << arrayNums[i] << "\n";
    }
}

void continuar()
{
    std::cout << "\n\nPresione ENTER para continuar...";
    std::cin.get(); // Capturar el ENTER
    system("cls");
}

int validarNum() {
    bool valorIncorrecto = true;

    std::cout << "\n ***** BUSCAR UN NÚMERO EN EL ARRAY *****\n";

    do {
        std::string entrada;
        std::cout << "\n\nIngrese un número entero positivo par a buscar (o 'q' para salir): ";
        std::getline(std::cin, entrada);

        if (entrada == "q" || entrada == "Q") {
            valorIncorrecto = false; // Exit the loop
        } else {
            try {
                int num = std::stoi(entrada);
                if (num > 0 && num % 2 == 0) {
                    buscado = num;
                    valorIncorrecto = false; // Exit the loop
                } else {
                    std::cout << "El número " << num << " es inválido. Debe ser positivo y par.\n\n";
                }
            } catch (const std::invalid_argument&) {
                std::cout << "Entrada inválida. Intente nuevamente.\n";
            }
        }
    } while (valorIncorrecto);

    std::cout << "Se buscará el número: " << buscado;

    continuar();

    return buscado;
}

int busquedaLineal(int arrayNums[],int size, int value)
{
    for (int i = 0; i < size; i++)
    {
        
        if (arrayNums[i] == value)
        {
            std::cout << "\nIteración: " << i + 1 << " se localizó " << value <<"\n";
            return i;
        } else
        {
            std::cout << "Iteración: " << i + 1 << " aún sin localizar " << value <<"\n\n";
        }
        
    }
    return -1;
}



void cambiarLugar(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
}

int particionar(int arrayNums[], int bajo, int alto) {
    int pivote = arrayNums[alto];
    int i = bajo - 1;

    for (int j = bajo; j <= alto - 1; j++) {
        if (arrayNums[j] < pivote) {
            i++;
            cambiarLugar(arrayNums[i], arrayNums[j]);
        }
    }

    cambiarLugar(arrayNums[i + 1], arrayNums[alto]);
    return (i + 1);
}

void quickSort(int arrayNums[], int bajo, int alto)
{
    if (bajo < alto)
    {
        int p = particionar(arrayNums, bajo, alto);
        quickSort(arrayNums, bajo, p - 1);
        quickSort(arrayNums, p + 1, alto);
    }
}

void ordenarArray()
{
    for(int i = 0; i < counter; i++)
    {
        arrayOrdenado[i] = arrayNums[i];
    }

    quickSort(arrayOrdenado, 0, counter-1);
}



int busquedaBinaria(int arrayNums[], int target)
{
    int contador = 0;
    int izquierda = 0;
    int derecha = counter - 1;

    while (izquierda <= derecha)
    {
        int medio = izquierda + (derecha - izquierda) / 2;

        if (arrayNums[medio] == target)
        {
            std::cout << "\nIteración: " << contador + 1 << " se localizó " << target <<"\n";
            return medio;
        } else if (arrayNums[medio] < target)
        {
            izquierda = medio + 1;
            std::cout << "Iteración: " << contador + 1 << " aún sin localizar " << target <<"\n\n";
            contador++;
        } else
        {
            derecha = medio - 1;
            std::cout << "Iteración: " << contador + 1 << " aún sin localizar " << target <<"\n\n";
            contador++;
        }
    }
    return -1;
}



int busquedaInterpolacion(int arrayNums[], int target)
{
    int bajo = 0;
    int alto = counter - 1;
    int contador = 0;

    while (bajo <= alto && target >= arrayNums[bajo] && target <= arrayNums[alto]) {
        if (bajo == alto) {
            if (arrayNums[bajo] == target)
                return bajo;
            return -1;
        }

        int pos = bajo + ((double)(alto - bajo) / (arrayNums[alto] - arrayNums[bajo])) * (target - arrayNums[bajo]);


        if (arrayNums[pos] == target)
        {
            std::cout << "\nIteración: " << contador + 1 << " se localizó " << target <<"\n";
            return pos;
        } else if (arrayNums[pos] < target)
        {
            bajo = pos + 1;
            std::cout << "Iteración: " << contador + 1 << " aún sin localizar " << target <<"\n\n";
            contador++;
        } else
        {
            alto = pos - 1;
            std::cout << "Iteración: " << contador + 1 << " aún sin localizar " << target <<"\n\n";
            contador++;
        }
            
    }

    return -1;
}