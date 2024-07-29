class Solution {
public:
    int maxArea(vector<int>& height) {
        int area=0;
        int i=0;
        int n=height.size();
        int j=n-1;
        while(i<j){
            int newArea=(j-i)*min(height[j],height[i]);
            area=max(area,newArea);
            if(height[i]>height[j]){
                j--;
            }
            else{
                i++;
            }
        }
        return area;
        
    }
};