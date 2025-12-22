#include <iostream>
using namespace std;

// Structure to represent a high-demand node
struct DemandNode {
    int nodeID;
    int demandAmount;  // e.g., units of water or electricity needed
};

int main() {
    int numNodes;
    cout << "Enter number of high-demand nodes: ";
    cin >> numNodes;

    // Dynamically allocate array of DemandNode based on current demand
    DemandNode* nodes = new DemandNode[numNodes];

    // Input details for each node
    for (int i = 0; i < numNodes; i++) {
        cout << "Enter node ID for node " << i + 1 << ": ";
        cin >> nodes[i].nodeID;
        cout << "Enter demand amount for node " << nodes[i].nodeID << ": ";
        cin >> nodes[i].demandAmount;
    }

    // Simulate dynamic adaptation by adjusting supply (example logic)
    cout << "\nAllocating supply based on current demand...\n";
    for (int i = 0; i < numNodes; i++) {
        // Example: If demand > threshold, allocate extra resources dynamically
        if (nodes[i].demandAmount > 100) {
            cout << "Node " << nodes[i].nodeID << " is high-demand. Allocating additional resources.\n";
        } else {
            cout << "Node " << nodes[i].nodeID << " demand within normal limits.\n";
        }
    }

    // Clean up dynamic memory
    delete[] nodes;

    return 0;
}
