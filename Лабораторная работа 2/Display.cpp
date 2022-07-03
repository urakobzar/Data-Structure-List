#include<iostream>
#include"ListItem.h"
#include"Common.h"
using namespace std;


enum MenuItems
{
    AddMenuItem = 1,
    DeleteMenuItem = 2,
    SortMenuItem = 3,
    SearchMenuItem = 4,
    PrintMenuItem = 5,
    ExitMenuItem = 6
};

enum SearchItems
{
    LineSearchItem = 1,
};


int main()
{
    List list;
    list.Head = nullptr;
    list.Tail = nullptr;
    list.Count = 0;
    setlocale(LC_ALL, "rus");
    int size = ReadingCorrectSize();   
    for (int i = 0; i < size; i++)
    {
        //int data = rand()%100;    //Для замера времени
        cout << "\nВведите элемент: ";
        int data = ReadingCorrectValue();
        AddTail(list, data);
    }
    //Print(list);
    while (true)
    {
        cout << "\nЧто вы хотите сделать?\n";
        cout << "1: Добавить элемент\n";
        cout << "2: Удалить элемент\n";
        cout << "3: Отсортировать список\n";
        cout << "4: Найти элемент в списке\n";
        cout << "5: Вывести текущий список\n";
        cout << "6: Выйти из программы\n";
        cout << "\nВведите ваш вариант действий: ";
        int menuNumber = ReadingCorrectValue();
        //int menuNumber = 1;   //Для замера времени
        switch (menuNumber)
        {
            case AddMenuItem:
            {
                AddMenu(list);
                system("pause");
                break;
            }
            case DeleteMenuItem:
            {
                if (list.Count == 0)
                {
                    cout << "\nСписок пуст!\nВыход в главное меню\n";
                    break;
                }
                DeleteMenu(list);
                system("pause");
                break;
            }
            case SortMenuItem:
            {
                cout << "\n*Вы решили отсортировать список*\n";
                cout << "\nСписок отсортирован ";
                cout << " в порядке возрастания\n";
                Sort(list);
                system("pause");
                break;
            }
            case SearchMenuItem:
            {
                cout << "\nВыберите метод поиска\n";
                cout << "1:Линейный поиск\n";
                cout << "Для выхода в главное меню ";
                cout << "введите любую цифру, кроме ";
                cout << "предложенных\n";
                cout << "\nВведите ваш вариант действий: ";
                int localNumber = ReadingCorrectValue();
                cout << "\n";
                switch (localNumber)
                {
                    case LineSearchItem:
                    {
                        cout << "*Вы выбрали линейный поиск*\n";
                        cout << "Введите искомый элемент: ";
                        int searchKey = ReadingCorrectValue();
                        if (LineSearch(list, searchKey) == -1)
                        {
                            cout << "\nЭлемент не найден\n";
                        }
                        else
                        {
                            cout << "\nНомер элемента ";
                            cout << searchKey;
                            cout << " : ";
                            cout << LineSearch(list, searchKey) + 1;
                            cout << "\n";
                        }
                        break;
                    }
                    default:
                    {
                        cout << "\n*Вы решили вернуться в главное меню*\n";
                        break;
                    }
                }
                system("pause");
                break;
            }
            case PrintMenuItem:
            {
                Print(list);
                system("pause");
                break;
            }
            case ExitMenuItem:
            {
                cout << "\n*Вы решили выйти из программы*\n";
                return 0;
            }
            default:
            {
                cout << "Вы ошиблись!\nВведите правильно!\n\n";
                system("pause");
                break;
            }
        }
    }
    DeleteAll(list);
    return 0;
}
