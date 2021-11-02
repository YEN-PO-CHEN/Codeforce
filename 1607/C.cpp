// C - Minimum Extraction
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
        long long n;
        cin >> n;
        long long maxi{0}, temp;
        vector<long long> v(n);
        vector<long long> Table(n);
        for (int i{0}; i < n; ++i)
            cin >> v.at(i);
        sort(v.begin(), v.end());
        maxi = v.at(0);
        for (int i = 1; i < n; i++)
        {
            Table.at(i) = v.at(i) - v.at(i - 1);
            maxi = max(Table.at(i), maxi);
        }
        cout << maxi << "\n";
    }
}