#include "ll.h"

void insertNode(node *&head, int index, int data)
{
    node* newNode = new node;
    newNode->data = data;
    newNode->next = nullptr;

    if(index == 0)
    {
        newNode->next = head;
        head = newNode;
    }
    else
    {
        node* walker = head;
        int wIndex = 0;
        while(walker != NULL && wIndex < index-1)
        {
            walker = walker->next;
            wIndex++;
        }
        if(walker == nullptr)
        {
            cout << "Index is too large, can't insert" << endl;
            delete newNode;
            return;
        }
        else
        {
            newNode->next = walker->next;
            walker->next = newNode;
        }
    }
}

void deleteNode(node *&head, int index) 
{
    if (head == nullptr)
    {
        cout << "List is empty, can't delete" << endl;
        return;
    }

    if (index == 0)
    {
        node* temp = head;
        head = head->next;
        delete temp;
    }
    else
    {
        node* walker = head;
        int wIndex = 0;

        while (walker != nullptr && wIndex < index - 1)
        {
            walker = walker->next;
            wIndex++;
        }

        if (walker == nullptr || walker->next == nullptr)
        {
            cout << "Index is out of bounds" << endl;
            return;
        }

        node* temp = walker->next;
        walker->next = temp->next;
        delete temp;
    }
}

node* searchNode(node *head, int key)
{
    node* walker = head;

    while (walker != nullptr)
    {
        if (walker->data == key)
        {
            return walker;
        }
        walker = walker->next;
    }

    return nullptr;
}

void reverseList(node *&head)
{
    node* prev = nullptr;
    node* curr = head;
    node* next = nullptr;

    while (curr != nullptr)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    head = prev;
}

void displayList(node *head) 
{
    node* walker = head;

    while(walker != nullptr)
    {
        cout << walker->data << " ";
        walker = walker->next;
    }
    cout << endl;
}