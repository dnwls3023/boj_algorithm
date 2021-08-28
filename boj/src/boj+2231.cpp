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
  cin>>n;
  string str = to_string(n);
  int length = str.size();

  int minimum = INF;

  for(int i = 1 ; i<=n;++i){
    if()
    minimum = min(minimum, partitionSum(i)+i);
  }

  int answer = minimum;

  cout<< answer <<endl;

  return 0;
}