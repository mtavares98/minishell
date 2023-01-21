//Split needs to divide the string taking in account:
// spaces/tabs/new lines
// redirections
// quotes
#include <stdio.h>

int	ft_strncmp(char *s1, char *s2, size_t n)
{
    size_t	i;

    if (!s1 || !s2)
        return (-1);
    if (n == 0)
        return (n);
    i = -1;
    while (s1[++i] && s2[i] && s1[i] == s2[i] && i < n)
        ;
    return ((unsigned char)*(s1 + i - (n == i)) - \
	(unsigned char)*(s2 + i - (n == i)));
}

int	ft_isspace(char c)
{
    return ((c > 8 && c < 14) || c == 32);
}
char    *skip_quotes(char *s, char c)
{
    while (*s && *s != c)
        s++;
    return (s);
}

char *check_red(char *s)
{
	int	i, j;

    if (s[1] && (s[0] == '>' && s[1] == '>'))
        s += 2;
    else if (s[1] && (s[0] == '<' && s[1] == '<'))
        s += 2;
    else
		s += 1;
    return(s);
}

static size_t	ft_countword(char *s)
{
    size_t	count;

    if (!*s)
        return (0);
    count = 0;
    while (*s)
    {
        while (ft_isspace(*s))
            s++;
        if (*s)
            count++;
        while ( *s && !ft_isspace(*s))
        {
            if (*s == '"')
                s = skip_quotes(s + 1, '"');
            if (*s == '\'')
                s = skip_quotes(s + 1, '\'');
            if (*s == '<' || *s == '>')
            {
                count++;
				s = check_red(s);
				break ;
			}
            s++;
        }
    }
    return (count);
}

int main (int ac, char **av)
{
    printf("%ld\n", ft_countword(">> hello < again >> here<<now>fs"));
}
