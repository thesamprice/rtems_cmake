#define MAX_NAME_SIZE (64)
#include <stdio.h>
#include <stdint.h>

void temp_from_file(const char* filename, int32_t* temp, int* status)
{
    char buf[MAX_NAME_SIZE];
    char* s;
    int i;
    FILE* fp = fopen(filename, "r");
    if (!fp)
    {
        *status = -1;
        return;
    }
    s = fgets(buf, MAX_NAME_SIZE, fp);
    fclose(fp);
    if (!s)
    {
        *status = -2;
        return;
    }
    for (i = 0; (*s) && (i < MAX_NAME_SIZE); i++)
    {
        if (*s == '\n')
        *s = 0;
        s++;
    }
    
    sscanf(buf, "%d", temp);
}