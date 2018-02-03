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
    int n, c;
    cin >> n >> c;
    int a[1005];
    for (int i = 0; i < n; i++) cin >> a[i];
    
    int ans = 0;
    for (int i = 0; i < n; i++) { // iterate over each starting point
        int cur = c, cnt = 0;
        for (int j = i; j < n; j++) { // move onto each successive element and try to eat
            if(cur >= a[j]) {
                cur -= a[j];
                cnt++;
            }
        }
        ans = max(ans, cnt);
    }
    cout << ans << endl;
}

