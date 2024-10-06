#pragma once

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
// Класс Task для представления одной задачи
class Task {
public:
	int deadline; // Дедлайн задачи
	int stress;   // Величина стресса при невыполнении

	// Конструктор задачи
	Task(int d, int w) : deadline(d), stress(w) {}
};

// Класс TaskManager для управления задачами
class TaskManager {
private:
	vector<Task> tasks; // Список задач

public:
	// Метод для добавления задачи
	void addTask(int deadline, int stress) {
		tasks.emplace_back(deadline, stress);
	}
	// Метод для вычисления минимального суммарного стресса
	long long minimizeStress() {
		// Сортируем задачи по дедлайну
		sort(tasks.begin(), tasks.end(), [](const Task& a, const Task& b) {
			return a.deadline < b.deadline;
			});

		// Приоритетная очередь (max-heap) для хранения стрессов задач
		priority_queue<int, vector<int>, greater<int>> min_heap;

		//Для текущего дня
		int current_day = 0;
		long long result = 0;
		// Проходим по всем задачам

		for (const auto& task : tasks) {
			//Если наступил новый день, увеличиваем текущий день
			current_day = task.deadline;

			// Добавляем задачу в кучу
			min_heap.push(task.stress);
			cout << "Добавили задачу: дедлайн = " << task.deadline
				<< ", стресс = " << task.stress << endl;
			// Выводим текущий день и задачи в куче
			cout << "Current day: " << current_day << endl;
			cout << "Tasks in heap: ";
			cout << endl;
			// Если количество задач больше, чем доступные дни до дедлайна
			if (min_heap.size() > current_day) {
				result += min_heap.top();//суммируем саму кучу
				min_heap.pop(); // Удаляем эту задачу
			}
		}
		return result; // Возвращаем общий стресс, c которым задачи могут быть выполнены в сроки

	}
};
