class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {

        int left = 1;
        int right = *max_element(piles.begin(), piles.end());

        while(left < right){
            int mid = left + (right - left)/2;

            long long totalhour = 0;
            for(int pile : piles){
                totalhour += (pile + mid -1)/mid;
            }

            if(totalhour <= h){
                right = mid;
            }
            else{
                left = mid+1;
            }
        }
        return left;
        
    }
};
