#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
// mp2模擬操作後的版面
int mp1[55][55] = {}; // original
int mp2[55][55] = {}; // updated
int num[100] = {0};
int r, c, n, R, C;
// R C更新後的行列數量
void init()
{
  int t = 1;
  for (int i = 1; i <= r; i++)
  {
    for (int j = 1; j <= c; j++)
    {
      mp1[i][j] = mp2[i][j] = t++;
    }
  }
  return;
}
void DR()
{
  int total = 0;
  cin >> total;
  for (int i = 0; i < total; i++)
  {
    cin >> num[i];
  }
  sort(num, num + total, greater<int>());
  for (int i = 0; i < total; i++)
  {
    for (int j = num[i]; j <= R; j++)
    {
      for (int k = 1; k <= C; k++)
      {
        mp2[j][k] = mp2[j + 1][k];
      }
    }
  }
  R -= total;
}
void DC()
{
  int total = 0;
  cin >> total;
  for (int i = 0; i < total; i++)
  {
    cin >> num[i];
  }
  sort(num, num + total, greater<int>());
  for (int i = 0; i < total; i++)
  {
    for (int j = num[i]; j <= C; j++)
    {
      for (int k = 1; k <= R; k++)
      {
        mp2[k][j] = mp2[k][j + 1];
      }
    }
  }
  C -= total;
}
void IR()
{
  int total = 0;
  cin >> total;
  for (int i = 0; i < total; i++)
  {
    cin >> num[i];
  }
  sort(num, num + total, greater<int>());
  for (int i = 0; i < total; i++)
  {
    for (int j = R + 1; j > num[i]; j--)
    {
      for (int k = 1; k <= C; k++)
      {
        mp2[j][k] = mp2[j - 1][k];
      }
    }
    for (int j = 1; j <= C; j++)
    {
      mp2[num[i]][j] = 0;
    }
    R++;
  }
}
void IC()
{
  int total = 0;
  cin >> total;
  for (int i = 0; i < total; i++)
  {
    cin >> num[i];
  }
  sort(num, num + total, greater<int>());
  for (int i = 0; i < total; i++)
  {
    for (int j = C + 1; j > num[i]; j--)
    {
      for (int k = 1; k <= R; k++)
      {
        mp2[k][j] = mp2[k][j - 1];
      }
    }
    for (int j = 1; j <= R; j++)
    {
      mp2[j][num[i]] = 0;
    }
    C++;
  }
}
void solve()
{
  string cmd;
  cin >> cmd;
  if (cmd == "EX")
  {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    swap(mp2[a][b], mp2[c][d]);
    return;
  }

  if (cmd == "DR")
    DR();
  else if (cmd == "DC")
    DC();
  else if (cmd == "IR")
    IR();
  else
    IC();

  return;
}
void _find()
{
  int a, b;
  cin >> a >> b;
  for (int i = 1; i <= R; i++)
  {
    for (int j = 1; j <= C; j++)
    {
      if (mp1[a][b] == mp2[i][j])
      {
        printf("Cell data in (%d,%d) moved to (%d,%d)\n",a,b,i,j);
        return;
      }
    }
  }
    printf("Cell data in (%d,%d) GONE\n",a,b);
}
int main()
{
  int cnt = 1;
  bool flag = false;
  while (cin >> r >> c)
  {
    if (!r && !c)
      break;
    if (flag)
      cout << '\n';
    flag = true;
    R = r, C = c;
    init();
    cin >> n;
    for (int i = 0; i < n; i++)
    {
      solve();
    }
    int q;
    cin >> q;
    printf("Spreadsheet #%d\n", cnt++);
    while (q--)
    {
      _find();
    }
  }
  return 0;
}
