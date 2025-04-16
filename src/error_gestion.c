/*
** EPITECH PROJECT, 2024
** B-MUL-100-LYN-1-1-myradar-leonard.leroy
** File description:
** error_gestion.c
*/

#include "my_radar.h"

int write_error(int error_code)
{
    int iError = 84;

    switch (error_code) {
        case NO_ERROR:
            iError = 0;
            break;
        case ERROR_BAD_ARGUMENT:
            break;
        case ERROR_TEXTURE:
            write(2, "Error texture\n", 15);
            break;
        case ERROR_WINDOW:
            write(2, "Error window\n", 14);
            break;
        default:
            iError = write_error_2(error_code);
            break;
    }
    return (iError);
}

int write_error_2(int error_code)
{
    int iError = 84;

    switch (error_code) {
        case 1:
            iError = 0;
            break;
        case ERROR_BACKGROUND:
            write(2, "Error background\n", 18);
            break;
        case ERROR_AIRCRAFT:
            write(2, "Error aircraft\n", 16);
            break;
        case ERROR_TOWER:
            write(2, "Error tower\n", 13);
            break;
        default:
            iError = write_error_3(error_code);
            break;
    }
    return (iError);
}

int write_error_3(int error_code)
{
    int iError = 84;

    switch (error_code) {
        case ERROR_FILE:
            write(2, "Error file\n", 12);
            break;
        case ERROR_SECTION:
            write(2, "Error section\n", 15);
            break;
        default:
            write(2, "Unknown error\n", 15);
            break;
    }
    return (iError);
}
