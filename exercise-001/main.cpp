#include <fmt/chrono.h>
#include <fmt/format.h>

#include "config.h"

/*Globale Variablen sind außerhalb einer Funktion*/
int globalVar = 1;
char name[] = "Peter";
int alter = 25;
const int globalVar2 = 1;
static int globalVar3 =1;

int main(int argc, char **argv) {

    /**
     * The {fmt} lib is a cross platform library for printing and formatting text
     * it is much more convenient than std::cout and printf
     * More info at https://fmt.dev/latest/api.html
     */
    fmt::print("Hello, {}!\n", tea::PROJECT_NAME);

    /*Teil 1*/
    fmt::println("Teil 1");
    fmt::println("Wert: {}, Adresse: {}", globalVar, fmt::ptr(&globalVar));
    fmt::println("Wert: {}, Adresse: {}", globalVar2, fmt::ptr(&globalVar2));
    fmt::println("Wert: {}, Adresse: {}", globalVar3, fmt::ptr(&globalVar3));
    fmt::print("Name: {}, Alter: {}\n Wert: {}, Adresse: {}", name, alter, fmt::ptr(&name), fmt::ptr(&alter));
    /*Die Speicheradresse ändert sich minimal*/

    /*Teil 2*/
    fmt::println("Teil 2");

    /* INSERT YOUR CODE HERE */

    return 0; /* exit gracefully*/
}
