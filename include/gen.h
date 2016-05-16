/*
** gen.h for  in /home/baptiste/project/generator_h
**
** Made by
** Login   <baptiste@epitech.net>
**
** Started on  Mon May 16 10:50:03 2016
** Last update Mon May 16 11:18:22 2016 
*/

#ifndef GEN_H_
#define GEN_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

#define	TYPE_F ".c"

typedef struct  s_core
{
  char		*name_prog;
}               t_core;

		/* space.c */

char		*rostring(char *str);
char		*init_str_2(char *str);

		/* main.c */

int		directory_open(t_core *core, DIR **rep);
int		display_directory(DIR **rep);

		/* init.c */

t_core          *init_core(char *name);

#endif /* GEN_H_ */
