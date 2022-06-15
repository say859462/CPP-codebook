#include <iostream>
#include <vector>
#include <cstring>
#include <cstdio>
#include <iomanip>
using namespace std;
int main()
{
  cin.tie(0);
  cout.tie(0);
  ios::sync_with_stdio(0);
  int r, c;
  int t = 1;
  while (cin >> r)
  {
    if (r == 0)
      return 0;

    cin >> c;
    vector<vector<char>> mp(r + 1, vector<char>(c + 1, 0));
    int num[15][15] = {0};
    int cnt = 1;
    for (int i = 0; i < r; i++)
    {
      for (int j = 0; j < c; j++)
      {
        cin >> mp[i][j];
        if (mp[i][j] == '*')
          continue;
        if (!i || !j || mp[i - 1][j] == '*' || mp[i][j - 1] == '*')
          num[i][j] = cnt++;
      }
    }
    if(t-1)cout<<'\n';
    cout << "puzzle #" << t++ << ":" << '\n';
    bool vis[15][15][2] = {0};
    cout << "Across" << '\n';
    for (int i = 0; i < r; i++)
    {
      for (int j = 0; j < c; j++)
      {
        if (mp[i][j] == '*')
          continue;
        if (num[i][j] && !vis[i][j][0])
        {
          cout<<setw(3)<<num[i][j]<<".";
          for (int k = j; k < c; k++)
          {
            if (mp[i][k] == '*')
              break;
            cout << mp[i][k];
            vis[i][k][0] = 1;
          }
          cout << '\n';
        }
      }
    }
    cout << "Down" << '\n';

    for (int i = 0; i < r; i++)
    { 
      for (int j = 0; j < c; j++)
      {
        if(mp[i][j]=='*')continue;
        if(num[i][j]&&!vis[i][j][1]){
          cout<<setw(3)<<num[i][j]<<".";
          for(int k=i;k<r;k++){
            if(mp[k][j]=='*')break;
            cout<<mp[k][j];
            vis[k][j][1]=1;
          }
          cout<<'\n';
        }
      }
    }
  }
  return 0;
}
