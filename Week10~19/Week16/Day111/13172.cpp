#include <iostream>
#include <vector>

using namespace std;

typedef long long int_64;
int_64 MOD = 1000000007;

int_64 gcd(int_64 a, int_64 b)
{
    if(b == 0)
        return a;
    else
        return gcd(b, a % b);
}

int_64 modF(int_64 a, int_64 mod)
{
    // a의 모듈러 역원 a^-1를 리턴함
    // a^-1 * a = 1 mod X 이므로
    // a^X-1 = a mod X 이므로
    // a^X-2 = a ^ -1 mod X임 따라서 
    // a^X-2 mod X를 리턴함
    if(mod == 1)
    {
        return a;
    }
    if(mod % 2 == 1) // 홀수일 경우
    {
        return a * modF(a,mod-1) % MOD;
    }
    else { // 짝수일 경우 
        int_64 p = modF(a,mod/2);
        return p*p%MOD;
    }
}

int main(void)
{
    int num;
    cin >> num;
    int_64 total = 0; // 합계
    int_64 S, N; // S는 분자 N은 분모
    vector<pair<int_64,int_64>> v;
    for(int i = 0; i < num; i++)
    {
        cin >> N >> S;
        // 기약분수 형태로 변환시켜 저장
        int_64 temp = gcd(N,S); // S와 N의 최대공약수를 구해서 둘 다 나눠줌
        N /= temp;
        S /= temp;
        v.push_back({N,S});
    }
    // 입력 됐으므로 이제 모듈러 연산을 해야 함
    for(int i = 0; i < num; i++)
    {
        //  a × b^-1 mod X
        // => a x b^x-2 mod X
        // cout << total << '\n';
        total += v[i].second * modF(v[i].first,MOD-2) % MOD;
        total %= MOD;
    }
    cout << total << '\n';
    return 0;
}