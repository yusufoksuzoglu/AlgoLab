int uniquePaths(int m, int n) {
    int c;
    long long z=1;
    c=m+n-2;
    if(m<1||n>100) return -1;
    int i;
    for (int i = 1; i <= m-1;i++){
        z *= c - (m-1) + i;;
        z /= i;
    }
    return z;
}
