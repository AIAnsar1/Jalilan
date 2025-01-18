#ifndef JALILAN_JALILAN_HH
#define JALILAN_JALILAN_HH

#include <cstdio>
#include <pthread.h>

#include "Credentials.hh"
#include "Target.hh"

#define JALILAN_VERBOSE_MODE 0x1
#define JALILAN_VERBOSE_SSH_LIB 0x2

typedef struct {
    int Timeout;
    size_t MaxThreads;
    int ProgressBar;
    int Verbose;
    int DryRun;
    int PerformScan;
    int NonOpenSSH;
    int AllowHoneyPots;
    char *CheckHTTP;
    char *BruteforceOutputFormat;
    char *ScannerOutputFormat;
} Jalilan_Options_T;


typedef struct {
    Jalilan_Options_T Options;
    Jalilan_Credentials_List_T CredentialsList;
    Jalilan_Target_List_T Targets;
    pthread_mutex_t Lock;
    size_t Count;
    size_t SuccessFul;
    size_t Total;
    size_t CredentialsIDX;
    size_t TargetsIDX;
    FILE *Output;
    FILE *ScanOutput;
} Jalilan_Context_T;


/**
 * =================================================================
 * JalilanOptionsInit()
 * =================================================================
 * Эта функция устанавливает значения по умолчанию
 * для параметров, используемых в брутте.
 * силовой инструмент.
 * =================================================================
 * @brief
 * @param Jalilan_Options_T *Options
 */
void JalilanOptionsInit(Jalilan_Options_T *Options);

/**
 * =================================================================
 * JalilanContextInit()
 * =================================================================
 * Эта функция инициализирует структуру контекста,
 * включая встроенные
 * параметры, список учетных данных и целевой
 * список со значениями по умолчанию.
 * =================================================================
 * @brief
 * @param Jalilan_Context_T *Context
 */
void JalilanContextInit(Jalilan_Context_T *Context);


/**
 * =================================================================
 * JalilanContextDestroy()
 * =================================================================
 * Эта функция освобождает любые ресурсы,
 * связанные с контекстом, включая
 * мьютексы, список учетных данных и список
 * целей. Его следует вызывать, когда
 * контекст больше не нужен
 * во избежание утечек памяти.
 * =================================================================
 * @brief
 * @param Jalilan_Context_T *Context
 */
void JalilanContextDestroy(Jalilan_Context_T *Context);













#endif //JALILAN_JALILAN_HH
