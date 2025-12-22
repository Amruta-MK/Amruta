#include <iostream>
#include <vector>
using namespace std;

// Patient data for Priority Queue
struct Patient {
    int patientID;
    int urgency;   // Higher value = higher priority
};

// Priority Queue using Max Heap
class PriorityQueue {
private:
    vector<Patient> heap;

    void heapify(int i) {
        int n = heap.size();
        while (2 * i + 1 < n) {
            int largest = 2 * i + 1;

            if (largest + 1 < n &&
                heap[largest].urgency < heap[largest + 1].urgency)
                largest++;

            if (heap[i].urgency >= heap[largest].urgency)
                break;

            swap(heap[i], heap[largest]);
            i = largest;
        }
    }

public:
    // Insert emergency patient
    void push(int id, int urgency) {
        heap.push_back({id, urgency});
        int i = heap.size() - 1;

        while (i > 0 && heap[i].urgency > heap[(i - 1) / 2].urgency) {
            swap(heap[i], heap[(i - 1) / 2]);
            i = (i - 1) / 2;
        }
    }

    // Remove highest urgency patient
    Patient pop() {
        if (heap.empty())
            return {-1, -1};

        Patient top = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        heapify(0);
        return top;
    }

    Patient top() {
        if (heap.empty())
            return {-1, -1};
        return heap[0];
    }

    bool isEmpty() {
        return heap.empty();
    }

    void display() {
        for (auto p : heap)
            cout << "[ID: " << p.patientID
                 << ", Urgency: " << p.urgency << "] ";
        cout << endl;
    }
};

int main() {
    PriorityQueue pq;
    int choice, id, urgency;

    while (true) {
        cout << "\n1. Add Emergency Patient";
        cout << "\n2. Assign Doctor to Highest Priority Patient";
        cout << "\n3. View Next Patient";
        cout << "\n4. Display Queue";
        cout << "\n5. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter Patient ID: ";
            cin >> id;
            cout << "Enter Urgency Level: ";
            cin >> urgency;
            pq.push(id, urgency);
            break;

        case 2:
            if (!pq.isEmpty()) {
                Patient p = pq.pop();
                cout << "Doctor assigned to Patient ID "
                     << p.patientID
                     << " (Urgency: " << p.urgency << ")\n";
            } else {
                cout << "No emergency patients.\n";
            }
            break;

        case 3:
            if (!pq.isEmpty()) {
                Patient p = pq.top();
                cout << "Next Patient ID "
                     << p.patientID
                     << " (Urgency: " << p.urgency << ")\n";
            } else {
                cout << "Queue is empty.\n";
            }
            break;

        case 4:
            pq.display();
            break;

        case 5:
            return 0;

        default:
            cout << "Invalid choice!\n";
        }
    }
}

