class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        
        int n = piles.size();

        int upperBound = INT_MIN;
        
        for(int i = 0; i < n; i++){
            if(piles[i] > upperBound){
                upperBound = piles[i];
            }
        }
        if(n == h){        
            return upperBound;
        }

        int low = 1;
        while(low < upperBound){

            int mid = low + (upperBound - low) / 2;
            //if(mid == low) return upperBound;
            int numOfHours = 0;

            for(int j = 0; j < n; j++){
                if(piles[j] <= mid){
                    numOfHours += 1;
                } else{
                    numOfHours += piles[j] / mid;
                    if(piles[j] % mid != 0){
                        numOfHours += 1;
                    }
                }
            }

            if(numOfHours <= h){
                upperBound = mid;
            } else {
                low = mid+1;
            }
        }
        return low;

    }
};