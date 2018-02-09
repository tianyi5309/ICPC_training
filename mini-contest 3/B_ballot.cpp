#include <cmath>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <stack>
#include <map>

using namespace std;

int main() {
//    freopen("/Users/tianyi/Desktop/input.txt", "r", stdin);
    int num, c;
    map <int, int> n; // Map lower_bound searches by key => n[lotterynumber] = position
    scanf("%d %d", &num, &c);
    
    int tmp;
    for (int i = 1; i <= num; i++) {
        scanf("%d", &tmp);
        n[tmp] = i;
    }
    
    while (c--) {
        scanf("%d", &tmp);
        auto it = n.lower_bound(tmp);
        if (it == n.end()) {
            // We can only use the second one!
            advance(it, -1);
            printf("%d\n", it->second);
            n.erase(it);
        }
        else if (it == n.begin()) {
            // We can only use the first one!
            printf("%d\n", it->second);
            n.erase(it);
        }
        else {
            int dist1 = it->first - tmp;
            advance(it, -1);
            int dist2 = tmp - it->first;
//            printf("%d %d\n", dist1, dist2);
            if (dist1 < dist2) {
                // Use the first one
                advance(it, 1);
                printf("%d\n", it->second);
                n.erase(it);
            }
            else {
                // Use the second one (we're already on it)
                printf("%d\n", it->second);
                n.erase(it);
            }
        }
    }
    return 0;
}
