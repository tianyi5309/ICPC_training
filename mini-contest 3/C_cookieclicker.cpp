#include <cstdio>
#include <algorithm>
#include <vector>
#include <deque>
using namespace std;
long long ans = 0;
int P, x, N;
vector<int> v;
deque<int> dq;
int arr[7000000];
int main() {
    scanf("%d%d", &N, &P);
    while (P--) {
        scanf("%d", &x);
        if (x<7000000) arr[x]++; else v.push_back(x);
    }
    sort(v.begin(), v.end());
    while (N&&(!v.empty()||!dq.empty())) {
        if (!v.empty() && (dq.empty()||v.back()>=dq.front())) {
            x = v.back(); v.pop_back();
        } else {
            x = dq.front(); dq.pop_front();
        }
        ans += x;
        x = x*9LL/10;
        if (x<7000000) arr[x]++; else dq.push_back(x);
        N--;
    }
    for (int i=6999999;i>0&&N;i--) {
        if (arr[i]) {
            int buyAmt = min(arr[i], N);
            ans += i*(long long)buyAmt;
            arr[i] -= buyAmt;
            arr[i*9/10] += buyAmt;
            N -= buyAmt;
        }
    }
    printf("%lld\n", ans);
    return 0;
}
