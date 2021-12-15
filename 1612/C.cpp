// A - Linear Keyboard
#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    long long k, x, output, temp, tt, a2;
    long long db;
    while (t--)
    {
        cin >> k >> x;
        temp = k * (k + 1) / 2;
        if (2 * temp - k <= x)
        {
            output = 2 * k - 1;
        }
        else if (x == temp)
            output = k;
        else if (x == 1)
            output = 1;
        else
        {
            if (x > temp)
            {
                tt = x - temp;
                tt = temp - k - tt;
                db = sqrt(8LL * tt + 1LL) / 2LL;
                if (db * (db + 1) / 2 == k)
                    output = 2 * k - db - 1;
                else
                    output = 2 * k - db;
            }
            else
            {

                db = sqrt(8LL * k + 1LL) / 2LL;
                if (x > ((db + 1LL) * (db + 2LL) / 2LL))
                    output = db + 2LL;
                else
                    output = db + 1LL;
            }
        }
        cout << output << "\n";
    }
}
