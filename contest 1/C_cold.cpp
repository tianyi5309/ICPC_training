#include <iostream>
using namespace std;

int main(){
    int n, cnt = 0, tmp;
    cin >> n;
    while (n--) {
        cin >> tmp;
        if (tmp < 0) cnt++;
    }
    cout << cnt;
}
