



char ft_findchar(char *str, char target)
{
	while (*str && *str != target)
		str++;
	return (*str);
}