// B - Odd Grasshopper

#include <bits/stdc++.h>
using namespace std;
int main()
{

    long long t;
    long long n, a, b;
    cin >> t;

    while (t--)
    {
        queue<int> front;
        queue<int> end;
        queue<int> wait;

        queue<int> check;
        cin >> n >> a >> b;
        if (a < b)
        {
            if (a > n / 2 || b < n / 2 + 1)
            {
                cout << -1 << "\n";
                continue;
            }
        }
        else if (a > b)
        {
            if (a > n / 2 + 1 || b < n / 2)
            {
                cout << -1 << "\n";
                continue;
            }
        }

        for (int i{1}; i <= n; ++i)
        {
            if ((i < a || i == b) && end.size() < n / 2)
                end.push(i);
            else if ((i > b || i == a) && front.size() < n / 2)
                front.push(i);
            else
                wait.push(i);
        }
        while (!wait.empty())
        {
            int mmm = wait.front();
            wait.pop();
            if (mmm < b && end.size() < n / 2)
                end.push(mmm);
            else if (mmm > a && front.size() < n / 2)
                front.push(mmm);
            else
                check.push(mmm);
        }

        if (!check.empty())
            cout << -1;
        else
        {
            while (!front.empty())
            {
                cout << front.front() << " ";
                front.pop();
            }
            while (!end.empty())
            {
                cout << end.front() << " ";
                end.pop();
            }
        }
        cout << "\n";
    }
}
