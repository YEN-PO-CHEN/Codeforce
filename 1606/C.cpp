// C - Long Sequence
#include <iostream>
using namespace std;
int main()
{
    long long N, X, All = 0, carry, count = 0;
    cin >> N;
    long long *A = new long long[N];
    for (int i = 0; i < N; ++i)
    {
        cin >> A[i];
        All += A[i];
    }
    cin >> X;
    carry = X / All;
    X = X % All;
    while (X >= 0)
    {
        X -= A[count % N];
        ++count;
    }
    cout << count + N * carry;
    delete[] A;
    return 0;
}