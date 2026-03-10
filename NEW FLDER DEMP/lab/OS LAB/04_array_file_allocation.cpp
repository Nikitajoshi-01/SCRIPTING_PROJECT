#include <iostream>
using namespace std;

int main() {
    bool disk[50] = {0};   // 0 = free, 1 = allocated
    int start, length;

    cout << "Enter starting block: ";
    cin >> start;

    cout << "Enter length of file: ";
    cin >> length;

    // Check if blocks are free
    bool possible = true;
    for(int i = start; i < start + length; i++) {
        if(disk[i] == 1 || i >= 50) {
            possible = false;
            break;
        }
    }

    if(possible) {
        for(int i = start; i < start + length; i++) {
            disk[i] = 1;
        }
        cout << "File allocated successfully.\n";
    } else {
        cout << "Allocation failed. Blocks not free.\n";
    }

    return 0;
}
