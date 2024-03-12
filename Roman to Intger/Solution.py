class Solution(object):
    def romanToInt(self, s):
        """
        :type s: str
        :rtype: int
        """
        s+= "0"
        result =0
        lenght = len(s)
        i = 0
        while i < lenght:
            if (s[i] == "I" ):
                if ( s[i+1] == "V"):
                    result += 4
                    i+=1
                elif s[i+1] == "X":
                    result += 9
                    i+=1
                else:
                    result += 1

            elif (s[i] == "V"):
                result += 5

            elif( s[i] == "X" ):
                if  s[i+1] == "L":
                    result+= 40
                    i+= 1
                elif s[i+1] == "C":
                    result += 90
                    i+=1
                else:
                    result += 10


            elif ( s[i] == "L"):
                result += 50
            
            elif ( s[i] == "C"  ):
                if (s[i+ 1] == "D"):
                    result += 400
                    i+=1
                elif s[i+1] == "M":
                    result += 900
                    i += 1
                else:
                    result += 100
            elif( s[i] == "D"):
                result += 500
            elif (s[i] == "M"):
                result += 1000
            i+=1
        return result
            

        