/*
** init.c for h in /home/baptiste/project/generator_h
**
** Made by
** Login   <baptiste@epitech.net>
**
** Started on  Mon May 16 11:03:55 2016
** Last update Mon May 16 11:08:07 2016 
*/

#include "gen.h"

t_core		*init_core(char *name)
{
  t_core	*tmp;

  if ((tmp = malloc(sizeof(t_core) * 1)) == NULL)
    return (NULL);
  tmp->name_prog = name;
  return (tmp);
}
