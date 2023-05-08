#include <iostream>
#include <cmath>

using namespace std;

int main(void)
{
    // x1, y1, x2, y2와 거리 r1,r2를 받아 있을수 있는 점의 수를 구하면 된다
    // 이 문제는 x1^2 + y1^2 = r1^2 의 원과 x2^2 + y2^2 = r2^2의 원의 교점의 개수를 구하면 되는 문제이다
    int testcase;
    cin >> testcase;
    while(testcase--)
    {
        int x1, y1, x2, y2, r1, r2;
        cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
        // input;
        // 조건문을 잘 짜야함
        // 교점의 개수를 구하려면...?
        // 거리 변수를 이용해 각 원의 중심 간의 거리를 구한 뒤 반지름의 합보다 크다면 교점 2개, 같다면 교점 1개, 작다면 교점 0개
        // 이때 두 원이 일치한다면 교점의 개수는 무한대임
        // 바로 가보자
        if(x1 == x2 && y1 == y2) // 두 원의 원점이 일치할 경우
        {
            if(r1 == r2 && r1 != 0) // 원이면서 반지름이 일치하고 점이 아닐 때
                cout << "-1\n";
            else if(r1 == r2 && r1 == 0) // 점일 경우
            {
                cout << "1\n";
            }
            else if(r1 != r2) // 일치하지 않는 원일 때
            {
                cout << "0\n";
            }
        }
        else {
            double dist = 0;
            //cout << '\n';
            // ex) 0,0 5 0,1 1
            dist = sqrt(pow(abs(x1-x2),2) + pow(abs(y1-y2),2));
            //cout << "distance is : " << dist << '\n';
            if(abs(r1-r2) < dist && dist < r1 + r2) // 거리가 반지름의 합보다 작으므로 두 점에서 만남
            {
                cout << "2\n";
            }
            else if(dist == r1 + r2 || abs(r1-r2) == dist) // 거리가 반지름의 합과 같으므로 한 점에서 만남
            {
                cout << "1\n";
            }
            else // 거리가 반지름의 합보다 커서 만나지 않음
            {
                cout << "0\n";
            }
        }

    }
    return 0;
}
