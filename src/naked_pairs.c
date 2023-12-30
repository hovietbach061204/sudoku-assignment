// #include "naked_pairs.h"
// #include <stdio.h>

// bool is_naked_pair(Cell **p_cells, int value1, int value2)
// {
//     int counter = 0;
//     for(int i = 0; i < BOARD_SIZE; i ++)
//     {
//         if(p_cells[i]->num_candidates == 2)
//         {
//             int *candidate = get_candidates(p_cells[i]);
//             if(candidate[0] == value1 && candidate[1] == value2)
//             {
//                 counter += 1;
//             }
//         }
//     }
//     if(counter == 2)
//     {
//         return true;
//     }
//     else
//     {
//         return false;
//     }
// }

// bool is_in_cells(Cell *p_cell, int value1, int value2)
// {
//     int *candidate = get_candidates(p_cell);
//     if(candidate[0] == value1 && candidate[1] == value2)
//     {
//         return true;
//     }
//     else
//     {
//         return false;
//     }
// }

// int find_naked_pairs_values(Cell **p_cells, int *naked_pairs_values)
// {
//     int number_of_naked_pairs_values = 0;
//     int candidate_counter[BOARD_SIZE];
//     for(int i = 0; i < BOARD_SIZE; i++)
//     {
//         candidate_counter[i] = 0;
//     }

//     for(int j = 0; j < BOARD_SIZE; j ++)
//     {
//         if(p_cells[j]->num_candidates == 2) //p_cells[j] is a pointer to a cell in. If j = 0, it means the 0th pointer p_cell points to the 0th cell
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
//         if(candidate_counter[i] >= 2)
//         {
//             naked_pairs_values[number_of_naked_pairs_values] = i + 1;
//             number_of_naked_pairs_values += 1;
//         }
//     }
//     return number_of_naked_pairs_values;
// }

// void find_naked_pairs(Cell **p_cells, NakedPair *p_naked_pairs, int *p_counter)
// {
//     int naked_pairs_values[BOARD_SIZE];
//     int number_of_naked_pairs_values;
//     number_of_naked_pairs_values = find_naked_pairs_values(p_cells, naked_pairs_values);
//     for(int i = 0; i < number_of_naked_pairs_values - 1; i ++)
//     {
//         for(int j = i + 1; j < number_of_naked_pairs_values; j ++)
//         {
//             if(is_naked_pair(p_cells, naked_pairs_values[i], naked_pairs_values[j]))
//             {
//                 for(int k = 0; k < BOARD_SIZE; k ++)
//                 {
//                     if(is_in_cells(p_cells[k], naked_pairs_values[i], naked_pairs_values[j]))
//                     {
//                         p_naked_pairs[*p_counter].p_cell = p_cells[k];
//                         p_naked_pairs[*p_counter].value1 = naked_pairs_values[i];
//                         p_naked_pairs[*p_counter].value2 = naked_pairs_values[j];
//                         (*p_counter) += 1;
//                     }
//                 }
//             }
//         }
//     }
// }

// int naked_pairs(SudokuBoard *p_board)
// {
//     for(int i = 0; i < BOARD_SIZE; i ++)
//     {
//         for(int j = 0; j < BOARD_SIZE; j ++)
//         {
//             int * candidates = get_candidates(&(p_board->data[i][j]));
//             for(int k = 0; k < p_board->data[i][j].num_candidates; k ++)
//             {
//                 printf("%d" , candidates[k]);
//             }
//             printf("\t");
//         }
//         printf("\n");
//     }
//     int number_of_naked_pairs_values;
//     int naked_pairs_values[BOARD_SIZE];

//     int p_counter = 0;

//     NakedPair p_naked_pairs[BOARD_SIZE * BOARD_SIZE];
//     //number_of_naked_pairs_values = find_naked_pairs_values(p_board->p_cols[7], naked_pairs_values);
//     //find_naked_pairs(p_board->p_cols[7], p_naked_pairs, &p_counter);
//     for(int i = 0; i < BOARD_SIZE; i ++)
//     {
//         find_naked_pairs(p_board->p_rows[i], p_naked_pairs, &p_counter);
//         find_naked_pairs(p_board->p_cols[i], p_naked_pairs, &p_counter);
//         find_naked_pairs(p_board->p_boxes[i], p_naked_pairs, &p_counter);
//     }
//     // int overlap = p_counter;
//     // for (int j = 0; j < p_counter; j++)
//     // {
//     //     int not_overlap = 0;
//     //     Cell *p_cell = p_naked_pairs[j].p_cell;
//     //     int* candidate_array = get_candidates(p_cell);
//     //     int num_candidates = p_cell->num_candidates;
//     //     for (int k = 0; k < num_candidates; k++){
//     //         if ((candidate_array[k]!= p_naked_pairs[j].value1)&&(candidate_array[k]!=p_naked_pairs[j].value2)){
//     //             unset_candidate(p_cell, candidate_array[k]);
//     //             not_overlap = 1;
//     //         }
//     //     }
//     //     overlap -= not_overlap;
//     //     free(candidate_array);
//     // }

