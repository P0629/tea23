#ifndef GARAGENTOR_H
#define GARAGENTOR_H

#include <stdint.h>

// ----------------------------------------
// Zustände aus dem Zustandsdiagramm
// ----------------------------------------
typedef enum
{
    GARAGENTOR_OFFEN,
    FAHRE_RUNTER,
    STOP_ABWAERTS,
    GARAGENTOR_ZU,
    FAHRE_HOCH,
    STOP_AUFWAERTS
} GarageState;

// ----------------------------------------
// Eingänge (Taste, Endschalter oben/unten)
// ----------------------------------------
typedef struct
{
    uint8_t taste;   // 1 = gedrückt
    uint8_t oben;    // 1 = Endschalter oben aktiv
    uint8_t unten;   // 1 = Endschalter unten aktiv
} GarageInputs;

// ----------------------------------------
// Öffentliche API
// ----------------------------------------
void garage_init(void);
void garage_setInputs(GarageInputs in);
void garage_update(void);
GarageState garage_getState(void);

#endif
