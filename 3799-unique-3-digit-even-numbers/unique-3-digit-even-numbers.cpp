#include <vector>

class Solution {
public:
    int totalNumbers(std::vector<int>& digits) {
        int counts = 0;
  
        std::vector<int> freq(10, 0);
        for (int digit : digits) {
            freq[digit]++;
        }

        for (int i = 100; i <= 998; i += 2) {
            int hundreds = i / 100;
            int tens = (i / 10) % 10;
            int ones = i % 10;

            freq[hundreds]--;
            freq[tens]--;
            freq[ones]--;
            
            if (freq[hundreds] >= 0 && freq[tens] >= 0 && freq[ones] >= 0) {
                counts++; 
            }
  
            freq[hundreds]++;
            freq[tens]++;
            freq[ones]++;
        }
        
        return counts;
    }
};
