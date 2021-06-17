def longestCommonPrefix(strs):
        common = ""
       # Running loop to the length of the first string of the list
        for letter in range(len(strs[0])):
            count = 1  # counter for how many strings have the same character as the first
            try:
                for next_letter in range(1, len(strs)):    #starting from the next string of the list
                    # comparing the characters of the first string with the characters of subsequent strings
                    if strs[0][letter] == strs[next_letter][letter]:   
                        count += 1
                    else:
                        break # break if characters are not equal
                # if the counter is equal to length of the string, it means the said character is present in every string of the list
                if count == len(strs):
                    common += strs[0][letter]
                else:
                    break
            except IndexError:
                continue # exception for comparing last index
        return common                
        
