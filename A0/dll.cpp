#include "dll.h"

void insertNode(dnode *&head, int index, int data)
{
    dnode* newNode = new dnode;
    newNode->data = data;
    newNode->prev = nullptr;
    newNode->next = nullptr;

    if (index == 0)
    {
        newNode->next = head;
        if (head != nullptr)
        {
            head->prev = newNode;
        }
        head = newNode;
    }
    else
    {
        dnode* walker = head;
        int wIndex = 0;

        while (walker != nullptr && wIndex < index - 1)
        {
            walker = walker->next;
            wIndex++;
        }

        if (walker == nullptr)
        {
            cout << "Index is too large, can't insert" << endl;
            delete newNode;
            return;
        }

        newNode->next = walker->next;
        newNode->prev = walker;

        if (walker->next != nullptr)
        {
            walker->next->prev = newNode;
        }
        walker->next = newNode;
    }
}

void deleteNode(dnode *&head, int index)
{
    if (head == nullptr)
    {
        cout << "List is empty, can't delete" << endl;
        return;
    }

    if (index == 0)
    {
        dnode* temp = head;
        head = head->next;
        if (head != nullptr)
        {
            head->prev = nullptr;
        }
        delete temp;
    }
    else
    {
        dnode* walker = head;
        int wIndex = 0;

        while (walker != nullptr && wIndex < index)
        {
            walker = walker->next;
            wIndex++;
        }

        if (walker == nullptr)
        {
            cout << "Index is out of bounds" << endl;
            return;
        }

        if (walker->prev != nullptr)
        {
            walker->prev->next = walker->next;
        }

        if (walker->next != nullptr)
        {
            walker->next->prev = walker->prev;
        }

        delete walker;
    }
}

void displayList(dnode *head)
{
    dnode* walker = head;
    while (walker != nullptr)
    {
        cout << walker->data << " ";
        walker = walker->next;
    }
    cout << endl;
}