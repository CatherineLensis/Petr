#pragma once
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
// ����� Task ��� ������������� ����� ������
class Task {
public:
	int deadline; // ������� ������
	int stress;   // �������� ������� ��� ������������

	// ����������� ������
	Task(int d, int w) : deadline(d), stress(w) {}
};

// ����� TaskManager ��� ���������� ��������
class TaskManager {
private:
	vector<Task> tasks; // ������ �����

public:
	// ����� ��� ���������� ������
	void addTask(int deadline, int stress) {
		tasks.emplace_back(deadline, stress);
	}

	// ����� ��� ���������� ������������ ���������� �������
	long long minimizeStress() {
		// ��������� ������ �� ��������
		sort(tasks.begin(), tasks.end(), [](const Task& a, const Task& b) {
			return a.deadline < b.deadline;
			});

		// ������������ ������� (max-heap) ��� �������� �������� �����
		priority_queue<int> max_heap;
		long long total_stress = 0;
		//��� �������� ���
		int current_day = 0;
		int result = 0;
		// �������� �� ���� �������
		for (const auto& task : tasks) {
			//���� �������� ����� ����, ����������� ������� ����
			current_day = task.deadline;
			
			// ��������� ������ � ����
			max_heap.push(task.stress);
			cout << "�������� ������: ������� = " << task.deadline
				<< ", ������ = " << task.stress << endl;
			// ������� ������� ���� � ������ � ����
			cout << "Current day: " << current_day << endl;
			cout << "Tasks in heap: ";
			priority_queue<int> temp_heap = max_heap;
			while (!temp_heap.empty()) {
				cout << temp_heap.top() << " ";
				temp_heap.pop();
			}
			cout << endl;
			// ���� ���������� ����� ������, ��� ��������� ��� �� ��������
			if (max_heap.size() > current_day) {
				
				total_stress += max_heap.top(); // ��������� ������, ������� ����������
				max_heap.pop(); // ������� ��� ������
				result += max_heap.top(); //��������� ���� ����
			}
		}
		return result; // ���������� ����� ������, ������� ����� ���� �������� � �����

	}


};
