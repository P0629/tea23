#include <fmt/chrono.h>
#include <fmt/format.h>

#include "config.h"
void changeValueByParameter(int value);
void changeValueByPointer(int* ptr);

int main(int argc, char **argv) {

    /**
     * The {fmt} lib is a cross platform library for printing and formatting text
     * it is much more convenient than std::cout and printf
     * More info at https://fmt.dev/latest/api.html
     */
    fmt::print("Hello, {} in version {}!\n", tea::PROJECT_NAME, tea::PROJECT_VER);
/*Teil 0*/
    for (int i=0; i< argc; i++) {
        fmt::println("argc: {}, argument {} (Adresse: {})", i, argv[i], fmt::ptr(argv[i]));
    }
    fmt::println("Teil 1");
    int foo = 10;
    int* ptr = &foo;
    *ptr = 42;
    fmt::println("int foo = 10;");
    fmt::println("int* ptr = &foo;");
    fmt::println("Adresse von foo: {} Adresse im pointer ptr: {}", fmt::ptr(&foo), fmt::ptr(ptr));
    int bar = 4711;
    ptr = &bar;
    *ptr = foo;     /*was steht in bar?*/
    fmt::print("bar = {}", bar);

    fmt::println("Teil 2");
    double* d = new double(3.1415);   // Speicher reservieren UND initialisieren
    fmt::println("Wert: {}", *d);    // Zugriff über Dereferenzierung
    fmt::println("Adresse von d: {}", fmt::ptr(d));
    delete d;                         // Speicher freigeben
    return 0; /* exit gracefully*/
}

void changeValueByParameter(int value) {
    value = 4711;
    fmt::println("Der Wert von value in der Funktion (changeValueByParameter): {}", value);
}

void changeValueByPointer(int* ptr) {
    *ptr = 4711;
    fmt::println("Der Wert von value in der Funktion (changeValueByPointer): {}", *ptr);
    fmt::println("Die Adresse von ptr in der Funktion (changeValueByPointer): {}", fmt::ptr(ptr));
}