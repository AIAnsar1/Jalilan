#ifndef JALILAN_SUPPORT_HH
#define JALILAN_SUPPORT_HH



#include <cstdint>
#include <string>



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
void JalilanStrCopy(char *Dst, const char *Src, size_t DstSize);

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
std::string JalilanStrReplace(const char *Orig, const char *Rep, const char *With);

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
std::string JalilanStrReplacePlaceholder(const std::string &Input, const std::string &Search, const std::string &Replace);


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
void JalilanStrReplaceEscapeSequences(std::string &Str);


#endif //JALILAN_SUPPORT_HH
