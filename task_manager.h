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
		priority_queue<int> max_heap;
		long long total_stress = 0;
		//Для текущего дня
		int current_day = 0;
		int result = 0;
		// Проходим по всем задачам
		for (const auto& task : tasks) {
			//Если наступил новый день, увеличиваем текущий день
			current_day = task.deadline;
			
			// Добавляем задачу в кучу
			max_heap.push(task.stress);
			cout << "Добавили задачу: дедлайн = " << task.deadline
				<< ", стресс = " << task.stress << endl;
			// Выводим текущий день и задачи в куче
			cout << "Current day: " << current_day << endl;
			cout << "Tasks in heap: ";
			priority_queue<int> temp_heap = max_heap;
			while (!temp_heap.empty()) {
				cout << temp_heap.top() << " ";
				temp_heap.pop();
			}
			cout << endl;
			// Если количество задач больше, чем доступные дни до дедлайна
			if (max_heap.size() > current_day) {
				
				total_stress += max_heap.top(); // Суммируем стресс, который выкидываем
				max_heap.pop(); // Удаляем эту задачу
				result += max_heap.top(); //суммируем саму кучу
			}
		}
		return result; // Возвращаем общий стресс, который может быть выполнен в сроки

	}


};
