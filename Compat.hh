#ifndef JALILAN_COMPAT_HH
#define JALILAN_COMPAT_HH


#include <cstdio>




/**
 * =================================================================
 * JalilanGetDelim()
 * =================================================================
 * Эта функция читает строку из указанного
 * потока, разделенную знаком
 * указанный персонаж. Он предназначен
 * для платформ, которые не поддерживают
 * функция getdelim.
 *
 * =================================================================
 * @brief
 * @param char **Buf
 * @param size_t *BufSiz
 * @param int Delimiter
 * @param FILE *Fp
 * @return
 */
#if !HAVE_GETDELIM
size_t JalilanGetDelim(char **Buf, size_t *BufSiz, int Delimiter, FILE *Fp);
#endif





/**
 * =================================================================
 * JalilanGetLine()
 * =================================================================
 * Эта функция читает строку из указанного
 * потока, останавливаясь в конце
 * строки или конца файла. Он предназначен
 * для платформ, которые не поддерживают
 * поддержка функции getline.
 * =================================================================
 * @brief
 * @param char **Buf
 * @param size_t *BufSize
 * @param FILE *Fp
 * @return
 */
#if HAVE_GETLINE
size_t JalilanGetLine(char **Buf, size_t *BufSize, FILE *Fp);
#endif





#endif //JALILAN_COMPAT_HH
