#include <iostream>
#include <queue>
using namespace std;

int main() {
    priority_queue<pair<int,int>> pq;
    int choice, complaintID, urgency;

    do {
        cout << "\n1. Add Urgent Complaint";
        cout << "\n2. Resolve Highest Priority Complaint";
        cout << "\n3. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter Complaint ID: ";
                cin >> complaintID;
                cout << "Enter Urgency Level (Higher = More Urgent): ";
                cin >> urgency;

                pq.push({urgency, complaintID});
                cout << "Complaint added to priority queue.\n";
                break;

            case 2:
                if (!pq.empty()) {
                    auto top = pq.top();
                    pq.pop();
                    cout << "Resolving Complaint ID: " << top.second
                         << " (Urgency: " << top.first << ")\n";
                } else {
                    cout << "No urgent complaints.\n";
                }
                break;

            case 3:
                cout << "Exiting...\n";
                break;
        }
    } while (choice != 3);

    return 0;
}
