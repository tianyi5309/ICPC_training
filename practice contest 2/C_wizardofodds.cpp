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
    long double n, k;
    cin >> n >> k;
    while (k--) {
        n /= 2;
        if (n <= 1) {
            cout << "Your wish is granted!" << endl;
        }
    }
    if (n > 1) {
        cout << "You will become a flying monkey!" << endl;
    }
}
