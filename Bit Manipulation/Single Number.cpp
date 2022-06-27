Method 1 - Brute force approach

 Time Complexity - O(n^2)
 Space Complexity - O(1)
  
 int singleNumber(vector<int>& nums) {
	 int n = nums.size();
	 for(int i=0 ; i < n ; ++i){
         int Co=0;
         for(int j=0 ; j < n ; ++j){
             if(nums[i] == nums[j])
                 Co++;
         }
         if(Co % 2 != 0) return nums[i];
     }
     return 0;
 }


Method 2 - Counting set bit (Bit Manipulation)
  
 Time Complexity - O(32*n)
 Space Complexity - O(1)
  
 int singleNumber(vector<int>& nums) {
	   unsigned int leftshift = 1;
	   int res = 0;
     for(int i=0 ; i < 32 ; ++i){
         int Co=0;
         int mask = (1 << i);
         for(int i=0 ; i < nums.size() ; ++i){
             if(nums[i] & mask) Co++;
         }
         if(Co % 2 != 0) res += leftshift;
         leftshift *= 2;
     }
     return res;
  }


Method 3 - Sorting

 Time Complexity - O(nlogn)
 Space Complexity - O(1)
 
  int singleNumber(vector<int>& nums) {
	   sort(nums.begin(),nums.end());                
     for(int i=1 ; i < nums.size() ; i += 2){
         if(nums[i] != nums[i-1]) 
             return nums[i-1];
     }     
     return nums[nums.size()-1];
  }


Method 4 - Hashmap
 
 Time Complexity - O(n)
 Space Complexity - O(n)
 
 int singleNumber(vector<int>& nums) {
   unordered_map<int,int> freq;
   for(auto x : nums) freq[x]++;
   for(auto a : nums) if(freq[a] == 1) return a;
   return 0;
 }


Method 5 - Bitwise XOR Operator

 Time Complexity - O(n)
 Space Complexity - O(1)
  
 int singleNumber(vector<int>& nums) {
	   int result=0;
     for(int i=0 ; i < nums.size() ; ++i){
         result ^= nums[i];
     }
     return result;
 }
