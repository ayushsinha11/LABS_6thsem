// CRC
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char t[120], g[] = "1101";
int N = 5;
// void xor () {
//     for (j = 1; j < N; j++)
//         cs[j] = ((cs[j] == g[j]) ? '0' : '1');
// }

//     void crc()
// {
//     for (i = 0; i < N; i++)
//     {
//         cs[i] = t[i];
//         do
//         {
//             if (cs[0] == '1')
//                 xor();
//             for (j = 0; j < N - 1; j++)
//                 cs[j] = cs[j + 1];
//             cs[j] = t[i++];
//         } while (i <= a + N - 1);
//     }
// }

char *xor1(char a[], char b[])
{
    char *result;
    result = malloc((sizeof(char)) * N + 1);
    for (int i = 0; i < N; i++)
    {
        if (a[i] == b[i])
            result[i] = '0';
        else
            result[i] = '1';
    }
    return result;
}

char *division(char dividend[], char divisor[])
{
    int pick = strlen(divisor);
    char *tmp = malloc(sizeof(char) * N);
    strncpy(tmp, dividend, N);
    int n = strlen(dividend);
    while (pick < n)
    {
        char zeros[pick];
        memset(zeros, '0', pick * sizeof(char));
        char d[2];
        d[1] = '\0';
        if (tmp[0] == '1')
        {
            char *rem = xor1(divisor, tmp);
            d[0] = dividend[pick];
            strcat(rem, d);
            tmp = rem;
        }
        else
        {
            char *rem = xor1(zeros, tmp);
            d[0] = dividend[pick];
            strcat(rem, d);
            tmp = rem;
        }
        pick++;
    }
    char zeros[pick];
    memset(zeros, '0', pick * sizeof(char));
    if (tmp[0] == '1')
        tmp = xor1(divisor, tmp);
    else
        tmp = xor1(zeros, tmp);
    return tmp;
}

int main()
{
    printf("\nEnter the polynomial\t");
    scanf("%s", t);
    printf("\nThe generator polynomial is\t%s", g);
    int a = strlen(t);
    N = strlen(g);
    strcat(t, "000");
    printf("\nAppended: %s", t);
    char *rem = division(t, g);
    printf("\nRemainder: %s", rem);
}