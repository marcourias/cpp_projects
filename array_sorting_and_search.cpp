#include <iostream>
#include <string>
#include <algorithm>

int menu();
void continuar();
void llenadoArray();

template <typename T>
void mostrarArray(T miArray[], int tamano);

void mostrarArrays(std::string arrayNombres[], float arrayCalificaciones[], int tamano);

int menuOrdenar();

//Métodos de ordenamiento
void ordenarBurbuja(float arr[], std::string arr2[], int n);
void ordenarInsercion(float arr[], std::string arr2[], int n);
void ordenarSeleccion(float arr[], std::string arr2[], int n);
int particionar(float arr[], std::string arr2[], int izquierda, int derecha);
void quicksort(float arr[], std::string arr2[], int izquierda, int derecha);

//Métodos de búsqueda
int menuBusqueda();
int busquedaLineal(std::string arrayNombres[],int size, std::string buscado);

template <size_t N>
void obtenerOrdenOriginal(const std::string (&array)[N], int (&orden)[N]);
int busquedaBinaria(const std::string arr[], int tamano, const std::string buscado);


int busquedaInterpolacion(const std::string arr[], int tamano, const std::string buscado);






std::string arregloNombres[10];
float arregloCalificaciones[10];



int counter = 0;
int contadorParticion = 0;

std::string nombreBuscado;


