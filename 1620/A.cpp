#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define forloop(i, a, b) for (long long i = a; i < b; ++i)

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll t, w, h, count, temp;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        bool state = true;
        int stateee = 0;
        if (s.length() == 2)
        {
            if (s[0] != s[1])
                cout << "NO\n";
            else
                cout << "YES\n";
        }
        else
        {
            for (int i = 0; i < s.length(); ++i)
            {
                if (s[i] == 'N')
                {
                    stateee++;
                }
            }
            if (stateee != 1)
                cout << "YES\n";
            else
                cout << "NO\n";
        }
    }
}