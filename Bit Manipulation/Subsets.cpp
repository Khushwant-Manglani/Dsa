If the length of nums is n there are pow(2,n) combinations in output
value varies from 0 to pow(2,n) - 1

Example - nums = [1,2,3] , Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
the  length of nums is 3 there are pow(2,3) -> 8 combinations in output
value varies from 0 to 8 - 1   -> 0  to 7

Decimal                Binary                    Subset
0         ->            000         ->            []
1         ->            001         ->            [1]
2         ->            010         ->            [2]
3         ->            011         ->            [1,2]
4         ->            100         ->            [3]
5         ->            101         ->            [1,3]
6         ->            110         ->            [2,3]
7         ->            111         ->            [1,2,3]

Time Complexity -> O(pow(2,n) * n) 


vector<vector<int>> subsets(vector<int>& nums) {

    int n = nums.size();
    int pow = 1 << n;
    vector<vector<int>> subset(pow);
    for(int i=0; i < pow ;i++){
        for(int j=0 ; j < n ; j++){
            if((i & (1 << j)) != 0) // or we can use if(i >> j & 1) also
                subset[i].push_back(nums[j]);
        }
    }
    return subset;
    
    //recursion and bactracking method pending
    
}
