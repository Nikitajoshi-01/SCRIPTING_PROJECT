#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    int at[n], bt[n], ct[n], tat[n], wt[n];
    bool done[n] = {0};

    for (int i = 0; i < n; i++) {
        cin >> at[i] >> bt[i];
    }

    int time = 0, completed = 0;

    while (completed < n) {
        int idx = -1;
        int mn = INT_MAX;

        // select shortest job among arrived & not done
        for (int i = 0; i < n; i++) {
            if (at[i] <= time && !done[i] && bt[i] < mn) {
                mn = bt[i];
                idx = i;
            }
        }

        if (idx == -1) {
            time++;     // CPU idle
            continue;
        }

        // execute whole process
        time += bt[idx];
        ct[idx] = time;
        tat[idx] = ct[idx] - at[idx];
        wt[idx] = tat[idx] - bt[idx];

        done[idx] = true;
        completed++;
    }

    cout << "\nP\tAT\tBT\tCT\tTAT\tWT\n";
    for (int i = 0; i < n; i++) {
        cout << "P" << i+1 << "\t"
             << at[i] << "\t"
             << bt[i] << "\t"
             << ct[i] << "\t"
             << tat[i] << "\t"
             << wt[i] << "\n";
    }

    return 0;
}
