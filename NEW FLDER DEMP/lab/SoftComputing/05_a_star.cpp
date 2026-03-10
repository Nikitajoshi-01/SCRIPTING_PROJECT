#include <bits/stdc++.h>
using namespace std;

typedef vector<vector<int>> State;

State GOAL = {{1,2,3},
              {4,5,6},
              {7,8,0}};  // 0 represents blank

// Node structure
struct Node {
    State state;
    Node* parent;
    int g;   // Cost so far
    int h;   // Heuristic
    int f;   // g + h

    Node(State s, Node* p, int g_cost, int h_cost) {
        state = s;
        parent = p;
        g = g_cost;
        h = h_cost;
        f = g + h;
    }
};

// Comparator for priority queue
struct Compare {
    bool operator()(Node* a, Node* b) {
        return a->f > b->f;  // Min-heap
    }
};

string stateToString(State s) {
    string str = "";
    for(auto row : s)
        for(auto val : row)
            str += to_string(val);
    return str;
}

// ---------------------------
// Heuristic 1: Misplaced Tiles
// ---------------------------
int misplacedTiles(State s) {
    int count = 0;
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            if(s[i][j] != 0 && s[i][j] != GOAL[i][j])
                count++;
    return count;
}

// ---------------------------
// Heuristic 2: Manhattan Distance
// ---------------------------
int manhattanDistance(State s) {
    int dist = 0;
    for(int i=0;i<3;i++) {
        for(int j=0;j<3;j++) {
            int val = s[i][j];
            if(val != 0) {
                int goalX = (val - 1) / 3;
                int goalY = (val - 1) % 3;
                dist += abs(i - goalX) + abs(j - goalY);
            }
        }
    }
    return dist;
}

// Find blank position
pair<int,int> findBlank(State s) {
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            if(s[i][j] == 0)
                return {i,j};
    return {-1,-1};
}

// Generate successors
vector<State> generateSuccessors(State s) {
    vector<State> successors;
    int dx[4] = {-1,1,0,0};
    int dy[4] = {0,0,-1,1};

    auto [x,y] = findBlank(s);

    for(int k=0;k<4;k++) {
        int nx = x + dx[k];
        int ny = y + dy[k];

        if(nx>=0 && nx<3 && ny>=0 && ny<3) {
            State newState = s;
            swap(newState[x][y], newState[nx][ny]);
            successors.push_back(newState);
        }
    }

    return successors;
}

// Print solution path
void printSolution(Node* goalNode) {
    vector<State> path;

    while(goalNode != NULL) {
        path.push_back(goalNode->state);
        goalNode = goalNode->parent;
    }

    reverse(path.begin(), path.end());

    cout << "\nSolution Path:\n\n";
    for(auto state : path) {
        for(auto row : state) {
            for(auto val : row)
                cout << val << " ";
            cout << endl;
        }
        cout << endl;
    }

    cout << "Total Moves: " << path.size() - 1 << endl;
}

// A* Algorithm
void aStar(State initial, bool useManhattan) {

    priority_queue<Node*, vector<Node*>, Compare> openList;
    unordered_set<string> closedSet;

    int h = useManhattan ? manhattanDistance(initial)
                         : misplacedTiles(initial);

    Node* start = new Node(initial, NULL, 0, h);
    openList.push(start);

    int expandedNodes = 0;

    while(!openList.empty()) {

        Node* current = openList.top();
        openList.pop();

        expandedNodes++;

        if(current->state == GOAL) {
            printSolution(current);
            cout << "Expanded Nodes: " << expandedNodes << endl;
            return;
        }

        closedSet.insert(stateToString(current->state));

        vector<State> successors = generateSuccessors(current->state);

        for(auto s : successors) {

            if(closedSet.count(stateToString(s)))
                continue;

            int g = current->g + 1;
            int h = useManhattan ? manhattanDistance(s)
                                 : misplacedTiles(s);

            Node* child = new Node(s, current, g, h);
            openList.push(child);
        }
    }

    cout << "No solution found\n";
}

int main() {

    State initial = {{1,2,3},
                     {4,0,6},
                     {7,5,8}};

    cout << "Using Manhattan Distance Heuristic\n";
    aStar(initial, true);

    cout << "\nUsing Misplaced Tiles Heuristic\n";
    aStar(initial, false);

    return 0;
}
