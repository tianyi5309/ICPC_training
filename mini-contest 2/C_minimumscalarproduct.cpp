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
	// Notice that we get the minimum product when we multiply highest element of one vector with lowest of the other.
    int tc; cin >> tc;
    for (int tcn = 1; tcn <= tc; tcn++) {
        int n; cin >> n;
        long long a[1000], b[1000];
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) cin >> b[i];
        sort(a, a+n); sort(b, b+n);
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            ans += a[i]*b[n-i-1];
        }
        cout << "Case #" << tcn << ":" << " " << ans << endl;
    }
}
