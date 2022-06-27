class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        //Method 1 - slow and fast pointer algo
        int slow = nums[0];
        int fast = nums[0]; //int fast = nums[nums[0]];
        do{
            slow = nums[slow];
            fast = nums[nums[fast]];
        }while(slow != fast);
        
        slow = nums[0]; //slow = 0;
        while(slow != fast){
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
        
        
        //Method 2 - Mark visited vaue with the array
        /*for(int i=0 ; i < nums.size() ; ++i){
            int t = abs(nums[i]) - 1;
            nums[t] = -nums[t];
            if(nums[t] > 0) return t+1;
        }
        return 0;*/
        
        
        //Method 3 - Sorting
        /*sort(nums.begin(),nums.end());
        for(int i=0 ; i < nums.size()-1 ; ++i){
            if(nums[i] == nums[i+1]) return nums[i];
        }
        return 0;*/
        
        
        //Method 4 - Hashmap
        /*unordered_map<int,bool> dup;
        for(int i=0 ; i < nums.size() ; ++i){
            if(dup.count(nums[i]) > 0) return nums[i];
            dup.insert(make_pair(nums[i],true));
        }
        return 0;*/
        
        
        
        //Binary search pending
        
    }
};
