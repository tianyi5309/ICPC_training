#include <bits/stdc++.h>
using namespace std;
int fibo(int n, int m)
{
    int f = 1;
    int  s = 0;
    int t = 0;
    for(int i = 2; i <= n; i++)
    {
        t = f;
        f = f + s;
        s = t;
        
        f = f % m;
        s = s % m;
    }
    return f;
}

int main()
{
    int n, m;
    cin >> n >> m;
    cout << fibo(n, m);
}
