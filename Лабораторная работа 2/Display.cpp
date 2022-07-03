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
        //int data = rand()%100;    //��� ������ �������
        cout << "\n������� �������: ";
        int data = ReadingCorrectValue();
        AddTail(list, data);
    }
    //Print(list);
    while (true)
    {
        cout << "\n��� �� ������ �������?\n";
        cout << "1: �������� �������\n";
        cout << "2: ������� �������\n";
        cout << "3: ������������� ������\n";
        cout << "4: ����� ������� � ������\n";
        cout << "5: ������� ������� ������\n";
        cout << "6: ����� �� ���������\n";
        cout << "\n������� ��� ������� ��������: ";
        int menuNumber = ReadingCorrectValue();
        //int menuNumber = 1;   //��� ������ �������
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
                    cout << "\n������ ����!\n����� � ������� ����\n";
                    break;
                }
                DeleteMenu(list);
                system("pause");
                break;
            }
            case SortMenuItem:
            {
                cout << "\n*�� ������ ������������� ������*\n";
                cout << "\n������ ������������ ";
                cout << " � ������� �����������\n";
                Sort(list);
                system("pause");
                break;
            }
            case SearchMenuItem:
            {
                cout << "\n�������� ����� ������\n";
                cout << "1:�������� �����\n";
                cout << "��� ������ � ������� ���� ";
                cout << "������� ����� �����, ����� ";
                cout << "������������\n";
                cout << "\n������� ��� ������� ��������: ";
                int localNumber = ReadingCorrectValue();
                cout << "\n";
                switch (localNumber)
                {
                    case LineSearchItem:
                    {
                        cout << "*�� ������� �������� �����*\n";
                        cout << "������� ������� �������: ";
                        int searchKey = ReadingCorrectValue();
                        if (LineSearch(list, searchKey) == -1)
                        {
                            cout << "\n������� �� ������\n";
                        }
                        else
                        {
                            cout << "\n����� �������� ";
                            cout << searchKey;
                            cout << " : ";
                            cout << LineSearch(list, searchKey) + 1;
                            cout << "\n";
                        }
                        break;
                    }
                    default:
                    {
                        cout << "\n*�� ������ ��������� � ������� ����*\n";
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
                cout << "\n*�� ������ ����� �� ���������*\n";
                return 0;
            }
            default:
            {
                cout << "�� ��������!\n������� ���������!\n\n";
                system("pause");
                break;
            }
        }
    }
    DeleteAll(list);
    return 0;
}