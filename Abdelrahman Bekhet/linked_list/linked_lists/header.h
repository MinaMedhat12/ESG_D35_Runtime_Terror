#ifndef HEADER_H
#define HEADER_H

#include"datatypes.h"

void Add_last_Node(node** head, node** newNode);

void Delete_last_Node(node** head);

void Delete_Node(node** head, int index);

void Add_Node(node** head, node** newNode, int index);

#endif