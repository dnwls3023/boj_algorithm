#include <iostream>
#include <algorithm> // sort 함수 사용 위해서 추가
#include <vector> // 값을 넣는 것과 출력하는 것을 효율적으로 하기 위해 vector 사용
#define MAX 26 // 최대값이 25 (인덱스값을 즉각적으로 사용하기 위해서 +1함)
using namespace std;

bool visited[MAX][MAX];
int arr[MAX][MAX];
int n;

// 상하좌우를 좌표계로 구현
int dy[4] = {1,0,-1,0};
int dx[4] = {0,1,0,-1};

// 컴포넌트의 총 개수
int componentCnt;
// 각각의 컴포넌트에 대한 영역의 개수
int eachCnt;

// 깊이 우선 탐색 알고리즘 (DFS)
int dfs(int y,int x){
  // 함수가 호출될 때마다 값을 증가시킴
  eachCnt++;
  visited[y][x] = true;
  // 상하좌우로 탐색
  for(int i = 0 ; i<4;++i){
    int ny = y + dy[i];
    int nx = x + dx[i];

    // 방문하지 않았을 때 범위내에 값이 존재할 때
    if(!visited[ny][nx] && (0<= ny && ny< n && 0<=nx && nx < n)){
      dfs(ny,nx);
    }
  }
}

int main(void){
  vector<int> vec;
  cin>>n;
  for(int i =0 ;i<n;++i){
    for(int j = 0 ;j<n;++j){
      cin>>arr[i][j];
      // 집이 아닌영역은 방문했다고 표시를 해줌으로 써 방문하지 않게 해준다.
      if(arr[i][j] == 1)
        visited[i][j] = true;
    }
  }

  for(int i =0 ;i<n;++i){
    for(int j = 0 ;j<n;++j){
      // 하나씩 찾으면서 방문하지 않았더라면 방문하게끔 만듬
      if(!visited[i][j]){
        // 값을 초기화
        eachCnt = 0;
        componentCnt++;
        dfs(i,j);
        vec.push_back(eachCnt);
      }
    }
  }

  // 오름차순하여 값을 출력해야 하므로 정렬
  sort(vec.begin(),vec.end());
  // endl은 속도가 느리기 때문에 속도가 빠른 "\n"을 사용해주었다.
  cout<<componentCnt<<"\n";
  for(int i = 0 ; i<componentCnt;++i){
    cout<<vec[i]<<"\n";
  }
  return 0;
}