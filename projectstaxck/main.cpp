#include <iostream>
#include <stdlib.h>
#include "Stack.h"  // Include the stack class
using namespace std;

// Container structure
struct Container {
    unsigned code;
    unsigned size;
    float weight;
};

int main() {
    system("color 3");

    unsigned yardSize, block;
    cout << "ENTER YARD SIZE\nNUMBER OF BLOCKS: ";
    cin >> yardSize;

    // Create array of stack pointers
    Stack<Container>* p[yardSize];

    // Initialize each stack with a fixed size (e.g., 5)
    for (unsigned i = 0; i < yardSize; i++) {
        p[i] = new Stack<Container>(5);
    }

    Container c;
    int option;

    do {
        system("cls");
        cout << "****CONTAINER YARD****" << endl;
        cout << "1 - STORE CONTAINER" << endl;
        cout << "2 - REMOVE CONTAINER" << endl;
        cout << "3 - VIEW TOP CONTAINER" << endl;
        cout << "4 - DISPLAY YARD" << endl;
        cout << "9 - EXIT" << endl;
        cout << "SELECT OPTION: ";
        cin >> option;

        switch (option) {
            case 1:
                cout << "\nEnter the block: ";
                cin >> block;
                if (p[block]->isFull()) {
                    cout << "Block is full..." << endl;
                    system("pause");
                } else {
                    cout << "ENTER CONTAINER DETAILS." << endl;
                    cout << "Enter container code: ";
                    cin >> c.code;
                    cout << "Enter size: ";
                    cin >> c.size;
                    cout << "Enter weight: ";
                    cin >> c.weight;
                    p[block]->push(c);
                    cout << "\nCONTAINER STORED SUCCESSFULLY." << endl;
                    system("pause");
                }
                break;

            case 2:
                cout << "\nEnter the block: ";
                cin >> block;
                if (p[block]->isEmpty()) {
                    cout << "\nBLOCK IS EMPTY!!!" << endl;
                } else {
                    c = p[block]->pop();
                    cout << "CONTAINER DETAILS:" << endl;
                    cout << "Code: " << c.code << endl;
                    cout << "Size: " << c.size << endl;
                    cout << "Weight: " << c.weight << endl;
                    cout << "Container removed successfully." << endl;
                    system("pause");
                }
                break;

            case 3:
                cout << "Enter the block: ";
                cin >> block;
                if (p[block]->isEmpty()) {
                    cout << "\nBLOCK IS EMPTY!!!" << endl;
                } else {
                    c = p[block]->topElement();
                    cout << "CONTAINER DETAILS:" << endl;
                    cout << "Code: " << c.code << endl;
                    cout << "Size: " << c.size << endl;
                    cout << "Weight: " << c.weight << endl;
                    system("pause");
                }
                break;

            case 4:
                cout << "\nDisplaying yard..." << endl;
                for (int q = 0; q < yardSize; q++) {
                    if (p[q]->isEmpty()) {
                        cout << q << " - BLOCK IS EMPTY." << endl;
                    } else {
                        cout << q << " - BLOCK CONTAINERS:\n";
                        for (int i = 0; i <= p[q]->getTopIndex(); i++) {
                            c = p[q]->getValue(i);
                            cout << "Code: " << c.code << endl;
                            cout << "Size: " << c.size << endl;
                            cout << "Weight: " << c.weight << "\n\n";
                        }
                    }
                }
                system("pause");
                break;

            case 9:
                cout << "EXITING..." << endl;
                break;

            default:
                cout << "INVALID OPTION!!!\nPLEASE TRY AGAIN!" << endl;
                system("pause");
        }

    } while (option != 9);

    return 0;
}
