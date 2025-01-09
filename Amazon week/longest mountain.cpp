#leetcode 845
class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int n=arr.size();
        int ans=0;
        int i=1;
        int upper,lower;
        
        while(i<n)
       {    upper=0;lower=0;                  //Each time after traversing one mountain or not,we have to set upper & lower to 0
            while(i<n && arr[i-1]==arr[i])    //   for flat array,where elements are equal
              i++;                            //This also handles when we get same adjacent elements
            while(i<n && arr[i-1]<arr[i])     //Increasing part of mountain
            {  upper++;i++;
                
            }
                    
            
           while(i<n && arr[i-1]>arr[i])    //Decreasing part of mountain 
           {
               lower++;
               i++;    
           } 
          if(upper && lower)       //Mountain only exists if we have both incresing part and decreasing part adjacently
           { ans=max(ans,lower+upper+1);
           }
        
        }
        
        return ans;
     
    }
};
