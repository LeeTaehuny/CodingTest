/** 
[ 링크 ] https://school.programmers.co.kr/learn/courses/30/lessons/135808

[ 풀이 방법 ]

1. 낮은 순으로 과일을 정렬합니다.
2. 뒤에서부터 m개씩 건너뛰며 m번째 과일의 값 * m을 answer에 저장합니다.
*/

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int k, int m, vector<int> score) {
    int answer = 0;

    sort(score.begin(), score.end());

    for (auto it = score.end() - m; it >= score.begin(); it -= m)
    {
        answer += *it * m;
    }

    return answer;
}
