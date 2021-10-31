// D - Moderate Modular Mode
#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    unsigned long long N, X, Y, n;
    cin >> N;
    while (N--)
    {
        cin >> X >> Y;
        if (X > Y)
            n = X + Y;
        else
            n = Y - ((Y % X) / 2);
        cout << n << "\n";
    }
    return 0;
}