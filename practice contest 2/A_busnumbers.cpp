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
    int n; cin >> n;
    int a[1005];
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a, a+n);
    string ans = "";
    int seq_cnt = 0; // counts the number of numbers in sequence currently. If it's 1, then we have 2 consecutive numbers, if >1 then we need to print dashes 
    for (int i = 0; i < n; i++) { // for each number, check if it's the last one in a sequence.
        if (i != n-1 && a[i]+1 == a[i+1]) { // If it isn't, then it's either:
            if (!seq_cnt) ans += " " + to_string(a[i]); // the first one
            seq_cnt++; // If it's in the middle / first one, we increment seq_cnt
        } else { // if it is the last one, we print it!
            if (seq_cnt > 1) ans += "-";
            else ans += " ";
            ans += to_string(a[i]);
            seq_cnt = 0;
        }
    }
    cout << ans << endl;
}

