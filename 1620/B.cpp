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
        cin >> w >> h;
        int i;
        ll x0max, x0min, xmmax, xmmin, y0max, y0min, yhmax, yhmin;
        cin >> count;
        for (int i = 0; i < count; ++i)
        {
            cin >> temp;
            if (i == 0)
                y0min = temp;
            if (i == count - 1)
                y0max = temp;
        }
        cin >> count;
        forloop(i, 0, count)
        {
            cin >> temp;
            if (i == 0)
                yhmin = temp;
            if (i == count - 1)
                yhmax = temp;
        }
        cin >> count;
        forloop(i, 0, count)
        {
            cin >> temp;
            if (i == 0)
                x0min = temp;
            if (i == count - 1)
                x0max = temp;
        }
        cin >> count;
        forloop(i, 0, count)
        {
            cin >> temp;
            if (i == 0)
                xmmin = temp;
            if (i == count - 1)
                xmmax = temp;
        }
        ll y = max(y0max - y0min, yhmax - yhmin) * h;
        ll x = max(x0max - x0min, xmmax - xmmin) * w;
        cout << max(x, y) << "\n";
    }
}