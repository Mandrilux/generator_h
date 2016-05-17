/*
** gen.h for in /home/baptiste/project/generator_h
**
** Made by
** Login <baptiste@epitech.net>
**
** Started on Mon May 16 10:50:03 2016
** Last update Tue May 17 14:25:02 2016
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

typedef struct s_core
{
char *name_prog;
char **re_write;
char *name_h;
char *name_h_maj;
int nb_write;
} t_core;

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

		/* read.c */

int		 read_file(t_core *core, char *file);
int		 read_h(t_core *core, char *file);
void		 display_tableau(char **tab);

		/* init.c */

t_core		 *init_core(char *name, char *h);

		/* str.c */

char		 *format_str(char *str);
char		 *get_name_file(char *name);
int		 alloc(t_core *core, char *name);
char		 *add_include(char *str);
char		 *header_format(char *name);
void		 majuscule(char *chaine);

		/* get_line.c */

int		 my_memset_len(char *s, char c, int size, int flag);
char		 *m_realoc(char *s, int fillback, char *buff, int *start);
void		 init(int *nb2, int *nb);
char		 *get_next_line(const int fd);

		/* space.c */

char		 *init_str_2(char *str);
char		 *rostring(char *str);

		/* main.c */

int		 main(int ac, char **av);
int		 directory_open(t_core *core, DIR **rep);
int		 display_directory(t_core *core, DIR **rep);

#endif /* GEN_H_ */
