#ifndef JALILAN_ATTACKFLOOD_HH
#define JALILAN_ATTACKFLOOD_HH

#include <cstdint>

#include "Jalilan.hh"

typedef int Jalilan_attack;





/**
 * =================================================================
 * JalilanAttackSSHLoginFlood()
 * =================================================================
 * Попытайтесь взломать вход по SSH,
 * используя предоставленные учетные данные.
 * Эта функция пытается войти на SSH-сервер,
 * используя указанное имя хоста.
 * порт, имя пользователя и пароль.
 * Он выполняет попытку грубой силы и обрабатывает
 * любые связанные ошибки.
 * =================================================================
 * @param Jalilan_Context_T *Context
 * @param const char *Hostname
 * @param uint16_t Port
 * @param const char *Username
 * @param const char *Password
 * @return
 */
Jalilan_attack JalilanAttackSSHLoginFlood(Jalilan_Context_T *Context, const char *Hostname, uint16_t Port, const char *Username, const char *Password);


/**
 * =================================================================
 * JalilanAttackSSHTryLoginFlood()
 * =================================================================
 * Попробуйте войти на SSH-сервер с указанными учетными данными.
 * Эта функция пытается выполнить одну попытку входа в систему,
 * используя предоставленные учетные данные и
 * возвращает результат попытки.
 * =================================================================
 * @param Jalilan_Context_T *Context
 * @param const char *Hostname
 * @param uint16_t Port
 * @param const char *Username
 * @param const char *Password
 * @return
 */
Jalilan_attack JalilanAttackSSHTryLoginFlood(Jalilan_Context_T *Context, const char *Hostname, uint16_t Port, const char *Username, const char *Password);


/**
 * =================================================================
 * JalilanAttackFloodService()
 * =================================================================
 * Запустите процесс входа в систему по SSH методом грубой силы.
 * Эта функция инициализирует и запускает процесс перебора,
 * включая установку
 * создание необходимых потоков и обработка атаки грубой силы.
 * =================================================================
 * @param Jalilan_Context_T *Context
 */
void JalilanAttackFloodService(Jalilan_Context_T *Context);






#endif //JALILAN_ATTACKFLOOD_HH
