/**
 * _strlen - returns the length of a string
 * @s: string s
 *
 * Return: length of s
 */
int _strlen(char *s)
{
	int len = 0;
	int i = 0;

	if (s)
	{
		for (i = 0; s[i] != '\0'; i++)
		{
			len++;
		}
	}
	return (len);
}
