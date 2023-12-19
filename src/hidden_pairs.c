#include "hidden_pairs.h"
#include <stdio.h>

// int hidden_pairs(SudokuBoard *p_board)
// {
//     for(int i = 0; i < BOARD_SIZE; i ++)
//     {
//         for(int j = 0; j < BOARD_SIZE; j ++)
//         {
//             //create an array contains the pointers to all of candidates in a cell at position[i][j]
//             int* candidates = get_candidates(&p_board->data[i][j]);
//             for(int k = 0; k < p_board->data[i][j].num_candidates; k ++)
//             {
//                 printf("%d", candidates[k]);
//             }
//             printf("\t");
//         }
//         printf("\n");
//     }
//     int hidden_pairs_values[BOARD_SIZE];
//     int number_of_hidden_pairs_values;
//     number_of_hidden_pairs_values = find_hidden_pairs_values(p_board->p_rows[0], hidden_pairs_values);
//     return number_of_hidden_pairs_values;
// }


// int find_hidden_pairs_values(Cell **p_cells, int *hidden_pairs_values ) //**p_cells is an array represent for a row, col or box, which contains the p_cell pointers, which point to cells.
// {
//     int number_of_hidden_pairs_values = 0;
//     int candidate_counter[BOARD_SIZE];
//     for(int i = 0; i < BOARD_SIZE; i++)
//     {
//         candidate_counter[i] = 0;
//     }

//     for(int j = 0; j < BOARD_SIZE; j ++)
//     {
//         if(p_cells[j]->num_candidates > 2) //p_cells[j] is a pointer to a cell in. If j = 0, it means the 0th pointer p_cell points to the 0th cell
//         {
//             int *candidate = get_candidates(p_cells[j]);
//             for(int k = 0; k < p_cells[j]->num_candidates; k++)
//             {
//                 candidate_counter[candidate[k] - 1] += 1;
//             }
//         }
        
//     }

//     for(int i = 0; i < BOARD_SIZE; i ++)
//     {
//         if(candidate_counter[i] == 2)
//         {
//             hidden_pairs_values[number_of_hidden_pairs_values] = i + 1;
//             number_of_hidden_pairs_values += 1;
//         }
//     }
//     return number_of_hidden_pairs_values;
// }

// void find_hidden_pairs(Cell **p_cells, HiddenPair *p_hidden_pairs, int *p_counter)
// {
    
// }

//Solution:
int hidden_pairs(SudokuBoard *p_board)
{
    for(int i = 0; i < BOARD_SIZE; i ++)
    {
        for(int j = 0; j < BOARD_SIZE; j ++)
        {
            //create an array contains the pointers to all of candidates in a cell at position[i][j]
            int* candidates = get_candidates(&p_board->data[i][j]);
            for(int k = 0; k < p_board->data[i][j].num_candidates; k ++)
            {
                printf("%d", candidates[k]);
            }
            printf("\t");
        }
        printf("\n");
    }
    int hidden_pairs_values[BOARD_SIZE];
    int number_of_hidden_pairs_values;
    number_of_hidden_pairs_values = find_hidden_pairs_values(p_board->p_rows[0], hidden_pairs_values);
    return number_of_hidden_pairs_values;
}


int find_hidden_pairs_values(Cell **p_cells, int *hidden_pairs_values ) //**p_cells is an array represent for a row, col or box, which contains the p_cell pointers, which point to cells.
{
    int number_of_hidden_pairs_values = 0;
    int candidate_counter[BOARD_SIZE];
    for(int i = 0; i < BOARD_SIZE; i++)
    {
        candidate_counter[i] = 0;
    }

    for(int j = 0; j < BOARD_SIZE; j ++)
    {
        if(p_cells[j]->num_candidates > 2) //p_cells[j] is a pointer to a cell in. If j = 0, it means the 0th pointer p_cell points to the 0th cell
        {
            int *candidate = get_candidates(p_cells[j]);
            for(int k = 0; k < p_cells[j]->num_candidates; k++)
            {
                candidate_counter[candidate[k] - 1] += 1;
            }
        }
        
    }

    for(int i = 0; i < BOARD_SIZE; i ++)
    {
        if(candidate_counter[i] == 2)
        {
            hidden_pairs_values[number_of_hidden_pairs_values] = i + 1;
            number_of_hidden_pairs_values += 1;
        }
    }
    return number_of_hidden_pairs_values;
}

void find_hidden_pairs(Cell **p_cells, HiddenPair *p_hidden_pairs, int *p_counter)
{
    
}