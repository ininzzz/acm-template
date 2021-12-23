/*

// 求解形如线性方程组，前n项为系数ai，第n+1项为常数b
// eq[i][j]：第i个方程第j项的系数
// 时间复杂度O(n^3)

double eq[105][105];
void Gauss(){
    int n;cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n+1;j++){
            cin>>eq[i][j];
        }
    }
    for(int i=1;i<=n;i++){
        int mx=i;
        for(int j=i+1;j<=n;j++){
            if(fabs(eq[j][i])>fabs(eq[mx][i])) mx=j;
        }
        for(int j=1;j<=n+1;j++) swap(eq[i][j],eq[mx][j]);
        if(!eq[i][i]){
            puts("No Solution");
            return;
        }
        for(int j=1;j<=n;j++){
            if(j==i) continue;
            double temp=eq[j][i]/eq[i][i];
            for(int k=i+1;k<=n+1;k++){
                eq[j][k]-=eq[i][k]*temp;
            }
        }
    }
    for(int i=1;i<=n;i++){
        cout<<fixed<<setprecision(2)<<eq[i][n+1]/eq[i][i]<<endl;
    }
}

*/