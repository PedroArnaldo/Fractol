#include "fractol.h"

static int	ft_isspace(char c)
{
	if ((c == '\t'
			|| c == '\v'
			|| c == '\r'
			|| c == '\n'
			|| c == '\f'
			|| c == ' '))
		return (1);
	return (0);
}

double	ft_atod(const char *str)
{
	int	sin;
	double	result;
	int	i;
	int 	is_dot;
	int 	aux;
	
	is_dot = 0;
	i = 0;
	sin = 1;
	while (ft_isspace(str[i]) == 1)
		i++;
	if (str[i] == '-')
	{
		sin = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	result = 0;
	aux = 0;
	while (str[i])
	{
		if(str[i] == '.')
		{
			is_dot = 1;
			i++;
		}
		if (is_dot && str[i] != '0')
			result = result + 0.0 + (str[i] - '0') / pow(10, aux);
		else if (str[i] != '0')
			result = (result * 10) + (str[i] - '0');
		i++;
		aux++;
	}
	return (result * sin);
}
