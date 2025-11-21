// #include <iostream>
// #include "garagentor.h"

// using namespace std;

// int main() {
//     tor_init();

//     while(true) {
//         cout << "Aktueller Zustand: " << tor_getState() << endl;
//         cout << "Ereignis? (t = Taste, o = End oben, u = End unten): ";

//         char c;
//         cin >> c;

//         switch(c) {
//             case 't': tor_handleEvent(EVENT_TASTE); break;
//             case 'o': tor_handleEvent(EVENT_ENDSCHALTER_OBEN); break;
//             case 'u': tor_handleEvent(EVENT_ENDSCHALTER_UNTEN); break;
//             default: cout << "Unbekanntes Ereignis\n";
//         }
//     }
// }

#include <iostream>
#define GARAGENTOR_IMPLEMENTATION
#include "garagentor.h"

using namespace std;

// Hilfsfunktion: Zustand in lesbaren Text umwandeln
const char* stateToString(TorState s) {
    switch(s) {
        case STATE_CLOSED: return "Closed";
        case STATE_OPEN: return "Open";
        case STATE_UP: return "Up";
        case STATE_DOWN: return "Down";
        case STATE_STOP_UP: return "StopUp";
        case STATE_STOP_DOWN: return "StopDown";
        default: return "Unknown";
    }
}

int main() {
    tor_init();

    // Array mit Ereignissen für die Simulation
    TorEvent events[] = {
        EVENT_TASTE,             // Taste -> Tor fährt hoch
        EVENT_ENDSCHALTER_OBEN,  // Obere Grenze -> Tor offen
        EVENT_TASTE,             // Taste -> Tor fährt runter
        EVENT_ENDSCHALTER_UNTEN, // Untere Grenze -> Tor geschlossen
        EVENT_TASTE,             // Taste -> Tor fährt hoch
        EVENT_TASTE,             // Taste -> Tor stoppt auf dem Weg hoch
        EVENT_TASTE,             // Taste -> Tor fährt runter
        EVENT_ENDSCHALTER_UNTEN  // Untere Grenze -> Tor geschlossen
    };

    int numEvents = sizeof(events) / sizeof(events[0]);

    for(int i=0; i<numEvents; i++) {
        tor_handleEvent(events[i]);
        cout << "Ereignis " << i << ": aktueller Zustand = " 
             << stateToString(tor_getState()) << endl;
    }

    return 0;
}
