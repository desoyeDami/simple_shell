#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <signal.h>
#include <stdbool.h>


extern char **environ;
void handle_sig(int sig);
char *display();
char **tokenize(char *line);
void execute(char **tokens, char *shell_name);
char *path(char *cmd);
char *get_path();
void print_env(void);
int str_compare(const char *s1, const char *s2);
char *string_duplicate(const char *s);
char *strn_concat(char *dest, const char *src, size_t n);
char *strn_copy(char *dest, const char *src, size_t n);
int strn_compare(const char *s1, const char *s2, size_t n);
void env_exit(char **tokens);
int ato_int(const char *string);
void _setenv(char **tokens);
void _unsetenv(char **tokens);
ssize_t _getline(char **lineptr, size_t *n, FILE *stream);
void* _memcpy(void* dest, const void* src, size_t n);

#endif
