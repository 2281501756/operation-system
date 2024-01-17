#include "thread.c"

pthread_mutex_t gMutex = PTHREAD_MUTEX_INITIALIZER;

int n, count = 0;

void Tproduce() {
    printf("2");
    while(1) {
retry:
        pthread_mutex_lock(&gMutex);
        if (count == n) {
            pthread_mutex_unlock(&gMutex); 
            goto retry;
        }
        count++;
        printf("(");
        pthread_mutex_unlock(&gMutex); 
    }
}

void TConsume() {
    printf("3");
    while (1)
    {
retry:
        pthread_mutex_lock(&gMutex);
        if (count == 0) {
            pthread_mutex_unlock(&gMutex); 
            goto retry;
        }
         count--;
        printf(")");
        pthread_mutex_unlock(&gMutex); 
    }
}

int main(int argc, char *argv[]) {
    n = atoi(argv[1]);
    for (int i = 0; i < 8; i ++) {
        create(TConsume);
        create(Tproduce);
    }
}
