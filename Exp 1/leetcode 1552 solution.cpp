class Solution {
public:
    int maxDistance(vector<int>& position, int m) {
        int ans=0;
        int left=1;
        sort(position.begin(),position.end());
        int len=position.size();
        int right=position[len-1]-position[0];
        while(left<=right){
            int mid=left+(right-left)/2;
            int count=1;
            int prev_pos=position[0];
            for(int i=1;i<len;i++){
                if(position[i]-prev_pos>=mid){
                    count++;
                    prev_pos=position[i];
                    if(count==m){
                        break;
                    }
                }
            }
            if(count==m){
                ans=mid;
                left=mid+1;
            }
            else{
                right=mid-1;
            }
        }
        return ans;
    }
};