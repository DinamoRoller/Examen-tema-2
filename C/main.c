#include <stdio.h>
#include <string.h>

//estructura estudiante

struct Estudiante {
    char nombre[50];
    int edad;
    float promedio;
    char materias[5][10]; //lista de materias inscritas, asumiendo un maximo de 5 asignaturas
    int numMaterias;
};

//funcion para mostrar la informacion del estudiante
void mostrarEstudiante(struct Estudiante *estudiante) {
    printf("Nombre; %s\nEdad: %d\nPromedio: %.2f\nMaterias inscritas: ", estudiante->nombre, estudiante->edad, estudiante->promedio);
    for (int i = 0; i < estudiante->numMaterias; ++i) {
        printf("%s ", estudiante->materias[i]);
    }
    printf("\n");
}

//funciones para gestionar las asignaturas
void agregarMateria(struct Estudiante *estudiante, const char *materia) {
    if (estudiante->numMaterias < 5) {
        strcpy(estudiante->materias[estudiante->numMaterias], materia);
        estudiante->numMaterias++;
    } else {
        printf("No es posible añadir mas materias\n");
    }
}

void eliminarMateria(struct Estudiante *estudiante, const char *materia) {
    for (int i = 0; i < estudiante->numMaterias; ++i) {
        if (strcmp(estudiante->materias[i], materia) == 0) {
            for (int j = i; j < estudiante->numMaterias - 1; ++j) {
                strcpy(estudiante->materias[j], estudiante->materias[j + 1]);
            }
            estudiante->numMaterias--;
            return;
        }
    }
    printf("La materia no se encuentra en la lista.\n");
}

//estructura asistencia
struct Asistencia{
    char fecha[11];
    char materia[50];
    char estado[20];
};

//funcion para mostrar informacion de asistencia
void mostrarAsistencia(const struct Asistencia *asistencia) {
    printf("Fecha: %s\nMateria: %s\nEstado: %s\n", asistencia->fecha, asistencia->materia, asistencia->estado);
}

//funcion para registrar asistencia
void registrarAsistencia(const struct Estudiante *estudiante, const struct Asistencia *asistencia) {
    mostrarEstudiante(estudiante);
    printf("Asistencia registrada:\n");
    mostrarAsistencia(asistencia);
}

//implementacion de manejo de exepciones
enum Excepcion {
    EXITO,
    FORMATO_FECHA_INVALIDO
};

//funcion para manejar errores
const char *manejarError(enum Excepcion error) {
    switch (error) {
        case FORMATO_FECHA_INVALIDO:
            return "Error: Formato de fecha invalido.";
        default:
            return "Error desconocido.";
    }
}

int main() {
    //ejemplo de uso
    struct Estudiante estudiante = {"Juan", 20, 8.5, {"Matematicas", "Historia"}, 2};

    struct Asistencia asistencia = {"14-12-2023", "Matematicas", "Asitio"};

    //registro de asistencia
    registrarAsistencia(&estudiante, &asistencia);

    //manejo de excepcion
    enum Excepcion resultado = FORMATO_FECHA_INVALIDO;
    if (resultado != EXITO) {
        printf("Excepcion: %s\n", manejarError(resultado));
    }

    return 0;
}