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

int n, l, t;
int a[500005];
int main() {
	//freopen("/home/noiuser/Documents/input.txt", "r", stdin);
	scanf("%d%d%d", &n, &l, &t);
	for (int i = 0; i < n; i++) scanf("%d", &a[i]);
	sort(a, a+n); // Input may not be sorted
	a[n] = l;
	a[n+1] = 2000000000;
	int cnt = 0;
	int pos = 0;
	int apos = -1;
	int prevapos = -1;
	while (pos != l) {
		while (a[apos] <= pos + t) {
			apos++;
		}
		apos--; // we went over!
		if (prevapos == apos) break;
		prevapos = apos;
		pos = a[apos];
		cnt++;
	}
	cnt--;
	
	if (pos == l) printf("%d", cnt);
	else printf("-1");
	return 0;
}
