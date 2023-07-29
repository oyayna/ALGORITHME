#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 1000
void ReplaceAll(char string[MAX_SIZE], char str[MAX_SIZE], char str_replace[MAX_SIZE]);
int main()
{
    char First_Text[MAX_SIZE] = "I like cats. I have one cat.";
    char Second_Text[MAX_SIZE] = "cat";
    char Third_Text[MAX_SIZE] = "dog";
    ReplaceAll(First_Text, Second_Text, Third_Text);
}
void ReplaceAll(char string[MAX_SIZE], char str[MAX_SIZE], char str_replace[MAX_SIZE])
{
    int len_string = 0;
    while (string[len_string] != 0)
    {
        len_string++;
    }
    int len_str = 0;
    while (str[len_str] != 0)
    {
        len_str++;
    }
    int len_str_replace = 0;
    while (str_replace[len_str_replace] != 0)
    {
        len_str_replace++;
    }
    if (len_str == len_str_replace)
    {
        for (int i = 0; i <= len_string - 1; i++)
        {
            for (int j = 0; j <= len_str - 1; j++)
            {
                if (string[i + j] != str[j])
                {
                    break;
                }
                if (j == len_str - 1)
                {
                    for (int p = 0; p <= len_str_replace - 1; p++)
                    {
                        for (int s = 0; s <= 1; s++)
                        {
                            int ASCII_VALUE;
                            ASCII_VALUE = str_replace[s + p];
                            string[i + p] = ASCII_VALUE;
                            ASCII_VALUE = 0;
                            break;
                        }
                    }
                }
            }
        }
        printf("%s\n", string);
    }
    else if (len_str > len_str_replace)
    {
        for (int i = 0; i <= len_string - 1; i++)
        {
            for (int j = 0; j <= len_str - 1; j++)
            {
                if (string[i + j] != str[j])
                {
                    break;
                }
                if (j == len_str - 1)
                {
                    int p = 0;
                    while (p <= len_str_replace - 1)
                    {
                        for (int s = 0; s <= 1; s++)
                        {
                            int ASCII_VALUE;
                            ASCII_VALUE = str_replace[s + p];
                            string[i + p] = ASCII_VALUE;
                            break;
                        }
                        p++;
                    }
                    int w = 0;
                    while (w <= len_str - len_str_replace - 1)
                    {
                        string[i + p + w] = 127;
                        w++;
                    }
                }
            }
        }
        printf("%s\n", string);
    }
    else
    {
        char *TexT = (char *)malloc(len_string + MAX_SIZE);
        for (int i = 0; i < len_string; i++)
        {
            *(TexT + i) = string[i];
        }
        int len_TexT = 0;
        while (TexT[len_TexT] != 0)
        {
            len_TexT++;
        }
        for (int i = 0; i <= len_TexT - 1; i++)
        {
            for (int j = 0; j <= len_str - 1; j++)
            {
                if (TexT[i + j] != str[j])
                {
                    break;
                }
                if (j == len_str - 1)
                {
                    for (int n = 0; n < 2; n++)
                    {
                        TexT[len_TexT + n] = '\0';
                    }
                    int p = 0;
                    while (p <= len_str_replace - 1)
                    {
                        for (int s = 0; s <= 1; s++)
                        {
                            if (p >= len_str)
                            {
                                int v;
                                int q = 1;
                                for (int b = len_TexT; b >= 0; b--)
                                {
                                    v = TexT[b];
                                    TexT[b] = TexT[len_TexT - q];
                                    TexT[len_TexT - q] = v;
                                    q++;
                                    if (string[len_string] == TexT[i + p])
                                    {
                                        len_TexT++;
                                        break;
                                    }
                                }
                            }
                            int ASCII_VALUE;
                            ASCII_VALUE = str_replace[s + p];
                            TexT[i + p] = ASCII_VALUE;
                            ASCII_VALUE = 0;
                            break;
                        }
                        p++;
                    }
                }
            }
        }
        printf("%s\n", TexT);
        free(TexT);
    }
}