int main()
{
    

    while (true)
    {
        int opcion = menu();

        switch (opcion)
        {
        case 1:
            {
                llenadoArray();
                continuar();
                system("cls");

                std::cout << "\n\n----- ELEMENTOS DEL ARRAY DE NOMBRES -----\n\n";
                mostrarArray(arregloNombres, counter);
                std::cout << "\n\n----- ELEMENTOS DEL ARRAY DE CALIFICACIONES -----\n\n";
                mostrarArray(arregloCalificaciones, counter);
                continuar();
            }
            break;

        case 2:
            {
                int opcion2 = menuOrdenar();


                switch (opcion2)
                {
                case 1:
                {
                    system("cls");
                    std::string copiaNombres[10];
                    float copiaCalificaciones[10];

                    std::copy(arregloNombres, arregloNombres + counter, copiaNombres);
                    std::copy(arregloCalificaciones, arregloCalificaciones + counter, copiaCalificaciones);

                    std::cout << "\n\n+++++ MÉTODO BURBUJA +++++\n\n";

                    ordenarBurbuja(copiaCalificaciones, copiaNombres, counter);

                    continuar();

                    
                    std::cout << "Se han ordenado los arrays con el método burbuja: \n\n\n";

                    mostrarArrays(copiaNombres,copiaCalificaciones,counter);
                    continuar();
                }
                break;

                case 2:
                {
                    system("cls");
                    std::string copiaNombres[10];
                    float copiaCalificaciones[10];

                    std::copy(arregloNombres, arregloNombres + counter, copiaNombres);
                    std::copy(arregloCalificaciones, arregloCalificaciones + counter, copiaCalificaciones);

                    std::cout << "\n\n+++++ MÉTODO INSERCIÓN +++++\n\n";

                    ordenarInsercion(copiaCalificaciones, copiaNombres, counter);

                    continuar();

                    std::cout << "Se han ordenado los arrays con el método de inserción \n\n\n";

                    mostrarArrays(copiaNombres, copiaCalificaciones, counter);
                    continuar();
                }
                break;

                case 3:
                {
                    system("cls");
                    std::string copiaNombres[10];
                    float copiaCalificaciones[10];

                    std::copy(arregloNombres, arregloNombres + counter, copiaNombres);
                    std::copy(arregloCalificaciones, arregloCalificaciones + counter, copiaCalificaciones);

                    std::cout << "\n\n+++++ MÉTODO SELECCIÓN +++++\n\n";
                    ordenarSeleccion(copiaCalificaciones, copiaNombres, counter);

                    continuar();

                    std::cout << "Se han ordenado los arrays con el método de inserción \n\n\n";

                    mostrarArrays(copiaNombres, copiaCalificaciones, counter);
                    continuar();
                }
                break;

                case 4:
                {
                    system("cls");
                    std::string copiaNombres[10];
                    float copiaCalificaciones[10];

                    std::copy(arregloNombres, arregloNombres + counter, copiaNombres);
                    std::copy(arregloCalificaciones, arregloCalificaciones + counter, copiaCalificaciones);

                    std::cout << "\n\n+++++ MÉTODO QUICKSORT +++++\n\n";
                    quicksort(copiaCalificaciones, copiaNombres, 0, counter -1);
                    std::cout << "\nSe realizaron " << contadorParticion << " iteraciones para ordenar los arrays con quicksort.\n";
                    continuar();

                    std::cout << "Se han ordenado los arrays con el método quicksort \n\n\n";
                    mostrarArrays(copiaNombres, copiaCalificaciones, counter);
                    continuar();
                }
                break;
                
                default:
                    break;

                }
            }
            break;

        case 3:
            {
                system("cls");

                
                std::cout << "Ingrese el nombre a buscar: ";
                std::getline(std::cin, nombreBuscado); 

                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                
                int opcion3 = menuBusqueda();

                system("cls");

                switch (opcion3)
                {
                case 1:
                {
                    system("cls");

                    std::string copiaNombres[10];
                    float copiaCalificaciones[10];

                    std::copy(arregloNombres, arregloNombres + counter, copiaNombres);
                    std::copy(arregloCalificaciones, arregloCalificaciones + counter, copiaCalificaciones);

                    
                    std::sort(copiaNombres, copiaNombres + counter);


/////
                    std::cout << "El nombre buscado es: " << nombreBuscado;
                    
                    std::cout << "\n\nNombres en el array:\n";
                    for (int i = 0; i < counter; ++i) {
                        std::cout << "Posición [" << i << "]: " << copiaNombres[i] << "\n";
                    }

                    continuar();



                    std::cout << "\n\n***** BÚSQUEDA SECUENCIAL *****\n\n";
                    int posicion = busquedaLineal(copiaNombres, counter, nombreBuscado);

                    if (posicion >= 0)
                    {
                        std::cout << "El nombre " << copiaNombres[posicion] << " fue localizado.\n";
                        std::cout << "Se localizó en la posición: [" << posicion <<"] del arreglo de nombres ordenado alfabéticamente.";
                    } else
                    {
                        std::cout << "El dato no ha sido localizado en la estructura";
                    }

                    continuar();
                    
                    
                }
                    break;

                case 2:
                
                {
                    system("cls");
                    std::string copiaNombres[10];
                    
                    
                    std::copy(arregloNombres, arregloNombres + counter, copiaNombres);

                    

                    // Ordenar el array de nombres alfabéticamente
                    std::sort(copiaNombres, copiaNombres + counter);

                    continuar();
                    //////////////
                    std::cout << "\n\n***** BÚSQUEDA BINARIA *****\n\n";
                    
                    // Realizar la búsqueda binaria en el array ordenado alfabéticamente
                    int posicion = busquedaBinaria(copiaNombres, counter, nombreBuscado);

                    if (posicion != -1) {
                        // Obtener el índice original del nombre en el array no ordenado
                        
                        std::cout << "El nombre " << copiaNombres[posicion] << " fue localizado.\n";
                        std::cout << "Se localizó en la posición: [" << posicion <<"] del arreglo de nombres ordenado alfabéticamente.";
                    } else {
                        std::cout << "El dato no ha sido localizado en la estructura";
                    }

                    continuar();
                }
                    break;
                
                case 3:
                {
                    system("cls");

                    std::string copiaNombres[10];
                    float copiaCalificaciones[10];

                    std::copy(arregloNombres, arregloNombres + counter, copiaNombres);
                    std::copy(arregloCalificaciones, arregloCalificaciones + counter, copiaCalificaciones);

                    
                    std::sort(copiaNombres, copiaNombres + counter);

                    std::cout << "\n\n***** BÚSQUEDA POR INTERPOLACIÓN *****\n\n";
                    int posicion = busquedaInterpolacion(copiaNombres, counter, nombreBuscado);

                    if (posicion >= 0)
                    {
                        std::cout << "El nombre " << copiaNombres[posicion] << " fue localizado.\n";
                        std::cout << "Se localizó en la posición: [" << posicion <<"] del arreglo de nombres ordenado alfabéticamente.";
                    } else
                    {
                        std::cout << "El dato no ha sido localizado en la estructura";
                    }

                    continuar();
                }


                default:
                    break;
                }
            }
            break;

        case 4:
            {
                return 0;
                break;
            }
        
        default:
            std::cout << "Opción inválida.\n";
            break;
        }
    }
    

    return 0;
}

