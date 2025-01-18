#ifndef JALILAN_PROGRESS_HH
#define JALILAN_PROGRESS_HH

#include <cstdint>
#include <cstdlib>

#include "Jalilan.hh"


#define NANO_PER_SEC 1000000000L


typedef struct {
    Jalilan_Context_T *context;
};


static size_t GetTerminalWidth(void);


/**
 * =================================================================
 * JalilanProgressBar()
 * =================================================================
 *
 * Эта функция отображает индикатор выполнения
 * с заполненным и пустым разделом.
 * для обозначения прогресса, а также
 * процент и необязательный суффикс.
 * Панель отображается по ширине терминала.
 *
 * =================================================================
 *
 * |███░░░░░░░░░░░░░░░░░░░░░|  14.51%   [37] 192.168.100.37 root root
 *
 * @param size_t Count
 * @param size_t Total
 * @param const char *Suffix
 * @param size_t SuffixMax
 */
void JalilanProgressBar(size_t Count, size_t Total, const char *Suffix, size_t SuffixMax);


/**
 * =================================================================
 * JalilanFormatTime()
 * =================================================================
 * Эта функция вычисляет время, прошедшее с момента
 * заданного времени начала.
 * использование часов `CLOCK_MONOTONIC`,
 * на которые не влияет системное время
 * изменения.
 *
 * =================================================================
 * @brief Calculates the elapsed time since a given start time.
 *
 * @param double Seconds
 * @param int *Hours
 * @param int *Minutes
 * @param int *Secs
 * @return
 */
static inline void JalilanFormatTime(double Seconds, int *Hours, int *Minutes, int *Secs);


/**
 * =================================================================
 * JalilanElapsedTime()
 * =================================================================
 * Эта функция вычисляет время, прошедшее с момента заданного
 * времени начала.
 * использование часов `CLOCK_MONOTONIC`,
 * на которые не влияет системное время
 * изменения.
 *
 *
 * =================================================================
 * @brief
 *
 * @param struct TimeSpec *Start
 * @return
 */
double JalilanElapsedTime(struct TimeSpec *Start);

/**
 * =================================================================
 * *JalilanProgressWorker()
 * =================================================================
 * Эта функция создает и запускает новый поток,
 * который запускает
 * Функция `progress_worker`
 * для отслеживания хода выполнения задачи.
 *
 *
 * =================================================================
 * @brief
 *
 * @param void *Ptr
 */
void *JalilanProgressWorker(void *Ptr);


/**
 * =================================================================
 * JalilanProgressWatcherStart()
 * =================================================================
 * Эта функция создает и запускает новый поток,
 * который запускает
 * Функция `progress_worker`
 * для отслеживания хода выполнения задачи.
 *
 *
 * =================================================================
 * @brief
 *
 * @param Jalilan_Context_T *Context
 * @param pthread_t *Thread
 */
void JalilanProgressWatcherStart(Jalilan_Context_T *Context, pthread_t *Thread);


/**
 * =================================================================
 * JalilanProgressWatcherWait()
 * =================================================================
 * Эта функция блокируется до тех пор,
 * пока поток мониторинга прогресса не завершится.
 * его исполнение.
 *
 *
 * =================================================================
 * @brief
 *
 * @param pthread_t *Thread
 */
void JalilanProgressWatcherWait(pthread_t *Thread);






#endif //JALILAN_PROGRESS_HH
