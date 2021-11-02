// B - Odd Grasshopper

#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long t;
    long long here = 0;
    cin >> t;
    while (t--)
    {
        long long X0, n;
        cin >> X0 >> n;
        if (X0 % 2 == 0)
        {
            switch (n % 4)
            {
            case 1:
                X0 -= n;
                break;
            case 2:
                X0 += 1;
                break;
            case 3:
                X0 += n + 1;
                break;
            case 0:
                break;
            }
        }
        else
        {
            switch (n % 4)
            {
            case 1:
                X0 += n;
                break;
            case 2:
                X0 -= 1;
                break;
            case 3:
                X0 -= n + 1;
                break;
            case 0:
                break;
            }
        }
        cout << X0 << "\n";
    }
}
