#include <queue>
#include <random>
#include <vector>
#include <iostream>
#include <functional>
using namespace std;

void heapSortDec(int a[], int n) {
    priority_queue<int> maxHeap;

    for(int i = 0; i < n; i++)  {
        maxHeap.push(a[i]);
    }
    for(int i = 0; i < n; i++) {
        a[i] = maxHeap.top();
        maxHeap.pop();
    }
}

void heapSortInc(int a[], int n) {
    priority_queue<int, vector<int>, greater<int>> minHeap;

    for(int i = 0; i < n; i++) {
        minHeap.push(a[i]);
    }
    for(int i = 0; i < n; i++) {
        a[i] = minHeap.top();
        minHeap.pop();
    }
}

int main()
{
    int data[10];

    cout << "<내림차순>\n";
    for(int i = 0; i < 10; i++)
        data[i] = rand() % 100;
    cout << "\n정렬전: ";
    for(int i = 0; i < 10; i++)
        cout << data[i] << " ";
    heapSortDec(data, 10);
    cout << "\n정렬후: ";
    for(int i = 0; i < 10; i++)
        cout << data[i] << " ";
    cout << "\n\n";

    cout << "<오름차순>\n";
    for(int i = 0; i < 10; i++)
        data[i] = rand() % 100;
    cout << "\n정렬전: ";
    for(int i = 0; i < 10; i++)
        cout << data[i] << " ";
    heapSortInc(data, 10);
    cout << "\n정렬후: ";
    for(int i = 0; i < 10; i++)
        cout << data[i] << " ";
    cout << "\n";

    return 0;
}