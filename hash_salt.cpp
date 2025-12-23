#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    // Hash Map: Pan ID -> State
    unordered_map<int, string> saltPans;

    int choice, panID;
    string state;

    do {
        cout << "\n1. Add / Update Pan State";
        cout << "\n2. View Pan State";
        cout << "\n3. Remove Pan";
        cout << "\n4. Display All Pans";
        cout << "\n5. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter Pan ID: ";
                cin >> panID;
                cout << "Enter State (Evaporating / Crystallizing / Harvest-ready / Maintenance): ";
                cin >> state;

                saltPans[panID] = state;   // Hashing happens internally
                cout << "Pan data stored successfully.\n";
                break;

            case 2:
                cout << "Enter Pan ID to search: ";
                cin >> panID;

                if (saltPans.find(panID) != saltPans.end()) {
                    cout << "Pan ID " << panID
                         << " is in state: " << saltPans[panID] << endl;
                } else {
                    cout << "Pan not found.\n";
                }
                break;

            case 3:
                cout << "Enter Pan ID to remove: ";
                cin >> panID;

                if (saltPans.erase(panID))
                    cout << "Pan removed successfully.\n";
                else
                    cout << "Pan not found.\n";
                break;

            case 4:
                cout << "\nSalt Pan Status:\n";
                for (auto &p : saltPans) {
                    cout << "Pan ID: " << p.first
                         << " | State: " << p.second << endl;
                }
                break;

            case 5:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice!\n";
        }

    } while (choice != 5);

    return 0;
}
