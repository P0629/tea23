#include <fmt/chrono.h>
#include <fmt/format.h>

/*Aufgabe 2*/
// /*Beispiel 1: Der vergessene Geist*/
#include <fmt/format.h>
#include <cstdlib>
#include <cstring>

// #define SOULS 100

// void cursed() {
//     char *soul = (char*)malloc(8);
//     strcpy(soul, "boo!");
//     fmt::println("{}", soul);
//     free(soul);
// }

// int main() {
//     for(int i=0; i < SOULS; i++) {
//         cursed();
//     }
// }

// /*Beispiel 2: Der Zombie-Pointer*/
// int main() {
//     char *ghost = (char*)malloc(8);
//     strcpy(ghost, "evil");
//     free(ghost);
// // use after free
//     fmt::println("{}", ghost);
//     strcpy(ghost, "mad");
//     fmt::println("{}", ghost);
//     char* trap = (char*)malloc(8);
//     strcpy(trap, "caught");
//     fmt::println("trap: {}", trap);
//     fmt::println("ghost: {}", ghost);
// }

// /*Beispiel 3: Der Dämon des unendlichen Wachstums*/
// Stackoverflow
void re_cursed() {
    re_cursed();
}

int main() {
    re_cursed();
    while (1) {
        malloc(1024);
    }
}

/* .bss Segment */
int foo;
int foo2 = 0;

/* .data Segment */
int data = 45;
int data2 = 43;

/* .rodata Segment */
const int rodata = 45;
const int rodata2 = 43;



// void doSomething(int value)
// {
//     value = value + 1;
//     fmt::print("doSomething, value {}\n", value);
// }

// void doSomethingPtr(int* ptr)
// {
//     *ptr = *ptr + 1;
//     fmt::print("doSomethingPtr, value {}\n", *ptr);
// }

// int* doReturnAPtr()
// {
//     int value = 4711;
//     fmt::print("doReturnAPtr, value {}\n", value);
//     return &value;
// }

// void doSomethingStatic()
// {
//     static int value = 56;
//     value = value + 1;
//     fmt::print("doSomethingStatic, value {}\n", value);
// }
// auto main(int argc, char** argv) -> int
// {
//     /**
//      * The {fmt} lib is a cross platform library for printing and formatting text
//      * it is much more convenient than std::cout and printf
//      * More info at https://fmt.dev/latest/api.html
//      */
//     fmt::print("Hello, {}!\n", argv[0]);

//     doSomething(42);
//     int bar = 42;
//     doSomething(bar);
//     fmt::print("The value of bar is: {}\n", bar);

//     doSomethingPtr(&bar);
//     fmt::print("The value of bar after doSomethingPtr is: {}\n", bar);

//     int* returnedPtr = doReturnAPtr();
//     fmt::print("The value of returnedPtr content  after doReturnAPtr is: {}\n", *returnedPtr);
//     doSomething(42);
//     fmt::print("The value of returnedPtr content  after doReturnAPtr is: {}\n", *returnedPtr);

//     doSomethingStatic();
//     doSomethingStatic();
//     doSomethingStatic();
//     doSomethingStatic();

//     fmt::print("Value of foo {} address of foo {}\n", foo, fmt::ptr(&foo));
//     fmt::print("Value of foo2 {} address of foo2 {}\n", foo2, fmt::ptr(&foo2));
//     fmt::print("Value of data {} address of data {}\n", data, fmt::ptr(&data));
//     fmt::print("Value of data2 {} address of data2 {}\n", data2, fmt::ptr(&data2));
//     fmt::print("Value of rodata {} address of rodata {}\n", rodata, fmt::ptr(&rodata));
//     fmt::print("Value of rodata2 {} address of rodata2 {}\n", rodata2, fmt::ptr(&rodata2));

//     int var;
//     static int var2;
//     fmt::print("Value of var {} address of var {}\n", var, fmt::ptr(&var));
//     fmt::print("Value of var2 {} address of var2 {}\n", var2, fmt::ptr(&var2));

//     return 0; /* exit gracefully*/
// }
/*Aufgabe 1*/
/*1) Es entsteht ein Zombie-Pointer --> lokale Variable existiert nach Funktionsende nicht mehr (Pointer zeigt ins Nichts)
2) Undefine Behavior --> Nur Speicher von malloc() oder calloc() darf mit free() freigegeben werden, sonst führt es zu undefiniertem Verhalten
3) Stack Overflow --> Jeder Rekursion legt neue Stackframes an (ohne Abbruch füllt sich Stack bis zum Overflow)
4) Memory Leak --> nicht freigegebener Speicher sammelt sich an

Welche Fehler sind in echten Mikrocontrollersystemen besonders Kritisch?
Memory Leaks und Stack Overflows, da meist kein Betriebssystem und nur begrenzter Speicher vorhanden ist --> Fehler können zu Systemabstürzen der seltsamen Verhalten*/


/*Aufgabe 3*/
/*Stack:
Heap:*/

/*Aufgabe 4*/
/*Wann tritt ein Stack Overflow auf?
-Zu tiefe Rekursion, sehr große lokale Variablen, Endlosschleifen mit Funktionsaufrufen, hohe Verschachtelungstiefen

Warum entstehen Memory leaks?
- wenn dynamische Speicher angefordert werden, aber nicht freigegeben wird
- Speicher bleibt belegt bis das Programm beendet wird

Was ist gefährlicher: Pointer oder Leak?
- Pointer wird früher und heftiger auf die Füße fallen --> undefiniertes Verhalten oder Programmabsturz
- Leak: wird mehrere Tage,Wochen, Monate gut gehen und stürzt dann erst mit Terminated ab

Wie kann man solche Fehler frühzeitig erkennen?
- einfach vermeiden
- Code Reviews
- Tools zur statischen Analyse
- Saubere Programmierdisziplin*/