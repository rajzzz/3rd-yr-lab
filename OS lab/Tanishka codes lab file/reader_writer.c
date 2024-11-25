#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

pthread_mutex_t x = PTHREAD_MUTEX_INITIALIZER;  // Mutex for reader counter
pthread_mutex_t y = PTHREAD_MUTEX_INITIALIZER;  // Mutex for writer
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;

int readercount = 0;  // Count of readers
int writercount = 0;  // Count of writers (for illustration)

void *reader(void *param) {
    int reader_id = *((int *)param);

    // Reader wants to enter
    pthread_mutex_lock(&x);
    readercount++;
    if (readercount == 1) {
        pthread_mutex_lock(&y);  // First reader locks writer access
    }
    pthread_mutex_unlock(&x);

    // Reading section
    printf("Reader %d is reading data\n", reader_id);
    usleep(100000);  // Simulate reading time
    printf("Reader %d is done reading\n", reader_id);

    // Reader is leaving
    pthread_mutex_lock(&x);
    readercount--;
    printf("Reader %d is leaving. Remaining readers: %d\n", reader_id, readercount);
    if (readercount == 0) {
        pthread_mutex_unlock(&y);  // Last reader unlocks writer access
    }
    pthread_mutex_unlock(&x);

    return NULL;
}

void *writer(void *param) {
    int writer_id = *((int *)param);

    printf("Writer %d is trying to enter\n", writer_id);
    pthread_mutex_lock(&y);  // Lock access to writers
    printf("Writer %d is writing data\n", writer_id);
    usleep(200000);  // Simulate writing time
    printf("Writer %d is done writing\n", writer_id);
    pthread_mutex_unlock(&y);

    return NULL;
}

int main() {
    int n2, i;
    printf("Enter the number of readers and writers: ");
    scanf("%d", &n2);
    printf("\n");

    pthread_t readerthreads[n2], writerthreads[n2];
    int reader_ids[n2], writer_ids[n2];

    // Create reader and writer threads
    for (i = 0; i < n2; i++) {
        reader_ids[i] = i + 1;
        writer_ids[i] = i + 1;
        pthread_create(&readerthreads[i], NULL, reader, &reader_ids[i]);
        pthread_create(&writerthreads[i], NULL, writer, &writer_ids[i]);
    }

    // Wait for all threads to finish
    for (i = 0; i < n2; i++) {
        pthread_join(readerthreads[i], NULL);
        pthread_join(writerthreads[i], NULL);
    }

    pthread_mutex_destroy(&x);
    pthread_mutex_destroy(&y);

    return 0;
}
