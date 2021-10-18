class Solution {
int fir[100020], en[200040], nex[200040];
int dis[100020];
int tot;
int dl[100020];
int hd,td;
public:
    void tjb(int x,int y){
        en[++tot] = y;
        nex[tot]=fir[x];
        fir[x] = tot;
    }
    void bfs(int x){
        hd = 0;
        td = 1;
        dl[1] = 0;
        while(hd < td){
            int x = dl[++hd];
            for(int k=fir[x];k;k=nex[k]){
                int j=en[k];
                if(dis[j]==-1){
                    dis[j] = dis[x] + 1;
                    dl[++td] = j;
                }
            }
        }
    }
    int networkBecomesIdle(vector<vector<int>>& edges, vector<int>& patience) {
        int n = patience.size();
        int m = edges.size();
        for(int i=0;i<n;++i){
            fir[i] = 0;
            dis[i] = -1;
        }
        dis[0] = 0;
        tot = 0;
        for(int i=0;i<m;++i){
            int x = edges[i][0];
            int y = edges[i][1];
            tjb(x,y);
            tjb(y,x);
        }
        bfs(0);
        int ans = 0;
        for(int i=1;i<n;++i){
            int m = (dis[i]*2-1) / patience[i];
            ans = max(ans, m*patience[i] + dis[i]*2);
        }
        return ans+1;
    }
};