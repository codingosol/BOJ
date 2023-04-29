#include <iostream>

using namespace std;

typedef long long int_64;

int_64 fast_mult(int_64 num, int_64 power, int_64 quotient)
{
    // num ^ power은 num ^ (power / 2) * num ^ (power / 2)로 나타낼 수 있음
    if(power == 1) 
    {
        return num % quotient;
    }
    int_64 half = fast_mult(num, power/2, quotient) % quotient;
    if(power % 2 == 0)
    {
        return half * half % quotient;
    }
    else {
        return half % quotient * half % quotient * num % quotient;
    }
}


int main(void)
{
    int_64 num, power, quotient;
    cin >> num >> power >> quotient;
    cout << fast_mult(num,power,quotient) << '\n';
}