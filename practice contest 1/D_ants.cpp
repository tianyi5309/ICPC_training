#include <iostream>
using namespace std;

int main() {
    int tcn; cin >> tcn;
    while (tcn--) {
        // Notice that ants colliding doesn't actually change anything. Therefore, they walk to the nearest edge.
        int l, n, earliest = 0, latest = 0;
        cin >> l >> n;
        while (n--) {
            int tmp; cin >> tmp;
            earliest = max(earliest, min(tmp, l-tmp));
            latest = max(latest, max(tmp, l-tmp));
        }
        cout << earliest << " " << latest << endl;
    }
}
