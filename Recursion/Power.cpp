#include <iostream>
using namespace std;

double power(double x, int n) {
    if(n == 0) {
        return 1;
    } else if((n%2) == 0) {
        return power(x*x, n/2);
    } else {
        return x * power(x*x, (n-1)/2);
    }
}

int main()
{
    double a = power(2.0, 5);
    double b = power(2.0, 2);
    cout << a << " " << b << "\n";
    return 0;
}