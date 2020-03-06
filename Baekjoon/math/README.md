
## 이번에 푼 문제와 관련해 시간초과 줄이는 법
1. cin cout이 scanf printf보다 더 오래걸린다고 한다. 지금까지 cin cout이 간단해서 계속 써왔는데 오늘 처음 안 사실이다.
2. 당연히 이중, 삼중 루프는 피하는게 맞는 법!
3. 소수와 관련된 문제를 두 문제 정도 풀었다. 두 문제중 비교적 간단한 문제는 소수인지 하나하나 판별하는 방식을 사용하였다. 매 회차마다 그렇게 했기 떄문에 시간초과가 걱정되었지만 생각보다 시간이 얼마 안걸려 걱정안해도 되는 줄 알았다...
하지만! 문제는 제일 시간을 많이 잡아먹은 6588번 골드바흐의 추측이다. 혼자서 같은 방법을 사용하여 소수도 찾고 열심히 다 짰는데 시간초과... 심지어 거의 두배정도 시간초과가 나는 듯 했다. 인터넷 검색을 통하여 결국 에라토스테네스의 체 방법을 사용하기로 하였다.
물론 그 이후로 틀렸다고 떠서 한 부분을 수정해 결국 맞긴 했으나 내 생각으로는 바꾸는게 불필요해보였는데 이상할 따름이다.

## 알아야 할 팁&헷갈리는 문법
1. 최대공약수, 최소공배수가 나오는 문제는 유클리드 호제법을 적극 활용할 것!
ex) (24, 18)->(18, 6)
2. 소수 찾기 문제는 에라토스테네스의 체를 사용하는 쪽이 훨씬 빠르고 편리함!
3. sqrt등을 사용할때 불러오는 라이브러리는 math가 아니라 cmath! 틀리고 구글링하지 말고 기억해둘 것