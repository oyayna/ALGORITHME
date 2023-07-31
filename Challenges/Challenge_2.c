// description
/*
Required
Create a program that asks the user to enter three texts and stores them in three text variables S1, S2 And S3 Then it performs the following:

Tells him whether it was merged S1 with S2 It equals S3 or not.
Tell him if S1 represents part of S2 or equal to it( any S1 == s2).
if the length S1 greater than length S2 Add text S2 on S1 And store the output in a new text variable called S4.
if the length S2 greater than length S1 Add text S1 on S2 And store the output in a new text variable called S4.
Tell him if S2 represents part of the second half in S1.
Shows him the letters in the first half of the S1.
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX_SIZE 1000

void main()
{
    char s1[MAX_SIZE] = "Melio_";
    char s2[MAX_SIZE] = "Meliodas_";
    char s3[MAX_SIZE] = "Melio_Meliodas_";

    int len_S1 = 0;
    while (s1[len_S1] != '\0')
    {
        len_S1++;
    }

    int len_s2 = 0;
    while (s2[len_s2] != '\0')
    {
        len_s2++;
    }

    int len_s3 = 0;
    while (s3[len_s3] != '\0')
    {
        len_s3++;
    }

    char s[MAX_SIZE];
    int count = 0;
    for (int i = 0; i <= len_S1 + len_s2; i++)
    {
        s[i] = s1[i];
        if (s[i] == s1[len_S1])
        {
            s[i] = s2[count];
            count++;
        }
    }

    int ASCII_S;
    int ASCII_S3;
    int check = 0;
    for (int i = 0; i <= len_s3 - 1; i++)
    {
        ASCII_S = s[i];
        ASCII_S3 = s3[i];
        if (ASCII_S == ASCII_S3)
        {
            check++;
        }
    }
    if (check == len_s3)
    {
        printf("The concatenation of S1 and S2 is equal S3? true\n");
    }
    else
    {
        printf("The concatenation of S1 and S2 is equal S3? false\n");
    }

    if (len_S1 == len_s2)
    {
        int checkout = 0;
        for (int i = 0; i <= len_s2 - 1; i++)
        {
            int ASCII_1;
            int ASCII_2;
            ASCII_1 = s1[i];
            ASCII_2 = s2[i];
            if (ASCII_1 == ASCII_2)
            {
                checkout++;
            }
        }
        if (checkout == len_s2)
        {
            printf("S1 is part of S2 or S1=S2? true\n");
        }
        else
        {
            printf("S1 is part of S2 or S1=S2? false\n");
        }
    }
    else
    {
        bool found;
        for (int i = 0; i <= len_s2 - 1; i++)
        {
            int j = 0;
            while (j <= len_S1 - 1)
            {
                if (s2[i + j] != s1[j])
                {
                    found = false;
                    break;
                }
                j++;
                if (j == len_S1 - 1)
                {
                    found = true;
                    break;
                }
            }
            if (found == true)
            {
                break;
            }
        }
        if (found == true)
        {
            printf("S1 is part of S2 or S1=S2? true\n");
        }
        else
        {
            printf("S1 is part of S2 or S1=S2? false\n");
        }
    }

    if (len_S1 > len_s2)
    {
        char s4[MAX_SIZE];
        int count_ = 0;
        for (int i = 0; i <= len_S1 + len_s2; i++)
        {
            s4[i] = s1[i];
            if (s4[i] == s1[len_S1])
            {
                s4[i] = s2[count_];
                count_++;
            }
        }
        printf("%s\n", s4);
    }
    else if (len_S1 < len_s2)
    {
        char s4[MAX_SIZE];
        int count_ = 0;
        for (int i = 0; i <= len_S1 + len_s2; i++)
        {
            s4[i] = s2[i];
            if (s4[i] == s2[len_s2])
            {
                s4[i] = s1[count_];
                count_++;
            }
        }
        printf("%s\n", s4);
    }

    if ((float)len_s2 == (float)len_S1 / 2)
    {
        char s1_1[MAX_SIZE];
        for (int i = 0; i < len_S1; i++)
        {
            s1_1[i] = s1[i];
            if (s1_1[i] == s1[((int)len_S1 / 2)])
            {
                s1_1[((int)len_S1 / 2)] = '\0';
                break;
            }
        }
        char s1_2[MAX_SIZE];
        int count__ = 0;
        for (int i = (int)len_S1 / 2; i <= len_S1; i++)
        {
            s1_2[count__] = s1[i];
            if (s1_2[count__] == s1[len_S1])
            {
                break;
            }
            count__++;
        }

        int len_S1_1 = 0;
        while (s1_1[len_S1_1] != '\0')
        {
            len_S1_1++;
        }

        int len_s1_2 = 0;
        while (s1_2[len_s1_2] != '\0')
        {
            len_s1_2++;
        }

        int ASCII_1;
        int ASCII_2;
        int checkout_1 = 0;
        for (int i = 0; i < len_s2; i++)
        {
            if (len_s2 == len_S1_1)
            {
                ASCII_1 = s1_1[i];
                ASCII_2 = s2[i];
                if (ASCII_1 == ASCII_2)
                {
                    checkout_1++;
                }
            }
        }
        int checkout_2 = 0;
        for (int i = 0; i < len_s2; i++)
        {
            if (len_s2 == len_s1_2)
            {
                ASCII_1 = s1_2[i];
                ASCII_2 = s2[i];
                if (ASCII_1 == ASCII_2)
                {
                    checkout_2++;
                }
            }
        }
        if (checkout_1 == len_s2)
        {
            printf("S2 is part of the second half of S1? true\n");
        }
        else if (checkout_2 == len_s2)
        {
            printf("S2 is part of the second half of S1? true\n");
        }
        else
        {
            printf("S2 is part of the second half of S1? false\n");
        }
    }
    else
    {
        printf("S2 is part of the second half of S1? false\n");
    }

    char s1_1_[MAX_SIZE];
    for (int i = 0; i < len_S1; i++)
    {
        s1_1_[i] = s1[i];
        if (s1_1_[i] == s1[((int)len_S1 / 2)])
        {
            s1_1_[((int)len_S1 / 2)] = '\0';
            break;
        }
    }
    printf("The first half characters of S1 are: %s\n", s1_1_);
}