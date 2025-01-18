#pragma once

// #include <assert.h>
// #include <cstdio>
// #include <cstdlib>
// #include <iostream>

#include <memory>
#include <string>
#include <cstring>
#include <stdexcept>

#include "Support.hh"

using namespace std;

/**
 * =================================================================
 * JalilanStrCopy()
 * =================================================================
 * This function ensures that the destination
 * buffer is properly null-terminated
 * and does not exceed its allocated size,
 * preventing buffer overflows.
 *
 * =================================================================
 * @brief Safely copies a string to a destination buffer ensuring null termination.
 *
 * @param char *Dst
 * @param const char *Src
 * @param size_t DstSize
 */
void JalilanStrCopy(char *Dst, const char *Src, size_t DstSize)
{
    if (DstSize == 0)
    {
        throw invalid_argument("Destination Buffer Size Must Be Greater Than Zero.");
    }
    strncpy(Dst, Src, DstSize - 1);
    Dst[DstSize - 1] = '\0';
}

/**
 * =================================================================
 * *JalilanStrReplace()
 * =================================================================
 * This function performs a safe replacement of all
 * occurrences of a target substring
 * with the provided replacement string.
 * If no occurrences are found, the original string is returned.
 *
 *
 * =================================================================
 * @brief Replaces all occurrences of a substring with another substring in a given string.
 *
 * @param const char *Orig
 * @param const char *Rep
 * @param const char *With
 *
 * @return
 */
string JalilanStrReplace(const string &Orig, const string &Rep, const string &With)
{
    string Result;
    size_t StartPost = 0;
    size_t Pos;

    if (Rep.empty())
    {
        throw invalid_argument("Replacement substring cannot be empty.");
    }

    while ((Pos = Orig.find(Rep, StartPost)) != string::npos)
    {
        Result.append(Orig, StartPost, Pos - StartPost);
        Result += With;
        StartPost = Pos + Rep.length();
    }
    Result += Orig.substr(StartPost);
    return Result;

}

/**
 * =================================================================
 * *JalilanStrReplacePlaceholder()
 * =================================================================
 *
 * This function replaces all placeholders (substrings) in the input string
 * with the specified replacement value. It uses the JalilanStrReplace function
 * for the core logic.
 *
 * =================================================================
 * @brief Replaces placeholders in a string with specified values.
 *
 * @param char *Input
 * @param const char *Search
 * @param const char *Replace
 *
 * @return
 */
string JalilanStrReplacePlaceholder(const string &Input, const string &Search, const string &Replace)
{
    return JalilanStrReplace(Input, Search, Replace);
}


/**
 * =================================================================
 * JalilanStrReplaceEscapeSequences()
 * =================================================================
 *
 * Converts sequences like `\n` to a newline and `\t` to a tab character.
 * =================================================================
 * @brief
 *
 * @param string &Str
 */
void JalilanStrReplaceEscapeSequences(string &Str)
{
    string Result;

    for (size_t i = 0; i < Str.size(); ++i)
    {
        if (Str[i] == '\\' && i + 1 < Str.size())
        {
            ++i;

            switch (Str[i])
            {
                case 'n':
                    Result += '\n';
                     break;
                case 't':
                    Result += '\t';
                    break;
                default:
                    Result += '\\';
                    Result += Str[i];
            }
        } else {
            Result += Str[i];
        }
    }
    Str = Result;
}
