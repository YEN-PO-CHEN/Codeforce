
#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{

    int t;
    cin >> t;
    int a, b, n;
    while (t--)
    {
        cin >> n >> a >> b;
        if (abs(a - b) > 1 || a + b > (n - 2))
            cout << "-1";
        else
        {
            int up = 1, down = n;
            if (a > b)
            {
                cout << up << " ";
                up++;
                while (b--)
                {
                    cout << down << " " << up << " ";
                    down--;
                    up++;
                }
                while (1)
                {
                    if (down < up)
                        break;
                    cout << down << " ";
                    down--;
                }
            }
            else if (a == b)
            {
                while (a--)
                {
                    cout << up << " " << down << " ";
                    down--;
                    up++;
                }
                while (1)
                {
                    if (down < up)
                        break;
                    cout << up << " ";
                    up++;
                }
            }
            else
            {
                cout << down << " ";
                down--;
                while (a--)
                {
                    cout << up << " " << down << " ";
                    down--;
                    up++;
                }
                while (1)
                {
                    if (down < up)
                        break;
                    cout << up << " ";
                    up++;
                }
            }
        }
        cout << "\n";
    }
}