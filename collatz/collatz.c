#include <stdio.h>

int main()
{
    FILE *fp = fopen("D://results.txt", "w");
    for (int i = 0; i < 20000001; i++)
    {
        unsigned long number = i;
        fprintf(fp, "%d: ", number);
        printf("%d\n", number);
        while (number != 1)
        {
            if (number % 2 == 0)
            {
                number /= 2;
                fprintf(fp, "%d ", number);
            }
            else
            {
                number = (number * 3) + 1;
                fprintf(fp, "%d ", number);
            }
        }
        fprintf(fp, "\n");
    }
    fclose(fp);
}