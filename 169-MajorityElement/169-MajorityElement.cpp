class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int count = 1;
        int k= nums[0];
        
        for(int i=1;i<n;i++){
            
            if(nums[i]==k){
                count++;
            }
            else count--;
            
            if(count==0){
                k = nums[i];
                count = 1;
            }
        }

        return k;
    }
};