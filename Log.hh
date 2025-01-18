#ifndef JALILAN_LOG_HH
#define JALILAN_LOG_HH


#include <cstdio>


enum {
    LOG_TRACE,
    LOG_DEBUG,
    LOG_INFO,
    LOG_WARNING,
    LOG_ERROR,
    LOG_FATAL,
};


/**
 * =================================================================
 * JalilanLogError()
 * =================================================================
 * Этот макрос вызывает print_output с уровнем LOG_ERROR, красный цвет для
 * сообщение, включающее информацию о файле и строке.
 *
 * =================================================================
 * @brief
 *
 * @param ...
 */
#define JalilanLogError(...) JalilanPrintOutput(LOG_ERROR, __FILE__, __LINE__, "\033[91m", stderr, __VA_ARGS__)


/**
 * =================================================================
 * JalilanLogWarning()
 * =================================================================
 * Этот макрос вызывает print_output с уровнем
 * LOG_WARN и включает файл
 * и информация о строке.
 * =================================================================
 * @brief
 *
 * @param ...
 */
#define JalilanLogWarning(...) JalilanPrintOutput(LOG_WARNING, __FILE__, __LINE__, "", "", stderr, __VA_ARGS__)

/**
 * =================================================================
 * JalilanLogDebug()
 * =================================================================
 * Этот макрос вызывает print_output с уровнем LOG_DEBUG,
 * серый цвет для
 * сообщение, включающее информацию о файле и строке.
 * =================================================================
 * @brief
 *
 * @param ...
 */
#define JalilanLogDebug(...) JalilanPrintOutput(LOG_DEBUG, __FILE__, __LINE__, "\033[37m", "\033[0m", stderr, __VA__ARGS__)

/**
 * =================================================================
 * JalilanLogInfo()
 * =================================================================
 * Этот макрос вызывает print_output с уровнем LOG_INFO и
 * записывает в
 * стандартный вывод.
 *
 * =================================================================
 * @brief
 *
 *
 * @param ...
 */
#define JalilanLogInfo(...) JalilanPrintOutput(LOG_INFO, __FILE__, __LINE__, "", "", stdout, __VA_ARGS__)



static inline const char *JalilanGetCurrentTimestamp(void);


/**
 * =================================================================
 * JalilanPrintOutput()
 * =================================================================
 *
 *
 *
 *
 * =================================================================
 * @brief
 *
 * @param int Level
 * @param const char *File
 * @param int Line
 * @param const char *Head
 * @param const char *Tail
 * @param FILE *Stream
 * @param const char *Format
 * @param ...
 */
void JalilanPrintOutput(int Level, const char *File, int Line, const char *Head, const char *Tail, FILE *Stream, const char *Format, ...);


/**
 * =================================================================
 * JalilanLogOutput()
 * =================================================================
 *
 *
 *
 *
 * =================================================================
 * @brief
 *
 * @param FILE *Stream
 * @param const char *Format
 * @param ...
 */
void JalilanLogOutput(FILE *Stream, const char *Format, ...);


/**
 * =================================================================
 * JalilanLogSetLevel()
 * =================================================================
 * Эта функция устанавливает глобальный уровень
 * детализации журнала на основе заданного
 * параметр уровня. Уровень детализации можно
 * использовать для управления количеством
 * подробный вывод в сообщениях журнала.
 *
 * Уровень детализации обычно представляет
 * собой поразрядное ИЛИ различных флагов, которые
 * включить различные уровни детализации.
 * Например, следующие флаги могут
 * комбинироваться:
 * - `CBRUTEKRAG_VERBOSE_MODE` (0x1): включает базовое подробное ведение журнала.
 * - `CBRUTEKRAG_VERBOSE_SSHLIB` (0x2): включает подробное ведение журнала для библиотеки SSH.
 *
 *
 * =================================================================
 * @brief
 *
 * Example usage:
 * @code
 * options->verbose |= CBRUTEKRAG_VERBOSE_MODE;
 * log_set_level(options->verbose);
 * @endcode
 *
 * @param int Level
 */
void JalilanLogSetLevel(int Level);

/**
 * =================================================================
 * JalilanLogSuccessfullLogin()
 * =================================================================
 *
 *
 *
 *
 * =================================================================
 * @brief
 *
 * @param FILE *Stream
 * @param const char *Format
 * @param const char *Hostname
 * @param int Port
 * @param const char *Username
 * @param const char *Password
 */
void JalilanLogSuccessfullLogin(FILE *Stream, const char *Format, const char *Hostname, int Port, const char *Username, const char *Password);

/**
 * =================================================================
 * JalilanLogTargetFound()
 * =================================================================
 *
 *
 *
 *
 * =================================================================
 * @brief
 *
 * @param const char *Format
 * @param const char *Hostname
 * @param int Port
 * @param const char *Banner
 */
void JalilanLogTargetFound(FILE *Stream, const char *Format, const char *Hostname, int Port, const char *Banner);





#endif //JALILAN_LOG_HH
