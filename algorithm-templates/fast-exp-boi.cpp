long long fast_exp(long long base, long long exp, long long mod, long long tot = 1) {
    for(;exp > 0; exp >>= 1, base = base * base % mod) if((exp & 1) == 1) tot = tot * base % mod;
    return tot;
}