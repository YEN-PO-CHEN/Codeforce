// E - K Balanced Teams
#include <bits/stdc++.h>
using namespace std;
int main()
{
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector<long long> a(n), cnt(n);
    vector<vector<long long>> dp(n + 1, (vector<long long>(k + 1, 0)));
    //dp[i][j] the max number of students in at most j non-empty teams if we consider first i students.
    for (int i{0}; i < n; ++i)
        cin >> a.at(i);
    sort(a.begin(), a.end());
    for (int i{n}; i >= 1; --i)
    {
        for (int j{i - 1}; j >= 0; --j)
        {
            if (a[i] - a[j] > 5)
            {
                cnt[i] = j;
                break;
            }
            else if (j == 0)
                cnt[i] = 0;
        }
    }
    long long ans{0};
    for (int i{1}; i <= n; i++)
    {
        long long l = cnt[i];
        for (int j{1}; j <= k; j++)
        {
            /*
                dp[l][j - 1] + (i - l)  => 當 數到第l個學生，組出新的一分隊(i-cnt[i])
                dp[l][j]                => 當 數到第l個學生，已經完成總分隊
                dp[i - 1][j]            => 當 數到第i-1個學生，已經完成分隊
            */
            dp[i][j] = max(dp[k][j - 1] + (i - l), dp[l][j]);
            dp[i][j] = max(dp[i - 1][j], dp[i][j]);
            ans = max(ans, dp[i][j]);
            printf("cnt[%d](l) = %d, dp[%d][%d] = %d, dp[%d][%d] = %d ", i, cnt[i], i, j, dp[i][j], l, j - 1, dp[l][j - 1]);
            printf("dp[%d][%d] = %d , dp[%d][%d], ans = %d \n", l, j, dp[l][j], i - 1, j, dp[i - 1][j], ans);
        }
        cout << endl;
    }
    cout << ans << "\n";
}