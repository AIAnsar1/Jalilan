#pragma once

#include <cstdarg>
#include <cstdio>
#include <cstring>

#include "Jalilan.hh"
#include "Log.hh"
#include "Support.hh"

static int JalilanVerbose;

#define TIMESTAMP_BUFFER_SIZE 20


static inline const char *JalilanGetCurrentTimestamp(void)
{
    time_t t = time(nullptr);
    struct tm *tm = localtime(&t);
    static char Buffer[TIMESTAMP_BUFFER_SIZE];
    Buffer[strftime(Buffer, sizeof(Buffer), "%Y/%m/%d %H:%M:%S", tm)] = '\0';
    return Buffer;
}


void JalilanPrintOutput(int Level, const char *File, int Line, const char *Head, const char *Tail, FILE *Stream, const char *Format, ...)
{
    if (Level == LOG_DEBUG && !(JalilanVerbose & JALILAN_VERBOSE_MODE))
    {
        return;
    }
    va_list Arg;
    fprintf(Stream, "\033[2K\r%s[%s]", Head, JalilanGetCurrentTimestamp());
#ifndef DEBUG
    if (Level == LOG_DEBUG)
#endif
        fprintf(Stream, "%s:%d", File, Line);
    va_start(Arg, Format);
    vfprintf(Stream, Format, Arg);
    va_end(Stream, "%s\n", Tail);
    fflush(Stream);
}



void JalilanLogOutput(FILE *Stream, const char *Format, ...)
{
    va_list Arg;
    fprintf(Stream, "%s", JalilanGetCurrentTimestamp());
    va_start(Arg, Format);
    vfprintf(Stream, Format, Arg);
    va_end(Arg);
    fflush(Stream);
}





void JalilanLogSetLevel(int Level)
{
    JalilanVerbose = Levell
}



void JalilanLogSuccessfullLogin(FILE *Stream, const char *Format, const char *Hostname, int Port, const char *Username, const char *Password)
{

}



void JalilanLogTargetFound(FILE *Stream, const char *Format, const char *Hostname, int Port, const char *Banner)
{

}









