#include <iostream>
using namespace std;

int main() {
    int n; cin >> n;
    
    string bin; // binary representation of n, reversed
    while (n != 0) {
        bin += to_string(n%2); // append the last bit of n to the back of bin
        n /= 2;
    }
    
    int ans = 0;
    for (int i = 0; i < bin.size(); i++) {  // loop converts ans from string to integer. Takes first bit -> multiplies by 2 -> adds second bit, ...
        ans *= 2;
        ans += bin[i]-'0';  // Little trick here, bin[i] is '0' or '1'. Since characters are represented ASCII, '0'-'0' == 0 and '1'-'0' == 1. Simiarly. 'e'-'a' == 4
    }
    cout << ans;
}
