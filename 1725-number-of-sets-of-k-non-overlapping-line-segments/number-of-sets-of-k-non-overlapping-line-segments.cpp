class Solution {
public:
    long long mod=1e9+7;

    long long power(long long a,long long b){
        long long r=1;
        while(b){
            if(b&1) r=r*a%mod;
            a=a*a%mod;
            b>>=1;
        }
        return r;
    }

    int numberOfSets(int n,int k){
        long long ans=1;

        for(int i=1;i<=2*k;i++){
            ans=ans*(n+k-i)%mod;
            ans=ans*power(i,mod-2)%mod;
        }

        return ans;
    }
};