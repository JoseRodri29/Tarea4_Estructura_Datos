//Jose Antonio Rodriguez Garcia 62211223
/*Realizar un programa donde utilice el algoritmo de COLAS, el programa debe llevar el control de ingreso
y salida de usuarios para ser atendido por un oficial de atencion al cliente. Considerando que cada usuario
que llegue al establecimiento debe realizar una fila, por lo que el control de ingreso y salida debe ser que
los primeros que entran son los primeros en ser atendidos. En la estructura del nodo pueden guardar
informacion relevante de cada usuario como ser numero de identidad u otro atributos importantes.*/

#include <iostream>
#include <queue>
#include <string>

struct Usuario {
    int numero_identidad;
    std::string nombre;
    std::string motivo_visita;
    
    Usuario(int id, const std::string& nom, const std::string& motivo)
        : numero_identidad(id), nombre(nom), motivo_visita(motivo) {}
};

void mostrarUsuario(const Usuario& usuario) {
    std::cout << "Numero de Identidad: " << usuario.numero_identidad << "\n";
    std::cout << "Nombre: " << usuario.nombre << "\n";
    std::cout << "Motivo de la visita: " << usuario.motivo_visita << "\n";
}

int main() {
    std::queue<Usuario> colaUsuarios;
    int opcion;

    do {
        std::cout << "\nSistema de Control de Ingreso y Salida de Usuarios\n";
        std::cout << "1. Ingresar usuario\n";
        std::cout << "2. Atender usuario\n";
        std::cout << "3. Salir\n";
        std::cout << "Seleccione una opcion: ";
        std::cin >> opcion;

        switch (opcion) {
            case 1: {
                int id;
                std::string nombre;
                std::string motivo;
                std::cout << "Ingrese el numero de identidad: ";
                std::cin >> id;
                std::cin.ignore(); 
                std::cout << "Ingrese el nombre: ";
                std::getline(std::cin, nombre);
                std::cout << "Ingrese el motivo de la visita: ";
                std::getline(std::cin, motivo);
                                
                colaUsuarios.push(Usuario(id, nombre, motivo));
                std::cout << "Usuario agregado a la cola.\n";
                break;
            }
            case 2: {
                if (!colaUsuarios.empty()) {            
                    Usuario usuarioAtendido = colaUsuarios.front();
                    std::cout << "\nAtendiendo al siguiente usuario:\n";
                    mostrarUsuario(usuarioAtendido);
                    colaUsuarios.pop(); 
                } else {
                    std::cout << "No hay usuarios en la cola.\n";
                }
                break;
            }
            case 3:
                std::cout << "Saliendo del programa.\n";
                break;
            default:
                std::cout << "Opcion invalida. Por favor, intente de nuevo.\n";
        }
    } while (opcion != 3);

    return 0;
}
