class Solution {
public:
    int maxArea(vector<int>& height) {
        int i=0;
        int j= height.size()-1;
        int max_area=0;

        while(i<=j){
            int max1 = ( min(height[i],height[j]) * (j-i));
            max_area = max(max_area,max1);

            if(height[i]> height[j]){
                j--;
            }
            else{
                i++;
            }

        }
        return max_area;
        
    }
};