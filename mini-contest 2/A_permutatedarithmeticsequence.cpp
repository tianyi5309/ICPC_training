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
    int tcn; cin >> tcn;
    while (tcn--) {
        int n; cin >> n;
        int a[105];
        for (int i = 0; i < n; i++) cin >> a[i];
        // check if arithmetic 
        int diff = a[1] - a[0];
        bool arithmetic = true;
        for (int i = 0; i < n-1; i++) {
            if (a[i+1] - a[i] != diff) arithmetic = false;
        }
        if (arithmetic) {
            cout << "arithmetic" << endl;
            continue;
        }
        // check if permutated arithmetic 
        sort(a, a+n);
        diff = a[1] - a[0];
        arithmetic = true;
        for (int i = 0; i < n-1; i++) {
            if (a[i+1] - a[i] != diff) arithmetic = false;
        }
        if (arithmetic) {
            cout << "permuted arithmetic" << endl;
            continue;
        }
        
        cout << "non-arithmetic" << endl;
    }
}

