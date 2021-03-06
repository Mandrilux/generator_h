/*
** main.c for  in /home/baptiste/project/generator_h
**
** Made by
** Login   <baptiste@epitech.net>
**
** Started on  Mon May 16 10:48:51 2016
** Last update Sun Mar  5 08:49:55 2017 
*/

#include "gen.h"

int		main(int ac, char **av)
{
  DIR		*rep;
  t_core	*core;
  char		*tmp;

  if (ac == 1)
    tmp = strdup(NAME_DEFAULT);
  else
    tmp = av[1];
  if (is_a_header_file(tmp) == -1)
    return (printf("Error : this file is not header file\n"));
  if ((tmp = add_include(tmp)) == NULL)
    return (printf("Error : R.A.M was attacked !\n"));
  if ((core = init_core(av[0], tmp)) == NULL)
    return (printf("Error : R.A.M was attacked !\n"));
  init_all_h(core);
  if (read_h(core, core->name_h) == -1)
    return (EXIT_FAILURE);
  write_def_top(core);
  if (directory_open(core, &rep) == -1)
    return (EXIT_FAILURE);
  display_directory(core, &rep);
  write_def_bottom(core);
  printf("[+] Generation %s successful\n", core->name_h);
  free_all(core);
  return (EXIT_SUCCESS);
}

int		directory_open(t_core *core, DIR **rep)
{
  *rep = opendir(".");
  if (*rep == NULL)
    {
      perror(core->name_prog);
      return (-1);
    }
  else
    return (1);
}

int    display_directory(t_core *core, DIR **rep)
{
  struct dirent *ent;

  if (*rep != NULL)
    {
      while ((ent = readdir(*rep)) != NULL)
	{
	  if (strlen(ent->d_name) > 2)
	    {
	      if (strcmp(&(ent->d_name[strlen(ent->d_name) - 2]), TYPE_F) == 0)
		read_file(core, ent->d_name);
	    }
	}
      closedir(*rep);
    }
  return (1);
}
