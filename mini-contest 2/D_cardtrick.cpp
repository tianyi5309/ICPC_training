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
	// Simulate the placement of cards. #1 -> pos #2. #2 -> pos #5.
	// Notice that if you exceed n, the cards 'wrap over'
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        int a[50];
        memset(a, -1, sizeof(a)); // sets everything in a to -1
        int pos = -1;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= i; j++) {
				// Shifts pos by one, while skipping over previous cards that have already been removed.
                do {
                    pos++; pos %= n;
                }
                while (pos == -1 || a[pos] != -1);
            }
            a[pos] = i;
        }
        for (int i = 0; i < n; i++) {
            cout << a[i] << " ";
        }
        cout << endl;
    }
}

