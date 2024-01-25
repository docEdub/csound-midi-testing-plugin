#ifndef MIDITESTING_COMMON_H
#define MIDITESTING_COMMON_H

#include "csdl.h"

void MidiTesting_Common_Init(CSOUND *csound);
void MidiTesting_Common_AddNoteOn(MYFLT *channel, MYFLT *noteNumber, MYFLT *velocity);
void MidiTesting_Common_AddNoteOff(MYFLT *channel, MYFLT *noteNumber);

#endif
