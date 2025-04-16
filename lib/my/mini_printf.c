/*
** EPITECH PROJECT, 2024
** B-MUL-100-LYN-1-1-myradar-leonard.leroy
** File description:
** mini_printf.c
*/

#include <stdarg.h>
#include <unistd.h>

int write_character(char character)
{
    write(1, &character, 1);
    return (1);
}

int write_integer(int number)
{
    int iNbCar = 0;
    long nbr = number;

    if (nbr < 0) {
        write_character('-');
        iNbCar++;
        nbr *= -1;
    }
    if (nbr > 9) {
        iNbCar += write_integer(nbr / 10);
    }
    write_character(nbr % 10 + '0');
    iNbCar++;
    return (iNbCar);
}

int write_string(char *string)
{
    int nbr = 0;

    while (string[nbr] != '\0') {
        write_character(string[nbr]);
        nbr++;
    }
    return (nbr);
}

int process_format_specifier(const char *format_specifier, va_list arguments)
{
    int count_character = 0;

    switch (*format_specifier) {
        case 's':
            count_character += write_string(va_arg(arguments, char *));
            break;
        case 'd':
        case 'i':
            count_character += write_integer(va_arg(arguments, int));
            break;
        case 'c':
            count_character += write_character(va_arg(arguments, int));
            break;
        case '%':
            count_character += write(1, "%", 1);
            break;
        default:
            return (-1);
    }
    return (count_character);
}

int mini_printf(const char *format_string, ...)
{
    va_list arguments;
    int count_total_character = 0;

    va_start(arguments, format_string);
    while (*format_string) {
        if ((*format_string == '%') && (*(format_string + 1))) {
            format_string++;
            count_total_character = count_total_character
                + process_format_specifier(format_string, arguments);
        } else {
            write(1, format_string, 1);
            count_total_character++;
        }
        format_string++;
    }
    va_end(arguments);
    if (count_total_character == -1) {
        write(2, "Invvalid parameter", 19);
    }
    return (count_total_character);
}
