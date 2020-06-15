// By Giorgi Gvimradze //as a homework
// CENTRAL LIMIT THEOREM simple code in C
// Source: https://builtin.com/data-science/understanding-central-limit-theorem

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROLL_TIMES 320

int dice=0;
int dice_side[12]={0};

void print_dice_sides()
{
    int j,k,limit;
    double i;
    
    printf("%d Rolls, %d Dice:\nAVG\tFreq\n",ROLL_TIMES,dice);

    for(i=2; i<=12; i++)
    {
        printf("%.1f\t", i/2);
        limit=i;
        for(j=0;j<dice_side[limit-1];j++)
            printf("*");
        printf("\n");    
    }

}

void roll()
{
    int i, j, sum,mean;
    time_t t;
    

    srand((unsigned) time(&t));

    for( i = 0 ; i < ROLL_TIMES ; i++ ) {
        sum=0;
        for(j=0; j<dice; j++)
        {
            sum += rand()%12 + 2;
        }
        mean = sum/dice; // mean of rolls- roughly. ~0.5
        dice_side[mean-1]++; 
        
    }
    printf("\n");
}

// disabled for demo purposes
int read_input()
{
    while(!(dice>=2&&dice<=5)){
        printf("Enter the amount of dice between 2 & 5 to roll:\n");
        scanf("%d", &dice);
        if (dice>=2&&dice<=5)
            return dice;
        printf("Wrong input. Try again.\n");
    }
    return 0;
}


int main()
{
    
    dice=read_input();

    roll();
    print_dice_sides();
    return 0;
}
