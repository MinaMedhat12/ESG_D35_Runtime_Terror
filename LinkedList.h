#include "typedef.h"
#ifndef LINKEDLIST_H
#define LINKEDLIST_H

void printList(node_t *head);
void AddLast(node_t **head, u8_t data);
void DeleteLast ();
void add_at_position(node_t *head, u8_t data, u8_t pos);
void Delete_at_position(node_t **head, u8_t pos);


#endif