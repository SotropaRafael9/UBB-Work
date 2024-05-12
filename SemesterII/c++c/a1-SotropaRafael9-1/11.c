#include <stdio.h>

int is_prime(int number_that_is_check)
{
    int ok = 1;
    if (number_that_is_check <= 2 && number_that_is_check % 2 == 0)
        ok = 0;
    for (int divider = 3; divider <= number_that_is_check; divider+=2)
        if (number_that_is_check % divider)
            ok = 0;
    return ok;
    
}

int pair_of_twin_numbers(int first_number_that_is_check, int secound_number_that_is_check)
{
    if(is_prime(first_number_that_is_check) != 0 && is_prime(secound_number_that_is_check) != 0)
        if (first_number_that_is_check - secound_number_that_is_check == 2)
            return 1;
    return 0;

}

int main()
{
    int vector[99] = {5,3,8,4,1};
    int number =2;
    for(int i = 0;i < len(vector)-1;i++)
        for(int j =i+1;j< len(vector);j++)
            if (pair_of_twin_numbers(vector[i],vector[j])==0)
            {
                printf("%d", &vector);
                break;
            }
        
    

            

    


    
    return 0;
}