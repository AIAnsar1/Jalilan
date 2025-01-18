#ifndef JALILAN_CREDENTIALS_HH
#define JALILAN_CREDENTIALS_HH


#include <cstdlib>


#ifndef LOGIN_NAME_MAX
#define LOGIN_NAME_MAX 32
#endif
#ifndef LOGIN_PASSWORD_MAX
#define LOGIN_PASSWORD_MAX 100
#endif


typedef struct {
    char Username[LOGIN_NAME_MAX + 1];
    char Password[LOGIN_PASSWORD_MAX + 1];
} Jalilan_Credentials_T;



typedef struct {
    size_t Length;
    Jalilan_Credentials_T *Credentials;
} Jalilan_Credentials_List_T;


/**
 * =================================================================
 * JalilanCredentialsListInit()
 * =================================================================
 *
 *
 *
 * =================================================================
 * @brief
 *
 * @param Jalilan_Credentials_List_T *Credentials
 */
void JalilanCredentialsListInit(Jalilan_Credentials_List_T *Credentials);

/**
 * =================================================================
 * JalilanCredentialsParse()
 * =================================================================
 *
 *
 *
 * =================================================================
 * @brief
 *
 * @param char *Line
 * @param Jalilan_Credentials_T *DST
 *
 * @return
 */
int JalilanCredentialsParse(char *Line, Jalilan_Credentials_T *DST);

/**
 * =================================================================
 * JalilanCredentialsListLoad()
 * =================================================================
 *
 *
 *
 * =================================================================
 * @brief
 *
 * @param Jalilan_Credentials_List_T *CredentialsList
 * @param char *Filename
 */
void JalilanCredentialsListLoad(Jalilan_Credentials_List_T *CredentialsList, char *Filename);

/**
 * =================================================================
 * JalilanCredentialsListAppend()
 * =================================================================
 *
 *
 *
 * =================================================================
 * @brief
 *
 * @param Jalilan_Credentials_List_T *CredentialsList
 * @param Jalilan_Credentials_T JCT
 */
void JalilanCredentialsListAppend(Jalilan_Credentials_List_T *CredentialsList, Jalilan_Credentials_T JCT);

/**
 * =================================================================
 * JalilanCredentialsListDestroy()
 * =================================================================
 *
 *
 *
 * =================================================================
 * @brief
 *
 * @param Jalilan_Credentials_List_T *CredentialsList
 */
void JalilanCredentialsListDestroy(Jalilan_Credentials_List_T *CredentialsList);


#endif //JALILAN_CREDENTIALS_HH
