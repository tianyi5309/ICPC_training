#include <iostream>
using namespace std;

int main() {
    int r, c;
    char a[50005][15];
    cin >> r >> c;
    for (int i = r-1; i >= 0; i--) { // Inverting the array top-down, so that it makes more sense.
        for (int j = 0; j < c; j++) { 
            scanf(" %c", &a[i][j]); // similar to cin, but deals with whitespace better
        }
    }
    
    for (int j = 0; j < c; j++) {
        // We keep track of two 'pointers', i for the current position we are exploring, spc for the first found empty space.
        int spc = -1;
        for (int i = 0; i < r; i++) {
            if (a[i][j] == 'a') {
                while (a[spc][j] != '.' && spc < i) { // Advance spc to the first available empty space, or the current location if no empty space
                    spc++;
                }
                if (spc != i) { // If space is available, then swap apple and space.
                    a[spc][j] = 'a';
                    a[i][j] = '.';
                }
            }
            else if (a[i][j] == '#') { // If we meet a wall, we move spc up to the wall
                spc = i;
            }
        }
    }
    
    for (int i = r-1; i >= 0; i--) {
        for (int j = 0; j < c; j++) {
            cout << a[i][j];
        }
        cout << endl;
    }
}
