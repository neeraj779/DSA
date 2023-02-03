#include <iostream>
#include <cmath>
using namespace std;

bool isPrime(int n)
{
    if (n <= 1)
        return false;
    // Check if n is divisible by any number from 2 to sqrt(n)
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
            return false;
    }
    // If n is not divisible by any number from 2 to sqrt(n), it is a prime number
    return true;
}

bool isPrime2(int n)
{
    if (n <= 1)
        return false;
    else if (n <= 3)
        return true;
    else if (n % 2 == 0 || n % 3 == 0)
        return false;
    // Check if n is divisible by any number of the form 6n ± 1, starting from 5 and ending at sqrt(n) since all prime numbers are of the form 6n ± 1 except 2 and 3 which are already checked above
    for (int i = 5; i <= sqrt(n); i += 6)
    {
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    }
    // If n is not divisible by any number of the form 6n ± 1, it is a prime number
    return true;
}

int main()
{
    int n;
    cin >> n;
    cout << isPrime(n) << endl;
    cout << isPrime2(n) << endl;
    return 0;
}