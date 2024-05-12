#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct {
    int first;
    int second;
}pair;

int is_prime(int number_that_is_check)
{
    if (number_that_is_check == 2)
        return 1;
    if (number_that_is_check < 2 || number_that_is_check % 2 == 0)
        return 0;
    for (int divider = 3; divider < number_that_is_check; divider += 2)
        if (number_that_is_check % divider == 0)
            return 0;
    return 1;

}
int read_vector(int *vector)
{
    int size_of_sequence = 0;
    scanf("%d", &size_of_sequence);
    *vector = (int*)malloc(sizeof(int) * size_of_sequence);


    for (int i = 0; i < size_of_sequence; i++)
        scanf("%d", vector + i);
    return size_of_sequence;
}

pair find_longgest_decreasing_contigeous_sequence(int size, int vector[])
{
    int current_left = 0, current_right = 0, max_left = 0, max_right = 0;
    for (int i = 1; i < size; i++)
    {
        if (vector[i] < vector[i - 1])
            current_right++;
        else
        {
            if (current_right - current_left > max_right - max_left)
            {
                max_right = current_right;
                max_left = current_left;
            }
            current_left = current_right = i;
        }
    }
    if (current_right - current_left > max_right - max_left)
    {
        max_right = current_right;
        max_left = current_left;
    }
    pair result;
    result.first = max_left;
    result.second = max_right;
    return result;
}
void print_menu()
{
    printf("Menu:\n");
    printf("\t1. Find the first n pairs \n");
    printf("\t2. Find the longgest decreasing contigues sequance \n");
    printf("\t0. Exit\n");
}

void main()
{
    while (true)
    {
        print_menu();
        int option;
        scanf("%d", &option);

        if (option == 0)
        {
            break;
        }

        switch (option)
        {
        case 1:
        {
            int* vector = malloc(sizeof(int));
            int number;
            int number_of_pairs = 0;
            scanf("%d", &number);
            printf("\n");

            for (int current_number = 3; number_of_pairs < number; current_number+=2)
            {
                if (is_prime(current_number) && is_prime(current_number - 2))
                {
                   
                    printf("%d %d\n", current_number, current_number - 2);
                    number_of_pairs++;
                }
            }

            break;
        }
        case 2:
        {
            int* vector;
            int size_of_sequence = read_vector(vector);


            
            pair result_b = find_longgest_decreasing_contigeous_sequence(size_of_sequence, vector);
            printf("%d, %d\n", result_b.first, result_b.second);
            break;
        }
        default:
            break;
        }
    }
    


    
    
}