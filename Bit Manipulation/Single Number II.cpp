Method 1 - Hashmap

Time complexity  -> O(nlogn) 
Space Complexity -> O(n)

int singleNumber(vector<int>& nums) {
        unordered_map<int,int> freq;

        for(auto x : nums) freq[x]++; 
        //Element appearing three time have frequency three after increment three time and element appearing one time has freq 1 after increment it by one time

        for(auto x : nums) 
            if(freq[x] == 1) //Frequency of single element x is 1
                return x;  // so return that single element x
        return -1; //otherwise return -1 
}

Method 2 - Sorting

Time complexity  -> O(nlogn + n) -> O(nlogn) 
Space Complexity -> O(1)

if(size == 1) return single element present in the array
then sort all the elements of nums using sort function

Example 1 - nums = [2,3,3,3] -> if(nums[1] != nums[0]) -> return nums[0];

Example 2 - nums = [3,3,3,4] -> if(nums[n-1] != nums[n-2]) -> return nums[n-1];

Example 3 - nums = [2,2,2,3,5,5,5] 
when i=1 -> if(nums[1] == nums[0]) - if(2 == 2) -> i += 3
then i=4 -> if(nums[4] != nums[3]) - if(5 != 3) -> return nums[3] - return 3;
  
Code

int singleNumber(vector<int>& nums) {
	int n = nums.size();
	if(n == 1) return nums[0]; 
	sort(nums.begin(),nums.end()); 

	//Corner cases
	if(nums[1] != nums[0]) return nums[0]; 


	if(nums[n-1] != nums[n-2]) return nums[n-1];


	for(int i=1; i < nums.size()-1 ; i += 3){
		if(nums[i] != nums[i-1]) return nums[i-1];

	}
	return -1;
}

Method 3 - Bit Manipuation (Counting Set bits)
  
 Time Complexity -> O(32*n) 
 Space Complexity - O(1)

 we take two variable result=0 and leftshift=1
 we add bits of all the elements one by one from rsb (right significant bit) then calculate 
 if(sumbit % 3 == 0) leave the bit and if(sumbit % 3 != 0) the take that bit to the result

 Example - nums = [1,1,1,5,7,7,7] 
 1. Decimal     ->       Binary                        |2. Decimal     ->       Binary
				->              _                      |               ->             _
	1           ->       000000|1|                     |   1           ->       00000|0|1
	1           ->       000000|1|                     |   1           ->       00000|0|1    
	1           ->       000000|1|                     |   1           ->       00000|0|1
	5           ->       000010|1| -> single element   |   5           ->       00001|0|1 -> single element
	7           ->       000011|1|                     |   7           ->       00001|1|1
	7           ->       000011|1|                     |   7           ->       00001|1|1
	7           ->       000011|1|                     |   7           ->       00001|1|1
	---------------------------|-|                     |   --------------------------|-|-
	sumbit ->                  |7|                     |   sumbit ->                 |3|
							   |_|                     |                             |_|
													   |               
7 % 3 != 0 -> update result =0(result) + 1(leftshift); |   3 % 3 == 0  do not update result
and leftshift *= 2; -> leftshift = 2                   |   update leftshift *= 2; -> leftshift = 4

 3. Decimal     ->       Binary                     
				->            _                     
	1           ->       0000|0|01                  
	1           ->       0000|0|01                      
	1           ->       0000|0|01                  
	5           ->       0000|1|01 -> single element
	7           ->       0000|1|11                  
	7           ->       0000|1|11                  
	7           ->       0000|1|11                  
	-------------------------|-|--                  
	sumbit ->                |4|                       
							 |_|                    
4 % 3 != 0 -> update result = 1(result) + 4(leftshift); -> result = 5 -> required ans  
and leftshift *= 2; -> leftshift = 8               

and all the remaining bits are zero added by this method upto 32 bits and the final answer in 5 

but sorting method is better than this method because 
		   n <= 3 * pow(10,4)
	  so,  n < INT_MAX
therefore, logn < 32  ----- equation 1st
by multiply the equation 1st by n we will get  ->  n * logn < n * 32
O(n*logn) < O(32*n)     ->   therefore , Time complexity of sorting < Time complexity of counting set bits

Code

int singleNumber(vector<int>& nums) {
	unsigned long int leftshift = 1;
	int result = 0;
	int sumbit = 0;
	
	for(int i=0 ; i < 32 ; ++i){
		for(auto x : nums)
			sumbit += ((x >> i) & 1);
		if(sumbit % 3 != 0){
			result += leftshift;
			sumbit = 0;
		} 
		leftshift *= 2;
	}
	return result;
}

Method 4 - Bit Manipulation (XOR)
  
Time Compexity   ->  O(n)
Space Complexity ->  O(1)

Best ones and twos method 

Example - nums = [5,5,5,7] , n=4

we will take two variable ones = 0 and twos = 0

Decimal    |    Binary
5          |    000101
7          |    000111
we runs a for loop i = 0 to n-1(4-1=3)
initialize i as 0 

1st - when i = 0

a. - ones ^ a[i] (0 ^ 5) ->  00000    we know that 0 ^ 0 = 0
						   ^ 00101                 1 ^ 1 = 0
							-------                0 ^ 1 = 1
							 00101                 1 ^ 0 = 1

