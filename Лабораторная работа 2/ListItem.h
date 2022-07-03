#pragma once
#include "Node.h"

/// @brief Структура списка
struct List
{
    // Указатель на начало списка 
    Node* Head;
    // Указатель на конец списка
    Node* Tail;
    // Количество элементов
    int Count;
};

/// @brief Удаление элемента
/// @param list Переменная структуры списка
/// @param index Индекс удаляемого элемента
void Delete(List& list, int index);

/// @brief Добавление по индексу 
/// @param list Переменная структуры списка
/// @param addElement Добавляемый элемент
/// @param index Индекс, перед которым добавляют элемент
void AddIndex(List& list, int addElement, int index);

/// @brief Добавление в конец списка
/// @param list Переменная структуры списка
/// @param addElement Добавляемый элемент
void AddTail(List& list, int addElement);

/// @brief Добавление в начало списка
/// @param list Переменная структуры списка
/// @param addElement Добавляемый элемент
void AddHead(List& list, int addElement);

/// @brief Удаление всех элементов
/// @param list Переменная структуры списка
void DeleteAll(List& list);

/// @brief Линейный поиск элемента
/// @param list Переменная структуры списка
/// @param key Искомый элемент
/// @return Возвращается или искомый элемент, или параметр,
/// который говорит об отсутствии элемента
int LineSearch(List& list, int searchKey);

/// @brief Сортировка списка в порядке возрастания
/// @param list Переменная структуры списка
void Sort(List& list);

