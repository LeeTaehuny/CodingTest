### 부등호 [브루트포스 알고리즘, 백트래킹]
---
https://www.acmicpc.net/problem/2529

[문제 풀이] 

- 위 문제는 2번의 DFS를 통해 쉽게 풀수 있는 문제입니다.
- 먼저 가장 작은 수를 구하기 위해 boolean 변수를 하나 두고 해당 부등호 조건을 만족하는 경우 bool 변수를 true로 만들어 나머지는 연산하지 않도록 설정했습니다.
- 가장 큰 수는 작은수와 반대로 큰 값부터 완전 탐색을 통해 구하고 위와 동일하게 boolean 변수를 활용해 하나가 구해지면 나머지는 무시하도록 문제를 해결하였습니다.