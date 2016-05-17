		/* strtoword.c */

int		 count_words(char *str, char decoup);
int		 wordlen(char *str, char decoup);
char		 *complete_line(char *str, int nb, char decoup);
char		 **small_tab(char *str);
char		 **strtowordtab(char *str, char decoup);

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

char		 *get_name_file(char *name);
int		 alloc(t_core *core, char *name);
char		 *add_include(char *str);

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

