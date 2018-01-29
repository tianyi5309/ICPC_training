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
    int t; cin >> t;
    while (t--) {
        int cs, e;
        cin >> cs >> e;
        int a[200005], b[200005];
        for (int i = 0; i < cs; i++) cin >> a[i];
        for (int i = 0; i < e; i++) cin >> b[i];
        sort(a, a+cs); sort(b, b+e);
        long long cst = 0, et = 0; // total iq
        for (int i = 0; i < cs; i++) cst += a[i];
        for (int i = 0; i < e; i++) et += b[i];
        
        int ans = 0;
        for (int i = 0; i < cs; i++) {
            if ((long long)a[i]*cs < cst && (long long)a[i]*e > et) ans++; // integer arithmetic to avoid float errors
        }
        cout << ans << endl;
    }
}