int menu(){

    int opcion;

    std::cout << "***** MENÚ PRINCIPAL *****\n";
    std::cout << "1. Llenado de arreglos\n";
    std::cout << "2. Ordenación de datos\n";
    std::cout << "3. Búsqueda de datos\n\n";
    std::cout << "4. Salir\n\n";

    std::cin >> opcion;
    std::cin.ignore(); // Descartar el carácter de nueva línea
    return opcion;
}

void continuar()
{
    std::cout << "\n\nPresione ENTER para continuar...";
    std::cin.get(); // Capturar el ENTER
    system("cls");
}

void llenadoArray()
{
    system("cls");

    std::cout << "\n\n+++++ CREAR ARRAY +++++\n\n\nIngrese valores para agregar al array. Presione 'q' para finalizar.\n";

    while (counter < 10) {

        std::string entrada;
        std::cout << "Ingrese el nombre del estudiante [" << counter+1 << "]: \n";
        std::getline(std::cin, entrada);

        if (entrada == "q" || entrada == "Q") {
            break;
        }

        arregloNombres[counter] = entrada;

        std::string calificacion;  // Declarar 'calificacion' aquí
        float calificacionFloat;   // Declarar 'calificacionFloat' aquí
        bool calificacionValida = false;

        do {
            std::cout << "Ingrese la calificación del estudiante[" << counter +1 <<"]: \n";
            std::getline(std::cin, calificacion);


            try {
                calificacionFloat = std::stof(calificacion);  // Convertir el string en un float

                if (calificacionFloat >= 0 && calificacionFloat <= 10) {
                    arregloCalificaciones[counter] = calificacionFloat;
                    calificacionValida = true;
                } else {
                    std::cout << "El número " << calificacionFloat << " es inválido. Debe estar entre 0 y 10.\n\n";
                }
                        
            } catch (const std::invalid_argument&) {
                std::cout << "Entrada inválida. Intente nuevamente.\n";
            }
        } while (!calificacionValida);
        counter++;
    }
}

template <typename T>
void mostrarArray(T miArray[], int tamano)
{
    std::cout << "Los elementos agregados al array son:\n\n";
    for (int i = 0; i < tamano; ++i) {
        std::cout << "Posición [" << i << "]: " << miArray[i] << "\n";
    }
}

void mostrarArrays(std::string arrayNombres[], float arrayCalificaciones[],  int tamano)
{
    for (int i = 0; i < tamano; ++i) {
        std::cout << "Posición [" << i << "] " << arrayNombres[i] << " - calificación: " << arrayCalificaciones[i] << "\n";
    }
}

int menuOrdenar() {
    system("cls");

    int opcion;
    bool entradaValida = false;

    do {
        std::cout << "***** MENÚ ORDENACIÓN *****\nEscoja el método de ordenación:\n\n";
        std::cout << "1. Burbuja\n";
        std::cout << "2. Inserción\n";
        std::cout << "3. Selección\n";
        std::cout << "4. Quicksort\n";
        std::cout << "5. Regresar\n\n";

        std::string entrada;
        std::getline(std::cin, entrada);

        try {
            opcion = std::stoi(entrada);
            if (opcion >= 1 && opcion <= 5) {
                entradaValida = true;
            } else {
                std::cout << "Opción inválida. Por favor, elija una opción válida del menú.\n";
            }
        } catch (const std::invalid_argument&) {
            std::cout << "Entrada inválida. Por favor, ingrese un número válido.\n";
        }
    } while (!entradaValida);

    return opcion;
}

void ordenarBurbuja(float arr[], std::string arr2[], int n) {
    int c = 0;
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                // Intercambiar elementos en ambos arreglos
                float temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;

                // Intercambiar elementos en el arreglo de strings
                std::string tempString = arr2[j];
                arr2[j] = arr2[j + 1];
                arr2[j + 1] = tempString;
            }
            c++;
        }
    }
    std::cout << "Se realizaron " << c << " iteraciones para ordenar los arrays.";
}

void ordenarInsercion(float arr[], std::string arr2[], int n)
{
    int c = 0;
    for (int i = 1; i < n; ++i) {
        float valorActual = arr[i];
        std::string valorActualNombres = arr2[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > valorActual) {
            arr[j + 1] = arr[j];
            arr2[j + 1] = arr2[j];
            j = j - 1;
            c++;
        }

        arr[j + 1] = valorActual;
        arr2[j + 1] = valorActualNombres;
    }

    std::cout << "\nSe realizaron " << c << " iteraciones para ordenar los arrays.\n";
}

