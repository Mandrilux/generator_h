/*
** check.c for  in /home/baptiste/rendu/marvin_heraud_b
**
** Made by
** Login   <baptiste@epitech.net>
**
** Started on  Fri May 13 22:16:55 2016
** Last update Wed May 18 11:00:15 2016 
*/

#include "gen.h"

int	free_tab(char **tab)
{
  int	i;

  i = -1;
  while (tab[++i] != NULL)
    free(tab[i]);
  free(tab);
  return (1);
}

int	free_two_tab(char **tab1, char **tab2)
{
  free_tab(tab1);
  free_tab(tab2);
  return (1);
}

int	free_all(t_core *core)
{
  t_header	*tmp;

  if (core != NULL)
    {
      if (core->re_write != NULL)
	free_tab(core->re_write);
      /* if (core->name_h != NULL) */
      /* 	free(core->name_h); */
      if (core->name_h_maj != NULL)
	free(core->name_h_maj);
      if (core->header != NULL)
	{
	  tmp = core->header;
	  while (tmp != NULL)
	    {
	      free_tab(tmp->line);
	      tmp = tmp->nxt;
	    }
	}
      free(core);
    }
  return (1);
}
