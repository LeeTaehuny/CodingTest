### 수열 [누적 합, 슬라이딩 윈도우, 두 포인터] (다시 풀어보기)
---
https://www.acmicpc.net/problem/2559

[문제 풀이] 

- 연속적인 날짜의 온도 합을 구하는 문제입니다.
- 누적합을 이용해 문제를 해결했습니다.
- 연속적인 날짜의 수가 K라고 가정했을 때 psum[k] - psum[i - k]의 값이 가장 큰 것을 구해 출력하는 방식으로 해결했습니다.

[추가 사항]
- 이번 문제에서 가장 중요한 것은 최초의 최소값을 설정하는 것입니다.
- 최악의 경우 "-100"도인 날이 10만일 연속 지속되는 경우라면?
- -10,000,000 이 최소값이 됩니다.

- 여기서 -10,000,000으로 설정하지 않고 조금은 여유를 두는 습관을 들이는 것이 좋습니다.