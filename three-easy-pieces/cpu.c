#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <assert.h>
#include "common.h"

int main(int argc, char *argv[]) {
    char *str = argv[1];
    while(1) {
        Spin(1);
        printf("%s\n", str);
    }
    return 0;
}