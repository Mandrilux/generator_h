/*
** get_line.c for  in /home/baptiste/project/generator_h
**
** Made by
** Login   <baptiste@epitech.net>
**
** Started on  Mon May 16 11:29:12 2016
** Last update Mon May 16 11:33:41 2016 
*/

#include "gen.h"

int		my_memset_len(char *s, char c, int size, int flag)
{
  int		i;

  if (flag == 1)
    {
      i  = 0;
      while (i < size)
	s[i++] = c;
      return (0);
    }
  else if (flag == 0)
    {
      (void) c;
      (void) size;
      i = 0;
      while (s != NULL && s[i] != '\0')
	i++;
      return (i);
    }
  return (0);
}

char		*m_realoc(char *s, int fillback, char *buff, int *start)
{
  char		*line;
  int		old_len;

  old_len = 0;
  s != 0 ? (old_len = my_memset_len(s, '\n', 1, 0)) : (old_len = 0);
  line = malloc((old_len + fillback + 1) * sizeof(char));
  if (line == NULL)
    return (NULL);
  my_memset_len(line, '\0', old_len + fillback + 1, 1);
  s != 0 ? strncpy(line, s, old_len) : strncpy(line, "", old_len);
  line[old_len + fillback] = '\0';
  strncpy(line + old_len, buff + start[0], fillback);
  start[0] = start[0] + fillback + 1;
   return (line);
}

void		init(int *nb2, int *nb)
{
  *nb = 0;
  *nb2 = 0;
}

char		*get_next_line(const int fd)
{
  static char   buff[READ_SIZE];
  static int    n = 0;
  static int    start;
  int           back;
  char          *s;

  s = NULL;
  if (fd == -1)
    return (NULL);
  back = 0;
  while (1)
    {
      if (n <= start)
	{
	  init(&start, &back);
	  if (!(n = read(fd, buff, READ_SIZE)))
	    return (s);
       	  if (n == -1)
	    return (NULL);
	}
      if (buff[start + back] == '\n')
      	return (s = m_realoc(s, back, buff, &start));
      start + back == n - 1 ? s = m_realoc(s, back + 1, buff, &start) : NULL;
      back++;
    }
}
