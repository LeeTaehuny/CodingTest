### 좋은 단어 [자료구조, 스택] (다시 풀어보기)
---
https://www.acmicpc.net/problem/3986

[문제 풀이] 

- 스택을 이용해야 합니다.

- N개의 문자열을 입력받아 배열에 저장합니다.
- 각 문자열을 스택에 하나씩 넣으며 스택의 가장 위(top)와 비교합니다.
- 세부 로직은 다음과 같습니다.
1. 스택이 비어있다면 push
2. 스택의 top과 들어오는 문자가 같은 경우라면 pop
3. 스택의 top과 들어오는 문자가 다른 경우라면 push

- 전체 과정이 끝난 후 스택이 비어있으면 cnt를 1 증가시키고, 다음 문자열로 넘어갑니다.

[추가 사항]

- 문제에서 짝 짓기 or 폭발 -> 스택 생각하기

- 문제에서 이해가 잘 안된다면 그림으로 그릴 생각을 해야 합니다.
- 즉, 90도 회전, 뒤집어보기, 하나를 추가로 붙여보기 등등 시도를 해봐야 합니다.

- 여기서는 들어오는 값이 가장 뒤의 값과 같으면 삭제하는 로직이 필요하다는 생각을 할 수 있습니다.
- 즉, 가장 뒷 부분을 참조할 수 있는 자료구조는 Stack입니다.

- Queue : 가장 앞만 참조
- Stack : 가장 뒤만 참조

[주의 사항]

- Stack이나 Queue와 같은 자료구조의 맨 뒤 / 앞을 꺼낼 때는 사이즈를 체크해야 합니다.

- 즉, 없는 경우 참조 에러가 발생하므로 다음과 같은 형식으로 사이즈 체크가 필요합니다.
if (stk.size() && stk.top() == a) { // 로직; }