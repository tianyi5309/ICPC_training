#include<iostream>
#include <algorithm>
#include <cmath>
#include<string>
#include <set>
#include <map>
#include <cstdio>
#include <vector>
#include <deque>

using namespace std;

int n, k;
int g[200005];
int e[200005];
int main() {
	//freopen("/home/noiuser/Documents/input.txt", "r", stdin);
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++) scanf("%d", &g[i]);
	for (int i = 0; i < n; i++) scanf("%d", &e[i]);
	deque<pair<int, int> > q; // day, number left
	
	long long eaten = 0;
	for (int day = 0; day < n; day++) {
		if (g[day] != 0) q.push_back(pair<int, int>(day, g[day]));
		if (q.empty()) continue;
		// check expire
		if (q.front().first < day - k) q.pop_front();
		while (e[day] != 0 && !q.empty()) {
			if (q.front().second > e[day]) {
				q.front().second -= e[day];
				eaten += e[day];
				e[day] = 0;
			}
			else {
				eaten += q.front().second;
				e[day] -= q.front().second;
				q.pop_front();
			}
		}
	}
	
	printf("%lld", eaten);
	
}
