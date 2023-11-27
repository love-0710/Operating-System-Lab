#include <stdio.h>
#include <pthread.h>

int current_number = 2; // Start from 2 as the first prime number
int limit = 20;

int isPrime(int num) {
    if (num <= 1) return 0;

    for (int i = 2; i * i <= num; ++i) {
        if (num % i == 0) {
            return 0;
        }
    }

    return 1;
}

void *print_prime(void *args) {
    while (current_number <= limit) {
        if (isPrime(current_number)) {
            printf("Prime: %d\n", current_number);
        }
        current_number++;
    }
    pthread_exit(NULL);
}

int main() {
    pthread_t thread1, thread2;

    pthread_create(&thread1, NULL, print_prime, NULL);
    pthread_create(&thread2, NULL, print_prime, NULL);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

return 0;
}