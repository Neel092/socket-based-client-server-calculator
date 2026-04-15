#include "io/Input.h"

int main(int argc, char *argv[])
{
    int n1 = 0, n2 = 0;
    char operator = ' ';
    int result = 0;

    CheckInput(&n1, &n2, &operator, &result, argc, argv);
    return 0;
}
