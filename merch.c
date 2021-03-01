#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"
#include "string.h"

bool canConvertInt(char *);
bool canConvertFloat(char *);

/**
 * The main function
 * 
 * @author Danylo Liakhovetskyi, AS-193 [ukr: AC-193] (danylo.liakh@gmail.com)
 */
int main(int argc, char **argv)
{
    printf("\n"); //for better outputt
    if (argc < 4 || argc % 3 != 1) //if num of arguments is wrong
    {
        printf(">>>Error: number of arguments is wrong!\n\n");
        return -1; //stop the program
    }

    printf("Products:\n");
    printf("%-16s %-12s %-9s\n", "name", "price", "amount"); //better looking table

    float sumPrice = 0; //summing the overall price of all merchandise

    for (int i = 1; i < argc; i += 3)
    {
        /*Getting the string arguments*/
        char *merchandise = argv[i];
        char *price = argv[i + 1];
        char *amount = argv[i + 2];

        if (canConvertFloat(price) && canConvertInt(amount)) //if can covert without errors (see below)
        {
            /*Converting values*/
            float priceFloat = atof(price);
            int amountInt = atoi(amount);

            printf("%-16s %-12.2f %-9d\n", merchandise, priceFloat, amountInt); //better looking table

            sumPrice += priceFloat * amountInt; //adding the overall price for the current merchandise
        }
        else //if one of the numbers is of a wrong form, terminate the program
        {
            printf(">>>Error: input is of wrong format: -> %s or -> %s\n\n", price, amount);
            return -1;
        }
    }

    printf("\nOverall price: %.2f\n\n", sumPrice); //Show the overall price
    return 0; //return 0 as a sign of a correct exit 
}

/**
 * Checks if it's possible to convert this string to an integer.
 */
bool canConvertInt(char *str)
{
    int length = strlen(str);
    for (int i = 0; i < length; i++)
    {
        char c = str[i];
        if ((c < '0' || c > '9') && c != '-') //if character is not a number and not a minus
        {
            return false;
        }

        if (c == '-' && i != 0) //if the character IS minus, but it's not a first char
        {
            return false;
        }
    }
    return true; //if all characters are good
}

/**
 * Checks if it's possible to convert this string to a float.
 */
bool canConvertFloat(char *str)
{
    int length = strlen(str);
    bool dotFound = false;
    for (int i = 0; i < length; i++)
    {
        char c = str[i];
        if ((c < '0' || c > '9') && c != '-') //if character is not a number and not a minus
        {
            if (c == '.') //if it's first dot then it's ok, if second then return false
            {
                if (dotFound)
                {
                    return false;
                }
                else
                {
                    dotFound = true;
                    continue;
                }
            }
            return false; //if not a dot and not a number or minus, return false
        }

        if (c == '-' && i != 0) //if minus and not at the first position
        {
            return false;
        }
    }
    return true; //if all characters are good
}