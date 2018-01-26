#include <iostream>
using namespace std;

int main() {
    int tcn; cin >> tcn;
    while (tcn--) {
        // Notice that Michael must walk in a full loop. Therefore, min distance is just 2 * (rightmost - leftmost)
        int n, low = 200, high = 0;
        cin >> n;
        while (n--) {
            int tmp; cin >> tmp;
            low = min(low, tmp);
            high = max(high, tmp);
        }
        cout << 2*(high-low) << endl;
    }
}
