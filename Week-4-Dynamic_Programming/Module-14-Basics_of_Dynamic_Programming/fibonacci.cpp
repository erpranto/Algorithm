#include <bits/stdc++.h>
using namespace std;
int fibo(int n)
{
    if (n == 0 || n == 1) //(n<2)
        return 1;

    return fibo(n - 1) + fibo(n - 2);
}
int main()
{
    cout << fibo(5);
    return 0;
}