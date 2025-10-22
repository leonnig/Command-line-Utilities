#include <stdio.h>
#include <dirent.h>

int main() 
{
    DIR *dir;
    const char *path = ".";
    dir = opendir(path);

    struct dirent *dir_entry;
    
    if(!dir) {
        perror("opendir failed");
        return 1;
    }
    
    while ((dir_entry = readdir(dir)) != NULL) {
        printf("%s ",dir_entry->d_name);
    }

    closedir(dir);
    printf("\n");
    return 0;
}

