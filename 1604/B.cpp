// B - XOR Specia-LIS-t

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
        long long temp, last{0}, current{0};
        bool re{true};
        cin >> n;
        for (int i{1}; i <= n; ++i)
        {
            last = current;
            cin >> current;
            if (last >= current)
                re = false;
        }
        if (n % 2 == 0 || re == false)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}
