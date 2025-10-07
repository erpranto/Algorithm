#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void conquer(int c[], int l, int mid, int r)
{
    int n = mid - l + 1;
    int a[n];
    for (int i = 0, k = l; i < n; i++, k++)
    {
        a[i] = c[k];
    }
    int m = r - mid;
    int b[m];
    for (int i = 0, k = mid + 1; i < m; i++, k++)
    {
        b[i] = c[k];
    }
    int i = 0, j = 0, cur = l;
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
}

void devide(int a[], int l, int r)
{
    if (l >= r)
        return;
    int mid = (l + r) / 2;
    devide(a, l, mid);
    devide(a, mid + 1, r);
    conquer(a, l, mid, r);
}
// Final Complexity of Mrger_shot -->O(NlogN)
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
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}