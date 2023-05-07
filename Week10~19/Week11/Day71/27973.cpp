#include <iostream>

using namespace std;
typedef long long int_64;

/*  0 x: $S$의 모든 원소에 x를 더한다. $(-100 \, 000 \leq$ x $\leq 100 \, 000)$ 
    1 x: $S$의 모든 원소에 x를 곱한다. $(1 \leq$ x $\leq 100)$ 
    2 n: $S$에서 작은 원소부터 차례대로 n개를 제거한다. $(1 \leq$ n $\leq 100 \, 000 \, 000)$ 
    3: $S$에서 가장 작은 원소를 출력한다.*/

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // 0 ~ 1234567890123의 정수가 들어 있음
    // 사실 모든 원소에 x를 더하고 곱하게 되면 무조건 메모리, 시간초과가 나게 됨
    // 양수/음수를 더하거나 빼는 문제는 배열의 순서에 영향을 미치지 않음
    // 양수를 곱하는 연산 역시도 순서에 영향을 끼치지 않음
    // 이를 기억하며 풀어보자
    int_64 front = 1;
    int n;
    cin >> n;
    int oper;
    int_64 opernum;
    int mult = 1;
    while(n--)
    {
        cin >> oper;
        if(oper == 0) // 모든 원소에게 덧셈이나 뺄셈 
        {
            cin >> opernum;
            front += opernum;
        }
        else if(oper == 1) // 모든 원소에게 곱셈
        {
            cin >> opernum;
            front *= opernum;
            mult *= opernum;
        }
        else if(oper == 2) // 작은 원소부터 n개 제거
        {   
            cin >> opernum;
            front += opernum * mult;
        }
        else if(oper == 3) // 가장 작은 원소 출력
        {
            cout << front << '\n';
        }
    }
    return 0;
}