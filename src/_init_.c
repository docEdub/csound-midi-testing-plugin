#include "noteOn.h"
#include "noteOff.h"

static OENTRY localops[] = {
    {
        .opname = "midiTesting_noteOn",
        .dsblksiz = sizeof(MidiTesting_NoteOn),
        .thread = 3,
        .outypes = "",
        .intypes = "kkk",
        .iopadr = (SUBR) MidiTesting_NoteOn_init,
        .kopadr = (SUBR) MidiTesting_NoteOn_perf,
        .aopadr = NULL
    },
    {
        .opname = "midiTesting_noteOff",
        .dsblksiz = sizeof(MidiTesting_NoteOff),
        .thread = 3,
        .outypes = "",
        .intypes = "kk",
        .iopadr = (SUBR) MidiTesting_NoteOff_init,
        .kopadr = (SUBR) MidiTesting_NoteOff_perf,
        .aopadr = NULL
    },
};

LINKAGE
