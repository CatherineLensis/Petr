#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include "task_manager.h"
using namespace std;

int main() {
    setlocale(LC_ALL, "");
    int n;
    cin >> n; // ��������� ���������� �����
    wcout << L"���������� �����: " << n << endl; // ���������� �����

    TaskManager taskManager;

    // ��������� ������ � ��������� �� � TaskManager
    for (int i = 0; i < n; ++i) {
        int deadline, stress;
        cin >> deadline >> stress;
        wcout << L"������� ������: ������� = " << deadline << L", ������ = " << stress << endl; // ���������� �����
        taskManager.addTask(deadline, stress);
    }

    // ��������� � ������� ����������� ��������� ������
    long long result = taskManager.minimizeStress();
    wcout << L"��������� ������������ ���������� �������: " << result << endl;

    return 0;
}