void ordenarSeleccion(float arr[], std::string arr2[], int n) {
    
    int c = 0;

    for (int i = 0; i < n - 1; ++i) {
        int minIndex = i;

        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
            c++;
        }

        // Intercambiar elementos en los dos arreglos
        std::swap(arr[i], arr[minIndex]);
        std::swap(arr2[i], arr2[minIndex]);
    }

    std::cout << "\nSe realizaron " << c << " iteraciones para ordenar los arrays.\n";
}

int particionar(float arr[], std::string arr2[], int izquierda, int derecha) {
    float pivote = arr[derecha];
    int i = izquierda - 1;

    for (int j = izquierda; j < derecha; ++j) {
        if (arr[j] <= pivote) {
            i++;
            std::swap(arr[i], arr[j]);
            std::swap(arr2[i], arr2[j]);
        }
        contadorParticion++;
    }

    std::swap(arr[i + 1], arr[derecha]);
    std::swap(arr2[i + 1], arr2[derecha]);

    return i + 1;
}

void quicksort(float arr[], std::string arr2[], int izquierda, int derecha) {
    if (izquierda < derecha) {
        int pivotIndex = particionar(arr, arr2, izquierda, derecha);
        quicksort(arr, arr2, izquierda, pivotIndex - 1);
        quicksort(arr, arr2, pivotIndex + 1, derecha);
    }
}

int menuBusqueda() {
    system("cls");

    int opcion;
    bool entradaValida = false;

    do {
        std::cout << "***** MENÚ BÚSQUEDA *****\nEscoja el método de búsqueda:\n\n";
        std::cout << "1. Secuencial\n";
        std::cout << "2. Binaria\n";
        std::cout << "3. Por interpolación\n\n";
        std::cout << "4. Regresar\n\n\n";

        std::string entrada;
        std::getline(std::cin, entrada);

        try {
            opcion = std::stoi(entrada);
            if (opcion >= 1 && opcion <= 4) {
                entradaValida = true;
            } else {
                std::cout << "Opción inválida. Por favor, elija una opción válida del menú.\n";
            }
        } catch (const std::invalid_argument&) {
            std::cout << "Entrada inválida. Por favor, ingrese un número válido.\n";
        }
    } while (!entradaValida);

    return opcion;
}

int busquedaLineal(std::string arrayNombres[],int size, const std::string buscado)
{
    for (int i = 0; i < size; i++)
    {
        
        if (arrayNombres[i] == buscado)
        {
            //std::cout << "\nIteración: " << i + 1 << " se localizó " << buscado <<"\n";
            return i;
        } else
        {
            //std::cout << "Iteración: " << i + 1 << " aún sin localizar " << buscado <<"\n\n";
        }
        
    }
    return -1;
}

int busquedaBinaria(const std::string arr[], int tamano, const std::string buscado) {
    int izquierda = 0;
    int derecha = tamano - 1;

    while (izquierda <= derecha) {
        int medio = izquierda + (derecha - izquierda) / 2;

        int comparacion = buscado.compare(arr[medio]);

        if (comparacion == 0) {
            return medio; // Se encontró el elemento
        } else if (comparacion < 0) {
            derecha = medio - 1; // Continuar en la mitad izquierda
        } else {
            izquierda = medio + 1; // Continuar en la mitad derecha
        }
    }

    return -1; // El elemento no se encontró
}


template <size_t N>
void obtenerOrdenOriginal(const std::string (&array)[N], int (&orden)[N]) {
    for (int i = 0; i < N; ++i) {
        orden[i] = i;
    }

    std::sort(orden, orden + N, [&](int a, int b) {
        return array[a] < array[b];
    });
}


int busquedaInterpolacion(const std::string arr[], int tamano, const std::string buscado) {
  int inicio = 0;
  int fin = tamano - 1;
  int medio;

  while (inicio <= fin) {
    medio = (inicio + fin) / 2;

    if (arr[medio] == buscado) {
      return medio;
    } else if (arr[medio] < buscado) {
      inicio = medio + 1;
    } else {
      fin = medio - 1;
    }
  }

  return -1;
}

