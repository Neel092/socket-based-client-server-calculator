#include <string.h>
#include "Core/Parser.h"
#include "Core/Calculator.h"

int parse_and_calculate(char str[])
{
    int num1 = 0, num2 = 0;
    char operation = ' ';
    int done = 0;
    int i = 0;
    int len = strlen(str);
    int ans = -1;

    while (i < len)
    {
        char ch = str[i++];

        if (ch == '+' || ch == '*' || ch == '%' || ch == '/' || ch == '-')
        {
            done = 1;
            operation = ch;
        }
        else if (ch >= '0' && ch <= '9')
        {
            if (done == 0)
                num1 = num1 * 10 + (ch - '0');
            else
                num2 = num2 * 10 + (ch - '0');
        }
        else if (ch == '=')
        {
            ans = calculate(num1, num2, operation, NULL);

            num1 = 0;
            num2 = 0;
            operation = ' ';
            done = 0;
        }
    }

    return ans;
}

int Client_Server(char str[])
{
    return parse_and_calculate(str);
}
