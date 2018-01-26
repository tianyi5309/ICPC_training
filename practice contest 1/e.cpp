#include <iostream>
using namespace std;

int main() {
    int tcn; cin >> tcn;
    while (tcn--) {
        // Notice that you would have to move a plate at most once. In any situation in which you move it twice, the first time is redundant.
        // Also notice that a lot of plates have to be moved. In fact, everything other than a few have to be moved.
        // Plates that do not need to be moved: starting from the bottom, consecutive sequences of 1, 2, 3, ....
        // You can prove this using combinatorics but here we just assume our intution is correct.
        int n, prev = 0;
        cin >> n;
        for (int i = 0; i < n; i++) {
            int tmp; cin >> tmp;
            if (tmp == prev+1) prev++; // Every time you see a higher consecutive number, you increase the counter/ previous number tracker. The prev varible serves two purposes
        }
        cout << n - prev << endl;
    }
}
