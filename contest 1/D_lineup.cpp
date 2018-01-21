#include <iostream>
using namespace std;

int main() {
    int n;
    string s[30];
    cin >> n;
    for (int i = 0; i < n; i++) cin >> s[i];
    
    bool dec = true, inc = true;
    for (int i = 0; i < n-1; i++) { // Iterate through all consecutive pair (a, b): if a < b, cannot be decreasing. if a > b, cannot be increasing
        if (s[i] < s[i+1]) dec = false; 
        else inc = false;
    }
    
    if (inc) cout << "INCREASING";
    else if (dec) cout << "DECREASING";
    else cout << "NEITHER";
}
