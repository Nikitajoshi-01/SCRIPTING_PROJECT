// #include<iostream>
// #include<vector>
// using namespace std;
// int main(){
//     int n;
//     cout<<"enter the number of prrocesses";
//     cin>>n;
//     vector<int>p(n);
//     vector<int>arr(n);
//     vector<int>brr(n);
//     cout<<"enter process id , arrival time and burst time"<< endl;
//     for(int i=0;i<n;i++){
//         cin>>v[i]>>arr[i]>>brr[i];
//     }
//     vector<int>trr(n);
//     vector<int>wt(n); 
// }



#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    int at[n], bt[n], rt[n], ct[n], tat[n], wt[n];

    for (int i = 0; i < n; i++) {
        cin >> at[i] >> bt[i];
        rt[i] = bt[i];   // remaining time
    }

    int time = 0, done = 0;

    while (done < n) {
        int idx = -1;
        int mn = INT_MAX;

        // find process with minimum remaining time
        for (int i = 0; i < n; i++) {
            if (at[i] <= time && rt[i] > 0 && rt[i] < mn) {
                mn = rt[i];
                idx = i;
            }
        }

        if (idx == -1) {
            time++;      // CPU idle
            continue;
        }

        // execute for 1 unit
        rt[idx]--;
        time++;

        // process finished
        if (rt[idx] == 0) {
            done++;
            ct[idx] = time;
            tat[idx] = ct[idx] - at[idx];
            wt[idx] = tat[idx] - bt[idx];
        }
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