//     for(int i = 0; i < BOARD_SIZE; i++)
//     {
//         for(int j = 0; j < BOARD_SIZE; j++)
//         {
//             int *candidates = get_candidates(&(p_board->data[i][j]));
//             if(p_board->data[i][j].num_candidates > 2)
//             {
//                 for(int k = 0; k < p_board->data[i][j].num_candidates; k++)
//                 {
//                     if(candidates[k] == p_naked_pairs[i].value1 || candidates[k] == p_naked_pairs[i].value2)
//                     {
//                         unset_candidate(&(p_board->data[i][j]), candidates[k]);
//                     }
//                 }
//             }/*
//             void unset_candidate(Cell *cell, int value) //remove a value from the list of possible values (candidates) that a particular cell can take.
// {
//     cell->candidates[value - 1] = 0;
//     cell->num_candidates -= 1;
// }
//             */
//         }
//     }
//     return p_counter + 1;
// }





#include "sudoku.h"
#include <stdlib.h>
#include <stdio.h>
#include "naked_pairs.h"

int naked_cell_array[BOARD_SIZE];

bool is_naked_pair(Cell **p_cells, int value1, int value2){
    int count = 0;
    for (int i =0; i < BOARD_SIZE; i++){
        if (p_cells[i]->num_candidates == 2){
            if(is_candidate(p_cells[i], value1) && is_candidate(p_cells[i], value2)){
            count ++;
            }
        }
    }
    return (count ==2);
}

bool is_in_naked_pair_cell(NakedPair *p_array, Cell *p){
    for (int i = 0; i < BOARD_SIZE * BOARD_SIZE; i++){
        if ((p_array[i].p_cell1 == p)||(p_array[i].p_cell2 == p)){
            return true;
        }
    }
    return false;
}

int is_naked_cell(Cell *p_cell, int value1, int value2){
    if (p_cell->num_candidates == 2){
        return (is_candidate(p_cell, value1) && is_candidate(p_cell, value2));
    }
    return 0;
}

int find_naked_double_values(Cell **p_cells, int *naked_double_values)
{
    int naked_double_count = 0;
    int naked_double_array[BOARD_SIZE];
    for (int i = 0; i < BOARD_SIZE; i++){
        naked_double_array[i] = 0;
    }
    for (int i = 0; i < BOARD_SIZE; i++){
        if (p_cells[i]->num_candidates >= 2){
            int* candidate_array = get_candidates(p_cells[i]); 
            for (int j = 0; j < p_cells[i]->num_candidates; j++){
                naked_double_array[candidate_array[j]-1] += 1; 
            }
            free(candidate_array);
        }
    }
    for (int i = 0; i < BOARD_SIZE; i++){
        if (naked_double_array[i] >= 2){
            naked_double_values[naked_double_count++] = i+1;                  
        }
    }
    return naked_double_count;
}



void find_naked_double(Cell **p_cells, NakedPair *p_naked_double,
                        int *p_counter)
{       
    int naked_double_value_array[BOARD_SIZE];
    int num_value = find_naked_double_values(p_cells, naked_double_value_array);

    for (int i = 0; i < num_value-1; i++){
        for (int j = i+1; j < num_value; j++){
            if(is_naked_pair(p_cells, naked_double_value_array[i], naked_double_value_array[j])){
                    for (int k = 0; k < BOARD_SIZE-1; k++){
                        for (int l = k+1; l < BOARD_SIZE; l++){
                            if (is_naked_cell(p_cells[k], naked_double_value_array[i], naked_double_value_array[j]) && is_naked_cell(p_cells[l], naked_double_value_array[i], naked_double_value_array[j])){
                                NakedPair naked_double_object;
                                naked_double_object.p_cell1 = p_cells[k];
                                naked_double_object.p_cell2 = p_cells[l];
                                naked_double_object.p_cell = p_cells;
                                naked_double_object.value1 = naked_double_value_array[i];
                                naked_double_object.value2 = naked_double_value_array[j];
                                p_naked_double[(*p_counter)++] = naked_double_object;
                            }
                        }                
                    }
            }
        }   
    }

}

int naked_pairs(SudokuBoard *p_board)
{
    NakedPair p_naked_double[BOARD_SIZE*BOARD_SIZE];
    int p_counter = 0;
    for (int i = 0; i< BOARD_SIZE; i++){
        find_naked_double(p_board->p_cols[i], p_naked_double, &p_counter);
        find_naked_double(p_board->p_rows[i], p_naked_double, &p_counter);
        find_naked_double(p_board->p_boxes[i], p_naked_double, &p_counter);
    }
    int overlap = 0;
    NakedPair solved_cell[BOARD_SIZE*BOARD_SIZE];
    int solved_cell_count = 0;
    for (int i = 0; i < p_counter; i++){
        Cell **p_cells = p_naked_double[i].p_cell;
        if (is_in_naked_pair_cell(solved_cell, p_naked_double[i].p_cell1))
        {
            overlap += 1;
            continue;
        }
        solved_cell[solved_cell_count++] = p_naked_double[i];
        for (int k = 0; k < BOARD_SIZE; k++)
        {
            if (p_cells[k] == p_naked_double[i].p_cell1 || p_cells[k] == p_naked_double[i].p_cell2) continue; 
            int* candidate_array = get_candidates(p_cells[k]);
            int num_candidates = p_cells[k]->num_candidates;
            for (int j = 0; j < num_candidates; j++){
                if ((candidate_array[j]== p_naked_double[i].value1)){
                unset_candidate(p_cells[k], candidate_array[j]);
                }
                if ((candidate_array[j]== p_naked_double[i].value2)){
                unset_candidate(p_cells[k], candidate_array[j]);
                }

            } 
            free(candidate_array);
        }
    }
    return p_counter - overlap;
}


