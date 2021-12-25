#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define max_size 256

int main()
{
    int m = 0;
    char p[max_size];

    FILE *f = fopen("f1.txt", "r");
    
    while(1)
    {
        char s[max_size];
        if (fgets(s, max_size, f) == NULL) break;

        char *c = strchr(s, '\n');
        if (c != NULL) *c = '\0';

        int l = strlen(s);

        if (l > m)
        {
            m = l;
            strcpy(p, s);
        }
        printf("str = %s, len =  %d\n", s, l);
    }

    printf("str_max = %s, len = %d\n", p, m);
    
    fclose(f);

    return 0;
}
