#include <iostream>
#include <queue>
using namespace std;

// Structure to store pan data
struct Pan {
    int panID;
    int saltYield;
};

// Comparator for Max Heap (highest salt first)
struct Compare {
    bool operator()(Pan const& p1, Pan const& p2) {
        return p1.saltYield < p2.saltYield;
    }
};

int main() {
    priority_queue<Pan, vector<Pan>, Compare> pq;

    int choice, panID, saltYield;

    do {
        cout << "\n1. Add Pan with Salt Yield";
        cout << "\n2. Process Pan with Highest Yield";
        cout << "\n3. Display Total Pans";
        cout << "\n4. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter Pan ID: ";
                cin >> panID;
                cout << "Enter Salt Yield: ";
                cin >> saltYield;

                pq.push({panID, saltYield});
                cout << "Pan added to priority queue.\n";
                break;

            case 2:
                if (!pq.empty()) {
                    Pan topPan = pq.top();
                    pq.pop();

                    cout << "Processing Pan ID: " << topPan.panID
                         << " with Salt Yield: " << topPan.saltYield << endl;
                } else {
                    cout << "No pans available.\n";
                }
                break;

            case 3:
                cout << "Total pans in queue: " << pq.size() << endl;
                break;

            case 4:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice!\n";
        }

    } while (choice != 4);

    return 0;
}
