#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void devide(int a[], int l, int r)
{
    for (int i = l; i <= r; i++)
        cout << a[i] << " ";
    cout << "\n";

    if (l >= r)
        return;
    int mid = (l + r) / 2;
    devide(a, l, mid);
    devide(a, mid + 1, r);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    devide(a, 0, n - 1);
    return 0;
}