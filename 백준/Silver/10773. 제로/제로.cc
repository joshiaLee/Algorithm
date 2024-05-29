#include <bits/stdc++.h>
using namespace std;

int s[100001];
int pos;


int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, z;
  long long sum=0;
  cin >> n;

  for (int i=0; i<n; i++){
    cin >> z;
    if(z){
      s[pos] = z;
      pos++;
    }

    else{
      pos--;
    }
  }

  for (int i=0; i<pos; i++){
    sum += s[i];
  }

  cout << sum;
}