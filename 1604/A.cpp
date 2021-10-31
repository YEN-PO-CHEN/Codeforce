// A - Era
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
        int n;
        long long temp, i{0}, insert{0}, count{1};
        cin >> n;
        vector<long long> v;
        while (n--)
        {
            cin >> temp;

            if (temp > count)
            {
                insert += (temp - count);
                count += (temp - count);
            }
            count++;
        }
        cout << insert << "\n";
    }
}
