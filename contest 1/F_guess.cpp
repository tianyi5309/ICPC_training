#include <iostream>
using namespace std;

int main() {
    // Implementing binary search
    int low = 1, high = 1000;
    while (true) {
        int guess = (low+high)/2;
        cout << guess << endl;
        
        string res; cin >> res;
        if (res == "lower") high = guess-1; // If number is lower, it must be in [low, guess-1]
        else if (res == "higher") low = guess+1; // If number is higher, it must be in [guess+1, high]
        else exit(0); // quit running if "correct"
    }
}
