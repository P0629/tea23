#include <fmt/chrono.h>
#include <fmt/format.h>

#include "config.h"

/*Globale Variablen sind außerhalb einer Funktion*/
int globalVar = 1;
char name[] = "Peter";
int alter = 25;
const int globalVar2 = 1;
static int globalVar3 =1;

void foo()      /*Teil 4*/
    { fmt::print("Hello from foo!\n"); }

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
    
    /*Teil 4*/
    fmt::println("Teil 4");
    foo();
    fmt::print("Adresse von foo: {}\\n", fmt::ptr(&foo));
    /* INSERT YOUR CODE HERE */

    return 0; /* exit gracefully*/
} 

/*Zusatz*/

/*Welche Art von Variablen wo gespeichert wird.
Warum es wichtig ist, zwischen Stack und Heap zu unterscheiden.
Welche Rolle Zeiger in diesem Zusammenhang spielen.
Erstellen Sie eine Skizze des gesamten Arbeitsspeicher.*/

/*
Fazit: Speichersegmente in C++

In C++ werden Daten je nach Art in verschiedene Speicherbereiche gelegt:

Globale und statische Variablen liegen im Datensegment.
Initialisierte Werte kommen ins .data-, nicht initialisierte ins .bss-Segment.
const-Daten befinden sich im schreibgeschützten Bereich (.rodata).

Lokale Variablen liegen auf dem Stack.
Er wird automatisch verwaltet und ist sehr schnell.
Mit static bleibt eine lokale Variable jedoch dauerhaft im Datensegment.

Dynamisch erzeugte Variablen (mittels new) liegen im Heap, der manuell mit delete verwaltet werden muss.

Funktionen liegen im Code-Segment, wo der ausführbare Programmcode gespeichert ist.

---------------
Wichtig !!!
---------------

Stack und Heap unterscheiden sich in Lebensdauer und Verwaltung.
Zeiger sind notwendig, um auf Speicher im Heap zuzugreifen und machen sichtbar, wo Daten tatsächlich liegen.
-------------------------------------------------------------------------------------------------------------

Skizze Arbeitsspeicher:

+------------------------+
| Code-Segment (Text)    |  → Funktionen, ausführbarer Code
+------------------------+
| Data-Segment           |  → globale/statische Variablen
|  - .data (init)        |
|  - .bss (uninit)       |
|  - .rodata (const)     |
+------------------------+
| Heap                   |  → dynamisch angeforderter Speicher (new/delete)
|         ↑ wächst nach oben
+------------------------+
| Stack                  |  → lokale Variablen, Funktionsaufrufe
|         ↓ wächst nach unten
+------------------------+

*/