#include <iostream>

using namespace std;

int gcd(int a, int b)
{
	while(b != 0){
		int r = a%b;
		a= b;
		b= r;
	}
	return a;
}

int lcm(int a, int b){
    return a * b / gcd(a,b);
}

int main(void)
{
    int testcase;
    cin >> testcase;
    int m,n,x,y;
    for(int i = 0; i < testcase; i++)
    {
        cin >> m >> n >> x >> y; // m:n이 달력의 마지막 해일때 x:y는 몇 번째 해인지 구하시오
        int cnt = 1; // 몇 번째 해인지 판별
        // 단순 곱으로 생각할 수는 없음
        int curx = 1; 
        int cury = 1;
        // 뒷 수를 먼저 찾고 앞 수가 x와 일치할 때까지 n만큼 더해가면서 찾기
        while(cury != y)
        {
            curx++;
            if(curx == m + 1)
            {
                curx = 1;
            }
            cury++;
            cnt++;
        } // 뒷 수를 맞췄으면 이제 curx = x가 될 때까지 y만큼 더함
        // cout << curx << ' ' << cury << '\n';
        while(true) // 최대로 살펴볼 수 있는 횟수는 최소공배수만큼
        {
            if(curx == x && cury == y)
            {
                cout << cnt << '\n';
                break;
            }
            else{
                curx = (curx + n - 1) % m + 1;
                cnt += n;
                if(cnt > lcm(m,n))
                {
                    cout << "-1\n";
                    break;
                }
                // cout << curx << ' ' << cury << '\n';
            }
        }
    }
    return 0;
}