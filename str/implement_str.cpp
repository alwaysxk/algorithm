class Solution {
public:
    int strStr(string haystack, string needle) {
        int *next = buildNext(needle);
        int n = haystack.size(), i = 0;
        int m = needle.size(), j = 0;
        
        while(j < m && i < n){
            if(j < 0 || haystack[i] == needle[j]){i++; j++;}
            else j = next[j];
        }
        return j == m ? i - j : -1;
    }
    
    int* buildNext(string needle){
        int m = needle.size(), j = 0;
        int *N = new int[m];
        int t = N[0] = -1;
        while(j < m - 1){
            if(t < 0 || needle[j] == needle[t]){
                j++; t++;
               N[j] = (needle[j] == needle[t]) ? N[t] : t;
            }else
                t = N[t];
        }
        return N;
    }
};