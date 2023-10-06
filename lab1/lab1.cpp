﻿#define _CRT_SECURE_NO_WARNINGS
#include <windows.h>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include < string.h >

void sumColumns(int arr[][4], int rows, int cols) {
    int i, j, sum;

    for (j = 0; j < cols; j++) {   // перебираем столбцы
        sum = 0;
        for (i = 0; i < rows; i++) {   // перебираем строки в столбце
            sum += arr[i][j]; // добавляем значение элемента к сумме
        }
        printf("Сумма значений в столбце %d: %d\n", j + 1, sum);
    }
}// функция для подсчета суммы значений в столбцах двумерного массива

int main() {

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    struct {  // определяем структуру для хранения информации о студентах
        char familiya[20];
        char name[20];
        char facultet[20];
        char gruppa[20];
    }stud[4], search;  // создаем массив структур и переменную для поиска

    int n, i, j, min, max; // объявляем переменные
    int arr[4][4]; // объявляем двумерный массив

    srand(time(NULL)); // инициализируем генератор случайных чисел текущим временем

    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            arr[i][j] = rand() % 100; // заполняем случайными числами от 0 до 99
            printf("%d ", arr[i][j]); // выводим элементы массива
        }
        printf("\n");
    }

    min = arr[0][0];
    max = arr[0][0];

    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            if (arr[i][j] < min) { // находим минимальный элемент
                min = arr[i][j];
            }
            if (arr[i][j] > max) { // находим максимальный элемент
                max = arr[i][j];
            }
        }
    }

    printf("\nМинимальный элемент: %d\n", min);
    printf("Максимальный элемент: %d\n", max);
    printf("Разница между максимальным и минимальным элементами: %d\n", max - min);


    sumColumns(arr, 4, 4); // вызываем функцию для подсчета суммы значений в столбцах массива

    printf("\n");

    for (int i = 0; i < 3; i++) // заполняем информацию о студентах
    {
        printf("Введите фамилию студента №%d\n", i + 1);
        scanf("%20s", &stud[i].familiya);
        printf("Введите имя студента №%d\n", i + 1);
        scanf("%20s", &stud[i].name);
        printf("Введите название факультета студента №%d\n", i + 1);
        scanf("%20s", &stud[i].facultet);
        printf("Введите номер группы студента №%d\n", i + 1);
        scanf("%20s", &stud[i].gruppa);
    }
    for (int i = 0; i < 3; i++) { // выводим информацию о всех
        printf(" Cтудент %s %s обучается на факультете %s, номер группы %s\n", stud[i].familiya, stud[i].name, stud[i].facultet, stud[i].gruppa);

    }
    printf("найти:\n");
    printf("Фамилия - ");
    scanf("%20s", &search.familiya);
    printf("Имя - ");
    scanf("%20s", &search.name);
    printf("факульт - ");
    scanf("%20s", &search.facultet);
    printf("Группа - ");
    scanf("%20s", &search.gruppa);
    int t = 0;
    for (int i = 0; i < 3; i++) { // ищем студента по заданным параметрам
        if (strcmp(search.familiya, stud[i].familiya) == 0 || (strcmp(search.name, stud[i].name) == 0) || strcmp(search.facultet, stud[i].facultet) == 0 || search.gruppa == stud[i].gruppa) {
            printf("совпадение под номером %d", i + 1);
            printf(" Cтудент %s %s обучается на факультете %s, номер группы %s\n", stud[i].familiya, stud[i].name, stud[i].facultet, stud[i].gruppa);
            t = 1;
        }
    }
    if (t == 0)
        printf("совпадений не найдено");



    getchar(); // ожидаем нажатия клавиши перед закрытием консоли
    return 0; // завершаем программу
}
