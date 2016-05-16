/*
** gen.h for  in /home/baptiste/project/generator_h
**
** Made by
** Login   <baptiste@epitech.net>
**
** Started on  Mon May 16 10:50:03 2016
** Last update Mon May 16 20:56:58 2016 
*/

#ifndef GEN_H_
#define GEN_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include "get_next_line.h"

#define	TYPE_F ".c"

typedef struct  s_core
{
  char		*name_prog;
  char		**re_write;
  char		*name_h;
}               t_core;

char		*strdup(const char *s);

		/* space.c */

char		*rostring(char *str);
char		*init_str_2(char *str);

		/* main.c */

int		directory_open(t_core *core, DIR **rep);
int		display_directory(DIR **rep);

		/* init.c */

t_core          *init_core(char *name, char *h);

		/* read.c */

int		read_file(char *file);
int		read_h(t_core *core, char *file);

		/* check.c */

int		check_is_proto(char *str);
int		check_parenthesis(char *str);
int		is_no_op(char *str);
int		check_not_key_word(char *str);
int		count_tab(char **tab);
int		last_line_ok(char **tab);

		/* str.c */

char		*format_str(char *str);
char		*get_name_file(char *name);
int		alloc(t_core *core, char *name);
char		*add_include(char *str);

		/* strtoword.c */

int		count_words(char *str, char decoup);
int		wordlen(char *str, char decoup);
char		*complete_line(char *str, int nb, char decoup);
char		**small_tab(char *str);
char		**strtowordtab(char *str, char decoup);

#endif /* GEN_H_ */
