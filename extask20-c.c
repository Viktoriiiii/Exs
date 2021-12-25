#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define max_size 256

int main()
{
    int m = 0;
    char p[max_size];

    FILE *f1 = fopen("f1.txt", "r");
    FILE *f2 = fopen("f2.txt", "w+");

    while (1)
    {
        char s[max_size];
        if (fgets(s, max_size, f1) == NULL) break;        
        
        char *c = strchr(s, '\n');
        if (c != NULL) *c = '\0';
        
        int l_max = strlen(s);
        if (l_max > m)
        {
            m = l_max;
            strcpy(p, s);
        }
        printf("%s %d\n", s, l_max);
    }    
    printf("str_max = %s, len = %d\n", p, m);    
    fclose(f1);

    char ast = '*';
    char per = '\n';

    FILE *f3 = fopen("f1.txt", "r");
    while (1)
    {
        char s[max_size];
        if (fgets(s, max_size, f3) == NULL) break;        
        
        char *c = strchr(s, '\n');
        if (c != NULL) *c = '\0';
        
        int l = strlen(s);
        if (l < m)
        {                
            int dif = m - l;
            fprintf(f2, "%s", s);
            while(dif > 0)
            {
                fprintf(f2, "%c", ast);
                dif--;
            }
            fprintf(f2, "%c", per);
        }
        else fprintf(f2, "%s\n", s);
    }        

    fclose(f3);
    fclose(f2);

    return 0;
}
