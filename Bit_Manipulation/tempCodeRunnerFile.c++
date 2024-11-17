//clear the mth bit
    //using xor
    cout<<"\nclear the mth bits = "<<(n^(1<<m));
    //using and and not
    cout<<"\nclear the mth bits = "<<(n&~(1<<m));