### 연구소 [구현, 그래프이론, 브루트포스 알고리즘, 그래프탐색, 너비우선탐색]
---
https://www.acmicpc.net/problem/14502

[문제 풀이] 
- 위 문제는 연구소에 랜덤한 벽 3개를 세워 해당 벽의 위치별로 가장 안전 영역이 많을 때의 수를 구하는 문제입니다.
- 입력을 받으며 벽이 세워질 수 있는 장소(좌표)를 vector<pair<int, int>>에 저장하고, 해당 벡터 컨테이너를 이용해 3개의 벽을 세우고, DFS로 바이러스가 퍼질 때마다 숫자를 세어 전체 크기에서 벽의 수, 바이러스의 수를 제외한 것 중 가장 큰 값을 출력하는 방식으로 문제를 해결했습니다.