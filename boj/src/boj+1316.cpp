#include <iostream>
#include <string>
#include <cstring> // memset
using namespace std;

// 그룹단어이면 1을 반환하고 아니면 0을 반환
int solve(string s){
  // 본적이 있는 알파뱃인가?
  bool alpha[27];
  memset(alpha,false,sizeof(alpha));
  int length = s.size();

  for(int i = 0 ; i<length;){
    // 처음 보는 단어가 아니라면
    if(alpha[s[i]-'a']){
      return 0;
    }
    else{
      int idx = 1;
      alpha[s[i]-'a']=true;
      // 이전 알파벳과 같은 단어인동안
      // 애먹은 부분 : (s[i]-'a') == (s[idx]-'a') 이렇게 해서 상당히 해맴
      while((s[i]-'a') == (s[idx+i]-'a')){
        idx++;
      }
      i+=idx;
    }

  }
  // 다 돌아도 처음 보는 단어이면 1을 반환합니다.
  return 1;
} 

int main(void){
  int n;
  cin>>n;
  
  string str;
  int answer = 0;
  for(int i = 0; i<n;++i){
    cin>>str;
    answer+=solve(str);
  }
  cout<<answer<<endl;
  return 0;
}