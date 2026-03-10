// #include <bits/stdc++.h>
// using namespace std;
// const int N = 4;
// // Heuristic: number of attacking pairs
// int heuristic(vector<int>& board) {
//     int attacks = 0;
//     for (int i = 0; i < N; i++) {
//         for (int j = i + 1; j < N; j++) {
//             if (board[i] == board[j] || 
//                 abs(board[i] - board[j]) == abs(i - j)) {
//                 attacks++;
//             }
//         }
//     }
//     return attacks;
// }

// // Print board
// void printBoard(vector<int>& board) {
//     for (int r = 0; r < N; r++) {
//         for (int c = 0; c < N; c++) {
//             if (board[c] == r) cout << "Q ";
//             else cout << ". ";
//         }
//         cout << "\n";
//     }
//     cout << "----------------\n";
// }

// int main() {
//     srand(time(0));

//     // Random initial state
//     vector<int> board(N);
//     for (int i = 0; i < N; i++)
//         board[i] = rand() % N;

//     while (true) {
//         int curr_h = heuristic(board);
//         printBoard(board);

//         if (curr_h == 0) {
//             cout << "Solution found!\n";
//             break;
//         }

//         vector<int> best_board = board;
//         int best_h = curr_h;

//         // Generate all neighbors
//         for (int col = 0; col < N; col++) {
//             int original_row = board[col];
//             for (int row = 0; row < N; row++) {
//                 if (row == original_row) continue;
//                 board[col] = row;
//                 int h = heuristic(board);
//                 if (h < best_h) {
//                     best_h = h;
//                     best_board = board;
//                 }
//             }
//             board[col] = original_row;
//         }

//         // If no improvement → stuck in local minimum
//         if (best_h >= curr_h) {
//             cout << "Stuck at local minimum.\n";
//             break;
//         }

//         board = best_board;
//     }

//     return 0;
// }




// //random restart   can offer me completeness
// //bc it has the condition that if the huristic is unable to find an answer or path then it starts from any random node!





// h(state) = number of pairs of queens attacking each other
// Goal:
// h = 0 → solution
// Hill climbing tries to reduce h
#include <bits/stdc++.h>
using namespace std;

const int N = 4;

// Heuristic: count attacking queen pairs
int heuristic(const vector<int>& board) {
    int h = 0;
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            // Same row or same diagonal
            if (board[i] == board[j] ||
                abs(board[i] - board[j]) == abs(i - j)) {
                h++;
            }
        }
    }
    return h;
}

// Print board in chessboard form
void printBoard(const vector<int>& board) {
    for (int r = 0; r < N; r++) {
        for (int c = 0; c < N; c++) {
            if (board[c] == r)
                cout << "Q ";
            else
                cout << ". ";
        }
        cout << "\n";
    }
    cout << "Heuristic = " << heuristic(board) << "\n";
    cout << "----------------------\n";
}

int main() {

    // Known LOCAL MINIMUM state
    vector<int> board = {0, 2, 1, 3};

    cout << "Initial State:\n";
    printBoard(board);

    while (true) {
        int curr_h = heuristic(board);

        vector<int> best_board = board;
        int best_h = curr_h;

        // Generate all neighbors
        for (int col = 0; col < N; col++) {
            int original_row = board[col];

            for (int row = 0; row < N; row++) {
                if (row == original_row) continue;

                board[col] = row;
                int h = heuristic(board);

                // STRICT improvement only
                if (h < best_h) {
                    best_h = h;
                    best_board = board;
                }
            }

            board[col] = original_row; // restore
        }

        // No better neighbor → stuck
        if (best_h >= curr_h) {
            cout << "❌ Stuck in local minimum.\n";
            break;
        }

        board = best_board;
        printBoard(board);
    }

    return 0;
}
