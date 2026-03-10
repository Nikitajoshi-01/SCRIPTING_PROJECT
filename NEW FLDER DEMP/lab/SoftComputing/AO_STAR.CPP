#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include<limits.h>

using namespace std;

// Structure to represent AND-OR graph
unordered_map<string, vector<vector<string>>> graph;

// Heuristic values
unordered_map<string, int> heuristic;

// To store final cost
unordered_map<string, int> cost;

// Function to implement AO*
int aoStar(string node) {

    // If node is a leaf node
    if (graph.find(node) == graph.end()) {
        cost[node] = heuristic[node];
        return cost[node];
    }

    int minCost = INT_MAX;

    // Iterate over all possible groups (AND/OR combinations)
    for (auto group : graph[node]) {

        int currentCost = 0;

        // If group has more than 1 child → AND node
        if (group.size() > 1) {
            for (auto child : group) {
                currentCost += aoStar(child);
            }
        }
        // OR node (single child in group)
        else {
            currentCost = aoStar(group[0]);
        }

        minCost = min(minCost, currentCost);
    }

    cost[node] = minCost;
    return cost[node];
}

int main() {

    // Construct AND-OR Graph

    // T (OR) → A or B
    graph["T"] = { {"A"}, {"B"} };

    // A (AND) → C and D
    graph["A"] = { {"C", "D"} };

    // B (OR) → E or F
    graph["B"] = { {"E"}, {"F"} };

    // Heuristic values
    heuristic["T"] = 9;
    heuristic["A"] = 6;
    heuristic["B"] = 5;
    heuristic["C"] = 2;
    heuristic["D"] = 3;
    heuristic["E"] = 4;
    heuristic["F"] = 2;

    int result = aoStar("T");

    cout << "Optimal Cost: " << result << endl;

    return 0;
}