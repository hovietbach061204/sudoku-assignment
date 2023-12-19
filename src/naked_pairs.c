#include "naked_pairs.h"
#include <stdio.h>
int naked_pairs(SudokuBoard *p_board)
{
    for(int i = 0; i < BOARD_SIZE; i ++)
    {
        for(int j = 0; j < BOARD_SIZE; j ++)
        {
            int * candidates = get_candidates(&(p_board->data[i][j]));
            for(int k = 0; k < p_board->data[i][j].num_candidates; k ++)
            {
                printf("%d" , candidates[k]);
            }
            printf("\t");
        }
        printf("\n");
    }
    int number_of_naked_pairs_values;
    int naked_pairs_values[BOARD_SIZE];
    for(int i = 0; i < BOARD_SIZE; i ++)
    {
        naked_pairs_values[i] = 0;
    }
    number_of_naked_pairs_values = find_naked_pairs_values(p_board->p_cols[7], naked_pairs_values);

}

int find_naked_pairs_values(Cell **p_cells, int *naked_pairs_values)
{
    int number_of_naked_pairs_values = 0;
    int candidate_counter[BOARD_SIZE];
    for(int i = 0; i < BOARD_SIZE; i++)
    {
        candidate_counter[i] = 0;
    }

    for(int j = 0; j < BOARD_SIZE; j ++)
    {
        if(p_cells[j]->num_candidates == 2) //p_cells[j] is a pointer to a cell in. If j = 0, it means the 0th pointer p_cell points to the 0th cell
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
        if(candidate_counter[i] >= 2)
        {
            naked_pairs_values[number_of_naked_pairs_values] = i + 1;
            number_of_naked_pairs_values += 1;
        }
    }
    return number_of_naked_pairs_values;
}

void find_naked_pairs(Cell **p_cells, NakedPair *p_naked_pairs, int *p_counter)
{
    int naked_pairs_values[BOARD_SIZE];
    int counter = 0;
    for(int i = 0; i < BOARD_SIZE; i ++)
    {
        naked_pairs_values[i] = 0;
    }
    int number_of_naked_pairs_values;
    number_of_naked_pairs_values = find_naked_pairs_values(p_cells, naked_pairs_values);
    for(int i = 0; i < number_of_naked_pairs_values; i ++)
    {
        for(int j = 0; j < BOARD_SIZE; j ++)
        {
            if(p_cells[j]->num_candidates == 2)
            {
                int *candidate = get_candidates(p_cells[j]);
                for(int k = 0; k < p_cells[j]->num_candidates; k ++)
                {
                    if(candidate[k] == naked_pairs_values[i] && candidate[k + 1] == naked_pairs_values[i + 1])
                    {
                        p_naked_pairs[*p_counter].p_cell = p_cells[j];
                        counter += 1;
                    }
                    if (counter == 2)
                    {
                        
                        //p_naked_pairs[*p_counter].value = naked_pairs_values[i];
                        *p_counter += 1;
                    }
                }
            }
        }
    }


}