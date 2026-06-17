class Solution {
public:
    string addBinary(string a, string b) {
        string ans = "";
        int i = a.length() - 1;
        int j = b.length() - 1;
        int carry = 0;
        
        // Loop as long as there are digits in either string OR a remaining carry
        while (i >= 0 || j >= 0 || carry) {
            int sum = carry;
            
            if (i >= 0) sum += a[i--] - '0'; // Convert char to int
            if (j >= 0) sum += b[j--] - '0';
            
            // The bit to add is sum % 2 (0 if sum is 0 or 2, 1 if 1 or 3)
            ans += to_string(sum % 2);
            
            // The new carry is sum / 2 (1 if sum is 2 or 3, 0 otherwise)
            carry = sum / 2;
        }
        
        // Since we appended digits from right to left, we must reverse the result
        reverse(ans.begin(), ans.end());
        return ans;
    }
};