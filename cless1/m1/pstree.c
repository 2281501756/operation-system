#include <stdio.h>
#include <dirent.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

typedef struct pstreeNode
{
    char *name;
    char *pid;
    int tid;
    struct pstreeNode *bro;
    struct pstreeNode *child;
} node;



void trim(char *str)
{
    int start = 0, end = strlen(str) - 1;
    while (isspace(str[start]))
    {
        start++;
    }
    while (end >= start && isspace(str[end]))
    {
        end--;
    }
    for (int i = 0; i <= end - start; i++)
    {
        str[i] = str[start + i];
    }
    str[end - start + 1] = '\0';
}

void readStatusFile(const char *statusfile)
{
    FILE *file = fopen(statusfile, "r");
    if (file == NULL)
    {
        perror("file open");
        exit(1);
    }
    char line[256];
    while (fgets(line, sizeof(line), file) != NULL)
    {
        if (strncmp(line, "Name:", 5) == 0)
        {
            char *name = line + 5;
            trim(name);
            printf("%s\n", name);
        }
        if (strncmp(line, "PPid:", 5) == 0)
        {
            char *ppid = line + 5;
            trim(ppid);
            printf("%s\n", ppid);
        }
    }
    fclose(file);
}

int main()
{
    DIR *dp;
    struct dirent *fip;
    dp = opendir("/proc");
    while ((fip = readdir(dp)) != NULL)
    {
        if (fip->d_type == DT_DIR && isdigit(fip->d_name[0]))
        {
            // printf("name: %s Type: %d\n", fip->d_name, fip->d_type);
            char path[1024];
            sprintf(path, "/proc/%s/status", fip->d_name);
            readStatusFile(path);
        }
    }
}
