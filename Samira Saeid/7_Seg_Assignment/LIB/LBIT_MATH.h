/** 
 * @file LSTD_TYPES.h
 * @author Samira Saeid(samirasaeid264@gmail.com)
 * @brief this files contains the developed c typesdef
 * @version 1.0
 * @date 2022-09-10
 * 
 * 
 */
/*Header file guard*/
#ifndef __LBIT_MATH_H__
#define __LBIT_MATH_H__

/*Bit manipulation operations*/
#define SET_BIT(REG, BIT)    REG |= (1<<BIT)
#define CLEAR_BIT(REG,BIT)   REG &= ~(1<<BIT)
#define TOGGLE_BIT(REG,BIT)  REG ^= (1<<BIT)
#define GET_BIT(REG,BIT)     ((REG>>BIT) & 0X1)

#endif /*LBIT_MATH_H__*/
