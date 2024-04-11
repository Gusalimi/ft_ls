# Allowed functions
1. **write**
   - Prototype: `ssize_t write(int fd, const void *buf, size_t count);`
   - Return: Returns the number of bytes written on success, -1 on error.
   - Description: Writes data from the buffer pointed to by `buf` to the file descriptor `fd`.

2. **opendir**
   - Prototype: `DIR *opendir(const char *name);`
   - Return: Returns a pointer to the directory stream on success, NULL on failure.
   - Description: Opens a directory stream corresponding to the directory name `name`.

3. **readdir**
   - Prototype: `struct dirent *readdir(DIR *dirp);`
   - Return: Returns a pointer to a `dirent` structure representing the next directory entry, or NULL on reaching the end of the directory stream or if an error occurs.
   - Description: Returns a pointer to the next directory entry in the directory stream `dirp`.

4. **closedir**
   - Prototype: `int closedir(DIR *dirp);`
   - Return: Returns 0 on success, -1 on failure.
   - Description: Closes the directory stream associated with `dirp`.

5. **stat**
   - Prototype: `int stat(const char *pathname, struct stat *statbuf);`
   - Return: Returns 0 on success, -1 on failure.
   - Description: Obtains information about the file pointed to by `pathname` and stores it in the structure pointed to by `statbuf`.

6. **lstat**
   - Prototype: `int lstat(const char *pathname, struct stat *statbuf);`
   - Return: Returns 0 on success, -1 on failure.
   - Description: Similar to `stat`, but if `pathname` refers to a symbolic link, it returns information about the link itself rather than the file it refers to.

7. **getpwuid**
   - Prototype: `struct passwd *getpwuid(uid_t uid);`
   - Return: Returns a pointer to a `passwd` structure containing the user information associated with the given user ID, or NULL on failure.
   - Description: Retrieves user information based on the user ID `uid`.

8. **getgrgid**
   - Prototype: `struct group *getgrgid(gid_t gid);`
   - Return: Returns a pointer to a `group` structure containing the group information associated with the given group ID, or NULL on failure.
   - Description: Retrieves group information based on the group ID `gid`.

9. **listxattr**
   - Prototype: `ssize_t listxattr(const char *path, char *list, size_t size);`
   - Return: Returns the number of bytes in the extended attribute list on success, -1 on failure.
   - Description: Lists the extended attributes associated with the file at the given `path`.

10. **getxattr**
    - Prototype: `ssize_t getxattr(const char *path, const char *name, void *value, size_t size);`
    - Return: Returns the size of the extended attribute value on success, -1 on failure.
    - Description: Retrieves the value of the extended attribute with the given `name` associated with the file at the specified `path`.

11. **time**
    - Prototype: `time_t time(time_t *t);`
    - Return: Returns the current calendar time on success, -1 on failure.
    - Description: Retrieves the current calendar time.

12. **ctime**
    - Prototype: `char *ctime(const time_t *timep);`
    - Return: Returns a pointer to a string representing the local time and date, or NULL on failure.
    - Description: Converts the calendar time pointed to by `timep` into a string representing the local time and date.

13. **readlink**
    - Prototype: `ssize_t readlink(const char *pathname, char *buf, size_t bufsiz);`
    - Return: Returns the number of bytes placed in `buf` on success, -1 on failure.
    - Description: Reads the contents of the symbolic link `pathname` into the buffer `buf`.

14. **malloc**
    - Prototype: `void *malloc(size_t size);`
    - Return: Returns a pointer to the allocated memory block on success, or NULL on failure.
    - Description: Allocates a block of memory of size `size` bytes.

15. **free**
    - Prototype: `void free(void *ptr);`
    - Return: No return value.
    - Description: Frees the memory space pointed to by `ptr`, which must have been returned by a previous call to `malloc`, `calloc`, or `realloc`.

16. **perror**
    - Prototype: `void perror(const char *s);`
    - Return: No return value.
    - Description: Prints a descriptive error message to the standard error stream, incorporating the custom message `s`, followed by a colon and a space, and then the textual representation of the current errno value.

17. **strerror**
    - Prototype: `char *strerror(int errnum);`
    - Return: Returns a pointer to the textual representation of the current errno value.
    - Description: Returns a pointer to a string describing the error code `errnum`.

18. **exit**
    - Prototype: `void exit(int status);`
    - Return: Does not return a value. Terminates the calling process.
    - Description: Causes normal process termination and returns the exit status `status` to the parent process.


# TODO
- [ ] Create a fatal error function to free and exit properly
- [ ] Brainstorm needed linked lists and implement corresponding functions (mainly `lstnew` and `lst_addback`)
- [ ] Store entries in a linked list to allow
   - Sorting in reverse (`-r`), by time (`-t`) or both (`-tr`)
   - Getting stats with the function corresponding to the type of file
   - Easier print (first get all data then print)
   - Call ls on directories for `-R`
- [ ] Get full path for `stat`
- [ ] Store stats in `entry` linked list
