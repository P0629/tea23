#include "garagentor.h"

// interne Variablen
static GaragentorState state;
static GaragentorInputs inputs;

// Hardware-Funktionen (kannst du auch in motor.c auslagern)
static void motor_up(void)   { /* ... */ }
static void motor_down(void) { /* ... */ }
static void motor_stop(void) { /* ... */ }

void garage_init(void)
{
    state = GARAGENTOR_OFFEN;
    motor_stop();
}

void garage_setInputs(GaragentorInputs in)
{
    inputs = in;
}

void garage_update(void)
{
    switch(state)
    {
        case GARAGENTOR_OFFEN:
            if (inputs.taste) {
                motor_down();
                state = FAHRE_RUNTER;
            }
            break;

        case FAHRE_RUNTER:
            if (inputs.unten) {
                motor_stop();
                state = GARAGENTOR_ZU;
            } else if (inputs.taste) {
                motor_stop();
                state = STOP_ABWAERTS;
            }
            break;

        case STOP_ABWAERTS:
            if (inputs.taste) {
                motor_up();
                state = FAHRE_HOCH;
            }
            break;

        case GARAGENTOR_ZU:
            if (inputs.taste) {
                motor_up();
                state = FAHRE_HOCH;
            }
            break;

        case FAHRE_HOCH:
            if (inputs.oben) {
                motor_stop();
                state = GARAGENTOR_OFFEN;
            } else if (inputs.taste) {
                motor_stop();
                state = STOP_AUFWAERTS;
            }
            break;

        case STOP_AUFWAERTS:
            if (inputs.taste) {
                motor_down();
                state = FAHRE_RUNTER;
            }
            break;
    }
}
