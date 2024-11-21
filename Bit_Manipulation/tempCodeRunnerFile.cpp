int divide_the_two_number(int dividend,int divisor){
    if(dividend==divisor) return 1;
    bool sign = true;
    if(dividend>=0 && divisor<0) sign = false;
    else if(dividend<0 && divisor>0) sign = false;
    int n = abs(dividend);
    int d = abs(divisor);
    divisor = abs(divisor);
    int q = 0;
    while(n>=d){
        int cnt = 0;
        while(n>=(d*pow(2,cnt))){
            cnt++;
        }
        q+=pow(2,cnt);
        n-=pow(2,cnt)*d;
    }
    if(q==pow(2,31) && sign) return INT_MAX;
    if(q==pow(2,31) && !sign) return INT_MIN;
    return sign?q:-q;
}