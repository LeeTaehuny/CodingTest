### 사다리 조작 [구현, 브루트포스 알고리즘, 백트래킹]
---
https://www.acmicpc.net/problem/15684

[문제 풀이] 

- 위 문제는 사다리를 배치할 수 있는 공간이 30 * 10 이므로 300C3의 시간복잡도를 가집니다.
- 즉, 완전탐색으로 문제를 해결할 수 있습니다. (+백트래킹)
- 사다리를 배치할 때 a, b 형식으로 배치하기 때문에 이와 맞는 visited[][] 배열을 선언했습니다.
- visited[a][b] = 1, go(a, cnt + 1), visited[a][b] = 0의 방식으로 완탐 및 복구를 수행하며 cnt가 3이 되었을 경우 모든 i번째 위치가 정상적으로 i번째로 도달하는지 체크합니다.
- 성공적으로 완료되었다면 ret에 해당 성공 cnt 값과 기존 ret값 중 작은 값을 저장하고, 다음부터는 cnt가 ret보다 같거나 큰 경우 return 시켜주는 방식으로 문제를 해결했습니다.