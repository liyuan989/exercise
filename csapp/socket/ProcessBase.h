#ifndef __BLINK_PROCESSBASE_H__
#define __BLINK_PROCESSBASE_H__

#include <sys/types.h>
#include <signal.h>

namespace blink
{

namespace processes
{

pid_t getpid();
pid_t getppid();

pid_t fork();
pid_t waitpid(pid_t pid, int* status, int options);
pid_t wait(int* status);
int execve(const char* filename, char* const argv[], char* const envp[]);

pid_t getpgrp();
int setpgid(pid_t pid, pid_t pgid);

int kill(pid_t pid, int sig);
unsigned int alarm(unsigned int secs);

//typedef void (*sighandler_t)(int);

sighandler_t signal(int signum, sighandler_t handler);
sighandler_t signalRestart(int signum, sighandler_t handler);

//  struct sigaction
//  {
//     void (*sa_handler)(int);                          /* func pointer */
//     void (*sa_sigaction)(int, siginfo_t *, void *);   /* func pointer */
//     sigset_t sa_mask;
//     int sa_flags;
//     void (*sa_restorer)(void);
//  };

//  typedef struct
//  {
//      unsignedlong sig[_NSIG_WORDS];
//
//  } sigset_t;

int sigaction(int signum, struct sigaction* act, struct sigaction* oldact);
int sigprocmask(int how, const sigset_t* set, sigset_t* oldset);
int sigemptyset(sigset_t* set);
int sigfillset(sigset_t* set);
int sigaddset(sigset_t* set, int signumi);
int sigdelset(sigset_t* set, int signum);
int sigismember(const sigset_t* set, int signum);

}  // namespace processes

}  // namespace blink

#endif
