#ifndef MY_SHELL
#define MY_SHELl

#define _GNU_SOURCE
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>
#include <stdarg.h>


extern char **environ;
/**
* struct builtin - builtins
* @b_name: name of the command
* @b_func: pointer to a function
*/
typedef struct builtin
{
	char *b_name;
	int (*b_func)();
} builtin_struct;

int (*handle_builtin(char *user_input))();
int exiting_function(void);
int envy_function(void);
void changes_to_char(char *str);
char *find_paths();
void error_message(char **args);
char **get_path(char *args);
char *_insert_path(char **args, char **path);
char **getenvpath(void);
void free_freely(int n, ...);
int non_interactive_mode(char **av);
int inter_collabo(char **av __attribute__((unused)));
int pearl_used(char *buffer);
char **pars_given(char *buffer, int characters);
int execute_exe(char *command, char **args);
void free_all(char **dptr1, char **dptr2, char *sptr1, char *sptr2);
void logo(void);
int size_comp(char *s1, char *s2, size_t n);
int length_string(char *s);
char *dup_string(char *s);
int comp_str(char *s1, char *s2);
char *str_str(char *dest, char *src);
int buff_bust(char *buffer);
int l_number(int n);
char *int_charac_ter(int num);
char *_strcat(char *dest, char *src);
char *_strdup(char *s);
char *_itoa(int num);
char *string_str(char *x, char *y);
int com_pare(char *x, char *y);
int _strlen(char *s);
int _strcmp(char *s1, char *s2);
int _strncmp(char *s1, char *s2, size_t n);
char *string_copy(char *dest, char *src);

void error_notgood(char **args, char *buffer);
char **args_arguments(char *buffer);
void sim_getline(char *buffer, int len, char **args, char **env_args);
int entered_nty(char **av __attribute__((unused)));
#endif /*MY_SHELL.H*/

