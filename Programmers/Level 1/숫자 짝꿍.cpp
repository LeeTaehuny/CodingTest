/** 
[ 링크 ] https://school.programmers.co.kr/learn/courses/30/lessons/131128 

[ 풀이 방법 ]

1. X와 Y 문자열을 map에 <char, int> 형식으로 각각 저장하며 카운트를 증가시켜줍니다. (X -> m / Y -> m2)
2. m과 m2중 크기가 사이즈가 작은 것을 기준으로 더 작은 second 만큼 해당 문자를 answer에 추가합니다.
  (생각해보면 0 ~ 9 까지의 많아야 9개의 정보가 들어갈텐데.. 굳이 map의 사이즈 비교를 안했어도 괜찮았을 듯)

3. 완성된 answer의 상태에 따라 값을 수정합니다.
	-> answer의 크기 0 -> answer = "-1"
	-> answer의 크기 1 이상 -> reverse() 함수를 이용해 문자열 뒤집기 (map을 만들 때 큰 순서대로 정렬했으면 좋았을 듯)
	   -> 첫 문자가 0이라면? -> answer = "0" (중복 0 제거) 
*/

#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

string solution(string X, string Y) {
    string answer = "";

    map<char, int> m;
    for (int i = 0; i < X.size(); i++)
    {
        if (m.find(X[i]) == m.end())
        {
            m.insert(make_pair(X[i], 1));
        }
        else
        {
            m[X[i]]++;
        }
    }

    map<char, int> m2;
    for (int i = 0; i < Y.size(); i++)
    {
        if (m2.find(Y[i]) == m2.end())
        {
            m2.insert(make_pair(Y[i], 1));
        }
        else
        {
            m2[Y[i]]++;
        }
    }

    if (m2.size() > m.size())
    {
        for (auto it : m)
        {
            if (m2.find(it.first) != m2.end())
            {
                int idx = min(m2[it.first], it.second);
                while (idx--)
                {
                    answer += it.first;
                }
            }
        }
    }
    else
    {
        for (auto it : m2)
        {
            if (m.find(it.first) != m.end())
            {
                int idx = min(m[it.first], it.second);
                while (idx--)
                {
                    answer += it.first;
                }
            }
        }
    }

    if (answer.empty())
    {
        answer = "-1";
    }
    else
    {
        reverse(answer.begin(), answer.end());

        if (answer[0] == '0')
        {
            answer = "0";
        }
    }

    return answer;
}
