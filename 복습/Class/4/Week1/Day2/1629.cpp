#include <iostream>

using namespace std;

typedef long long int_64;

int_64 solve(int_64 a, int_64 b, int_64 c)
{
    if(b == 1){
        return a % c;
    }
    else if(b == 2){
        return a * a % c;
    }
    else{
        int_64 half = solve(a,b/2,c) % c;
        if(b % 2 == 0){ // 짝수일 경우
            return half * half % c;
        }
        else{ // 홀수일 경우
            return (half * half) % c * solve(a,1,c) % c;
        }
    }
}

int main(void)
{
    int_64 a, b, c;
    cin >> a >> b >> c;
    cout << solve(a,b,c) << '\n';
    return 0;
}