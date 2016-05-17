/*
** gen.h for in /home/baptiste/project/generator_h
**
** Made by
** Login <baptiste@epitech.net>
**
** Started on Mon May 16 10:50:03 2016
** Last update Tue May 17 19:54:33 2016 
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

#define TYPE_F ".c"
#define TYPE_H ".h"

typedef struct s_header
{
char **line;
struct s_header *nxt;
} t_header;

typedef struct s_core
{
char *name_prog;
char **re_write;
char *name_h;
char *name_h_maj;
int nb_write;
t_header *header;
} t_core;

char		*strdup(const char *s);

		/* strtoword.c */

int		 count_words(char *str, char decoup);
int		 wordlen(char *str, char decoup);
char		 *complete_line(char *str, int nb, char decoup);
char		 **small_tab(char *str);
char		 **strtowordtab(char *str, char decoup);

		/* write.c */

int		 write_def_top(t_core *core);
int		 write_def_bottom(t_core *core);

		/* check.c */

int		 check_is_proto(char *str);
int		 check_parenthesis(char *str);
int		 is_no_op(char *str);
int		 check_not_key_word(char *str);
int		 count_tab(char **tab);
int		 last_line_ok(char **tab);
int		 is_a_header_file(char *str);
int		 is_empty_elm2(char *str);
int		 is_exist_already(t_core *core, char *str);

		/* read.c */

int		 read_file(t_core *core, char *file);
int		 read_h(t_core *core, char *file);

		/* doublon.c */

int		 init_all_h(t_core *core);
int		 open_include(t_core *core, DIR **rep);
int		 check_all_h(t_core *core, DIR **rep);
int		 read_to_h(t_core *core, char *name);

		/* init.c */

t_core		 *init_core(char *name, char *h);
int		 add_last(t_header **header, int fd);

		/* str.c */

char		 *format_str(char *str);
char		 *get_name_file(char *name);
char		 **alloc(char **re_write, char *name);
char		 *add_include(char *str);
char		 *header_format(char *name);
void		 majuscule(char *chaine);

		/* get_line.c */


		/* space.c */

char		 *init_str_2(char *str);
char		 *rostring(char *str);
int		delete_line_empty(t_core *core);
int		while_not_clean(t_core *core);

		/* main.c */

int		 main(int ac, char **av);
int		 directory_open(t_core *core, DIR **rep);
int		 display_directory(t_core *core, DIR **rep);

#endif /* GEN_H_ */
