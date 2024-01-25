#ifndef MIDITESTING_NOTEON_H
#define MIDITESTING_NOTEON_H

#include "common.h"

typedef struct MidiTesting_NoteOn
{
    OPDS h;
    MYFLT *channel;
    MYFLT *noteNumber;
    MYFLT *velocity;
} MidiTesting_NoteOn;

int32_t MidiTesting_NoteOn_init(CSOUND *csound, MidiTesting_NoteOn *p);
int32_t MidiTesting_NoteOn_perf(CSOUND *csound, MidiTesting_NoteOn *p);

#endif
