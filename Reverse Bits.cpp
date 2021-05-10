class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ans = 0;
        for (uint32_t i=0; i<32; i++) {
            ans |= ((1 << i) & n) > 0 ? 1 << (31 - i) : 0;
        }
        return ans;
    }
};