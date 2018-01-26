#include <iostream>
using namespace std;

int main() {
    int a[5], b[5];
    for (int i = 0; i < 3; i++) {
        cin >> a[i] >> b[i];
    }
	// Find the unique number in x/ y coordinates
    for (int i = 0; i < 3; i++) {
        bool uniq = true;
        for (int j = 0; j < 3; j++) {
            if (i!=j && a[i]==a[j]) uniq = false;
        }
        if (uniq) cout << a[i] << " ";
    }
    
    for (int i = 0; i < 3; i++) {
        bool uniq = true;
        for (int j = 0; j < 3; j++) {
            if (i!=j && b[i]==b[j]) uniq = false;
        }
        if (uniq) cout << b[i];
    }
}
