class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string str;
        if(strs.size()==0)
        return "";
        string temp1 = strs[0];
        for(int i = 1; i<strs.size(); i++){
            str = "";
            string temp = strs[i];
            for(int j = 0; j<temp1.size(); j++){
                if(temp[j]==temp1[j])
                str+=temp[j];
                else{
                temp1 = str;
                break;
            }
            }

        }
        return temp1;
    }
};
