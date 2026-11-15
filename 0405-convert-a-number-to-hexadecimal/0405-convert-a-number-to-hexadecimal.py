class Solution:
    def toHex(self, num: int) -> str:
        # Number to Decimal
        # In general terms we keep diving no by 16 untill we reach value less than 16
        # Let's tackel +ve no's first
        res = []
        idx = 0
        shift = 28

        if num == 0:
            return str(0)

        while ((num >> shift) & 0xF) == 0:
            shift = shift - 4

        # 32 bit of integer gives me 8 nibbles, based on nibbles I can calculate Hex
        while shift >= 0:
            temp = (num >> shift) & 0xF
            if temp <= 9:
                res.append(str(temp))
            elif temp == 10:
                res.append('a') 
            elif temp == 11:
                res.append('b') 
            elif temp == 12:
                res.append('c') 
            elif temp == 13:
                res.append('d') 
            elif temp == 14:
                res.append('e') 
            elif temp == 15:
                res.append('f') 
            
            shift = shift - 4

        ans = "".join(res)
        return ans