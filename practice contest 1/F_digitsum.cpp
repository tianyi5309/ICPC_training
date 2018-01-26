#include <iostream>
#include <cmath>
using namespace std;

int main() {
        int tcn; cin >> tcn;
    while (tcn--) {
        long long a, b;
        cin >> a >> b;
        b++; // NOTE: b is excluded now
        long long ans = 0;
        for (int pos = 0; pos <= 20; pos++) { // Digit position, counting the digits of the order 10^pos
            long long mag = pow(10, pos);
            long long cur = a; // tracks current value of 'a'
            // Define cycle to be a sequence of numbers, before changing digits. Cycle has max length mag, is 'complete' if length = mag
            // Define full cycle to be 10 cycles, from 0-9
            // Count: current cycle, full cycles until reaching end, next x complete cycles, end cycle
            
            // If current cycle ends before finishing, just count directly
            if (b/mag == a/mag) {
                ans += ((a/mag) %10) * (b-a);
                continue;
            }
            
            // count current cycle
            ans += ((a/mag) %10) * (mag - a%mag);
            cur += mag - a%mag;
            
            // count full cycles until end
            long long num_full_cycles = (b - cur) / (10 * mag);
            ans += num_full_cycles * mag * 45;
            cur += num_full_cycles * mag * 10;
            
            // count next complete cycles
            long long num_complete_cycles = (b - cur) / mag;
            while (num_complete_cycles--) {
                ans += mag * ((cur/mag)%10);
                cur += mag;
            }
            
            ans += ((cur/mag) %10) * (b - cur);
        }
        cout << ans << endl;
    }
}
