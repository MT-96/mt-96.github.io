#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <time.h>

int main() {
    char *filePath = "example2.json"; // File path
    int fd = open(filePath, O_RDONLY); // Open file in read-only mode
    if (fd == -1) {
        perror("Error opening file");
        return 1;
    }

    struct stat fileStat;
    if (fstat(fd, &fileStat) == -1) {
        perror("Error getting file stats");
        close(fd);
        return 1;
    }

    size_t fileSize = fileStat.st_size; // Get file size
    printf("%ld ddd\n",fileSize);
    if (fileSize == 0) {
        printf("File is empty.\n");
        close(fd);
        return 0;
    }

    // Memory-map the file
    char *mappedFile = mmap(NULL, fileSize, PROT_READ, MAP_PRIVATE, fd, 0);
    if (mappedFile == MAP_FAILED) {
        perror("Error mapping file");
        close(fd);
        return 1;
    }

    close(fd); // File descriptor no longer needed after mmap

    clock_t start = clock(); // Start the clock for benchmarking

    // Process the file
    size_t totalBytesRead = 0;
    size_t chunkSize = 50240; // Processing chunk size
    size_t chunkCount = 0;

    for (size_t i = 0; i < fileSize; i += chunkSize) {
        size_t bytesToProcess = (i + chunkSize <= fileSize) ? chunkSize : fileSize - i;
        // Process the chunk
        totalBytesRead += bytesToProcess;
        chunkCount++;
    }

    clock_t end = clock(); // End the clock for benchmarking

    // Clean up
    if (munmap(mappedFile, fileSize) == -1) {
        perror("Error unmapping file");
        return 1;
    }

    // Print benchmark results
    double timeTaken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Number of chunks: %zu\n", chunkCount);
    printf("Total bytes read: %zu\n", totalBytesRead);
    printf("Time taken: %.6f seconds\n", timeTaken);

    return 0;
}
