#include <stdlib.h> // Para el exit().
#include <unistd.h> // Funciones exec
#include <string.h>
/* Viernes, 25 de diciembre del 2020

    - PROGRAMA PARA CORRER Python desde C utilizando excec.
*/

/* Esta es la forma correcta con la que puedo ejecutar un programa de Python
    en C mandando argumentos.*/
void correct_way_to_send_args_and_execute_python();
void send_received_args_to_python_script(char *python_script_name,
                            char *received_args[], int number_of_received_args);

int main(int argc, char *argv[]){
    /* De esta forma corremos Python desde C.
        - El primer parámetro, por
        convención debe ser el filename del ejecutable.
        - El segundo parámetro es la palabra clave con la que corres el programa
        desde la terminal, ej: python hola_mundo.py "argumento 1" "argumento 2"
        - El tercer parámetro es el nombre del programa con su extensión.
        - El cuarto parámetro son los argumentos para el programa.
        - El quinto y último argumento es NULL.*/
    // char *args[] = {"Programa 1", "Hola", "Adiós", "."};

    // Así mandaría solo un argumento.
    // execlp("python", "python", "receiving_args_shell_python.py", "1", NULL);

    // char *args[] = {"python", "receiving_args_shell_python.py", "Programa 1", "Hola", "Adiós", ".", NULL};
    // execv(args[0], args);

    // char *args[] = {"receiving_args_shell_python.py", "Programa 1", "Hola", "Adiós", "."};
    // char *args[] = {"receiving_args_shell_python.py", "Programa 1", "Hola", "Adiós", "."};
    // Mandando cada argumento manualmente sí los imprime.
    // Mandando el arreglo no imprime.
    // execlp("python", "python", args[0], args[1], args[2], NULL);

    // Logrado a las [03:33PM]
    correct_way_to_send_args_and_execute_python();

    /* -------------------------------------------------------------------------
        TODO LO DE ABAJO ERA PARA CORRER EL PROGRAMA EN PYTHON CON LOS PARÁMETROS
        QUE SE LE HAYAN PASADO EN C.
       -------------------------------------------------------------------------
    */

    // // Nombre del programa python.
    // char python_script_name[] = "receiving_args_shell_python.py";
    // // Arreglo de cadenas sin el ejecutable C.
    // char *args_without_c_program_name[argc - 1];
    //
    // // Copiamos la lista de argumentos sin el nombre del ejecutable C en el
    // //    arreglo de cadenas.
    // for(int i = 0; i < argc; i++)
    //     strcpy(args_without_c_program_name[i], argv[i + 1]);
    //
    // send_received_args_to_python_script(python_script_name,
    //         args_without_c_program_name,
    //         sizeof(args_without_c_program_name) / sizeof(args_without_c_program_name[0]));
    // -------------------------------------------------------------------------
    exit(0);
}

/* FUNCIÓN QUE EJECUTARÁ EL PROGRAMA CON LOS ARGUMENTOS RECIBIDOS.*/
void send_received_args_to_python_script(char *python_script_name,
                            char *received_args[], int number_of_received_args){
    /* De esta forma corremos Python desde C.
        - El primer parámetro, por
        convención debe ser el filename del ejecutable.
        - El segundo parámetro es la palabra clave con la que corres el programa
        desde la terminal, ej: python hola_mundo.py "argumento 1" "argumento 2"
        - El tercer parámetro es el nombre del programa con su extensión.
        - El cuarto parámetro son los argumentos para el programa.
        - El quinto y último argumento es NULL.
    */
    // char *args[] = {"python", python_script_name, *received_args, NULL};

    // size_t number_of_received_args = sizeof(received_args) / sizeof(received_args[0]);

    char *args[number_of_received_args];

    strcpy(args[0], "python");
    strcpy(args[1], python_script_name);

    // *args = {"python", python_script_name};
    // Agregar los valores restantes.
    int i = 2;
    for(int j = 0; i < number_of_received_args; i++, j++)
        strcpy(args[i], received_args[j]);
    strcpy(args[i], NULL);
    // Con excecvp solo mando el nombre del programa como primer argumento,
    //  y con excev tengo que mandar todo el directorio, o así lo entendí.
    execvp(args[0], args);
}

/* Esta es la forma correcta con la que puedo ejecutar un programa de Python
    en C mandando argumentos.*/
void correct_way_to_send_args_and_execute_python(){
    /* De esta forma corremos Python desde C.
        - El primer parámetro, por
        convención debe ser el filename del ejecutable.
        - El segundo parámetro es la palabra clave con la que corres el programa
        desde la terminal, ej: python hola_mundo.py "argumento 1" "argumento 2"
        - El tercer parámetro es el nombre del programa con su extensión.
        - El cuarto parámetro son los argumentos para el programa.
        - El quinto y último argumento es NULL.
    */
    char *args[] = {"python", "receiving_args_shell_python.py", "Programa 1", "Hola", "Adiós", ".", NULL};
    // Con excecvp solo mando el nombre del programa como primer argumento,
    //  y con excev tengo que mandar todo el directorio, o así lo entendí.
    execvp(args[0], args);
}
