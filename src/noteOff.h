#ifndef MIDITESTING_NOTEOFF_H
#define MIDITESTING_NOTEOFF_H

#include "common.h"

typedef struct MidiTesting_NoteOff
{
    OPDS h;
    MYFLT *channel;
    MYFLT *noteNumber;
} MidiTesting_NoteOff;

int32_t MidiTesting_NoteOff_init(CSOUND *csound, MidiTesting_NoteOff *p);
int32_t MidiTesting_NoteOff_perf(CSOUND *csound, MidiTesting_NoteOff *p);

#endif
