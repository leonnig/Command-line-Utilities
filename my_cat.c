#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[])
{
    if (argc < 2) {
        printf("Usage: %s <file name>\n", argv[0]);
        return 1;
    }

    for (int i = 1; i < argc; i++) {
        char *file = argv[i];
        int fd = open(file, O_RDONLY);

        if (fd == -1) {
            perror("open");
            continue; // If one of them fail, others can continue
        }

        char buf[BUFFER_SIZE];
        ssize_t bytes_read; // ssize_t is read's return type

        while ((bytes_read = read(fd, buf, BUFFER_SIZE)) > 0) {
            if (write(1, buf, bytes_read) != bytes_read) {
                perror("write error");
                break;
            }
        }

        if (bytes_read == -1) {
            perror("read error");
        }
        close(fd);
    }
    return 0;
}
