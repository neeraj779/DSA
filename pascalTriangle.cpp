#include <iostream>
using namespace std;

int pascalTriangle(int n, int r)
{
    int res = 1;
    for (int i = 0; i < r; ++i)
    {
        res *= (n - i);
        res /= (i + 1);
    }
    return res;
}

int main()
{
    int n;
    cin >> n;
    int res = 1;
    cout << res;

    // res * (row - col) / col
    for (int i = 1; i < n; ++i)
    {
        res = res * (n - i);
        res = res / i;
        cout << res << " ";
    }
    return 0;
}