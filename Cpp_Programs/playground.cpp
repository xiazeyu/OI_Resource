bool IsPrime[1000010];
int Prim[1000010];
int  euler_prime(int n){
    int num = 0, j;
    for(int i = 2; i <= n; i ++){
        if(!IsPrime[i])
            Prim[num ++] = i;
        for(j  = 0; j < num; j ++){
            if(i * Prim[j] > n)
                break;
            IsPrime[i * Prim[j]] = true;
            if(i % Prim[j] == 0)
                break;
        }
    }
    //for(int i = 0; i < num; i ++){
    //    cout << Prim[i] << endl;
    //}
}
