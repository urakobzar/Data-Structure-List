#include<iostream>
#include"ListItem.h"
using namespace std;

enum AddItems
{
    AddBeginItem = 1,
    AddEndItem = 2,
    AddBeforeIndexItem = 3,
    AddAfterIndexItem = 4
};

enum DeleteItems
{
    DeleteIndex = 1
};

void Print(List& list)
{
    cout << "������:\n";
    if (list.Count != 0)
    {
        Node* temporary = list.Head;
        cout << "( ";
        while (temporary->Next != 0)
        {
            cout << temporary->Data << ", ";
            temporary = temporary->Next;
        }
        cout << temporary->Data << " )\n";
    }
    cout << "\n";
}

int ReadingCorrectIndex(List& list)
{
    int index;
    while (true)
    {
        cin >> index;
        if ((index > list.Count) || (index <= 0))
        {
            cout << "\n�� ��������!\n";
            cout << "(�� ������ ������ ����� ����� �� 1 �� ";
            cout << list.Count << ")\n";
            cout << "������� ������";
            cout << " ���������: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else
        {
            break;
        }
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return index;
}

int ReadingCorrectSize()
{
    int size;
    while (true)
    {
        cout << "������� ��������� ���������� ���������: ";
        cin >> size;
        if (size <= 0)
        {
            cout << "�� ��������!\n";
            cout << "(��������� ���������� ������ ���� �����"; 
            cout << " ������ ������ 0)\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else
        {
            break;
        }
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return size;
}

int ReadingCorrectValue()
{
    int value;
    while (true)
    {
        if (cin >> value)
        {
            break;
        }
        cout << "�� ��������!\n";
        cout << "(�������� �������� ������ ���� ����� ������)\n";
        cout << "������� �����: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return value;
}

void AddMenu(List& list)
{
    cout << "1:�������� ������� � ������\n";
    cout << "2:�������� ������� � �����\n";
    cout << "3:�������� ������� ����� ";
    cout << "������������ ���������\n";
    cout << "4:�������� ������� ����� ";
    cout << "������������� ��������\n";
    cout << "��� ������ � ������� ���� ";
    cout << "������� ����� �����, ����� ";
    cout << "������������\n";
    cout << "\n������� ��� ������� ��������: ";
    int localNumber = ReadingCorrectValue();
    //int localNumber = 3;      //��� ������ �������
    cout << "\n";
    switch (localNumber)
    {
        case AddBeginItem:
        {
            cout << "*�� ������ ��������";
            cout << " ������� � ������*\n";
            cout << "\n������� �������: ";
            int addElement = ReadingCorrectValue();
            AddHead(list, addElement);
            break;
        }
        case AddEndItem:
        {
            cout << "*�� ������ ��������";
            cout << " ������� � �����*\n";
            cout << "\n������� �������: ";
            int addElement = ReadingCorrectValue();
            AddTail(list, addElement);
            break;
        }
        case AddBeforeIndexItem:
        {
            cout << "*�� ������ �������� ������� �����";
            cout << " ������������ ���������*\n";
            Print(list);
            cout << "������� ����� ��������,";
            cout << "����� ������� ������ �������: ";
            int index = ReadingCorrectIndex(list);
            //int index = 4999;     //��� ������ �������
            cout << "\n������� �������: ";
            int addElement = ReadingCorrectValue();
            //int addElement = 10;      //��� ������ �������
            AddIndex(list, addElement, index);
            break;
        }
        case AddAfterIndexItem:
        {
            cout << "*�� ������ �������� ������� �����";
            cout << " ������������� ��������*\n";
            Print(list);
            cout << "������� ����� ��������,";
            cout << "����� �������� ������ �������: ";
            int index = ReadingCorrectIndex(list);
            cout << "\n������� �������: ";
            int addElement = ReadingCorrectValue();
            AddIndex(list, addElement, index + 1);
            break;
        }
        default:
        {
            cout << "\n*�� ������ ��������� � ������� ����*\n";
            break;
        }
    }
}

void DeleteMenu(List& list)
{
    cout << "\n�� ������ ������� �������?\n";
    cout << "1:������� ������������ �������\n";
    cout << "��� ������ � ������� ���� ";
    cout << "������� ����� �����, ����� ";
    cout << "������������\n";
    cout << "\n������� ��� ������� ��������: ";
    int localNumber = ReadingCorrectValue();
    cout << "\n";
    switch (localNumber)
    {
        case DeleteIndex:
        {            
            cout << "*�� ������ ������� ";
            cout << "������������ �������*\n";
            Print(list);
            cout << "������� ����� ��������,";
            cout << "������� ������ �������: ";
            int index = ReadingCorrectIndex(list);
            Delete(list, index);
            break;
        }
        default:
        {
            cout << "\n*�� ������ ��������� � ������� ����*\n";
            break;
        }
    }
}

