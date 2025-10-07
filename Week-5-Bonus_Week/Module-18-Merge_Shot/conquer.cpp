#include <bits/stdc++.h>
using namespace std;
#define ll long long int
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
    int m;
    cin >> m;
    int b[m];
    for (int i = 0; i < m; i++)
    {
        cin >> b[i];
    }
    int c[n + m];
    int i = 0, j = 0, cur = 0;
    while (i < n && j < m)
    {
        if (a[i] < b[j])
        {
            c[cur] = a[i];
            i++;
            cur++;
        }
        else
        {
            c[cur] = b[j];
            j++;
            cur++;
        }
    }
    while (i < n)
    {
        c[cur] = a[i];
        i++;
        cur++;
    }
    while (j < m)
    {
        c[cur] = b[j];
        j++;
        cur++;
    }

    for (int i = 0; i < m + n; i++)
        cout << c[i] << " ";
    return 0;
}