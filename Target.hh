#ifndef JALILAN_TARGET_HH
#define JALILAN_TARGET_HH


#include <iostream>
#include <vector>
#include <cstdint>


#define MAX_PORT 65535
#define DEFAULT_PORT 22

struct Jalilan_Target_T {
    std::string Host;
    uint16_t Port;

    Jalilan_Target_T() : Host(""), Port(DEFAULT_PORT) {}
    Jalilan_Target_T(std::string host, uint16_t port = DEFAULT_PORT): Host(std::move(host)), Port(port) {}
};

struct Jalilan_Target_List_T {
    std::vector<Jalilan_Target_T> Targets;
    [[nodiscard]] size_t Length() const {
        return Targets.size();
    };
};



/**
 * =================================================================
 * JalilanTargetPortIsValid()
 * =================================================================
 *
 *
 *
 *
 *
 * =================================================================
 * @brief
 *
 * @param const long Port
 *
 * @return
 */
bool JalilanTargetPortIsValid(long Port);


/**
 * =================================================================
 * *JalilanTargetListCreate()
 * =================================================================
 *
 *
 *
 *
 *
 * =================================================================
 * @brief
 *
 * @return
 */
std::shared_ptr<Jalilan_Target_List_T> JalilanTargetListCreate(void);


/**
 * =================================================================
 * JalilanTargetListDestroy()
 * =================================================================
 *
 *
 *
 *
 *
 * =================================================================
 * @brief
 *
 * @param Jalilan_Target_List_T *TargetList
 */
void JalilanTargetListDestroy(Jalilan_Target_List_T *TargetList);


/**
 * =================================================================
 * JalilanTargetListInit()
 * =================================================================
 *
 *
 *
 *
 *
 * =================================================================
 * @brief
 *
 * @param Jalilan_Target_List_T *TargetList
 */
void JalilanTargetListInit(Jalilan_Target_List_T *TargetList);


/**
 * =================================================================
 * JalilanTargetListAppend()
 * =================================================================
 *
 *
 *
 *
 *
 * =================================================================
 * @brief
 *
 * @param Jalilan_Target_List_T *TargetList
 * @param Jalilan_Target_T *Target
 */
void JalilanTargetListAppend(Jalilan_Target_List_T *TargetList, Jalilan_Target_T *Target);


/**
 * =================================================================
 * JalilanTargetListAppendRange()
 * =================================================================
 *
 *
 *
 *
 *
 * =================================================================
 * @brief
 *
 * @param Jalilan_Target_List_T *TargetList
 * @param const char *Range
 * @param uint16_t Port
 */
void JalilanTargetListAppendRange(Jalilan_Target_List_T *TargetList, const char *Range, uint16_t Port);


/**
 * =================================================================
 * JalilanTargetListLoad()
 * =================================================================
 *
 *
 *
 *
 *
 * =================================================================
 * @brief
 *
 * @param Jalilan_Target_List_T *TargetList
 * @param const char *Filename
 */
void JalilanTargetListLoad(Jalilan_Target_List_T *TargetList, const char *Filename);


/**
 * =================================================================
 * *JalilanTargetParse()
 * =================================================================
 *
 *
 *
 *
 *
 * =================================================================
 * @brief
 *
 * @param char *Line
 *
 * @return
 */
Jalilan_Target_T *JalilanTargetParse(char *Line);

#endif //JALILAN_TARGET_HH
