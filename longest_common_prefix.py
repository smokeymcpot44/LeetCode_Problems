def longestCommonPrefix(strs):
        common = ""
        for letter in range(len(strs[0])):
            count = 0
            try:
                for next_letter in range(1, len(strs)):
                    if strs[0][letter] == strs[next_letter][letter]:
                        count += 1
                    else:
                        break
                if count == len(strs) - 1:
                    common += strs[0][letter]
                else:
                    break
            except IndexError:
                continue
        return common                
        
