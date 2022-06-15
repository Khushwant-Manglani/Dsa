class Solution {
public:
    vector<int> countBits(int n) {
        //Dynamic programming
        vector<int> result;
        result.push_back(0);
        int offset = 1;
        for(int index = 1; index < n+1; ++index){
            if(offset*2 == index){
                offset *= 2;
            }
            //result[index] = result[index - offset] + 1;
            result.push_back(result[index - offset] + 1);
        }
        return result;
        
        
        
        
        /*vector<int> res;
        for(int i=0; i<n+1 ;i++){
            int Co=0;
            int j = i;
            while(j){
                j = j & (j-1);
                Co++;
            }
            res.push_back(Co);
        }
        return res;*/
        
    }
};
