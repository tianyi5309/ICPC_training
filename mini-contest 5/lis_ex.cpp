#include <cmath>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iterator>

using namespace std;

int num[1000001];
int n;
int mem[1000001];
int minpos[1000001];
int lis(int pos) {
//    printf("pos = %d\n", pos);
    if (mem[pos] >= 0) return mem[pos];
//    for (int i = 0; i < pos; i++) {
//        if (num[i] < num[pos]) ans = max(ans, lis(i));
//    }
    auto it = lower_bound(minpos, minpos+1000000, num[pos]);
    int ans = it-minpos - 1 + 1; // Minus one to offset upper_bound, plus one to increase the LIS
    minpos[ans] = min(minpos[ans], num[pos]);
    mem[pos] = ans;
    return ans;
}

int main() {
//    freopen("/Users/tianyi/Desktop/input.txt", "r", stdin);
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) scanf("%d", &num[i]);
    // Reset mem
    for (int i = 0; i < 1000001; i++) mem[i] = -1;
    // Set all minpos to 1000000000
    for (int i = 0; i < 1000001; i++) minpos[i] = 2147483647;
    mem[0] = 1;
    minpos[0] = 0;
    minpos[1] = num[0];
    int ans = 0;
    for (int i = 0; i < n; i++) {
//        printf("lis=%d\n", lis(i));
        ans = max(lis(i), ans);
//        printf("ans=%d\n", ans);
    }
    
    printf("%d", ans);
//    printf("\n");
//    for (int i = 0; i < 10; i++) printf("%d\n", minpos[i]);
    return 0;
}
