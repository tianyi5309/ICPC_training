#include <bits/stdc++.h>
using namespace std;

int n;
int a[1000005];
int m[100005] = {0};
int sum[100005] = {0};
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n;i ++) scanf("%d", &a[i]);
	int cnt = 0;
	for (int i = 0; i < n-1; i++) {
		if (a[i] == a[i+1]) {
			cnt++;
			m[a[i]]++;
		}
	}
	for (int i = 0; i < n; i++) {
	    sum[a[i]]++;
	}
	
	int curmax = 0;
	for (int i = 0; i < 100005; i++) {
	    curmax = max(curmax, m[i]);
	}
	int summax = 0;
	for (int i  =0; i < 100005; i++) {
	    summax = max(summax, sum[i]);   
	}
	if (summax > (n+1)/2) {
	    printf("-1");
	}
	else if ((cnt+1)/2 >= curmax) {
		printf("%d", (cnt+1)/2);
	}
	else {
		printf("%d", curmax);
	}
}
