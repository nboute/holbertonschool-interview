/**
 * is_palindrome - checks whether or not a given number is a palindrome.
 * @n: unsigned long integer to be checked
 * Return: 1 if n is a palindrome, and 0 otherwise
*/
int is_palindrome(unsigned long n)
{
	unsigned long reversed = 0;
	unsigned long original = n;

	while (n > 0)
	{
		reversed = reversed * 10 + n % 10;
		n /= 10;
	}

	return (original == reversed);
}
