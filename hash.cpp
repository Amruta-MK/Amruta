#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    // Hash map: slotID -> vehicleID (-1 means empty)
    unordered_map<int, int> parkingSlots;

    // Initialize parking slots
    parkingSlots[101] = -1; // slot 101 is empty
    parkingSlots[102] = 203; // slot 102 has vehicle 203
    parkingSlots[103] = -1;
    parkingSlots[104] = 305; // slot 104 has vehicle 305

    int choice, slotID, vehicleID;

    do {
        cout << "\n1. Park vehicle\n2. Remove vehicle\n3. Check slot\n4. Display all slots\n5. Exit\nEnter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter slot ID: ";
                cin >> slotID;
                cout << "Enter vehicle ID: ";
                cin >> vehicleID;

                if (parkingSlots.find(slotID) != parkingSlots.end()) {
                    if (parkingSlots[slotID] == -1) {
                        parkingSlots[slotID] = vehicleID;
                        cout << "Vehicle " << vehicleID << " parked at slot " << slotID << ".\n";
                    } else {
                        cout << "Slot " << slotID << " is already occupied by vehicle " << parkingSlots[slotID] << ".\n";
                    }
                } else {
                    cout << "Invalid slot ID.\n";
                }
                break;

            case 2:
                cout << "Enter slot ID to remove vehicle: ";
                cin >> slotID;

                if (parkingSlots.find(slotID) != parkingSlots.end()) {
                    if (parkingSlots[slotID] != -1) {
                        cout << "Vehicle " << parkingSlots[slotID] << " removed from slot " << slotID << ".\n";
                        parkingSlots[slotID] = -1;
                    } else {
                        cout << "Slot " << slotID << " is already empty.\n";
                    }
                } else {
                    cout << "Invalid slot ID.\n";
                }
                break;

            case 3:
                cout << "Enter slot ID to check: ";
                cin >> slotID;

                if (parkingSlots.find(slotID) != parkingSlots.end()) {
                    if (parkingSlots[slotID] == -1)
                        cout << "Slot " << slotID << " is empty.\n";
                    else
                        cout << "Slot " << slotID << " has vehicle " << parkingSlots[slotID] << ".\n";
                } else {
                    cout << "Invalid slot ID.\n";
                }
                break;

            case 4:
                cout << "All parking slots:\n";
                for (auto &p : parkingSlots) {
                    if (p.second == -1)
                        cout << "Slot " << p.first << ": EMPTY\n";
                    else
                        cout << "Slot " << p.first << ": Vehicle " << p.second << "\n";
                }
                break;

            case 5:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice.\n";
        }

    } while (choice != 5);

    return 0;
}
