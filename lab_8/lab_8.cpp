#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <time.h>
#include <queue>
#include <vector>

void find_och(int x, std::vector<std::vector<int>>& k, int m, std::vector<int>& D) {
    std::queue<int> q;
    q.push(x);
    D[x - 1] = 1;

    while (!q.empty()) {
        int current = q.front();
        q.pop();
        printf("%d\n", current);

        for (int i = 0; i < m; i++) {
            if (k[current - 1][i] == 1 && D[i] == 0) {
                q.push(i + 1);
                D[i] = 1;
            }
        }
    }
}

int main() {
    setlocale(LC_ALL, "rus");

    clock_t start, end; // объявляем переменные для определения времени выполнения
    int m;
    int l;
    int x; // Вершина

    srand(time(NULL));

    printf("Введите размер матрицы\n");
    scanf("%d", &m);

    std::vector<std::vector<int>> k(m, std::vector<int>(m, 0));

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            int t = rand() % 2;
            k[i][j] = t;
            k[j][i] = t;
            k[i][i] = 0;
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", k[i][j]);
        }
        printf("\n");
    }

    //_____________________________________________

    std::vector<int> D(m, 0); // Массив вершин

    printf("Введите номер вершины - ");
    scanf("%d", &l);
    x = l;

    start = clock(); // в переменную start записываем время от начала запуска программы

    find_och(x, k, m, D);

    end = clock(); // в переменную end записываем время от начала запуска программы
    double time = (end - start) * 1000.0 / CLOCKS_PER_SEC; // вычисляем разность(т.е. время, затраченное на умножение матриц)

    printf("%lf ms\n", time); // выводим результат работы программы в секундах

    //_____________________________________________

    D.assign(m, 0); // Массив вершин

    x = l;

    start = clock(); // в переменную start записываем время от начала запуска программы

    find_och(x, k, m, D);

    end = clock(); // в переменную end записываем время от начала запуска программы
    time = (end - start) * 1000.0 / CLOCKS_PER_SEC; // вычисляем разность(т.е. время, затраченное на умножение матриц)

    printf("%lf ms\n", time); // выводим результат работы программы в секундах

    getchar(); getchar();
    return 0;
}
