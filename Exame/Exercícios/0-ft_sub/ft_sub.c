/*
create a function that subtracts an integer from an integer pointed by a pointer.the parameters are an integer and a pointer pointing to an integer.

it should be prototyped as such

void    ft_subtract(int a, int *ptr)

*/

void    ft_subtract(int a, int *ptr)
{
    *ptr -= a;
}