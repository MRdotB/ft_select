# ft_select

_A 42 project._

**bchaleil**

##Documentation
### Termcaps
+ 'cm' String of commands to position the cursor at line l, column c. Both parameters are origin-zero, and are defined relative to the screen, not relative to display memory. All display terminals except a few very obsolete ones support 'cm', so it is acceptable for an application program to refuse to operate on terminals lacking 'cm'.
+ 've' String of commands to return the cursor to normal.
+ 'vi' String of commands to make the cursor invisible.
+ 'te' String of commands to undo what is done by the 'ti' string. Programs that output the 'ti' string on entry should output this string when they exit.
+ 'dl' String of commands to delete the line the cursor is on. The following lines move up, and a blank line appears at the bottom of the screen (or bottom of the scroll region). If the terminal has the 'db' flag, a nonblank line previously pushed off the screen bottom may reappear at the bottom. The cursor must be at the left margin before this command is used. This command does not move the cursor.


### Linux Signals
Signal Name | Number | Description
--- | --- | ---
SIGHUP | 1 | Hangup (POSIX)
SIGINT | 2 | Terminal interrupt (ANSI)
SIGQUIT | 3 | Terminal quit (POSIX)
SIGILL | 4 | Illegal instruction (ANSI)
SIGTRAP | 5 | Trace trap (POSIX)
SIGIOT | 6 | IOT Trap (4.2 BSD)
SIGBUS | 7 | BUS error (4.2 BSD)
SIGFPE | 8 | Floating point exception (ANSI)
SIGKILL | 9 | Kill(can't be caught or ignored) (POSIX)
SIGUSR1 | 10 | User defined signal 1 (POSIX)
SIGSEGV | 11 |Invalid memory segment access (ANSI)
SIGUSR2 | 12 | User defined signal 2 (POSIX)
SIGPIPE | 13 | Write on a pipe with no reader, Broken pipe (POSIX)
SIGALRM | 14 | Alarm clock (POSIX)
SIGTERM | 15 | Termination (ANSI)
SIGSTKFLT | 16 | Stack fault
SIGCHLD | 17 | Child process has stopped or exited, changed (POSIX)
SIGCONT | 18 | Continue executing, if stopped (POSIX)
SIGSTOP | 19 | Stop executing(can't be caught or ignored) (POSIX)
SIGTSTP | 20 | Terminal stop signal (POSIX)
SIGTTIN | 21 | Background process trying to read, from TTY (POSIX)
SIGTTOU | 22 | Background process trying to write, to TTY (POSIX)
SIGURG | 23 | Urgent condition on socket (4.2 BSD)
SIGXCPU | 24 | CPU limit exceeded (4.2 BSD)
SIGXFSZ | 25 | File size limit exceeded (4.2 BSD)
SIGVTALRM | 26 | Virtual alarm clock (4.2 BSD)
SIGPROF | 27 | Profiling alarm clock (4.2 BSD)
SIGWINCH | 28 | Window size change (4.3 BSD, Sun)
SIGIO | 29 | I/O now possible (4.2 BSD)
SIGPWR | 30 | Power failure restart (System V)
