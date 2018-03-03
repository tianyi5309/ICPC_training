#include <cmath>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iterator>

using namespace std;

int num[1000001];
int n;
int mem[1000001];
int lis(int pos) {
//    printf("pos = %d\n", pos);
    if (mem[pos] >= 0) return mem[pos];
    if (pos == 0) return 1;
    int ans = 0;
    for (int i = 0; i < pos; i++) {
        if (num[i] < num[pos]) ans = max(ans, lis(i));
    }
    mem[pos] = ans+1;
    return ans+1;
}

int main() {
//    freopen("/Users/tianyi/Desktop/input.txt", "r", stdin);
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) scanf("%d", &num[i]);
    // Reset mem
    for (int i = 0; i < 1000001; i++) mem[i] = -1;
    
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans = max(lis(i), ans);
//        printf("ans=%d\n", ans);
    }
    
    printf("%d", ans);
    return 0;
}
