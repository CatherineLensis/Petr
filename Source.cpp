#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include "task_manager.h"
using namespace std;

int main() {
    setlocale(LC_ALL, "");
    int n;
    cin >> n; // Считываем количество задач
    wcout << L"Количество задач: " << n << endl; // Отладочный вывод

    TaskManager taskManager;

    // Считываем задачи и добавляем их в TaskManager
    for (int i = 0; i < n; ++i) {
        int deadline, stress;
        cin >> deadline >> stress;
        wcout << L"Считали задачу: дедлайн = " << deadline << L", стресс = " << stress << endl; // Отладочный вывод
        taskManager.addTask(deadline, stress);
    }

    // Вычисляем и выводим минимальный суммарный стресс
    long long result = taskManager.minimizeStress();
    wcout << L"Результат минимального суммарного стресса: " << result << endl;

    return 0;
}

