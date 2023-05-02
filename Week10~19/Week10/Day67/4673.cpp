#include <iostream>

using namespace std;

int selfnum[10001];

int main(void)
{
    // 10000보다 작거나 같은 셀프넘버 전부 출력
    for(int i = 1; i < 10001; i++)
    {
        int curnum = i;
        int next = 0;
        next += curnum; // 원본 숫자 더함
        int n = 0;
        // 원본 숫자와 자릿수를 모두 더해서 새로운 수를 만듬
        while(curnum > 0)
        {
            n += curnum % 10;
            curnum /= 10;
        }
        next += n;
        selfnum[next]++; 
    }
    for(int i = 1; i <= 10000; i++)
    {
        if(selfnum[i] == 0) // 셀프넘버라면
        {
            cout << i << '\n';
        }
    }
    return 0;
}