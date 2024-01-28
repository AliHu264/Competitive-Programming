#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <map>
#include <tuple>


// C++ program of a space optimized DP solution for
// 0-1 knapsack problem.
#include<bits/stdc++.h>

using namespace std;

// val[] is for storing maximum profit for each weight
// wt[] is for storing weights
// n number of item
// W maximum capacity of bag
// dp[W+1] to store final result
int knapSack(int *val, int *wt, int n, int W) {
    // array to store final result
    //dp[i] stores the profit with knapSack capacity "i"
    int dp[W + 1];

    //initially profit with 0 to W knapSack capacity is 0
    memset(dp, 0, sizeof(dp));

    // iterate through all items
    for (int i = 0; i < n; i++)
        //traverse dp array from right to left
        for (int j = W; j >= wt[i]; j--)
            dp[j] = max(dp[j], val[i] + dp[j - wt[i]]);
    /*above line finds out maximum of  dp[j](excluding ith element value)
      and val[i] + dp[j-wt[i]] (including ith element value and the
      profit with "knapSack capacity - ith element weight") */
    return dp[W];
}

int main() {
    int val[] = {1, 1, 3, 7, 5, 2},
        wt[] = {2, 5, 4, 6, 1, 2}, W = 6, n = 6;
    cout << knapSack(val, wt, n, W) << endl;
    return 0;
}

//// using 2d array

//for (i = 0; i <= n; i++){
//    for (j = 0; j <= W; j++){
//        if (i==0 || j==0)
//            dp[i][j] = 0;
//        else if (wt[i] <= j)
//            dp[i][j] = max(val[i] + dp[i-1][j-wt[i]],  dp[i-1][j]);
//        else
//            dp[i][j] = dp[i-1][j];
//    }
//}