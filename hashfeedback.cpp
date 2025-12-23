#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    unordered_map<int, string> feedbackMap;
    int choice, complaintID;
    string feedback;

    do {
        cout << "\n1. Submit Feedback";
        cout << "\n2. View Feedback";
        cout << "\n3. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter Complaint ID: ";
                cin >> complaintID;
                cout << "Enter Feedback: ";
                cin.ignore();
                getline(cin, feedback);

                feedbackMap[complaintID] = feedback;
                cout << "Feedback stored successfully.\n";
                break;

            case 2:
                cout << "Enter Complaint ID: ";
                cin >> complaintID;

                if (feedbackMap.find(complaintID) != feedbackMap.end())
                    cout << "Feedback: " << feedbackMap[complaintID] << endl;
                else
                    cout << "Complaint not found.\n";
                break;

            case 3:
                cout << "Exiting...\n";
                break;
        }
    } while (choice != 3);

    return 0;
}
