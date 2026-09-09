#include <iostream>
using namespace std;

long long f(long long x)
{
    if (x <= 2)
        return 1;
    return f(x - 1) + f(x - 2);
}

int main()
{
    int n = 0;
    cin >> n;
    cout << "Número de Fibonacci " << n << " es " << f(n) << endl;
    return 0;
}