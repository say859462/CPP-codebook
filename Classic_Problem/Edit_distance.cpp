int EditDis(){

  int len1 = strlen(a+1);

  int len2 = strlen(b+1);

//初始化

  for(int i=1;i<=len1;i++)

    for(int j=1;j<=len2;j++)

       dp[i][j] = INF;

  for(int i=1;i<=len1;i++)

    dp[i][0] = i;

  for(int j=1;j<=len2;j++)

    dp[0][j] = j;

for(int i=1;i<=len1;i++){
  for(int j=1;j<=len2;j++){

      int flag;

      if(a[i]==b[j])
        flag=0;
      else
        flag=1;

       dp[i][j]=min(dp[i-1][j]+1,min(dp[i][j-1]+1,dp[i-1][j-1]+flag));

//dp[i-1][j]+1表示删掉字符串a最后一个字符a[i]

//dp[i][j-1]+1表示给字符串添加b最后一个字符

//dp[i-1][j-1]+flag表示改变,相同则不需操作次数,不同则需要,用flag记录
     }
}


  return dp[len1][len2];

}

