
/*
설명 :

어떤 자연수 N이 있을 때,

그 자연수 N의 "분해합"은  

N과 N을 이루는 각 자리수의 합을 의미한다. ok

 

어떤 자연수 M의 분해합이 N인 경우,

M을 N의 생성자라 한다.

 

예를들어 M이 123이라 하면 1 + 2 + 3 + 123 = 129

가 N이 되고 N은 129가 되어버린다.

123은 129의 생성자

 

문제 : N이 주어지면 N의 가장 작은 생성자를

구해내는 프로그램

 

129를 주어주면 1+2+3+123=129가 성립하는 값

을 구해낸다.

 

해결방법: 생성자가 129보다 커질 수 없으므로

129보다 작은 숫자의 모든 생성자를 찾아낸다.

 

의사 코드 : 

 

for i=1, i<N,i+=1

  minimum=

  min(minimum,i의 각각의 자리를 더하게 하는 알고리즘+i)

각각의 자리를 더하는 알고리즘 
각각의 자리수를 구하고 그것들을 더함
*/

#include <iostream>
#include <string>
#define INF 987654321 
using namespace std;

int n;

// 각각의 자릿수의 합을 구하고 그 값을 반환하는 로직
int partitionSum(int n){
  int ret = 0;
  string s = to_string(n);
  int length = s.size();
  for(int i = 0 ; i< length;++i){
    ret += s[i]-'0';
  }
  return ret;
}

int main(void){
  // 입력을 받고
  cin>>n;

  // 분해합이 존재하는가?
  bool hasAnswer = false;

  string str = to_string(n);
  int length = str.size();

  int minimum = INF;

  // 일일이 분해합을 찾는다.
  for(int i = 1 ; i<=n;++i){
    int pSum = partitionSum(i)+i;
    // 분해합이라면
    if(pSum == n){
      minimum = min(minimum, i);
      hasAnswer = true;
    }
      
  }

  int answer = minimum;
  
  if(!hasAnswer)
    cout<<0<<endl;
  else 
    cout<< answer <<endl;

  return 0;
}