#include <stdio.h>
#include <stdlib.h>
#define ll long long

typedef struct{
    ll col,row,value;
}term;
int compare(ll x,ll y){
    if(x==y)return 0;
    else if(x<y)return -1;
    else return 1;
}
ll n1,m1,n2,m2,x;
int main(){
    while(scanf("%d %d %d %d",&n1,&m1,&n2,&m2)!=EOF){
        if(m1!=n2){
            printf("Error\n");
            continue;
        }
        term a[50005];
        term b[50005];
        a[0].row=n1,a[0].col=m1;
        b[0].row=n2,b[0].col=m2;
        ll num[50005]={0};
        ll starting_pos[50005]={0};
        ll totala=0,totalb=0;
        for(int i=0;i<n1;i++){
            for(int j=0;j<m1;j++){
                scanf("%d",&x);
                if(x!=0){
                    a[0].value++;
                    a[++totala].row=i;
                    a[totala].col=j;
                    a[totala].value=x;
                }
            }
        }
        

        for(int i=0;i<n2;i++){
            for(int j=0;j<m2;j++){
                scanf("%d",&x);
                if(x!=0){
                    b[0].value++;
                    b[++totalb].row=i;
                    b[totalb].col=j;
                    b[totalb].value=x;
                }
            }
        }
        
       // for(int i=1;i<=totala;i++)printf("%d %d %d\n",a[i].row,a[i].col,a[i].value);

        starting_pos[0]=1;
        term bt[50005];
        for(int i=1;i<=totalb;i++)num[b[i].col]++;
        for(int i=1;i<b[0].col;i++){
            starting_pos[i]=starting_pos[i-1]+num[i-1];
        }
        int j,i;
        bt[0].row=b[0].col;
        bt[0].col=b[0].row;
        
        for(int i=1;i<=totalb;i++){
            j=starting_pos[b[i].col]++;
            bt[j].row=b[i].col;
            bt[j].col=b[i].row;
            bt[j].value=b[i].value;
        }
        
        bt[0].value=b[0].value;
        
        ll column, row = a[1].row;
        ll sum=0;
        ll totald = 0;
        ll rowsA = a[0].row, colsB = b[0].col;
        ll row_begin = 1;
        a[a[0].value+1].row=rowsA;
        bt[b[0].value+1].col=colsB;
        bt[b[0].value+1].col=0;

        term ans[50005];
        for(i=1;i<=a[0].value;){
            column=bt[1].row;
            for(j=1;j<=b[0].value+1;){
                if(row!=a[i].row){//超過欲計算row 代表這次的col計算完成，換到下個col，並使當前row回歸
                    if(sum){
                        ans[++totald].value=sum;
                        ans[totald].row=row;
                        ans[totald].col=column;
                        sum=0;
                    }
                    i=row_begin;
                    while(bt[j].row==column)j++;
                    column=bt[j].row;
                }
                else if(column!=bt[j].row){
                    if(sum){
                        ans[++totald].value=sum;
                        ans[totald].row=row;
                        ans[totald].col=column;
                        sum=0;
                    }
                    i=row_begin;
                    column=bt[j].row;
                }
                else switch(compare(a[i].col,bt[j].col)){
                    case -1://若a[i].col<bt[j].col 
                        i++;
                        break;
                    case 0:
                        sum+=(a[i].value * bt[j].value);
                        i++;
                        j++;
                        break;
                    case 1:
                        j++;
                }
            }
            while(a[i].row==row)i++;
            row_begin=i;
            row=a[i].row;
        }
        ans[0].row=rowsA;
        ans[0].col=colsB;
        ans[0].value=totald;
        ll now=1;
        for(int i=0;i<ans[0].row;i++){
            for(int j=0;j<ans[0].col;j++){
                if(i==ans[now].row && j==ans[now].col){
                    printf("%d ",ans[now].value);
                    now++;
                }
                else printf("0 ");
            }
            printf("\n");
        }
    }
    
    return 0;
}
