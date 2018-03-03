#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int n, v, c[51];
long long a[10001][51];

long long coin(int v, int cpos)
{
    if (v == 0)
    {
        return 1;
    }
    else if (cpos == -1)
    {
        return 0;
    }
    else if (a[v][cpos] != -1) { return a[v][cpos]; }
    else
    {
        if (v >= c[cpos])
        {
            a[v][cpos] = coin (v, cpos-1) + coin(v-c[cpos], cpos);
            return a[v][cpos];
        }
        else
        {
            a[v][cpos] = coin (v, cpos-1);
            return a[v][cpos];
        }
    }
}

int main()
{
    cin >> n >> v;
    for (int i = 0; i <= n-1; i++) { cin >> c[i]; }
    
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= v; j++)
        {
            a[j][i] = -1;
        }
    }
    
    cout << coin(v, n-1)%13371337 << endl;
    
    return 0;
}


