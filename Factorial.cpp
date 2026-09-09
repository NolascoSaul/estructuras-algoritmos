#include <iostream>
using namespace std;

long long f(long long x)
{
    if (x == 0)
        return 1;

    return x * f(x - 1);
}

int main()
{
    int n = 0;
    cin >> n;
    cout << "Factorial de " << n << " es " << f(n) << endl;
    return 0;
}