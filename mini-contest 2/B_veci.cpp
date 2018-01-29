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
	// Note that this problem can also be solved by iterating through numbers from 1 to 1000000, and comparing their digits
    int n; cin >> n;
    int n_cpy = n;
    int a[100]; // a is the individual digits
    int m = 0; // m is the number of digits 
    while (n_cpy != 0) {
        a[m] = n_cpy%10;
        m++;
        n_cpy/= 10;
    }
    sort(a, a+m);
    bool ans_found = false;
    do {
        int k = 0;
        for (int i = 0; i < m; i++) {
            k *= 10;
            k += a[i];
        }
        if (k > n) {
            cout << k << endl;
            ans_found = true;
            break;
        }
    } while (next_permutation(a, a+m)); // useful function that takes an array and converts it to the next higher permutation. Returns false if it is already the last permutation.
    if (!ans_found) cout << 0;
}
