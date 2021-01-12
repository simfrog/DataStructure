#include "MaxHeap.h"
#include <random>
using namespace std;

void heapSort(int a[], int n) {
    MaxHeap h;
    for(int i = 0; i < n; i++)
        h.insert(a[i]);
    for(int i = n-1; i >= 0; i--)
        a[i] = h.remove().getKey();
}

int main()
{
    MaxHeap heap;
    int data[10];

    for(int i = 0; i < 10; i++)
        data[i] = rand() % 100;
    cout << "\n정렬전: ";
    for(int i = 0; i < 10; i++)
        cout << data[i] << " ";
    heapSort(data, 10);
    cout << "\n정렬후: ";
    for(int i = 0; i < 10; i++)
        cout << data[i] << " ";
    cout << "\n";

    return 0;
}