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

int h, w;
int a, b;

vector<vector<int>> city;
vector<vector<int>> minnum;

int main() {
//    freopen("/Users/tianyi/Desktop/input.txt", "r", stdin);
    scanf("%d%d%d%d", &h, &w, &a, &b);
    int tmp;
    for (int i = 0; i < h; i++) {
        city.push_back(vector<int>());
    }
    for (int i = 0; i < h; i++) {
        minnum.push_back(vector<int>());
        minnum[i].resize(w);
    }
    
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            scanf("%d", &tmp);
            city[i].push_back(tmp);
        }
    }
    
    // Generate minnums
    for (int col = 0; col < w; col++) {
        deque <int> q;
        for (int i = 0; i < a; i++) {
            while (!q.empty() && city[i][col] >= city[q.back()][col]) {
                q.pop_back();
            }
            q.push_back(i);
        }
        
        for (int i = a; i < h; i++) {
            minnum[i-a][col] = city[q.front()][col];
            while (!q.empty() && q.front() <= i-a) q.pop_front();
            
            while (!q.empty() && city[i][col] >= city[q.back()][col]) {
                q.pop_back();
            }
            q.push_back(i);
        }
        minnum[h-a][col] = city[q.front()][col];
    }
    
//    for (int i = 0; i <= h-a; i++) {
//        for (int j = 0; j < w; j++) {
//            printf("%d ", minnum[i][j]);
//        }
//        printf("\n");
//    }
    
    int ans = 2000000000;
    // Big window!
    for (int row = 0; row <= h-a; row++) {
        deque<int> q;
        for (int i = 0; i < b; i++) {
            while (!q.empty() && minnum[row][i] >= minnum[row][q.back()]) {
                q.pop_back();
            }
            q.push_back(i);
        }
        
        for (int i = b; i < w; i++) {
            ans = min(ans, minnum[row][q.front()]);
            while (!q.empty() && i-b >= q.front()) q.pop_front();
            
            while (!q.empty() && minnum[row][i] >= minnum[row][q.back()]) {
                q.pop_back();
            }
            q.push_back(i);
        }
        ans = min(ans, minnum[row][q.front()]);
    }
    
    printf("%d", ans);
    
    return 0;
}
