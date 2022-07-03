#pragma once
#include "Node.h"

/// @brief ��������� ������
struct List
{
    // ��������� �� ������ ������ 
    Node* Head;
    // ��������� �� ����� ������
    Node* Tail;
    // ���������� ���������
    int Count;
};

/// @brief �������� ��������
/// @param list ���������� ��������� ������
/// @param index ������ ���������� ��������
void Delete(List& list, int index);

/// @brief ���������� �� ������� 
/// @param list ���������� ��������� ������
/// @param addElement ����������� �������
/// @param index ������, ����� ������� ��������� �������
void AddIndex(List& list, int addElement, int index);

/// @brief ���������� � ����� ������
/// @param list ���������� ��������� ������
/// @param addElement ����������� �������
void AddTail(List& list, int addElement);

/// @brief ���������� � ������ ������
/// @param list ���������� ��������� ������
/// @param addElement ����������� �������
void AddHead(List& list, int addElement);

/// @brief �������� ���� ���������
/// @param list ���������� ��������� ������
void DeleteAll(List& list);

/// @brief �������� ����� ��������
/// @param list ���������� ��������� ������
/// @param key ������� �������
/// @return ������������ ��� ������� �������, ��� ��������,
/// ������� ������� �� ���������� ��������
int LineSearch(List& list, int searchKey);

/// @brief ���������� ������ � ������� �����������
/// @param list ���������� ��������� ������
void Sort(List& list);

