#pragma once

/// @brief Функция корректного считывания индекса
/// @param list Переменная структуры Списка
/// @return Корректное значение индекса
int ReadingCorrectIndex(List& list);

/// @brief Функция корректного считывания элемента
/// @return Корректное значение элемента
int ReadingCorrectValue();

/// @brief  Функция корректного считывания размера
/// @return Корректное значение размера
int ReadingCorrectSize();

/// @brief Функция для вывода интерфейса удаления Списка
/// @param list Переменная структуры Списка
void DeleteMenu(List& list);

/// @brief Функция для вывода интерфейса добавления Списка
/// @param list Переменная структуры Списка
void AddMenu(List& list);

/// Функция вывода Списка
void Print(List& list);
