class Solution {
public:
    int nthUglyNumber(int n) {
        int arr[n+1];
        arr[1]=1;
        int i2=1, i3=1, i5=1; 

        for(int i=2; i<=n; i++){
            int val[3] = {arr[i2]*2, arr[i3]*3, arr[i5]*5};

            arr[i] = min({val[0], val[1], val[2]});
            
            if(arr[i]==val[0]) i2++;
            if(arr[i]==val[1]) i3++;
            if(arr[i]==val[2]) i5++;
        }

        return arr[n];
    }
};