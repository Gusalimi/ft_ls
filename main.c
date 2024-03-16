#include "ft_ls.h"

int main(int argc, char *argv[]) {
    DIR *directory;
    struct dirent *entry;

    // Open the directory
    if (argc < 2) {
        directory = opendir(".");
    } else {
        directory = opendir(argv[1]);
    }

    // Check if directory opened successfully
    if (directory == NULL) {
        perror("opendir");
        exit(EXIT_FAILURE);
    }

    // Read and print directory contents
    while ((entry = readdir(directory)) != NULL) {
        printf("%s : %d\n", entry->d_name, entry->d_type);
    }

    // Close the directory
    closedir(directory);

    return 0;
}
