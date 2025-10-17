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
    fmt::println("Name: {}, Alter: {}\n Wert: {}, Adresse: {}", name, alter, fmt::ptr(&name), fmt::ptr(&alter));
    /*Die Speicheradresse ändert sich minimal*/

    /*Teil 2*/
    fmt::println("Teil 2");
    int localVar = 2;
    static int localVar2 = 2;
    const int localVar3= 2;
    fmt::println("Wert: {}, Adresse: {}", localVar, fmt::ptr(&localVar));
    fmt::println("Wert: {}, Adresse: {}", localVar2, fmt::ptr(&localVar2));
    fmt::println("Wert: {}, Adresse: {}", localVar3, fmt::ptr(&localVar3));
    /*Adresse ändert sich gegenüber zu 1.4 und 1.5, da sie mit 0x7ff anfangen, die static int localVar2 startet gleich wie die globalen*/

    /*Teil 3*/
    fmt::println("Teil 3");
    int* heapVar = new int(3);
    fmt::println("Wert: {}, Adresse: {}", *heapVar, fmt::ptr(&heapVar));

    delete heapVar;
    /*Globale Variablen liegen im Datensegment und existieren während der gesamten Programmlaufzeit.
Lokale Variablen liegen auf dem Stack und werden automatisch beim Funktionsaufruf angelegt und wieder gelöscht.
Dynamisch erzeugte Variablen liegen auf dem Heap und müssen mit delete manuell freigegeben werden.
static beschränkt die Sichtbarkeit, const macht den Wert unveränderlich.*/
    
    /* INSERT YOUR CODE HERE */

    return 0; /* exit gracefully*/
} 