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

int r, c;
char a[20][20]; // global array for easy comparison 

bool comp(int n) { // compares column n and n+1, returning true if n > n+1
    for (int i = 0; i < r; i++) {
        if (tolower(a[i][n]) < tolower(a[i][n+1])) return false;
        else if (tolower(a[i][n]) > tolower(a[i][n+1])) return true;
    }
    return false;
}

void swap(int n) { // swaps column j and j+1
    for (int i = 0; i < r; i++) {
        char tmp = a[i][n];
        a[i][n] = a[i][n+1];
        a[i][n+1] = tmp;
    }
}

int main(){
    while (true) {
        cin >> r >> c;
        if (r+c == 0) return 0;
        
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) scanf(" %c", &a[i][j]);
        }
        
        for (int i = 0; i < c; i++) { // run bubble sort, c iterations
            for (int j = 0; j < c-1; j++) {
                if (comp(j)) {
                    swap(j);
                }
            }
        }
        
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                cout << a[i][j];
            }
            cout << endl;
        }
    }
}

