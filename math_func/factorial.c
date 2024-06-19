unsigned long factorial(int num) {
    register int k = num;
    if(!k) return 1;
    register unsigned long res = k;
    while(--k) res *= k;
    return res;
}