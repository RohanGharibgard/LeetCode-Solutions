class Solution
{


public:
    bool isPalindrome(string s)
    {
        char left, right;
        int start = 0;
        int end = s.length() - 1;

        if (end <= 0)
            return true;

        while (start <= end)
        {
            left = s.at(start);
            right = s.at(end);
            while (!isAlpha(left))
            {
                start++;
                if (start > end)
                {
                    return (!isAlpha(right));
                }
                left = s.at(start);
            }
            while (!isAlpha(right))
            {
                end--;
                if (start > end)
                {
                    return (!isAlpha(left));
                }
                right = s.at(end);
            }

            if (makeLower(left) != makeLower(right))
                return false;
            start++;
            end--;
        }
        return true;
    }
    bool isAlpha(char c)
    {
        return (c >= '0' && c <= '9' || c >= 'A' && c <= 'Z' || c >= 'a' && c <= 'z');
    }
    char makeLower(char c)
    {
        if (c >= 'A' && c <= 'Z')
            return c + 32;
        return c;
    }
};
