class Solution {
public:

    string encode(vector<string>& strs) {
        string mstr("");

        for (string s : strs){
            mstr += (std::to_string(s.size()) + "#" + s); 
        }
        
        std::cout << mstr << std::endl;
        return mstr;
    }

    vector<string> decode(string s) {
        vector<string> ret;
        
        string curr("");
        int ind = 0;
        int strLen(0);
        while (ind < s.size()){
            
            if (s[ind] == '#'){
                strLen = std::stoi(curr);
                ret.push_back(s.substr(ind + 1, strLen));
                curr = "";
                ind += strLen + 1;
            }
            else {
                curr += s[ind];
                ind++;
            }
            
        }
        return ret;


    }
};
