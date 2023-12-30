// #include "hidden_pairs.h"
// #include <stdio.h>
// #include <stdlib.h>

// int hidden_pairs(SudokuBoard *p_board)
// {
//     int hidden_pairs_cells_counter = 0;
//     HiddenPair hidden_pair_cells[BOARD_SIZE * BOARD_SIZE];

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
//     for(int i = 0; i < BOARD_SIZE; i ++)
//     {
//         hidden_pairs_values[i] = 0;
//     }
//     int number_of_hidden_pairs_values;
//     //number_of_hidden_pairs_values = find_hidden_pairs_values(p_board->p_rows[5], hidden_pairs_values);
//     find_hidden_pairs(p_board->p_cols[5], hidden_pair_cells, &hidden_pairs_cells_counter);
//     //return number_of_hidden_pairs_values;
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
//         if(p_cells[j]->num_candidates >= 2) //p_cells[j] is a pointer to a cell in. If j = 0, it means the 0th pointer p_cell points to the 0th cell
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
//     int hidden_pairs_values[BOARD_SIZE];
//     for(int i = 0; i < BOARD_SIZE; i ++)
//     {
//         hidden_pairs_values[i] = 0;
//     }
//     int number_of_hidden_pairs_values;
//     number_of_hidden_pairs_values = find_hidden_pairs_values(p_cells, hidden_pairs_values); //number_of_hidden_pairs_values = 2. hidden_pairs_values = {1, 5, 0,0,0,0,...}
//     int hidden_pairs_cells_counter = 0;
//     int hidden_pairs_cells[BOARD_SIZE];
//     if(number_of_hidden_pairs_values >= 2)
//     {
//         for(int j = 0; j < BOARD_SIZE; j++)
//         {
//             int count = 0;
//             for(int i = 0; i < number_of_hidden_pairs_values; i ++)
//             {
//                 if(p_cells[j]->num_candidates >= 2)
//                 {
//                     int *candidate = get_candidates(p_cells[j]); //candidate is pointer to an array of candidates in a cell4
//                     for(int k = 0; k < p_cells[j]->num_candidates; k ++)
//                     {
//                         if(candidate[k] == hidden_pairs_values[i])
//                         {
//                             count ++;    
//                         }
//                     }
//                 }
//             }
//             if(count == 2)
//             {
//                 p_hidden_pairs[hidden_pairs_cells_counter].p_cell = p_cells[j]; 
//                 hidden_pairs_cells_counter ++;
//             }
//         }
//     }
// }







#include "hidden_pairs.h"
#include "sudoku.h"
#include <stdlib.h>


bool is_hidden_pair(Cell **p_cells, int value1, int value2){ //check that if that row, column or box has enough 2 cells contain the hidden pair values.
    int count = 0;
    for (int i = 0; i < BOARD_SIZE; i++){
        //if(is_candidate(p_cells[i], value1) && is_candidate(p_cells[i], value2)){ // p_cells[i] is pointer to a cell in that row, column or box. If there is a cell contains both hidden pair values, then count += 1
        if(is_in_cell(p_cells[i], value1, value2)){
            count ++;
        }

    }
    return (count == 2); //return true if count = 2, else return false. It means if the row column or box has 2 cells contain the hidden pair values, then return true, else return false.
}


bool is_in_cell(Cell *p_cell, int value1, int value2){
    return (is_candidate(p_cell, value1) && is_candidate(p_cell, value2)); //return true if the cell contains the hidden pair values, else return false
}

int find_hidden_double_values(Cell **p_cells, int *hidden_double_values)
{
    int hidden_double_count = 0;
    int hidden_double_array[BOARD_SIZE];
    for (int i = 0; i < BOARD_SIZE; i++){
        hidden_double_array[i] = 0;
    }
    for (int i = 0; i < BOARD_SIZE; i++){
        if (p_cells[i]->num_candidates >= 2){
            int* candidate_array = get_candidates(p_cells[i]); 
            for (int j = 0; j < p_cells[i]->num_candidates; j++){
                hidden_double_array[candidate_array[j]-1] += 1; 
            }
            free(candidate_array);
        }
    }
    for (int i = 0; i < BOARD_SIZE; i++){
        if (hidden_double_array[i] == 2){
                hidden_double_values[hidden_double_count++] = i+1;                  
        }
    }
    return hidden_double_count;
}



void find_hidden_double(Cell **p_cells, HiddenPair *p_hidden_double,
                        int *p_counter)
{       
      int hidden_double_value_array[BOARD_SIZE];
      int num_value = find_hidden_double_values(p_cells, hidden_double_value_array);

      for (int i = 0; i < num_value-1; i++){
            for (int j = i+1; j < num_value; j++){
                if(is_hidden_pair(p_cells, hidden_double_value_array[i], hidden_double_value_array[j])){
                    for (int k = 0; k < BOARD_SIZE; k++){
                        if (is_in_cell(p_cells[k], hidden_double_value_array[i], hidden_double_value_array[j])){
                        p_hidden_double[*p_counter].value1 = hidden_double_value_array[i];
                        p_hidden_double[*p_counter].value2 = hidden_double_value_array[j];
                        p_hidden_double[*p_counter].p_cell = p_cells[k];
                        (*p_counter) ++;
                        }                    
                    }
                }
            }
      }
}

int hidden_pairs(SudokuBoard *p_board)
{
    HiddenPair p_hidden_double[BOARD_SIZE*BOARD_SIZE];
    int p_counter = 0;
    for (int i = 0; i< BOARD_SIZE; i++){
        find_hidden_double(p_board->p_cols[i], p_hidden_double, &p_counter);
        find_hidden_double(p_board->p_rows[i], p_hidden_double, &p_counter);
        find_hidden_double(p_board->p_boxes[i], p_hidden_double, &p_counter);
    }
    int overlap = p_counter;
    for (int i = 0; i < p_counter; i++){
        int not_overlap = 0;
        Cell *p_cell = p_hidden_double[i].p_cell;
        int* candidate_array = get_candidates(p_cell);
        int num_candidates = p_cell->num_candidates;
        for (int j = 0; j < num_candidates; j++){
            if ((candidate_array[j]!= p_hidden_double[i].value1)&&(candidate_array[j]!=p_hidden_double[i].value2)){
                unset_candidate(p_cell, candidate_array[j]);
                not_overlap = 1;
            }
        }
        overlap -= not_overlap;
        free(candidate_array);

    }

    return (p_counter - overlap)/2;
}
