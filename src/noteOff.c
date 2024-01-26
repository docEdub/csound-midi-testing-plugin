#include "noteOff.h"

int32_t MidiTesting_NoteOff_init(CSOUND *csound, MidiTesting_NoteOff *p)
{
    (void)p;
    MidiTesting_Common_Init(csound);
    return OK;
}

int32_t MidiTesting_NoteOff_perf(CSOUND *csound, MidiTesting_NoteOff *p)
{
    (void)csound;
    MidiTesting_Common_AddNoteOff(p->channel, p->noteNumber);
    return OK;
}
