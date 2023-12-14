#include <iostream>
#include <vector>
#include <stdexcept>
#include <algorithm>

//estructura Estudiante
struct Estudiante {
    std::string nombre;
    int edad;
    float promedio;
    std::vector<std::string> materias; //lista de materias añadidas

    //funcion para mostrar la informacion del estudiante
    void mostrarEstudiante() {
        std::cout << "Nombre: " << nombre << "\nEdad: " << edad << "\nPromedio: " << promedio << "\nMaterias inscritas: ";
        for (const auto &materia : materias) {
            std::cout << materia << " ";
        }
        std::cout << "\n";
    }

    //funciones para gestionar materias
    void agregarMateria(const std::string& materia) {
        materias.push_back(materia);
    }

    void eliminarMateria(const std::string& materia) {
        auto it = std::find(materias.begin(), materias.end(), materia);
        if (it != materias.end()) {
            materias.erase(it);
        }
    }
};

//estructura Asistencia
struct Asistencia {
    std::string fecha;
    std::string materia;
    std::string estado;
};

//funcion para mostrar informacion de asistencia
void mostrarAsistencia(const Asistencia& asistencia) {
    std::cout << "Fecha: " << asistencia.fecha << "\nMateria: " << asistencia.materia << "\nEstado: " << asistencia.estado << "\n";
}

//funcion para registrar asistencia
void registrarAsistencia(Estudiante & estudiante, const Asistencia& asistencia) {
    //implementacion sencilla, sin manejo de excepciones en C++
    estudiante.mostrarEstudiante();
    std::cout << "Asistencia registrada: \n";
    mostrarAsistencia(asistencia);
}

//implementacion de excepciones personalizadas
class FormatoFechaInvalido : public std::exception {
public:
    const char *what() const noexcept override {
        return "Error: Formato de fecha invalido.";
    }
};

int main() {
    //ejemplo de uso
    Estudiante estudiante;
    estudiante.nombre = "Juan";
    estudiante.edad = 20;
    estudiante.promedio = 8.5;
    estudiante.agregarMateria("Matematicas");
    estudiante.agregarMateria("Historia");

    Asistencia asistencia;
    asistencia.fecha = "14-12-2023";
    asistencia.materia = "Matematicas";
    asistencia.estado = "Asistio";

    //registro de asistencia
    registrarAsistencia(estudiante, asistencia);
    //manejo de excepcion
    try {
        throw FormatoFechaInvalido();
    } catch (const std::exception &e) {
        std::cerr << "Excepcion: " << e.what() << "\n";
    }

    return 0;
}