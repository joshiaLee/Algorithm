#include <bits/stdc++.h>
using namespace std;


int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  int a,b,c,d,e,f;
  cin >> a >> b >> c >> d >> e >> f;

  int x = ((e*c) - (b*f)) / (a*e - b*d);
  int y = ((a*f) - (d*c)) / (a*e - b*d);

  cout << x << ' ' << y << '\n';

}