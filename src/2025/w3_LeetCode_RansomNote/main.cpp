class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {

        unordered_map<char, int> dic;

        for (auto & c : magazine){
            if (  dic.find( c ) != dic.end() ){
                dic[c]++;
            }else{
                dic[c] = 1;
            }
        }

        for (auto & c : ransomNote ){
            if ( dic.find(c) == dic.end() || dic[c] <= 0){
                return false;
            }
            dic[c] --;
        }
        return true;
    }
};