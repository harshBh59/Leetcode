class Solution {
public:
    int minMoves(vector<string>& a, int e) {
       int m=a.size(),n=a[0].size();
        vector<vector<int>> id(m,vector<int>(n,-1));
        int x=0,y=0,k=0;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(a[i][j]=='S'){
                    x=i;
                    y=j;
                }else if(a[i][j]=='L'){
                    id[i][j]=k++;
                }
            }
        }

        if(k==0)return 0;

        int z=1<<k;
        vector<vector<vector<vector<bool>>>> v(
            m,vector<vector<vector<bool>>>(
                n,vector<vector<bool>>(
                    e+1,vector<bool>(z,false)
                )
            )
        );

        queue<tuple<int,int,int,int>> q;
        q.push({x,y,e,z-1});
        v[x][y][e][z-1]=true;

        int d[5]={-1,0,1,0,-1};
        int ans=0;

        while(!q.empty()){
            int sz=q.size();

            while(sz--){
                auto [r,c,en,mask]=q.front();
                q.pop();

                if(mask==0)return ans;
                if(en==0)continue;

                for(int i=0;i<4;i++){
                    int nr=r+d[i],nc=c+d[i+1];

                    if(nr<0||nr>=m||nc<0||nc>=n||a[nr][nc]=='X')
                        continue;

                    int ne=en-1,nm=mask;

                    if(a[nr][nc]=='R')
                        ne=e;

                    if(a[nr][nc]=='L')
                        nm&=~(1<<id[nr][nc]);

                    if(!v[nr][nc][ne][nm]){
                        v[nr][nc][ne][nm]=true;
                        q.push({nr,nc,ne,nm});
                    }
                }
            }

            ans++;
        }

        return -1;
     
    }
};