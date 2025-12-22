#include <iostream>
using namespace std;

const int TABLE_SIZE = 10;

// Node to store patient profile
struct Node {
    int patientID;     // Key
    int patientAge;    // Value (profile data)
    Node* next;

    Node(int id, int age) {
        patientID = id;
        patientAge = age;
        next = NULL;
    }
};

class HashTable {
private:
    Node* table[TABLE_SIZE];

    int hashFunction(int key) {
        return key % TABLE_SIZE;
    }

public:
    HashTable() {
        for (int i = 0; i < TABLE_SIZE; i++)
            table[i] = NULL;
    }

    // Store patient profile
    void insert(int patientID, int age) {
        int index = hashFunction(patientID);
        Node* newNode = new Node(patientID, age);

        if (table[index] == NULL) {
            table[index] = newNode;
        } else {
            Node* temp = table[index];
            while (temp->next != NULL) {
                if (temp->patientID == patientID) {
                    temp->patientAge = age;
                    delete newNode;
                    return;
                }
                temp = temp->next;
            }
            if (temp->patientID == patientID) {
                temp->patientAge = age;
                delete newNode;
                return;
            }
            temp->next = newNode;
        }
    }

    // Search patient profile
    void search(int patientID) {
        int index = hashFunction(patientID);
        Node* temp = table[index];

        while (temp != NULL) {
            if (temp->patientID == patientID) {
                cout << "Patient ID: " << temp->patientID
                     << ", Age: " << temp->patientAge << endl;
                return;
            }
            temp = temp->next;
        }
        cout << "Patient not found.\n";
    }

    // Remove patient profile
    void remove(int patientID) {
        int index = hashFunction(patientID);
        Node* temp = table[index];
        Node* prev = NULL;

        while (temp != NULL && temp->patientID != patientID) {
            prev = temp;
            temp = temp->next;
        }

        if (temp == NULL) {
            cout << "Patient not found.\n";
            return;
        }

        if (prev == NULL)
            table[index] = temp->next;
        else
            prev->next = temp->next;

        delete temp;
        cout << "Patient profile removed.\n";
    }
};

int main() {
    HashTable patientTable;
    int choice, id, age;

    do {
        cout << "\n1. Add Patient Profile";
        cout << "\n2. Search Patient Profile";
        cout << "\n3. Remove Patient Profile";
        cout << "\n4. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter Patient ID: ";
            cin >> id;
            cout << "Enter Patient Age: ";
            cin >> age;
            patientTable.insert(id, age);
            break;

        case 2:
            cout << "Enter Patient ID to search: ";
            cin >> id;
            patientTable.search(id);
            break;

        case 3:
            cout << "Enter Patient ID to remove: ";
            cin >> id;
            patientTable.remove(id);
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
