#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    int m, n = 7;
    while (t--)
    {
        vector<int> v;
        while (n--)
        {
            cin >> m;
            v.push_back(m);
        }
        n = 7;
        sort(v.begin(), v.end());
        if (v[0] + v[1] == v[3])
            cout << v[2] << " " << v[1] << " " << v[0] << "\n";
        else
            cout << v[3] << " " << v[1] << " " << v[0] << "\n";
    }
}