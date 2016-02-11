#include <iostream>

int mAtoi(char *str)
{
    int result = 0;
    
    for (int i = 0; str[i] != '\0'; ++i)
    {
        result = result*10 + str[i] - '0';
    }
    
    return result;
}

int main(int argc, char **argv)
{
    char str[] = "6776767";
    int res = mAtoi(str);
    std::cout << res << std::endl;
    
    return 0;
}
