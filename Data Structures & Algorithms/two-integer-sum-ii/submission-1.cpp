class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {

        for(int i =0; i<numbers.size(); i++){
            int l = i+1, r = numbers.size() - 1;
            int temp = target - numbers[i];
            while(l <= r){

                int mid = l + (r - l)/2;
                if(numbers[mid] == temp){
                    return { i + 1, mid + 1};
                }
                else if(numbers[mid] < temp){
                    l = mid + 1;
                }else{
                    r = mid - 1;
                }
            }
        }
        return {};
    }
};
