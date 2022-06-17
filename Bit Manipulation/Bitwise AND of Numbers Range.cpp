class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int count = 0;
        while(left != right){
            left >>= 1;
            right >>= 1;
            count++;
        }
        return right<<count;
        
        /*while(left < right){
            right = right & right-1;
        }
        return right&left;*/
        
        
        //return (right > left) ? rangeBitwiseAnd(left , right & (right-1)) : left&right;
        
        
        //worst time complexity of this solution
        /*int result = right;
        while(left < right){
            if(result == 0) return 0;
            result &= left;
            left++;
        }
        return result;*/
    }
};
