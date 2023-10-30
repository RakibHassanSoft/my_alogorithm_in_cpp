#include <bits/stdc++.h>
using namespace std;

int unbounded_knapsack(int n, int s, int val[], int w[])
{
    int dp[n + 1][s + 1];
    
    // Initializing the dp array
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= s; j++)
        {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else
                dp[i][j] = -1;
        }
    }

    // Filling up the dp array
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= s; j++)
        {
            if (w[i - 1] <= j)
            {
                dp[i][j] = max(val[i - 1] + dp[i][j - w[i - 1]], dp[i - 1][j]);
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    return dp[n][s];
}

int main()
{
    int n, s;
    cin >> n >> s;
    int val[n], w[n];
    for (int i = 0; i < n; i++)
    {
        cin >> val[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> w[i];
    }
    cout << unbounded_knapsack(n, s, val, w);
    return 0;
}



// 4 6
// 5 3 2 4
// 4 1 3 2

// 18