#include <stdio.h>
#include <assert.h>
#include <conio.h>

int main()
{
    /* Define an expression */
    int exp = 1;

    /* Display the value of exp */
    printf("Exp is %d\n", exp);

    /* Assert should not exit in this case since exp is not 0  */
    assert(exp);

    /* Change expression to 0 */
    exp = 0;

    /* Display the value of exp */
    printf("Exp is %d\n", exp);

    /* In this case exp is 0 so assert will display an error and exit */
    assert(exp);
    getch();
    return 0;
}
