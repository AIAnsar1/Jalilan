
#ifndef JALILAN_GETLINELIM_HH
#define JALILAN_GETLINELIM_HH


#include <cstdio>



/**
 * =================================================================
 * GetLine()
 * =================================================================
 *
 *
 * =================================================================
 * @param char **Buf
 * @param size_t *BufSiz
 * @param FILE *Fp
 *
 * @return
 */
size_t GetLine(char **Buf, size_t *BufSiz, FILE *Fp);



#if !HAVE_GETLINE
/**
 * =================================================================
 * GetDelim()
 * =================================================================
 *
 *
 * =================================================================
 * @param char **Buf
 * @param size_t *BufSiz
 * @param int Delimiter
 * @param FILE *Fp
 *
 * @return
 */
size_t GetDelim(char **Buf, size_t *BufSiz, int Delimiter, FILE *Fp);
#endif






#endif //JALILAN_GETLINELIM_HH
