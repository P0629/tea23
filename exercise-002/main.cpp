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

/*Aufgabe 5*/
#include <fmt/format.h>
#include "graveyard.h"

int undead = 7;

int main() {
    fmt::println("🪦 Globale Variable sagt: {}", undead);
    awaken();
    persistent();
    persistent();
    fmt::println("🪦 Globale Variable nach Aufruf: {}", undead);
}