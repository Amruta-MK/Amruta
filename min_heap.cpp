#include <iostream>
#include <vector>
using namespace std;

// Structure for demand node
struct DemandNode {
    int nodeID;
    int demandAmount;  // Smaller means higher priority for supply (e.g., urgent to serve low-demand first)
};

class MinHeap {
private:
    vector<DemandNode> heap;

    void heapifyUp(int index) {
        while (index > 0) {
            int parent = (index - 1) / 2;
            if (heap[parent].demandAmount > heap[index].demandAmount) {
                swap(heap[parent], heap[index]);
                index = parent;
            } else {
                break;
            }
        }
    }

    void heapifyDown(int index) {
        int n = heap.size();
        while (2 * index + 1 < n) {
            int leftChild = 2 * index + 1;
            int rightChild = 2 * index + 2;
            int smallest = index;

            if (leftChild < n && heap[leftChild].demandAmount < heap[smallest].demandAmount)
                smallest = leftChild;
            if (rightChild < n && heap[rightChild].demandAmount < heap[smallest].demandAmount)
                smallest = rightChild;

            if (smallest != index) {
                swap(heap[index], heap[smallest]);
                index = smallest;
            } else {
                break;
            }
        }
    }

public:
    void push(int nodeID, int demandAmount) {
        heap.push_back({nodeID, demandAmount});
        heapifyUp(heap.size() - 1);
    }

    DemandNode pop() {
        if (heap.empty()) return {-1, -1};
        DemandNode root = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);
        return root;
    }

    DemandNode top() {
        if (heap.empty()) return {-1, -1};
        return heap[0];
    }

    bool isEmpty() {
        return heap.empty();
    }
};

int main() {
    MinHeap demandHeap;
    int choice, id, demand;

    while (true) {
        cout << "\n1. Add Demand Node";
        cout << "\n2. Serve Node with Lowest Demand";
        cout << "\n3. View Node with Lowest Demand";
        cout << "\n4. Exit\nEnter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter node ID: ";
                cin >> id;
                cout << "Enter demand amount: ";
                cin >> demand;
                demandHeap.push(id, demand);
                cout << "Demand node added.\n";
                break;

            case 2:
                if (!demandHeap.isEmpty()) {
                    DemandNode served = demandHeap.pop();
                    cout << "Serving node " << served.nodeID 
                         << " with demand " << served.demandAmount << ".\n";
                } else {
                    cout << "No demand nodes available.\n";
                }
                break;

            case 3:
                if (!demandHeap.isEmpty()) {
                    DemandNode topNode = demandHeap.top();
                    cout << "Next node to serve: " << topNode.nodeID 
                         << " (Demand: " << topNode.demandAmount << ")\n";
                } else {
                    cout << "No demand nodes available.\n";
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
