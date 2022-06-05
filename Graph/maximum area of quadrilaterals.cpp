ll MXN_quadrilaterals(){
    int size=hull.size();

    ll ans=0;
    int t;
    int tt;
   for(int i=0;i<size;i++){
        t=(i+1)%size;
        tt=(i+3)%size;
       for(int j=(i+2)%size;j!=i;j=(j+1)%size){//分成兩部分做最大三角形 t在i和j之間(上半部) , tt在j到i之間(下半部)
           
           while(t!=j&&area(hull[i],hull[j],hull[t])<area(hull[i],hull[j],hull[(t+1)%size])){//
               t=(t+1)%size;
           }
            while(tt!=i&&area(hull[i],hull[j],hull[tt])<area(hull[i],hull[j],hull[(tt+1)%size])){
                tt=(tt+1)%size;
            }
            ans=max(ans,area(hull[i],hull[j],hull[t])+area(hull[i],hull[j],hull[tt]));
       }
   }
    return ans ;
}
