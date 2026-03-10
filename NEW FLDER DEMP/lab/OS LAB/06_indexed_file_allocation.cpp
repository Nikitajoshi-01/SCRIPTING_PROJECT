#include <iostream>
using namespace std;

int main() {
    int disk[50];     // 50 disk blocks
    int indexBlock, n, block;

    // Initialize all blocks as free (0)
    for(int i = 0; i < 50; i++)
        disk[i] = 0;

    cout << "Enter index block number: ";
    cin >> indexBlock;

    if(disk[indexBlock] == 1) {
        cout << "Index block already allocated.\n";
        return 0;
    }

    cout << "Enter number of blocks needed: ";
    cin >> n;

    int indexedBlocks[n];

    cout << "Enter block numbers:\n";
    for(int i = 0; i < n; i++) {
        cin >> block;

        if(disk[block] == 1) {
            cout << "Block " << block << " is already allocated!\n";
            return 0;
        }

        indexedBlocks[i] = block;
    }

    // Allocate index block
    disk[indexBlock] = 1;

    // Allocate file blocks
    for(int i = 0; i < n; i++)
        disk[indexedBlocks[i]] = 1;

    cout << "\nFile allocated successfully!\n";
    cout << "Index Block: " << indexBlock << endl;
    cout << "Blocks Allocated: ";

    for(int i = 0; i < n; i++)
        cout << indexedBlocks[i] << " ";

    cout << endl;

    return 0;
}
