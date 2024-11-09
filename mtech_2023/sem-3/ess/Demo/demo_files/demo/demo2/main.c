#include <stdio.h>
#include <unistd.h>

int main()
{
    char buf[20];
    int a = 21, b  = 21, c;
    printf("This program ONLY adds 21 to itself\n");
    printf("21 + 21 = ");
    c = a + b;
    printf("%d\n", c);
    printf("Anything to say?\n");
    scanf("%s", buf);
    return 0;
}
