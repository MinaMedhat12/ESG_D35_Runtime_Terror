
/*Header file guard*/
#ifndef __HPBUTT_INTERFACE_H__
#define __HPBUTT_INTERFACE_H__

/***************************************************************************************************/
/*                                         Interfacing macros                                      */
/***************************************************************************************************/

#define PBUTT0     (0)
#define PBUTT1     (1)
#define PBUTT2     (2)

/*push button status*/

#define pressed     (1)
#define released    (0)

/***************************************************************************************************/
/*                                        Functions' prototypes                                    */
/***************************************************************************************************/

void hpbutt_init(u8_t au8_pbuttNumber);

void hpbutt_status(u8_t au8_pbuttNumber , u8_t* pu8_pbuttStatus);



#endif