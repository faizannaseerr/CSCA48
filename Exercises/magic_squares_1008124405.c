////////////////////////////////////////////////
// CSC A48 - Winter 2022
//
// Exercise 5 - Solving Magic Squares
//
// (c) 2022 F. Estrada
////////////////////////////////////////////////
#include<stdio.h>
#include<stdlib.h>

// helper:

int find_required_sum_of_columns_and_rows(int square[6][6])
{
    int i;
    int j;
    int needed_sum_column;
    int count_column;
    int needed_sum_row;
    int count_row;
    for (i = 0; i < 6; i++){
        needed_sum_column = 0;
        count_column = 0;
        needed_sum_row = 0;
        count_row = 0;
        for (j = 0; j < 6; j++){
            if (square[i][j] != -1){
                count_row += 1;
                needed_sum_row = needed_sum_row + square[i][j];
            }
            if (square[j][i] != -1){
                count_column += 1;
                needed_sum_column = needed_sum_column + square[j][i];
            }
        }
        if (count_column == 6){
            return needed_sum_column;
        }
        if (count_row == 6){
            return needed_sum_row;
        }
    }
    return 1;
}

void solveMagicSquare(int square[6][6])
{
 // This function receives an array of size 6x6
 // that corresponds to a magic square.
 // It then finds any entries with value -1
 // (which means they are not known),
 // and figures out what their value should
 // be to solve the magic square.
 //
 // Conditions:
 // You can not hard-code the value of the rows
 // and columns in the magic square - because
 // we will test this with a *different* magic
 // square than the one in this starter code
 //
 // Your function has to (somehow) figure out
 // what the sum of the rows and columns should be,
 // and then figure out for each entry whose
 // value is -1, what its value is to correctly
 // complete the magic square.
 //
 // This is about problem solving - you don't
 // need any fancy pointer management or anything
 // like that. Just plain old C with a 2D array
 // and a bit of thinking.
 //
 // As a reminder. 2D arrays in C are indexed as
 // array[i][j] - gives you the element at row i,
 // column j

 //////////////////////////////////////
 // TO DO: Complete this function
 //////////////////////////////////////
    int required_sum = find_required_sum_of_columns_and_rows(square);
    int i;
    int j;
    int flag = 1;
    while (flag == 1){
        // row check
        for (i = 0; i < 6; i++){
            int count = 0;
            for (j = 0; j < 6; j++){
                if (square[i][j] != -1){
                    count += 1;
                }
            }
            if (count == 5){
                int present_sum = 0;
                for (j = 0; j < 6; j++){
                    present_sum = present_sum + square[i][j];
                }
                present_sum += 1;
                for (j = 0; j < 6; j++){
                    if (square[i][j] == -1){
                        square[i][j] = required_sum - present_sum;
                    }
                }
            }
        }

        // column check
        for (i = 0; i < 6; i++){
            int count = 0;
            for (j = 0; j < 6; j++){
                if (square[j][i] != -1){
                    count += 1;
                }
            }
            if (count == 5){
                int present_sum = 0;
                for (j = 0; j < 6; j++){
                    present_sum = present_sum + square[j][i];
                }
                present_sum += 1;
                for (j = 0; j < 6; j++){
                    if (square[j][i] == -1){
                        square[j][i] = required_sum - present_sum;
                    }
                }
            }
        }

        /// check at the end if no -1s left
        flag = 0;
        for (i = 0; i < 6; i++){
            for (j = 0; j < 6; j++){
                if (square[i][j] == -1){
                    flag = 1;
                }
            }
        }
    
    }

}


// DO NOT MODIFY ANYTHING BELOW THIS LINE!
// (we mean it! the auto-checker won't be happy)
void printMagicSquare(int square[6][6])
{
   // Prints out the contents of a magic square 6x6

   int i,j,sum;

   for (i=0; i<6; i++)
   {
       sum=0;
       for (j=0; j<6; j++)
       {
           printf("%03d, ",square[i][j]);
           sum=sum+square[i][j];
       }
       printf(" : %03d\n",sum);
   }

   printf("---------------------------\n");

   for (j=0; j<6; j++)
   {
       sum=0;
       for (i=0; i<6; i++)
       {
	   sum=sum+square[i][j];
       }
       printf("%03d, ",sum);
   }
   printf("\n");
}

#ifndef __testing   // This is a compiler directive - used by the auto-checker to enable/disable this part of the code
int main()
{
    int magic[6][6]={{32,29,4,1,24,21},{30,-1,2,3,-1,23},{12,9,17,20,28,25},{10,11,18,-1,26,27},{13,-1,36,33,5,8},{14,15,34,35,6,-1}};

    printMagicSquare(magic);
    printf("Solving Magic Square!\n");
    solveMagicSquare(magic);
    printMagicSquare(magic);

    return 0;
}
#endif
