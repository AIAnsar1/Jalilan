#ifndef JALILAN_IPRANGE_HH
#define JALILAN_IPRANGE_HH



typedef int jalilan_in_addr_t;

typedef struct Jalilan_Network_Address {
    jalilan_in_addr_t Address;
    int PFX;
} Jalilan_Network_Address_T;



/**
 *
 * =================================================================
 * JalilanAToHl()
 * =================================================================
 *
 *
 *
 *
 * =================================================================
 * @brief
 *
 * @param const char *IpStr
 *
 * @return
 *
 * @note
 */
jalilan_in_addr_t JalilanAToHl(const char *IpStr);


/**
 * =================================================================
 * JalilanNetMask()
 * =================================================================
 *
 *
 *
 *
 * =================================================================
 * @brief
 *
 * @param int Prefix
 *
 * @return
 */
jalilan_in_addr_t JalilanNetMask(int Prefix);


/**
 * =================================================================
 * JalilanNetwork()
 * =================================================================
 *
 *
 *
 *
 * =================================================================
 * @brief
 *
 * @param jalilan_in_addr_t Address
 * @param int Prefix
 *
 * @return
 */
jalilan_in_addr_t JalilanNetwork(jalilan_in_addr_t Address, int Prefix);


/**
 * =================================================================
 * JalilanBroadcast()
 * =================================================================
 *
 *
 *
 *
 * =================================================================
 * @brief
 *
 * @param jalilan_in_addr_t Address
 * @param int Prefix
 *
 * @return
 */
jalilan_in_addr_t JalilanBroadcast(jalilan_in_addr_t Address, int Prefix);


/**
 * =================================================================
 * JalilanStrToNetAddress()
 * =================================================================
 *
 *
 *
 *
 * =================================================================
 * @brief
 *
 * @param const char *IpStr
 *
 * @return
 *
 * @note
 */
Jalilan_Network_Address_T JalilanStrToNetAddress(const char *IpStr);





















#endif //JALILAN_IPRANGE_HH
