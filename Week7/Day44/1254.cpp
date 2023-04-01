#include <iostream>
using namespace std;
 
string s;
int answer = 0;
 
bool isPalindrom(string str)
{
    int cnt = str.size() / 2; // pivot 선정
    for(int i = 0; i < cnt; i++){
        if(str[i] != str[str.size() - 1 - i]){
            return false;
        }
    }
    return true;
}
 
int main()
{
    cin >> s; // 문자열 입력받음
    answer = s.size() * 2 - 1; // 최대로 생각함(팰린드롬이 어느것도 될 수 없다면 두 배 크기가 되어야 함)
    for(int i = 0; i < s.size(); i++){ // 현재 인덱스 이후부분이 팰린드롬인지 판별
        string temp = s.substr(i, s.size() - i);
        if(isPalindrom(temp)){ // 만약 이후부분이 팰린드롬이라면
            answer = s.size() + i;  // 전의 문자열 길이만큼 추가하면 됨
            break;
        }
    }
 
    cout<< answer <<"\n";
    return 0;
}
