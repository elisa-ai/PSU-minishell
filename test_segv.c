int main(void)
{
    char *str = 0;
    str[0] = 'X'; // Tentative d'écriture sur l'adresse NULL -> SEGV
    return 0;
}
