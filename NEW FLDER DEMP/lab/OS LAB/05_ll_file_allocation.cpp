#include <iostream>
using namespace std;
class Node {
public:
    int blockNo;
    Node* next;

    Node(int b) {
        blockNo = b;
        next = NULL;
    }
};


class File {
private:
    string fileName;
    Node* start;

public:
    // Constructor
    File() {
        start = NULL;
    }

    
    void createFile() {
        cout << "Enter file name: ";
        cin >> fileName;

        int n;
        cout << "Enter number of blocks: ";
        cin >> n;

        Node *temp = NULL;

        for(int i = 0; i < n; i++) {
            int block;
            cout << "Enter block number: ";
            cin >> block;

            Node* newNode = new Node(block);

            if(start == NULL) {
                start = newNode;
                temp = newNode;
            } else {
                temp->next = newNode;
                temp = newNode;
            }
        }

        cout << "File allocated successfully using linked allocation.\n";
    }

    
    void displayFile() {
        cout << "\nFile Name: " << fileName << endl;
        cout << "Blocks: ";

        Node* temp = start;

        while(temp != NULL) {
            cout << temp->blockNo << " -> ";
            temp = temp->next;
        }

        cout << "NULL\n";
    }
};

int main() {
    File file;

    file.createFile();
    file.displayFile();

    return 0;
}

struct File {
    string fileName;
    Node* start;
};

File createFile() {
    File file;
    cout << "Enter file name: ";
    cin >> file.fileName;

    file.start = NULL;

    int n;
    cout << "Enter number of blocks: ";
    cin >> n;

    Node *temp, *newNode;

    for(int i = 0; i < n; i++) {
        newNode = new Node();

        cout << "Enter block number: ";
        cin >> newNode->blockNo;

        newNode->next = NULL;

        if(file.start == NULL) {
            file.start = newNode;
            temp = newNode;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }

    cout << "File allocated successfully using linked allocation.\n";
    return file;
}

void displayFile(File file) {
    cout << "\nFile Name: " << file.fileName << endl;
    cout << "Blocks: ";

    Node* temp = file.start;
    while(temp != NULL) {
        cout << temp->blockNo << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

int main() {
    File file = createFile();
    displayFile(file);

    return 0;
}
