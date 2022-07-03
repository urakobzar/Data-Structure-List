#pragma once

/// @brief ������� ����������� ���������� �������
/// @param list ���������� ��������� ������
/// @return ���������� �������� �������
int ReadingCorrectIndex(List& list);

/// @brief ������� ����������� ���������� ��������
/// @return ���������� �������� ��������
int ReadingCorrectValue();

/// @brief  ������� ����������� ���������� �������
/// @return ���������� �������� �������
int ReadingCorrectSize();

/// @brief ������� ��� ������ ���������� �������� ������
/// @param list ���������� ��������� ������
void DeleteMenu(List& list);

/// @brief ������� ��� ������ ���������� ���������� ������
/// @param list ���������� ��������� ������
void AddMenu(List& list);

/// ������� ������ ������
void Print(List& list);
