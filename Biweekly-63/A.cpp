class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        int n = seats.size();
        int a[102];
        int b[102];
        for(int i=0;i<n;++i){
            a[i] = seats[i];
            b[i] = students[i];
        }
        sort(a,a+n);
        sort(b,b+n);
        int ans = 0;
        for(int i=0;i<n;++i){
            ans += abs(a[i] - b[i]);
        }
        return ans;
    }
};
