class Solution {
public:
    bool winnerOfGame(string colors) {
        int n1 = 0;
        int n2 = 0;
        int n = colors.length();
        for(int i=1;i<n-1;++i){
            if(colors[i] == 'A'){
                if(colors[i-1] == 'A' && colors[i+1] == 'A') ++ n1;
            }
            else{
                if(colors[i-1] == 'B' && colors[i+1] == 'B') ++ n2;
            }
        }
        if(n1 <= n2)return false;
        return true;
    }
};