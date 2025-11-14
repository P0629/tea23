#ifndef GARAGENTOR_H
#define GARAGENTOR_H

#include <stdint.h>

// ---------------------------------------------------------
// Zustände des Garagentors (aus dem Zustandsdiagramm)
// ---------------------------------------------------------
typedef enum
{
    GARAGENTOR_OFFEN,
    FAHRE_RUNTER,
    STOP_ABWAERTS,
    GARAGENTOR_ZU,
    FAHRE_HOCH,
    STOP_AUFWAERTS
} GaragentorState;


// ---------------------------------------------------------
// Eingänge (Sensoren + Taste)
//   taste:  1 = gedrückt
//   oben:   1 = Endschalter oben aktiv
//   unten:  1 = Endschalter unten aktiv
// ---------------------------------------------------------
typedef struct
{
    uint8_t taste;
    uint8_t oben;
    uint8_t unten;
} GaragentorInputs;


// ---------------------------------------------------------
// Externe API
//   -> Wird aus main() aufgerufen
// ---------------------------------------------------------

// Initialisiert den Automaten (z. B. Tor = offen, Motor = aus)
void garagentor_init(void);

// Übergibt der State Machine die aktuellen Eingänge
void garagentor_setInputs(GaragentorInputs in);

// Führt einen Schritt im Zustandsautomaten aus
void garagentor_update(void);

// (Optional) Ermöglicht, den Zustand von außen abzufragen
GaragentorState garagentor_getState(void);


#endif // GARAGENTOR_H
