#include <iostream>
using namespace std;

void hanoiTower(int n, char from, char tmp, char to) {
    if(n == 1) {
        cout << "원판 1을 " << from << "에서 " << to << "로 옮깁니다.\n"; 
    } else {
        hanoiTower(n-1, from, to, tmp);
        cout << "원판 " << n << "을 " << from <<"에서 " << to << "로 옮깁니다.\n";
        hanoiTower(n-1, tmp, from, to);
    }
}

int hanoiTower2(int n, char from, char tmp, char to) {
    if(n == 1) {
        cout << "원판 1을 " << from << "에서 " << to << "로 옮깁니다.\n"; 
    } else {
        int val1 = hanoiTower2(n-1, from, to, tmp);
        int val2 = hanoiTower2(1, from, tmp, to);
        int val3 = hanoiTower2(n-1, tmp, from, to);
        return val1 + val2 + val3;
    }
}

int main()
{
    hanoiTower(4, 'A', 'B', 'C');
    cout << "\n" << hanoiTower2(5, 'A', 'B', 'C') << "\n";
    return 0;
}