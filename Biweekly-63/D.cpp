class Solution {
public:
    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k) {
        long long mxabs1 = 0;
        long long mxabs2 = 0;
        int n = nums1.size();
        int m = nums2.size();
        for(int i=0;i<n;++i){
            mxabs1 = max(mxabs1, (long long)abs(nums1[i]));
        }
        for(int i=0;i<m;++i){
            mxabs2 = max(mxabs1, (long long)abs(nums2[i]));
        }        
        long long rgt = mxabs1 * mxabs2;
        long long lft = -rgt;
        long long ans;
        while(lft <= rgt){
            long long mid = (lft+rgt) / 2;
            long long sum = 0;
            for(int i=0;i<n;++i){
                if(nums1[i] >= 0){
                    int lft1 = 0;
                    int rgt1 = m-1;
                    int aug = -1;
                    while(lft1 <= rgt1){
                        int mid1 = (lft1+rgt1)>>1;
                        long long mul = nums2[mid1];
                        mul *= nums1[i];
                        if(mul <= mid){
                            aug = mid1;
                            lft1 = mid1+1;
                        }else rgt1 = mid1-1;
                    }
                    sum += aug+1;
                }else{
                    int lft1 = 0;
                    int rgt1 = m-1;
                    int aug = m;
                    while(lft1 <= rgt1){
                        int mid1 = (lft1+rgt1)>>1;
                        long long mul = nums2[mid1];
                        mul *= nums1[i];
                        if(mul <= mid){
                            aug = mid1;
                            rgt1 = mid1-1;
                        }else lft1 = mid1+1;
                    }
                    sum += m-aug;                    
                }
                
            }
          //  printf("Debug: %lld %lld %lld %lld\n",lft,rgt, sum, mid);
            if(sum >= k){
                ans = mid;
                rgt = mid-1;
            }else lft = mid+1;
        }
        //printf("===========\n");
        return ans;
    }
};