

def countAndSay(n):
        for i in range(n - 1):
            # initilazing the final string for the first iteration only
            if i == 0:
                raw = str(1)
            raw_list = [word for word in raw] 
            new_l = []
            num = 0
            while num < len(raw_list): 
                try:
                    rw = raw_list[num]  # initializing the string for similar next character
                    while True: 
                        if raw_list[num] == raw_list[num+1]:  # check if the next character is same as the current
                            rw += raw_list[num] # adding it to the string of similar characters
                            num += 1 # increase counter
                        else:
                            # if the next character is not same, increase the counter so that it moves to next character
                            # break the loop to make a fresh string of similar characters
                            num += 1 
                            break
                    new_l.append(rw) # add the string of similar characters to a list
                except IndexError:
                     # exception for last index of the list
                     # occurs when the last characters is compared to a non-existent next character
                     # adds the last element to the list if not previously added with last similar string
                    new_l.append(rw)
                    break
            # calculates the length of every similar string
            # combines the count of the character and the character
            raw = "".join([str(len(element)) + element[0] for element in new_l]) 

        return "1" if n == 1 else raw
        
                
            
        

