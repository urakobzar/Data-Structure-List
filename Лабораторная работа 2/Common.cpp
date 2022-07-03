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
    cout << "Список:\n";
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
            cout << "\nВы ошиблись!\n";
            cout << "(Вы должны ввести целое число от 1 до ";
            cout << list.Count << ")\n";
            cout << "Введите индекс";
            cout << " правильно: ";
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
        cout << "Введите начальное количество элементов: ";
        cin >> size;
        if (size <= 0)
        {
            cout << "Вы ошиблись!\n";
            cout << "(Начальное количество должно быть целым"; 
            cout << " числом больше 0)\n";
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
        cout << "Вы ошиблись!\n";
        cout << "(Вводимое значение должно быть целым числом)\n";
        cout << "Введите снова: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return value;
}

void AddMenu(List& list)
{
    cout << "1:Добавить элемент в начало\n";
    cout << "2:Добавить элемент в конец\n";
    cout << "3:Добавить элемент перед ";
    cout << "определенным элементом\n";
    cout << "4:Добавить элемент после ";
    cout << "определенного элемента\n";
    cout << "Для выхода в главное меню ";
    cout << "введите любую цифру, кроме ";
    cout << "предложенных\n";
    cout << "\nВведите ваш вариант действий: ";
    int localNumber = ReadingCorrectValue();
    //int localNumber = 3;      //Для замера времени
    cout << "\n";
    switch (localNumber)
    {
        case AddBeginItem:
        {
            cout << "*Вы решили добавить";
            cout << " элемент в начало*\n";
            cout << "\nВведите элемент: ";
            int addElement = ReadingCorrectValue();
            AddHead(list, addElement);
            break;
        }
        case AddEndItem:
        {
            cout << "*Вы решили добавить";
            cout << " элемент в конец*\n";
            cout << "\nВведите элемент: ";
            int addElement = ReadingCorrectValue();
            AddTail(list, addElement);
            break;
        }
        case AddBeforeIndexItem:
        {
            cout << "*Вы решили добавить элемент перед";
            cout << " определенным элементом*\n";
            Print(list);
            cout << "Введите номер элемента,";
            cout << "перед которым хотите вставку: ";
            int index = ReadingCorrectIndex(list);
            //int index = 4999;     //Для замера времени
            cout << "\nВведите элемент: ";
            int addElement = ReadingCorrectValue();
            //int addElement = 10;      //Для замера времени
            AddIndex(list, addElement, index);
            break;
        }
        case AddAfterIndexItem:
        {
            cout << "*Вы решили добавить элемент после";
            cout << " определенного элемента*\n";
            Print(list);
            cout << "Введите номер элемента,";
            cout << "после которого хотите вставку: ";
            int index = ReadingCorrectIndex(list);
            cout << "\nВведите элемент: ";
            int addElement = ReadingCorrectValue();
            AddIndex(list, addElement, index + 1);
            break;
        }
        default:
        {
            cout << "\n*Вы решили вернуться в главное меню*\n";
            break;
        }
    }
}

void DeleteMenu(List& list)
{
    cout << "\nВы хотите удалить элемент?\n";
    cout << "1:Удалить определенный элемент\n";
    cout << "Для выхода в главное меню ";
    cout << "введите любую цифру, кроме ";
    cout << "предложенных\n";
    cout << "\nВведите ваш вариант действий: ";
    int localNumber = ReadingCorrectValue();
    cout << "\n";
    switch (localNumber)
    {
        case DeleteIndex:
        {            
            cout << "*Вы решили удалить ";
            cout << "определенный элемент*\n";
            Print(list);
            cout << "Введите номер элемента,";
            cout << "который хотите удалить: ";
            int index = ReadingCorrectIndex(list);
            Delete(list, index);
            break;
        }
        default:
        {
            cout << "\n*Вы решили вернуться в главное меню*\n";
            break;
        }
    }
}

