// #include "garagentor.h"

// static TorState state;

// void tor_init() {
//     state = STATE_UP;   // [*] --> Up
// }

// TorState tor_getState() {
//     return state;
// }

// void tor_handleEvent(TorEvent e) {
//     switch(state) {

//     case STATE_CLOSED:
//         if (e == EVENT_TASTE)
//             state = STATE_UP;
//         break;

//     case STATE_UP:
//         if (e == EVENT_TASTE)
//             state = STATE_STOP_UP;
//         else if (e == EVENT_ENDSCHALTER_OBEN)
//             state = STATE_OPEN;
//         break;

//     case STATE_STOP_UP:
//         if (e == EVENT_TASTE)
//             state = STATE_DOWN;
//         break;

//     case STATE_OPEN:
//         if (e == EVENT_TASTE)
//             state = STATE_DOWN;
//         break;

//     case STATE_DOWN:
//         if (e == EVENT_TASTE)
//             state = STATE_STOP_DOWN;
//         else if (e == EVENT_ENDSCHALTER_UNTEN)
//             state = STATE_CLOSED;
//         break;

//     case STATE_STOP_DOWN:
//         if (e == EVENT_TASTE)
//             state = STATE_UP;
//         break;
//     }
// }
