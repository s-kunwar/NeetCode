/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int len=mountainArr.length();

        int l=0,peak=-1,r=len-1;
        while(l<=r){
            int mid=(l+r-1)/2;
            int term=mountainArr.get(mid);
            int prev=mountainArr.get(mid-1);
            int succ=mountainArr.get(mid+1);

            if(term>prev && term<succ){
                l=mid+1;
            }
            else if(term<prev && term>succ){
                r=mid-1;
            }
            else{
                peak=mid;
                break;
            }
        }
        
        l=0;r=peak;
        while(l<=r){
            int mid=(l+r+1)/2;
            int term=mountainArr.get(mid);

            if(term==target) return mid;
            else if(term>target) r=mid-1;
            else l=mid+1;
        }

        l=peak;r=len-1;
        while(l<=r){
            int mid=(l+r+1)/2;
            int term=mountainArr.get(mid);

            if(term==target) return mid;
            else if(term>target) l=mid+1;
            else r=mid-1;
        }

        return -1;

    }
};