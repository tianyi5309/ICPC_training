#include <cstdio>
#include <cmath>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <stack>
#include <map>
#include <queue>
#include <string>
#include <list>
#include <set>
#include <unordered_map>
#include <cstring>
#include <ctime>
#include <bitset>
#include <cassert>
using namespace std;


int main(){
    int n, casen = 0;
    while (cin >> n) {
        casen++;
        printf("Case %d:\n", casen);
        
        int a[1005];
        for (int i = 0; i < n; i++) cin >> a[i];
        
        int m; cin >> m;
        while (m--) {
            int q; cin >> q;
            int ans = 2000000000;
            for (int i = 0; i < n; i++) {
                for (int j = i+1; j < n; j++) {
                    int sum = a[i] + a[j];
                    if (abs(sum-q) < abs(ans-q)) ans = sum;
                }
            }
            printf("Closest sum to %d is %d.\n", q, ans);
        }
    }
}

