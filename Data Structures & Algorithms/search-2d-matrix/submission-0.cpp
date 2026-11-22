class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int numOfRows = matrix.size();
        int numOfCols = matrix[0].size();

        int left = 0;
        int right = numOfRows * numOfCols - 1;

        while(left <= right){
            int mid = left + (right - left) / 2;
            int rowNum = mid / numOfCols;
            int colNum = mid % numOfCols;

            if(matrix[rowNum][colNum] == target){
                return true;
            } else if(matrix[rowNum][colNum] < target){
                left = mid + 1;
            } else{
                right = mid - 1;
            }
        }
        return false;
    }
};
