#include"ListItem.h"
#include <iostream>
/*#include<chrono>          //Для замера времени
using namespace std;
using namespace chrono;*/

void AddHead(List& list, int addElement)
{
    Node* newElement = new Node;
    newElement->Prev = 0;
    newElement->Data = addElement;
    newElement->Next = list.Head;
    if (list.Head != 0)
    {
        list.Head->Prev = newElement;
    }
    if (list.Count == 0)
    {
        list.Head = list.Tail = newElement;
    }
    else
    {
        list.Head = newElement;
    }
    list.Count++;
}

void AddTail(List& list, int addElement)
{
    Node* newElement = new Node;
    newElement->Next = 0;
    newElement->Data = addElement;
    newElement->Prev = list.Tail;
    if (list.Tail != 0)
    {
        list.Tail->Next = newElement;
    }
    if (list.Count == 0)
    {
        list.Head = list.Tail = newElement;
    }
    else
    {
        list.Tail = newElement;
    }
    list.Count++;
}

void AddIndex(List& list, int addElement, int index)
{
    //steady_clock::time_point startProcess = steady_clock::now();     //Для замера времени
    if (index == list.Count + 1)
    {
        AddTail(list, addElement);
        return;
    }
    else if (index == 1)
    {
        AddHead(list, addElement);
        return;
    }
    int counter = 1;
    Node* insertBefore = list.Head;
    while (counter < index) //Сложность О(n)
    {
        insertBefore = insertBefore->Next;
        counter++;
    }
    Node* previousInsert = insertBefore->Prev;
    Node* newElement = new Node;
    newElement->Data = addElement;
    if (previousInsert != 0 && list.Count != 1)
    {
        previousInsert->Next = newElement;
    }
    newElement->Next = insertBefore;
    newElement->Prev = previousInsert;
    insertBefore->Prev = newElement;
    list.Count++;
    //steady_clock::time_point endProcess = steady_clock::now();        //Для замера времени
    //cout << "Time difference: " << duration_cast<nanoseconds>(endProcess - startProcess).count() << "[ns]" << endl << endl;       //Для замера времени
}

void Delete(List& list, int index)
{
    //steady_clock::time_point startProcess = steady_clock::now();     //Для замера времени
    int counter = 1;
    Node* del = list.Head;
    while (counter < index) //Сложность O(n)
    {
        del = del->Next;
        counter++;
    }
    Node* previousDelete = del->Prev;
    Node* afterDelete = del->Next;
    if (previousDelete != 0 && list.Count != 1)
    {
        previousDelete->Next = afterDelete;
    }
    if (afterDelete != 0 && list.Count != 1)
    {
        afterDelete->Prev = previousDelete;
    }
    if (index == 1)
    {
        list.Head = afterDelete;
    }
    if (index == list.Count)
    {
        list.Tail = previousDelete;
    }
    delete del;
    list.Count--;
    //steady_clock::time_point endProcess = steady_clock::now();     //Для замера времени
    //cout << "Time difference: " << duration_cast<nanoseconds>(endProcess - startProcess).count() << "[ns]" << endl << endl;     //Для замера времени
}

void DeleteAll(List& list)
{
    while (list.Count != 0)
    {
        Delete(list, 1);
    }
}

int LineSearch(List& list, int searchKey)
{
    Node* temporary = list.Head;
    for (int i = 0; i < list.Count; i++)
    {
        if (temporary->Data == searchKey)
        {
            return i;
        }
        temporary = temporary->Next;
    }
    return -1;
}

void Sort(List& list)
{
    Node* first = list.Head;
    Node* afterFirst = list.Head->Next;
    Node* temporary = new Node;
    while (first->Next)
    {
        while (afterFirst)
        {
            if ((first->Data) > (afterFirst->Data))
            {
                temporary->Data = first->Data;
                first->Data = afterFirst->Data;
                afterFirst->Data = temporary->Data;
            }
            afterFirst = afterFirst->Next;
        }
        first = first->Next;
        afterFirst = first->Next;
    }
}
