#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <stdio.h>

void call_test(void (*test_func)(), const char *msg) {
  pid_t pid = fork();
  if (pid == 0) {
    test_func();
    exit(0);
  } else {
    int status;
    waitpid(pid, &status, 0);
    if (WIFSIGNALED(status)) {
      printf("%s crashed with signal %d\n", msg, WTERMSIG(status));
    } else {
      printf("%s passed\n", msg);
    }
  }
}
