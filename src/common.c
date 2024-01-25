#include "common.h"

static int initialized = 0;
static unsigned char midiBuffer[1024];
static size_t midiBufferIndex = 0;


static int callback(CSOUND *csound, void *userData, unsigned char *buf, int nBytes)
{
    (void) csound;
    (void) userData;

    if (midiBufferIndex == 0) {
        return OK;
    }

    int byteCount = midiBufferIndex;
    int readEntireBuffer = 1;
    if (byteCount > nBytes) {
        byteCount = nBytes;
        readEntireBuffer = 0;
    }

    memcpy(buf, midiBuffer, byteCount);
    if (readEntireBuffer) {
        midiBufferIndex = 0;
    }
    else {
        midiBufferIndex -= byteCount;
        memmove(midiBuffer, midiBuffer + byteCount, midiBufferIndex);
    }

    return OK;
}


void MidiTesting_Common_Init(CSOUND *csound)
{
    if (initialized) {
        return;
    }
    initialized = 1;
    csound->SetExternalMidiReadCallback(csound, callback);
}


void MidiTesting_Common_AddNoteOn(MYFLT *channel, MYFLT *noteNumber, MYFLT *velocity)
{
    if (midiBufferIndex + 3 > sizeof(midiBuffer)) {
        return;
    }

    midiBuffer[midiBufferIndex++] = 0x90 | (char)*channel;
    midiBuffer[midiBufferIndex++] = (char)*noteNumber;
    midiBuffer[midiBufferIndex++] = (char)*velocity;
}


void MidiTesting_Common_AddNoteOff(MYFLT *channel, MYFLT *noteNumber)
{
    if (midiBufferIndex + 3 > sizeof(midiBuffer)) {
        return;
    }

    midiBuffer[midiBufferIndex++] = 0x80 | (char)*channel;
    midiBuffer[midiBufferIndex++] = (char)*noteNumber;
    midiBuffer[midiBufferIndex++] = 0;
}
