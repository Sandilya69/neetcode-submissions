class Solution {
public:
    bool isPerfectSquare(int num) {

        int l = 1;
        int r = num -1;

        if(num == 1){
            return true;
        }

        while(l <= r){
            int m = l + (r- l)/2;

            long long sq = 1LL*m*m;

            if(sq > num){
                r = m-1;
            }
            else if(sq < num){
                l = m+1;
            }
            else{
                return true;
            }
        }
        return false;
        
    }
};