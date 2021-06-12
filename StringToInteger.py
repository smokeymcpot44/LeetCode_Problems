class Solution:
    def myAtoi(self, s: str) -> int:
        raw = s.strip() # for stripping all the white spaces before actual string
        # checking boundary conditions like empty strings or only signs
        if not raw or raw == "+" or raw == "-":
            return 0
        raw_num = 0 
        if (raw[0] == "+" or raw[0] == "-" ) and raw[1].isnumeric() :
            raw_num = [raw[0]] # converted to list to add sign and digits
            for letter in raw[1:]:
                if not letter.isdigit():
                    break 
                raw_num.append(letter) # adding to list until a non-digit occurs
        elif raw[0].isnumeric():
            raw_num = [] # converted to list to add digits
            for letter in raw:
                if not letter.isdigit():
                    break
                raw_num.append(letter) # adding to list until a non-digit occurs
        else:
            return 0
        num = int("".join(raw_num)) # converting the list of strings as an integer
        # checking if the number cross the integer limits
        if num < -2147483648:
            return -2147483648
        elif num > 2147483647:
            return 2147483647
        else:
            return num        
