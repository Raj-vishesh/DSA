class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {

        sort(g.begin() , g.end());
        sort(s.begin() , s.end());
        

        int i =  0; // pointer for grred 
        int j = 0;  // pointer for child / student 
        while(i < g.size()  && j < s.size()){
            if(s[j]  >= g[i]){   // agar cookies bacche ki condtion satisfy krta hai to 
                i++;        //baccha kush g=ho gya and now next baccha 
            }

            j++;        // agar kush nhi hua to next size cookies ko dekho 

        }

        return i;       //   i will tells how many students are khush 
    }
};