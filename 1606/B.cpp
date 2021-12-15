
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long n, k, m;
        cin >> n >> k;
        long long count{0};
        long long temp = log2(n);
        long long here = log2(k);
        if (n == 1)
            cout << 0 << "\n";
        else if (n <= ((long long)1 << here + 1))
        {
            if (n == (long long)1 << temp)
                cout << temp << "\n";
            else
                cout << temp + 1 << "\n";
        }
        else
        {
            n -= ((long long)1 << (here + 1));
            here++;
            here += (n / k);
            if (n % k == 0)
                cout << here << "\n";
            else
            {
                here++;
                cout << here << "\n";
            }
        }
    }
}