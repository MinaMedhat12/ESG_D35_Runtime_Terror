#ifndef STD_TYPES_H_
#define STD_TYPES_H_


typedef unsigned char                        u8;
typedef signed char                          s8;
typedef short unsigned int                   u16;
typedef signed int                           s16;
typedef long unsigned int                    u32;
typedef long signed int                      s32;
typedef float                                f32;
typedef double                               f64;

typedef struct node{

    u8 data;
    struct node * next;

}node_t;

extern node_t *head ;



#endif

