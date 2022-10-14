string mul(string a, string b)
{
    int carry = 0;
    int sum = 0;
    reverse(ALL(a));
    reverse(ALL(b));
    vector<string> rec;
    for (int i = 0; i < SZ(a); i++)
    {
        string tmp;
        for (int j = 0; j < SZ(b); j++)
        {
            sum = (a[i] - '0') * (b[j] - '0') + carry;
            carry = sum / 10;
            sum %= 10;
            tmp.PB(char('0' + sum));
        }
        while (carry)
        {
            tmp.PB(char('0' + carry % 10));
            carry /= 10;
        }
        reverse(ALL(tmp));
        rec.PB(tmp);
    }
    string now = rec[0];
    for (int i = 1; i < SZ(rec); i++)
    {
        for (int j = 0; j < i; j++)
        {
            rec[i].PB('0');
        }
        now = add(now, rec[i]);
    }
    return now;
}
string add(string c, string d)
{

    int carry = 0;
    int sum = 0;
    string ans;
    reverse(ALL(c));
    reverse(ALL(d));
    for (int i = 0; i < min(SZ(c), SZ(d)); i++) //能對應數字進行相加
    {
        sum = c[i] + d[i] - 2 * '0' + carry;
        carry = (sum) / 10;
        sum %= 10;
        ans.PB(char(sum + '0'));
    }
    if (SZ(c) >= SZ(d)) //若有數字較長 則將其補足 (需加上由前面產生的進位)
    {
        for (int i = SZ(d); i < SZ(c); i++)
        {
            sum = c[i] + carry - '0';
            carry = sum / 10;
            sum %= 10;
            ans.PB(char(sum + '0'));
        }
    }
    else
    {
        for (int i = SZ(c); i < SZ(d); i++)
        {
            sum = d[i] + carry - '0';
            carry = sum / 10;
            sum %= 10;
            ans.PB(char(sum + '0'));
        }
    }
    while (carry) //考慮產生新的位數
    {
        ans.PB(char(carry % 10 + '0'));
        carry /= 10;
    }
    reverse(ALL(ans));
    return ans;
}
