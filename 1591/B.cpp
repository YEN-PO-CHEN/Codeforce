
#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int num;
        cin >> num;
        vector<pair<int, int>> v;
        int m;

        for (int i = 1; i <= num; ++i)
        {
            cin >> m;
            v.emplace_back(m, i);
        }
        sort(v.begin(), v.end());
        if (v[num - 1].second >= v[num - 2].second)
            cout << num - v[num - 1].second << "\n";
        else
            cout << num - v[num - 2].second + 1 << "\n";
    }
    return 0;
}