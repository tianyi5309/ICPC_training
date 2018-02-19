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

int n;
int j[200005];
int g[200005];

int main() {
	//freopen("/home/noiuser/Documents/input.txt", "r", stdin);
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", &j[i]);
	for (int i = 0; i < n; i++) scanf("%d", &g[i]);
	
	int jwin = 0;
	int gwin = 0;
	for (int i = 0; i < n; i++) {
		if (j[i] > g[i]) jwin++;
		else gwin++;
	}
	
	if (jwin > gwin) {
		printf("0"); // Don't need to combine!
		exit(0);
	}
	
	// Combine when a) 2 losing areas, b) 1 win 1 lose -> 1 win
	int combines = gwin - jwin + 1;
	
	// Check if it's possible to get that many combines
	int cnt = 0;
	for (int i = 0; i < n-1; i++) {
		if (j[i] > g[i] && j[i+1] <= g[i+1] && j[i] + j[i+1] > g[i] + g[i+1]) {
			cnt++;
			i++;
		}
		else if (j[i] <= g[i] && j[i+1] > g[i+1] && j[i] + j[i+1] > g[i] + g[i+1]) {
			cnt++;
			i++;
		}
		else if (j[i] <= g[i] && j[i+1] <= g[i+1]) {
			cnt++;
			i++;
		}
	}
	
	if (cnt >= combines) printf("%d", combines);
	else printf("-1");
}
