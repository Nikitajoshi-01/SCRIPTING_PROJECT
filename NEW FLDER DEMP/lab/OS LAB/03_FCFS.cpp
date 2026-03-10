#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    int at[n], bt[n], ct[n], tat[n], wt[n];
    int id[n];

    for(int i = 0; i < n; i++){
        cin >> at[i]>>bt[i];
        id[i] = i;   // store original process index
    }

    // sort by arrival time
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (at[i] > at[j]) {
                swap(at[i], at[j]);
                swap(bt[i], bt[j]);
                swap(id[i], id[j]);
            }
        }
    }

    int time = 0;

    for (int i = 0; i < n; i++) {
        if (time < at[i])
            time = at[i];   // CPU idle

        time += bt[i];
        ct[i] = time;
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
    }

    // store results in original order
    int fct[n], ftat[n], fwt[n];
    for (int i = 0; i < n; i++) {
        fct[id[i]] = ct[i];
        ftat[id[i]] = tat[i];
        fwt[id[i]] = wt[i];
    }

    cout << "\nP\tAT\tBT\tCT\tTAT\tWT\n";
    for (int i = 0; i < n; i++) {
        cout << "P" << i+1 << "\t"
             << at[id[i]] << "\t"
             << bt[id[i]] << "\t"
             << fct[i] << "\t"
             << ftat[i] << "\t"
             << fwt[i] << "\n";
    }

    return 0;
}
