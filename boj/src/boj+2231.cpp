#include <iostream>
#include <string>
#define INF 987654321 
using namespace std;

int n;

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

  bool hasAnswer = false;

  string str = to_string(n);
  int length = str.size();

  int minimum = INF;

  for(int i = 1 ; i<=n;++i){
    int pSum = partitionSum(i)+i;
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