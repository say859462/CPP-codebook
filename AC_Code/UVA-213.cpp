#include <iostream>
#include <cstring>
#include <string>
using namespace std;
char s[8][1 << 8]; // s[i][j] length=i status j's character ，儲存對應的二進位表示所對應的字元
char readchar()
{
    while (1)
    {
        char ch = getchar();
        if (ch != '\n' && ch != '\r')
            return ch;
    }
}
int read()
{

    s[1][0] = readchar();
    if (s[1][0] == -1)
        return 0; // while == EOF return 0
    for (int i = 2; i < 8; i++)
    {
        for (int j = 0; j < (1 << i) - 1; j++)
        {
            char ch = getchar();
         //   cout<<ch<<" ";
            if (ch == '\n' || ch == '\r')
                return 1;
            s[i][j] = ch;
        }
    }
    return 1;

}
int readint(int x)
{
    int rec = 0;
    while (x--)
    //計算編碼長度 first 3 digits
        rec = rec * 2 + readchar() - '0';
    
    return rec;
}
int main()
{
    
    while (read())
    {
        while (1)
        {
            int len = readint(3); //讀取前三個位元 計算編碼長度
            if (len == 0)
                break;
            while (1)
            {
                int v = readint(len); //以長度為len為一組的編碼 查詢其所對應的字元
                if (v == (1 << len) - 1)
                    break; //當編碼全部為1時 break
                putchar(s[len][v]);
            }
        }
        printf("\n");
    }
    return 0;
}
