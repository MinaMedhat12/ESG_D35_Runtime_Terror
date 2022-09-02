#ifndef  LINKED_LIST_H
#define  LINKED_LIST_H
#include "Std_Types.h"

void add_node_at_end(u8 new_data);
void delete_last_node(void);
void add_node(u8 data, u8 position);
void delete_node(int position);
void print_linked(node_t *head);

#endif