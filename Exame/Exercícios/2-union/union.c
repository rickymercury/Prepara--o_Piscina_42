/*
Assignment name  : union
Expected files   : union.c
Allowed functions: write
--------------------------------------------------------------------------------

Escreva um programa que receba duas strings e exiba, sem duplicatas, os caracteres
 que aparecem em qualquer uma das strings.

A exibição será na ordem em que os caracteres aparecem na linha de comando e será
 seguida por uma nova linha.

Se o número de argumentos não for 2, o programa exibirá uma nova linha.

Example:

$>./union zpadinton "paqefwtdjetyiytjneytjoeyjnejeyj" | cat -e
zpadintoqefwjy$
$>./union ddf6vewg64f gtwthgdwthdwfteewhrtag6h4ffdhsd | cat -e
df6vewg4thras$
$>./union "rien" "cette phrase ne cache rien" | cat -e
rienct phas$
$>./union | cat -e
$
$>
$>./union "rien" | cat -e
$
$>
*/

#include <unistd.h>

void 	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		ft_verif_char(char *str, char *symbol)
{
	while (str < symbol)
	{
		if (*str == *symbol)
			return (0);
		str++;
	}
	return (1);
}

void	ft_union(char **argv)
{
	int string;
	int	symbol;

	string = 0;
	while (string < 2)
	{
		symbol = 0;
		while (argv[string][symbol])
		{
			if (ft_verif_char(argv[0], &argv[string][symbol]))
				ft_putchar(argv[string][symbol]);
			symbol++;
		}
		string++;
	}
}

int		main(int argc, char **argv)
{
	if (argc == 3)
		ft_union(&argv[1]);
	ft_putchar('\n');
	return (0);
}

// ou

#include <unistd.h>

int check2(char *dest, char *str, int j)
{
    int d = 0;
    while(str[d] != '\0')
    {
        if(dest[j] == str[d])
            return 0;
        d++;
    }
    return 1;
}

int check(char *sat, int i)
{
    int c = 0;
    while(c < i)
    {
        if(sat[i] == sat[c])
            return 0;
        c++;
    }
    return 1;
}

void    ft_union(char *str, char *dest)
{
    int i = 0;
    int j;
    while(str[i] != '\0')
    {
       if(check(str,i) == 1)
        {
            write(1, &str[i], 1);
        }
        i++;
    }
    j = 0;
    while(dest[j] != '\0')
    {
        if(check2(dest,str,j) == 1 && check(dest,j) == 1)
            write(1, &dest[j], 1);
        j++;
    }
}

int main(int argc, char **argv)
{
    if(argc == 3)
    {
        ft_union(argv[1],argv[2]);
    }
    write(1, "\n", 1);
}