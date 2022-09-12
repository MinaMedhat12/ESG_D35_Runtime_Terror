#ifndef TYPEDEF_H
#define TYPEDEF_H

/** Standard data types **/
typedef unsigned char u8_t;
typedef unsigned short int u16_t;
typedef unsigned long int u32_t;


typedef signed char s8_t;
typedef signed short int s16_t;
typedef signed long int s32_t;

typedef float f32_t;
typedef double f64_t;



typedef struct node
{
    u8_t data;
    struct node *next;
}node_t;

extern node_t *head;

#endif