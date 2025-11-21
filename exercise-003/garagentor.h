// #ifndef GARAGENTOR_H
// #define GARAGENTOR_H

// typedef enum {
//     STATE_CLOSED,
//     STATE_OPEN,
//     STATE_UP,
//     STATE_DOWN,
//     STATE_STOP_UP,
//     STATE_STOP_DOWN
// } TorState;

// // Ereignisse
// typedef enum {
//     EVENT_TASTE,
//     EVENT_ENDSCHALTER_OBEN,
//     EVENT_ENDSCHALTER_UNTEN
// } TorEvent;

// void tor_init();
// TorState tor_getState();
// void tor_handleEvent(TorEvent e);

// #endif

// #ifndef GARAGENTOR_H
// #define GARAGENTOR_H

// #ifdef __cplusplus
// extern "C" {
// #endif

// typedef enum {
//     STATE_CLOSED,
//     STATE_OPEN,
//     STATE_UP,
//     STATE_DOWN,
//     STATE_STOP_UP,
//     STATE_STOP_DOWN
// } TorState;

// typedef enum {
//     EVENT_TASTE,
//     EVENT_ENDSCHALTER_OBEN,
//     EVENT_ENDSCHALTER_UNTEN
// } TorEvent;

// void tor_init();
// TorState tor_getState();
// void tor_handleEvent(TorEvent e);

// #ifdef __cplusplus
// }
// #endif

// #endif

#ifndef GARAGENTOR_H
#define GARAGENTOR_H

#ifdef __cplusplus
extern "C" {
#endif

// -----------------------------
// Zustände
// -----------------------------
typedef enum {
    STATE_CLOSED,    // Tor ist unten geschlossen
    STATE_OPEN,      // Tor ist oben offen
    STATE_UP,        // Tor fährt hoch
    STATE_DOWN,      // Tor fährt runter
    STATE_STOP_UP,   // Tor gestoppt auf dem Weg nach oben
    STATE_STOP_DOWN  // Tor gestoppt auf dem Weg nach unten
} TorState;

// -----------------------------
// Ereignisse
// -----------------------------
typedef enum {
    EVENT_TASTE,             // Taste gedrückt
    EVENT_ENDSCHALTER_OBEN,  // Oberer Endschalter erreicht
    EVENT_ENDSCHALTER_UNTEN  // Unterer Endschalter erreicht
} TorEvent;

// -----------------------------
// Funktionen
// -----------------------------
void tor_init();
TorState tor_getState();
void tor_handleEvent(TorEvent e);

#ifdef __cplusplus
}
#endif

// -----------------------------
// Implementierung (einmal definieren)
// -----------------------------
#ifdef GARAGENTOR_IMPLEMENTATION

static TorState state;

void tor_init() {
    state = STATE_UP;   // Start: Tor fährt hoch
}

TorState tor_getState() {
    return state;
}

void tor_handleEvent(TorEvent e) {
    switch(state) {
        case STATE_CLOSED:
            if (e == EVENT_TASTE) state = STATE_UP;
            break;

        case STATE_UP:
            if (e == EVENT_TASTE) state = STATE_STOP_UP;
            else if (e == EVENT_ENDSCHALTER_OBEN) state = STATE_OPEN;
            break;

        case STATE_STOP_UP:
            if (e == EVENT_TASTE) state = STATE_DOWN;
            break;

        case STATE_OPEN:
            if (e == EVENT_TASTE) state = STATE_DOWN;
            break;

        case STATE_DOWN:
            if (e == EVENT_TASTE) state = STATE_STOP_DOWN;
            else if (e == EVENT_ENDSCHALTER_UNTEN) state = STATE_CLOSED;
            break;

        case STATE_STOP_DOWN:
            if (e == EVENT_TASTE) state = STATE_UP;
            break;
    }
}

#endif // GARAGENTOR_IMPLEMENTATION

#endif // GARAGENTOR_H
