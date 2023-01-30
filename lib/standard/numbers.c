/*
** EPITECH PROJECT, 2023
** pui_print
** File description:
** print either an int or a float
*/

void put_char(char a);

void put_nbr(int number)
{
    if (number < 0)
        put_char('-'), number *= -1;
    if (number < 10 && number > -1) {
        put_char((number) + '0');
        return;
    }
    if (number)
        put_nbr((number / 10)), put_char((number %= 10) + '0');
}

void put_float(float number, int decimals)
{
    int times = 0;

    put_nbr((int)number);
    put_char('.');
    while (times < decimals) {
        number -= (int)number;
        number *= 10;
        put_char((int)number + '0');
        times++;
    }
}
