class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int s1=nums1.size();
        int s2=nums2.size();
        int medind=(s1+s2)/2;
        bool oddlen=((s1+s2)%2==0)?false:true; 

        // Initialize with a flag value
        int ind=0,i=0,j=0,m1=0,m2=0;
        
        while(ind<=medind){
            if(i<s1 && j<s2){
                if(nums1[i]<nums2[j]){
                    // Capture the exact current index before incrementing i
                    if(ind==medind-1){m1=(i+1);}
                    else if(ind==medind){m2=(i+1);break;}
                    ind++;
                    i++;
                }
                else{                    
                    // Capture the exact current index before incrementing j
                    if(ind==medind-1){m1=-(j+1);}
                    else if(ind==medind){m2=-(j+1);break;}
                    ind++;
                    j++;
                }
            }
            else if(i<s1){
                if(ind==medind-1){m1=(i+1);}
                else if(ind==medind){m2=(i+1);}
                ind++;
                i++; 
            }
            else{ //j<s2
                if(ind==medind-1){m1=-(j+1);}
                else if(ind==medind){m2=-(j+1);}
                ind++;
                j++; 
            }
        }

        // For odd length, the median is just the element at medind (m2)
        if(oddlen==true){
            if(m2>0){return nums1[m2-1];}
            else {return nums2[(-m2)-1];}
        }
        else{
            int t1=(m1>0)? nums1[m1-1]:nums2[(-m1)-1];
            int t2=(m2>0)? nums1[m2-1]:nums2[(-m2)-1];
            return (t1+t2)/(double)2;
        }
    }
};
