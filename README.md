# ft_ls
As simple as listing the files in a directory.

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
- getpwuid
- getgrgid
- listxattr
- getxattr
- time
- ctime
- readlink
- malloc
- free
- perror
- strerror
- exit
