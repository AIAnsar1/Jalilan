#ifndef JALILAN_DETECTION_HH
#define JALILAN_DETECTION_HH

#include <cstddef>
#include <cstdint>

#include <pthread.h>
#include <libssh/libssh.h>

#include "Jalilan.hh"
#include "Target.hh"
#include "Log.hh"

#define BUF_SIZE 1024
#define BANNER_LEN 256

Jalilan_Target_List_T Filtered;

static pthread_mutex_t Mutex = PTHREAD_MUTEX_INITIALIZER;

typedef struct {
    Jalilan_Context_T *Context;
    Jalilan_Target_List_T *TargetList;
} Jalilan_Detection_Args_T;


/**
 * =================================================================
 * JalilanDetectionLoginMethods()
 * =================================================================
 * Определите, работает ли служба SSH и поддерживает ли она
 * аутентификация по паролю.
 *
 * Эта функция подключается к SSH-серверу и проверяет его баннер и
 * методы аутентификации, чтобы определить,
 * является ли это действительной службой SSH и есть ли
 * поддерживает аутентификацию по паролю.
 *
 * =================================================================
 * @param ssh_session Session
 * @param const char *Hostname
 * @param int Port
 *
 * @return
 */
int JalilanDetectionLoginMethods(ssh_session Session, const char *Hostname, int Port);

/**
 * =================================================================
 * JalilandetectionDelectSSH()
 * =================================================================
 * Определите, работает ли служба SSH и поддерживает ли она
 * аутентификация по паролю.
 *
 * Эта функция подключается к SSH-серверу и проверяет его баннер и
 * методы аутентификации, чтобы определить,
 * является ли это действительной службой SSH и есть ли
 * поддерживает аутентификацию по паролю.
 *
 * =================================================================
 * @param Jalilan_Context_T *CTX
 * @param const char *Hostname
 * @param uint16_t Port
 * @param long Tm
 *
 * @return
 */
int JalilandetectionDelectSSH(Jalilan_Context_T *CTX, const char *Hostname, uint16_t Port, long Tm);

/**
 * =================================================================
 * JalilanDetectionProcess()
 * =================================================================
 * Функция потока для обработки обнаружения каждой цели.
 *
 * Эта функция обрабатывает цели из списка
 * целей, обнаруживает службы SSH.
 * и их методы аутентификации, а также
 * обновляет отфильтрованный целевой список.
 *
 * =================================================================
 *
 * @param void *Ptr
 *
 * @return
 */
void *JalilanDetectionProcess(void *Ptr);

/**
 * =================================================================
 * JalilanDetectionStart()
 * =================================================================
 * Запустите процесс обнаружения с помощью нескольких потоков.
 *
 * Эта функция инициализирует и запускает несколько
 * потоков для обработки цели.
 * список и обнаружение служб SSH. Он ожидает
 * завершения всех потоков, прежде чем
 * обновление целевого списка с результатами.
 *
 * =================================================================
 * @param Jalilan_Context_T *Context
 * @param Jalilan_Target_List_T *Source
 * @param Jalilan_Target_List_T *Target
 * @param size_t MaxThreads
 */
void JalilanDetectionStart(Jalilan_Context_T *Context, Jalilan_Target_List_T *Source, Jalilan_Target_List_T *Target, size_t MaxThreads);





#endif //JALILAN_DETECTION_HH
