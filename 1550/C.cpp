// C . Manhattan Subarrays
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int manhattan(int Xa, int Ya, int Xb, int Yb)
{
    return abs(Yb - Ya) + abs(Xb - Xa);
}
int main()
{
    int t;
    cin >> t;
    int n;

    while (t--)
    {
        cin >> n;
        int count = 1;
        int temp;
        vector<int> v;
        int ans = 0;
        while (n--)
        {
            cin >> temp;
            v.push_back(temp);
        }
        for (int i{0}; i < v.size(); ++i)
            for (int j{i}; j < v.size(); ++j)
            {
                bool OK = false;
                if (j - i > 1) // subsequence size is less than 3
                {
                    for (int p{i}; p <= j - 2; ++p)    // first
                        for (int q{p + 1}; q < j; ++q) //second ; j is end
                            if (manhattan(p, v.at(p), j, v.at(j)) == manhattan(p, v.at(p), q, v.at(q)) + manhattan(q, v.at(q), j, v.at(j)))
                            {
                                OK = true;
                                break;
                            }
                    if (OK)
                        break; // this subsequent exists bad!
                }
                if (!OK)
                    ans++; // Good Case!
            }
        cout << ans << "\n";
    }
}