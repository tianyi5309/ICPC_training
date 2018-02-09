#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
int n, k, i, q, w, e, r, t1;
bool chosen[400000];
int one[400000];
int two[400000];
int three[400000];
int four[400000];
vector<int> oneC;
vector<int> twoC;
vector<int> threeC;
vector<int> fourC;
int main(void) {
    //freopen("in.txt", "r", stdin);
    q=w=e=r=0;
    scanf("%d", &n);
    scanf("%d", &k);
    for (i=0;i<n;i++) {
        chosen[i] = false;
        scanf("%d", &t1);
        one[t1-1] = i;
        scanf("%d", &t1);
        two[t1-1] = i;
        scanf("%d", &t1);
        three[t1-1] = i;
        scanf("%d", &t1);
        four[t1-1] = i;
    }
    for (i=0;i<k;i++) {
        while (chosen[one[q]]) q++;
        oneC.push_back(one[q]);
        chosen[one[q]] = true;
        while (chosen[two[w]]) w++;
        twoC.push_back(two[w]);
        chosen[two[w]] = true;
        while (chosen[three[e]]) e++;
        threeC.push_back(three[e]);
        chosen[three[e]] = true;
        while (chosen[four[r]]) r++;
        fourC.push_back(four[r]);
        chosen[four[r]] = true;
    }
    sort(oneC.begin(), oneC.end());
    sort(twoC.begin(), twoC.end());
    sort(threeC.begin(), threeC.end());
    sort(fourC.begin(), fourC.end());
    printf("%d", oneC[0]+1);
    for (i=1;i<k;i++) {
        printf(" %d", oneC[i]+1);
    }
    printf("\n%d", twoC[0]+1);
    for (i=1;i<k;i++) {
        printf(" %d", twoC[i]+1);
    }
    printf("\n%d", threeC[0]+1);
    for (i=1;i<k;i++) {
        printf(" %d", threeC[i]+1);
    }
    printf("\n%d", fourC[0]+1);
    for (i=1;i<k;i++) {
        printf(" %d", fourC[i]+1);
    }
    return 0;
}