then we take complement of twos - ~twos = ~(0) -> 1111111
then we take and of both (ones ^ a[i]) & (~twos) and copy it in ones
ones ^ a[i]     ->     000101
~twos           ->   & 111111
					----------
					   000101
copy it to , ones = (ones ^ a[i]) & (~twos) = 5

Now we go to update twos

b. - twos ^ a[i] (0 ^ 5) ->  00000    we know that 0 ^ 0 = 0
						   ^ 00101                 1 ^ 1 = 0
							-------                0 ^ 1 = 1
							 00101                 1 ^ 0 = 1

then we take complement of ones - ~ones = ~(5) -> 111010
then we take and of both (twos ^ a[i]) & (~ones) and copy it in twos
twos ^ a[i]     ->     000101
~ones           ->   & 111010
					----------
					   000000
copy it to twos = (twos ^ a[i]) & (~ones) = 0
increment i to 1 -> i = 1

2nd - when i = 1

a. - ones ^ a[i] (5 ^ 5) ->  00101    we know that 0 ^ 0 = 0
						   ^ 00101                 1 ^ 1 = 0
							-------                0 ^ 1 = 1
							 00000                 1 ^ 0 = 1

then we take complement of twos - ~twos = ~(0) -> 1111111
then we take and of both (ones ^ a[i]) & (~twos) and copy it in ones
ones ^ a[i]     ->     000000
~twos           ->   & 111111
					----------
					   000000
copy it to , ones = (ones ^ a[i]) & (~twos) = 0

Now we go to update twos

b. - twos ^ a[i] (0 ^ 5) ->  00000    we know that 0 ^ 0 = 0
						   ^ 00101                 1 ^ 1 = 0
							-------                0 ^ 1 = 1
							 00101                 1 ^ 0 = 1

then we take complement of ones - ~ones = ~(0) -> 111111
then we take and of both (twos ^ a[i]) & (~ones) and copy it in twos
twos ^ a[i]     ->     000101
~ones           ->   & 111111
					----------
					   000101
copy it to twos = (twos ^ a[i]) & (~ones) = 5
1. when we travel 5 one times ones is 5 and twos is 0
2. when we travel 5 two times ones is 0 and twos is 5
3. now,when we travel 5 three times both ones and twos is 0
increment i to 1 -> i = 2    

2nd - when i = 2

a. - ones ^ a[i] (0 ^ 5) ->  00000    we know that 0 ^ 0 = 0
						   ^ 00101                 1 ^ 1 = 0
							-------                0 ^ 1 = 1
							 00101                 1 ^ 0 = 1

then we take complement of twos - ~twos = ~(5) -> 111010
then we take and of both (ones ^ a[i]) & (~twos) and copy it in ones
ones ^ a[i]     ->     000101
~twos           ->   & 111010
					----------
					   000000
copy it to , ones = (ones ^ a[i]) & (~twos) = 0

Now we go to update twos

b. - twos ^ a[i] (5 ^ 5) ->  00101    we know that 0 ^ 0 = 0
						   ^ 00101                 1 ^ 1 = 0
							-------                0 ^ 1 = 1
							 00000                 1 ^ 0 = 1

then we take complement of ones - ~ones = ~(0) -> 111111
then we take and of both (twos ^ a[i]) & (~ones) and copy it in twos
twos ^ a[i]     ->     000000
~ones           ->   & 111111
					----------
					   000000
copy it to twos = (twos ^ a[i]) & (~ones) = 0

-> both  ones and twos is zero
increment i to 1 -> i = 3

4th - when i = 3

a. - ones ^ a[i] (0 ^ 7) ->  00000    we know that 0 ^ 0 = 0
						   ^ 00111                 1 ^ 1 = 0
							-------                0 ^ 1 = 1
							 00111                 1 ^ 0 = 1

then we take complement of twos - ~twos = ~(0) -> 1111111
then we take and of both (ones ^ a[i]) & (~twos) and copy it in ones
ones ^ a[i]     ->     000111
~twos           ->   & 111111
					----------
					   000111
copy it to , ones = (ones ^ a[i]) & (~twos) = 7

Now we go to update twos

b. - twos ^ a[i] (0 ^ 7) ->  00000    we know that 0 ^ 0 = 0
						   ^ 00111                 1 ^ 1 = 0
							-------                0 ^ 1 = 1
							 00111                 1 ^ 0 = 1

then we take complement of ones - ~ones = ~(7) -> 111000
then we take and of both (twos ^ a[i]) & (~ones) and copy it in twos
twos ^ a[i]     ->     000111
~ones           ->   & 111000
					----------
					   000000
copy it to twos = (twos ^ a[i]) & (~ones) = 0
NOW at last we increment i to 1 -> i = 4
i > n -> come out of loop 
return ones -> it is the final result

You also use example - nums = [5,5,5,7,9,9,9] -> it will return 7 as ans

Code

int singleNumber(vector<int>& nums) {
	int ones = 0;
	int twos = 0;
	for(int i=0 ; i < nums.size() ; ++i){
		ones = (ones ^ nums[i]) & (~twos);
		twos = (twos ^ nums[i]) & (~ones);
	}
	return ones;
}
