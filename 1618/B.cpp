#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t, n, c;
    cin >> t;
    while (t--)
    {
        string s, last;
        cin >> n;
        c = n - 2;
        vector<string> A(c);
        cin >> s;
        cout << s;
        last = s;
        int count = c * 2 - n;
        if (c == 1)
        {
            cout << s[0] << "\n";
            continue;
        }
        while (--c)
        {
            cin >> s;
            if (last[1] == s[0] && count != 0)
                cout << s[1], count--;
            else
                cout << s;
            last = s;
        }
        cout << "\n";
    }
}
