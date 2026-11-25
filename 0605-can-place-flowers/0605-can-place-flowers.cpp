class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        // Check adjecent elements for this array
        // Place flower where we can
        
        // return true we there are no flowers to place i.e. n = 0
        if(n == 0){
            return true;
        }

        // Edge cases for smaller vectors
        if(flowerbed.size() == 0){
            if(n == 0){
                return true;
            } else {
                return false;
            }  
        } else if (flowerbed.size() == 1){
            if(flowerbed[0] == 0 && n == 1){
                return true;
            } else if(flowerbed[0] == 1){
                return false;
            }
        } else if (flowerbed.size() == 2){
            if(flowerbed[0] == 0 && flowerbed[1] == 0 && n == 1){
                return true;
            } else if(flowerbed[0] == 1 || flowerbed[1] == 1){
                return false;
            }
        }

        // Edge case for first 2 spots
        if((flowerbed[0] == 0) && (flowerbed[1] == 0)){
            flowerbed[0] = 1;
            n--;
            if(n == 0){
            return true;
            }
        }

        // Edge case for last 2 spots
        if((flowerbed[flowerbed.size()-1] == 0) && (flowerbed[flowerbed.size()-2] == 0)){
            flowerbed[flowerbed.size()-1] = 1;
            n--;
            if(n == 0){
            return true;
            }
        }

        // Actual Loop
        for(int i=1; i < flowerbed.size()-1; i++){
            if(flowerbed[i-1] == 0 && flowerbed[i] == 0 && flowerbed[i+1] == 0){
                flowerbed[i] = 1;
                n = n-1;
                if(n == 0){
                    return true;
                }
            }
        }

        return false;
    }
};