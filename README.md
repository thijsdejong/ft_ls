# ft_ls
As simple as listing the files in a directory.

https://www.gnu.org/software/libc/manual/html_node/Testing-File-Type.html

https://github.com/agavrel/42-ft_ls/blob/master/srcs/add_new_file.c

##Bonus

Handles the following options:
	-S sorts by size

##Notes

- Options to implement (5)
	-l, -R, -a, -r and -t

- When an illegal option is detected output the following error:
	```
	ls: illegal option -- FIRST INVALID OPTION
	usage: ls [-ABCFGHLOPRSTUWabcdefghiklmnopqrstuwx1] [file ...]
	```
- Loop detection
	When there is a loop when using symbolic links it might run forever

##Allowed functions
- write
	`write() attempts to write nbyte of data to the object referenced by the
     descriptor fildes from the buffer pointed to by buf.`
- opendir
	`The opendir() function opens the directory named by filename, associates
    a directory stream with it and returns a pointer to be used to identify
    the directory stream in subsequent operations.`
- readdir
	`The readdir() function returns a pointer to the next directory entry.  It
	returns NULL upon reaching the end of the directory or on error.  In the
	event of an error, errno may be set to any of the values documented for
	the getdirentries(2) system call.`
- closedir
	`The closedir() function closes the named directory stream and frees the
	structure associated with the dirp pointer, returning 0 on success.  On
	failure, -1 is returned and the global variable errno is set to indicate
	the error.`
- stat
	`The stat() function obtains information about the file pointed to by
	path.  Read, write or execute permission of the named file is not
	required, but all directories listed in the path name leading to the file
	must be searchable.`
- lstat
	`The lstat() function is like stat() except in the case where the named
	file is a symbolic link; lstat() returns information about the link,
	while stat() returns information about the file the link references.  For
	symbolic links, the st_mode member contains meaningful information when
	used with the file type macros, and the st_size member contains the
	length of the pathname contained in the symbolic link. File mode bits and
	the contents of the remaining members of the stat structure are unspeci-
	fied. The value returned in the st_size member is the length of the con-
	tents of the symbolic link, and does not count any trailing null.`
- getpwuid (user id) and getgrgid (group id)
	`The functions getpwnam(), getpwuid(), and getpwuuid() search the password data-
	base for the given login name, user uid, or user uuid respectively, always
	returning the first one encountered.`
- listxattr
	`listxattr() retrieves a list of names of extended attributes associated with the
	given path in the file system.`
- getxattr
	`The getxattr() function retrieves up to size bytes of data from the extended
	attribute identified by name associated with path into the pre-allocated buffer
	pointed to by value.  The function returns the number of bytes of data
	retrieved.`
- time
	`The time() function returns the value of time in seconds since 0 hours, 0 min-
	utes, 0 seconds, January 1, 1970, Coordinated Universal Time, without including
	leap seconds.  If an error occurs, time() returns the value (time_t)-1.`
- ctime
	`The ctime() function adjusts the time value for the current time zone, in the
	same manner as localtime().  It returns a pointer to a 26-character string of
	the form: Thu Nov 24 18:22:48 1986\n\0`
- readlink
	`readlink() places the contents of the symbolic link path in the buffer buf,
	which has size bufsize.  Readlink does not append a NUL character to buf.`
- malloc
	`The malloc() function allocates size bytes of memory and returns a pointer to
    the allocated memory.`
- free
	`The free() function deallocates the memory allocation pointed to by ptr. If ptr
    is a NULL pointer, no operation is performed.`
- perror
	`The perror() function finds the error message corresponding to the current value
	of the global variable errno (intro(2)) and writes it, followed by a newline, to
	the standard error file descriptor.  If the argument s is non-NULL and does not
	point to the null character, this string is prepended to the message string and
	separated from it by a colon and space (``: ''); otherwise, only the error mes-
	sage string is printed.`
- strerror
	`The strerror() function accepts an error number argument errnum and returns a
    pointer to the corresponding message string.`
- exit
	```The exit() and _Exit() functions terminate a process.

     Before termination, exit() performs the following functions in the order listed:

           1.   Call the functions registered with the atexit(3) function, in the
                reverse order of their registration.

           2.   Flush all open output streams.

           3.   Close all open streams.

           4.   Unlink all files created with the tmpfile(3) function.```
