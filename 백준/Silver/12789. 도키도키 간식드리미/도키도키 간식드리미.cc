#include <bits/stdc++.h>
using namespace std;

queue<int> q;
stack<int> st;

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  
  for(int i=0; i<n; i++){
    int a;
    cin >> a;
    q.push(a);
  }

  int order = 1;
  st.push(0);

  while (true)
  {

    if(q.empty()){
      if(order != st.top()){
        if(st.top() != 0){
          cout << "Sad" << '\n';
          break;
        }

        else{
          cout << "Nice" << '\n';
          break;
        }
      }

      else{
        st.pop();
        order++;
      }
    }

    else if(!q.empty() && order == q.front()){
      q.pop();
      order++;
    }

    else if(order == st.top()){
      st.pop();
      order++;
    }

    // 다 아닐땐 q -> st로 옮기기
    else{
      st.push(q.front());
      q.pop();
    }
    
  }
  

  
}