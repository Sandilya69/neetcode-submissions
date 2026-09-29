class Solution {
public:
    int mySqrt(int x) {

        int l =0;
        int r = x;
        int sq = 0;

        while(l<=r){
            int m = l + (r - l)/2;
            if((long)m*m > x){
                r = m - 1;
            }
            else if((long)m*m < x){
                l = m + 1;
                sq = m;
            }
            else{
                return m;
            }

        }
        return sq;

    }
};