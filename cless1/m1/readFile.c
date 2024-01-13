#include <stdio.h>
#include <dirent.h>

int main()
{
    DIR *dp;
    struct dirent *fip;
    dp = opendir("/proc");
    while ((fip = readdir(dp)) != NULL)
    {
        printf("name: %s Type: %d, %d\n", fip->d_name, fip->d_type, DT_DIR);
    }
}
