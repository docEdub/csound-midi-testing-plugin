#include "noteOn.h"

int32_t MidiTesting_NoteOn_init(CSOUND *csound, MidiTesting_NoteOn *p)
{
    (void)p;
    MidiTesting_Common_Init(csound);
    return OK;
}

int32_t MidiTesting_NoteOn_perf(CSOUND *csound, MidiTesting_NoteOn *p)
{
    (void)csound;
    MidiTesting_Common_AddNoteOn(p->channel, p->noteNumber, p->velocity);
    return OK;
}
