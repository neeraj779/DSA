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
    for (int i = 0; i < n; ++i)
    {
        cout << pascalTriangle(n - 1, i) << " ";
    }
    return 0;
}