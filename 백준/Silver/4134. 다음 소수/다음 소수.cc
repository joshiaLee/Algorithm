#include <bits/stdc++.h>
using namespace std;


int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;
  
  while (t--)
  {
    long long n;
    cin >> n;
    int flag=0;

    if(n ==0 || n == 1 || n == 2) cout << 2 << '\n';
    else if(n == 3) cout << 3 << '\n';
    else{
      while(true)
      {
        flag = 0;
        for(long long i=2; i*i <= n; i++){
          if(n % i == 0){
            flag=1;
            break;
          }
        }
        if(flag == 0) break;
        n++;
      } 

      cout << n << '\n';    

    }
  } 


}