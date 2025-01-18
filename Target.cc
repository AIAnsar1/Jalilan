#pragma once

#include <iostream>
#include <string>
#include <memory>
#include <stdexcept>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#include "Target.hh"
#include "Compat.hh"
#include "IpRange.hh"
#include "Log.hh"




/**
 * =================================================================
 * JalilanTargetPortIsValid()
 * =================================================================
 * * This function verifies if the port number is within
 * the valid range of 1 to 65535.
 *
 * =================================================================
 * @brief
 *
 * @param long Port
 *
 * @return
 */
bool JalilanTargetPortIsValid(long Port)
{
    return Port >= 1 && Port <= MAX_PORT;
}


/**
 * =================================================================
 * *JalilanTargetListCreate()
 * =================================================================
 * Creates a new `Jalilan_Target_List_T` structure and initializes it.
 *
 *
 * =================================================================
 * @brief
 *
 * @return
 */
std::shared_ptr<Jalilan_Target_List_T> JalilanTargetListCreate(void)
{
    return std::make_shared<Jalilan_Target_List_T>();
}


/**
 * =================================================================
 * JalilanTargetListDestroy()
 * =================================================================
 * Destroys and frees a `Jalilan_Target_List_T` structure, ensuring
 * all resources are properly cleaned up.
 *
 * =================================================================
 * @brief
 *
 * @param Jalilan_Target_List_T *TargetList
 */
void JalilanTargetListDestroy(Jalilan_Target_List_T* TargetList)
{
    if (TargetList == NULL) {
        return;
    }

    for (size_t i = 0; i < TargetList->Length; i++) {
        if (TargetList->targets[i].Host != NULL) {
            free(TargetList->Targets[i].Host);
        }
    }

    free(TargetList->Targets);
    TargetList->Length = 0;
    TargetList->Targets = NULL;
}


/**
 * =================================================================
 * JalilanTargetListInit()
 * =================================================================
 * Initializes the `Jalilan_Target_List_T` structure, setting the length
 * to zero and preparing the list for use.
 *
 * =================================================================
 * @brief
 *
 * @param Jalilan_Target_List_T *TargetList
 */
void JalilanTargetListInit(std::shared_ptr<Jalilan_Target_List_T> TargetList)
{
    TargetList->Targets.clear();
    TargetList->Length = 0;
}


/**
 * =================================================================
 * JalilanTargetListAppend()
 * =================================================================
 * Appends a new target to the `Jalilan_Target_List_T`.
 *
 * =================================================================
 * @brief
 *
 * @param Jalilan_Target_List_T *TargetList
 * @param Jalilan_Target_T *Target
 */
void JalilanTargetListAppend(std::shared_ptr<Jalilan_Target_List_T> TargetList, const Jalilan_Target_T &Target)
{
    TargetList->Targets.push_back(Target);
}


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
void JalilanTargetListAppendRange(std::shared_ptr<Jalilan_Target_List_T> TargetList, const std::string &Range, uint16_t Port)
{
    auto SlashPos = Range.find('/');

    if (SlashPos == std::string::npos)
    {
        JalilanTargetListAppend(TargetList, Jalilan_Target_T(Range, Port));
        return;
    }
    std::string BaseIP = Range.substr(0, SlashPos);
    int PrefixLen = std::stoi(Range.substr(SlashPos + 1));

    if (PrefixLen < 0 || PrefixLen > 32)
    {
        throw std::invalid_argument("Invalid CIDR prefix length.");
    }
    struct in_addr Address;

    if (inet_pton(AF_INET, BaseIP.c_str(), &Address) != 1)
    {
        throw std::invalid_argument("Invalid IP address format.");
    }
    uint32_t Mask = ~((1u << (32 - PrefixLen)) - 1);
    uint32_t StartIP = ntohl(Address.s_addr & Mask);
    uint32_t EndIP = ntohl(Address.s_addr | ~Mask);

    for (uint32_t IP = StartIP; IP <= EndIP; ++IP)
    {
        struct in_addr CurrentAddress;
        CurrentAddress.s_addr = htonl(IP);
        char IPStr[INET_ADDRSTRLEN];
        inet_ntop(AF_INET, &CurrentAddress, IPStr, INET_ADDRSTRLEN);
        JalilanTargetListAppend(TargetList, Jalilan_Target_T(IPStr, Port));
    }
}


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
void JalilanTargetListLoad(std::shared_ptr<Jalilan_Target_List_T> TargetList, const std::string &Filename)
{
    std::ifstream File(Filename);
    if (!File)
    {
        throw std::runtime_error("Failed to open file: " + Filename);
    }
    std::string Line;
    int LineNum = 0;

    while (std::getline(File, Line)) {
        LineNum++;

        if (Line.empty() || Line[0] == '#')
        {
            continue;
        }

        try {
            auto ColonPos = Line.find(':');
            std::string Host = Line.substr(0, ColonPos);
            uint16_t Port = DEFAULT_PORT;

            if (ColonPos != std::string::npos)
            {
                Port = std::stoi(Line.substr(ColonPos + 1));

                if (!JalilanTargetPortIsValid(Port))
                {
                    throw std::invalid_argument("Invalid Port.");
                }
            }
            JalilanTargetListAppend(TargetList, Jalilan_Target_T(Host, Port));
        } catch (const std::exception &e) {
            std::cerr << "Error on line " << LineNum << ": " << e.what() << std::endl;
        }
    }
}


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
Jalilan_Target_T *JalilanTargetParse(const std::string &Line)
{
    auto ColonPos = Line.find(':');
    std::string Host = Line.substr(0, ColonPos);
    uint16_t Port = DEFAULT_PORT;

    if (ColonPos != std::string::npos)
    {
        Port = std::stoi(Line.substr(ColonPos + 1));

        if (!JalilanTargetPortIsValid(Port))
        {
            throw std::invalid_argument("Invalid Port");
        }
    }
    return Jalilan_Target_T(Host, Port);
}



