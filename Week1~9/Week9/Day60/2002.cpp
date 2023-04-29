#include <iostream>
#include <map>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    map<string,int> m;
    int num; // 차량의 수
    cin >> num;
    string str;
    int fin[1001];
    int ans = 0;
    for(int i = 0; i < num; i++)
    {
        // 스택처럼 생각해야 함
        // map에 들어간 순번이랑 문자열을 엮어서 넣음
        // 만약에 현재 나온 순번이 아직 나오지 못한 순번의 최솟값보다 높다면 추월
        cin >> str;
        m[str] = i;
    }
    for (int i = 0; i < num; i++) {
		cin >> str;
		int val = m[str]; // 들어간 순번 저장
		fin[i] = val;
	}
	for (int i = 0; i < num - 1; i++) {
		for (int j = i + 1; j < num; j++) {
			if (fin[i] > fin[j]) {
				ans++;
				break;
			}
		}
	}
    cout << ans << '\n';
    return 0;
}