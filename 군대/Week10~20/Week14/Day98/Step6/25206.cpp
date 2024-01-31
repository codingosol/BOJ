#include <iostream>

using namespace std;

int main(void)
{
    fixed(cout);
    cout.precision(6);
    string c, s; // 과목명, 점수
    double n; // 학점
    double total = 0; // 학점 * 점수 저장
    double average = 0; // 평균
    double sum = 0; // 총 학점 저장
    for(int i = 0; i < 20; i++)
    {
        cin >> c >> n >> s;
        if(s == "P")
            continue;
        double ps;
        if(s == "A+")
            ps = 4.5;
        else if(s == "A0")
            ps = 4.0;
        else if(s == "B+")
            ps = 3.5;
        else if(s == "B0")
            ps = 3.0;
        else if(s == "C+")
            ps = 2.5;
        else if(s == "C0")
            ps = 2.0;
        else if(s == "D+")
            ps = 1.5;
        else if(s == "D0")
            ps = 1.0;
        else if(s == "F")
            ps = 0.0;
        sum += n; // 총 학점 저장
        total += n * ps;
    }
    if(sum == 0)
        cout << "0.000000\n";
    else
    {
        average = total / (sum);
        cout << average << '\n';
    }
    return 0;
}