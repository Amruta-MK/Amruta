#include <iostream>
using namespace std;

int main() {
    const int TOTAL_BEDS = 10;

    // Boolean array to track bed availability
    bool beds[TOTAL_BEDS];

    // Initially all beds are available
    for (int i = 0; i < TOTAL_BEDS; i++)
        beds[i] = true;

    int choice, bedNo;

    while (true) {
        cout << "\nHospital Bed Management";
        cout << "\n1. Show Bed Status";
        cout << "\n2. Occupy a Bed";
        cout << "\n3. Free a Bed";
        cout << "\n4. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "\nBed Status (1 = Available, 0 = Occupied):\n";
            for (int i = 0; i < TOTAL_BEDS; i++) {
                cout << "Bed " << i + 1 << ": " << beds[i] << endl;
            }
            break;

        case 2:
            cout << "Enter bed number to occupy (1-" << TOTAL_BEDS << "): ";
            cin >> bedNo;
            if (bedNo >= 1 && bedNo <= TOTAL_BEDS) {
                if (beds[bedNo - 1]) {
                    beds[bedNo - 1] = false;
                    cout << "Bed " << bedNo << " is now occupied.\n";
                } else {
                    cout << "Bed already occupied.\n";
                }
            } else {
                cout << "Invalid bed number.\n";
            }
            break;

        case 3:
            cout << "Enter bed number to free (1-" << TOTAL_BEDS << "): ";
            cin >> bedNo;
            if (bedNo >= 1 && bedNo <= TOTAL_BEDS) {
                if (!beds[bedNo - 1]) {
                    beds[bedNo - 1] = true;
                    cout << "Bed " << bedNo << " is now available.\n";
                } else {
                    cout << "Bed already available.\n";
                }
            } else {
                cout << "Invalid bed number.\n";
            }
            break;

        case 4:
            cout << "Exiting...\n";
            return 0;

        default:
            cout << "Invalid choice!\n";
        }
    }
}

