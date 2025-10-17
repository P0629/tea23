#include <fmt/chrono.h>
#include <fmt/format.h>

#include "config.h"

/*Globale Variablen sind außerhalb einer Funktion*/
int globalVar = 1;
char name[] = "Peter";
int alter = 25;

int main(int argc, char **argv) {

    /**
     * The {fmt} lib is a cross platform library for printing and formatting text
     * it is much more convenient than std::cout and printf
     * More info at https://fmt.dev/latest/api.html
     */
    fmt::print("Hello, {}!\n", tea::PROJECT_NAME);
    fmt::println("Teil 1");
    fmt::println("Wert: {}, Adresse: {}", globalVar, fmt::ptr(&globalVar));
    fmt::print("Name: {}, Alter: {}\n Wert: {}, Adresse: {}", name, alter, fmt::ptr(&name), fmt::ptr(&alter));
    /* INSERT YOUR CODE HERE */

    return 0; /* exit gracefully*/
}
