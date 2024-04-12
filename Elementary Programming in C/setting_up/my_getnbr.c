/*
** EPITECH PROJECT, 2023
** my_getnbr
** File description:
** donnenbr
*/
int minmax(long nbr, int signe)
{
    if (-2147483648 > nbr) {
        return 0;
    }
    if (2147483647 < nbr) {
        return 0;
    }
    return ((int) (nbr * signe));
}

int signe1(char i, int signe)
{
    if (i == '-') {
        signe = signe * -1;
    }
    return signe;
}

int my_getnbr(char *str)
{
    int signe = 1;
    int i = 0;
    long getnbr = 0;
    int signe3 = 1;

    while (str[i] == '-' || str[i] == '+'){
        signe3 = signe1(str[i], signe);
        i++;
    }
    while (str[i] != '\0') {
        if (str[i] >= 48 && str[i] <= 57) {
            getnbr = getnbr * 10;
            getnbr = getnbr + str[i] - 48;
            i = i + 1;
        } else {
            return (getnbr * signe3);
        }
    }
    return minmax(getnbr, signe3);
}
