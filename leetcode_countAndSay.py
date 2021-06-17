def countAndSay(n):
        for i in range(n - 1):
            if i == 0:
                raw = str(1)
            raw_list = [word for word in raw]
            new_l = []
            num = 0
            while num < len(raw_list):
                try:
                    rw = raw_list[num]
                    while True:
                        if raw_list[num] == raw_list[num+1]:
                            rw += raw_list[num]
                            num += 1
                        else:
                            num += 1
                            break
                    new_l.append(rw)
                except IndexError:
                    new_l.append(rw)
                    break
            raw = "".join([str(len(ty))+ty[0] for ty in new_l])

        return "1" if n == 1 else raw
        
                
            
        

