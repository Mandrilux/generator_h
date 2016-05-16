/*
** init.c for h in /home/baptiste/project/generator_h
**
** Made by
** Login   <baptiste@epitech.net>
**
** Started on  Mon May 16 11:03:55 2016
** Last update Mon May 16 20:52:30 2016 
*/

#include "gen.h"

t_core		*init_core(char *name, char *h)
{
  t_core	*tmp;

  if ((tmp = malloc(sizeof(t_core) * 1)) == NULL)
    return (NULL);
  tmp->name_h = h;
  tmp->name_prog = name;
  tmp->re_write = NULL;
  return (tmp);
}
