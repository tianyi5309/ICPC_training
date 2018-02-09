#include <cmath>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <stack>
#include <map>
#include <queue>
#include <set>
#include <unordered_map>
using namespace std;

int n, m, w;
vector<int> v;
deque <int> q;
int main() {
//    freopen("/Users/tianyi/Desktop/input.txt", "r", stdin);
    scanf("%d%d%d", &n, &m, &w);
    
//    set <int> s;
//    int tmp;
//    for (int i = 0; i < n; i++) {
//        scanf("%d", &tmp);
//        s.insert(tmp);
//    }
//    printf("%d", s.size());
    int tmp;
    for (int i = 0; i < n; i++) {
        scanf("%d", &tmp);
        v.push_back(tmp);
    }
    sort(v.begin(), v.end());
    
    int ans = 0;
    bool solved = false;
    
    for (int i = 0; i < n; i++) {
        q.push_back(v[i]);
//        if (i != n-1 && v[i+1] == v[i]) continue;
//        printf("push %d\n", v[i]);
        while (!q.empty() && q.front() <= v[i]-m) {
//            printf("pop %d\n", q.front());
            q.pop_front();
        }
        if (q.size() >= w) solved = true;
        if (q.size() > w) {
            ans += q.size() - w;
            while (q.size() >= w) {
                q.pop_back();
            }
            q.push_back(v[i]);
        }
    }
    if (solved) printf("%d", n-ans);
    else printf ("-1");
    return 0;
}
