#include <vector>
#include <bitset>
#include <iostream>
#include <algorithm>
#include <typeinfo>
#include <cmath>
using namespace std;

bitset<4> decToBin(int n)
{
    bitset<4> binary(n);
    return binary;
}

vector<int> decToBin2(int n)
{
    vector<int> binary;
    while (n > 0)
    {
        binary.push_back(n % 2);
        n /= 2;
    }

    reverse(binary.begin(), binary.end());

    for (int i : binary)
    {
        cout << i;
    }

    cout << endl;
    // array to int
    int result = 0;
    for (int i = 0; i < binary.size(); i++)
    {
        result = result * 10 + binary[i]; // 0*10 = 0, 1*10 = 10 then adding binary[i] to it
    }
    cout << result << typeid(result).name() << endl;
    return binary;
}

void binToDec(vector<int> binary)
{
    int decimal = 0;
    int power = 0;
    for (int i = binary.size() - 1; i >= 0; i--)
    {
        decimal += binary[i] * pow(2, power);
        power++;
    }
    cout << decimal << endl;
}

int binToDec2(int n)
{
    bitset<4> bin(n);
    return (int)bin.to_ulong();
}

int main()
{
    int n = 11;
    cout << decToBin(n) << endl;
    vector<int> bin = decToBin2(n);
    binToDec(bin);
    cout << binToDec2(101);
    return 0;
}