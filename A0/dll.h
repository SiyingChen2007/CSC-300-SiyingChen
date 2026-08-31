#ifndef DLL_H
#define DLL_H

#include <iostream>
using namespace std;

struct dnode
{
    int data;
    dnode *prev;
    dnode *next;
};

void insertNode(dnode *&head, int index, int data);
void deleteNode(dnode *&head, int index);
void displayList(dnode *head);

#endif