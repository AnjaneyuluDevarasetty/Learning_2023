#include<stdio.h>
#include<ctype.h>

void toggleCase(char* str)
{
    while(*str)
    {
        if(isupper(*str))
            *str= tolower(*str);

        else if(islower(*str))
            *str= toupper(*str);
    
        str++;
    }
}

int main() {
    char str[] = "Hello World";
    toggleCase(str);
    printf("%s\n", str);

    char str2[] = "A+B";
    toggleCase(str2);
    printf("%s\n", str2);

    char str3[] = "Prog4u";
    toggleCase(str3);
    printf("%s\n", str3);

    return 0;
}