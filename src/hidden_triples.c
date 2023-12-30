#include "hidden_triples.h"
#include <stdlib.h>
#include <stdio.h>

// int hidden_triples(SudokuBoard *p_board)
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
//     int hidden_triple_count;
//     int hidden_triple_array[BOARD_SIZE];
//     hidden_triple_count = find_hidden_triples_values(p_board->p_rows[0], hidden_triple_array);
// }

// bool is_hidden_triple(Cell **p_cells, int value1, int value2, int value3)
// {
//     int count = 0;
//     for(int i = 0; i < BOARD_SIZE; i++)
//     {
//         if(is_in_cells(p_cells[i], value1, value2, value3))
//         {
//             count++;
//         }
//     }
//     return (count == 3);
// }

// bool is_in_cells(Cell *p_cell, int value1, int value2, int value3){
//     return ((is_candidate(p_cell, value1) && is_candidate(p_cell, value2)) || (is_candidate(p_cell,value1) && is_candidate(p_cell, value3)) ||(is_candidate(p_cell,value2) && is_candidate(p_cell,value3)) || (is_candidate(p_cell,value1) && is_candidate(p_cell,value2) && is_candidate(p_cell, value3))); //return true if the cell contains the hidden triple values, else return false
// }


// int find_hidden_triples_values(Cell **p_cells, int *hidden_triples_values)
// {
//     int hidden_triple_count = 0;
//     int hidden_triple_array[BOARD_SIZE];
//     for (int i = 0; i < BOARD_SIZE; i++){
//         hidden_triple_array[i] = 0;
//     }
//     for (int i = 0; i < BOARD_SIZE; i++){
//         if (p_cells[i]->num_candidates >= 2){
//             int* candidate_array = get_candidates(p_cells[i]); 
//             for (int j = 0; j < p_cells[i]->num_candidates; j++){
//                 hidden_triple_array[candidate_array[j]-1] += 1; 
//             }
//             free(candidate_array);
//         }
//     }
//     for (int i = 0; i < BOARD_SIZE; i++){
//         if (hidden_triple_array[i] >= 2 && hidden_triple_array[i] <= 3){
//                 hidden_triples_values[hidden_triple_count++] = i+1;                  
//         }
//     }
//     return hidden_triple_count;
// }

// void find_hidden_triples(Cell **p_cells, HiddenTriple *p_hidden_triples, int *p_counter)
// {
//     int hidden_triple_array[BOARD_SIZE];
//     int hidden_triple_count = find_hidden_triples_values(p_cells, hidden_triple_array);
//     for(int i = 0; i < hidden_triple_count - 2; i++)
//     {
//         for(int j = i + 1; j < hidden_triple_count - 1; j++)
//         {
//             for(int k = j + 1; k < hidden_triple_count; j++)
//             {
//                 if(is_hidden_triple(p_cells, hidden_triple_array[i], hidden_triple_array[j], hidden_triple_array[k]))
//                 {
//                    for(int t = 0; t < BOARD_SIZE; t ++)
//                    {
//                         if(is_in_cells(p_cells[t], hidden_triple_array[i], hidden_triple_array[j], hidden_triple_array[k]))
//                         {
//                             p_hidden_triples[*p_counter].p_cell = p_cells[t];
//                             p_hidden_triples[*p_counter].value1 = hidden_triple_array[i];
//                             p_hidden_triples[*p_counter].value2 = hidden_triple_array[j];
//                             p_hidden_triples[*p_counter].value3 = hidden_triple_array[k];
//                             (*p_counter)++;
//                         }
//                    }
//                 }
//             }
//         }
//     }
// }

// int hidden_triples(SudokuBoard *p_board)
// {
//     int hidden_triple_count = 0;
//     HiddenTriple hidden_triples[BOARD_SIZE * BOARD_SIZE];
//     for(int i = 0; i < BOARD_SIZE; i++)
//     {
//         find_hidden_triples(p_board->p_rows[i], hidden_triples, &hidden_triple_count);
//         find_hidden_triples(p_board->p_cols[i], hidden_triples, &hidden_triple_count);
//         find_hidden_triples(p_board->p_boxes[i], hidden_triples, &hidden_triple_count);
//     }
//     int overlap = hidden_triple_count;
//     for (int i = 0; i < hidden_triple_count; i++){
//         int not_overlap = 0;
//         Cell *p_cell = hidden_triples[i].p_cell;
//         int* candidate_array = get_candidates(p_cell);
//         int num_candidates = p_cell->num_candidates;
//         for (int j = 0; j < num_candidates; j++){
//             if ((candidate_array[j]!= hidden_triples[i].value1)&&(candidate_array[j]!=hidden_triples[i].value2) &&(candidate_array[j]!=hidden_triples[i].value3)){
//                 unset_candidate(p_cell, candidate_array[j]);
//                 not_overlap = 1;
//             }
//         }
//         overlap -= not_overlap;
//         free(candidate_array);

//     }

//     return (hidden_triple_count - overlap)/3;
// }


// #include "hidden_triples.h"
// #include "sudoku.h"
// #include <stdlib.h>
// #include <stdio.h>


// int is_hidden_triple_set(Cell **p_cells, int value1, int value2, int value3){
//     int count = 0;
//     for (int i =0; i < BOARD_SIZE; i++){
//         if (p_cells[i]->num_candidates >= 2){
//             if((is_candidate(p_cells[i], value1) || is_candidate(p_cells[i], value2) || is_candidate(p_cells[i], value3))){
//             count ++;
//             }
//         }
//     }
//     return (count ==3);
// }

// bool is_in_hidden_triple_list(HiddenTriple *p_array, Cell *p){
//     for (int i = 0; i < BOARD_SIZE * BOARD_SIZE; i++){
//         if ((p_array[i].p_cell1 == p)||(p_array[i].p_cell2 == p)|| (p_array[i].p_cell3 == p) ){
//             return true;
//         }
//     }
//     return false;
// }

// int is_hidden_triple_cell(Cell *p_cell, int value1, int value2, int value3){
//     if (p_cell->num_candidates >= 2){
//         return ((is_candidate(p_cell, value1)) || (is_candidate(p_cell, value2)) || (is_candidate(p_cell, value3))); 
//     }
//     return 0;
// }

// int find_hidden_triple_values(Cell **p_cells, int *hidden_triple_values)
// {
//     int hidden_triple_count = 0;
//     int hidden_triple_array[BOARD_SIZE];
//     for (int i = 0; i < BOARD_SIZE; i++){
//         hidden_triple_array[i] = 0;
//     }
//     for (int i = 0; i < BOARD_SIZE; i++){
//         if (p_cells[i]->num_candidates >= 2){
//             int* candidate_array = get_candidates(p_cells[i]); 
//             for (int j = 0; j < p_cells[i]->num_candidates; j++){
//                 hidden_triple_array[candidate_array[j]-1] += 1; 
//             }
//             free(candidate_array);
//         }
//     }
//     for (int i = 0; i < BOARD_SIZE; i++){
//         if (hidden_triple_array[i] == 2 || hidden_triple_array[i] == 3){
//             hidden_triple_values[hidden_triple_count++] = i+1;                  
//         }
//     }
//     return hidden_triple_count;
// }



// void find_hidden_triple(Cell **p_cells, HiddenTriple *p_hidden_triple,
//                         int *p_counter)
// {       
//     int hidden_triple_value_array[BOARD_SIZE];
//     int num_value = find_hidden_triple_values(p_cells, hidden_triple_value_array);

//     for (int i = 0; i < num_value-2; i++){
//         for (int j = i+1; j < num_value-1; j++){
//             for (int k = j+1; k < num_value; k++){
//                 if(is_hidden_triple_set(p_cells, hidden_triple_value_array[i], hidden_triple_value_array[j], hidden_triple_value_array[k])){
//                     for (int l = 0; l < BOARD_SIZE-2; l++){
//                         for (int m = l+1; m < BOARD_SIZE-1; m++){
//                             for (int n = m+1; n < BOARD_SIZE; n++){
//                                 if ((is_hidden_triple_cell(p_cells[l], hidden_triple_value_array[i], hidden_triple_value_array[j], hidden_triple_value_array[k])) && (is_hidden_triple_cell(p_cells[m], hidden_triple_value_array[i], hidden_triple_value_array[j], hidden_triple_value_array[k])) && (is_hidden_triple_cell(p_cells[n], hidden_triple_value_array[i], hidden_triple_value_array[j], hidden_triple_value_array[k]))) {
//                                     HiddenTriple hidden_triple_object;
//                                     hidden_triple_object.p_cell1 = p_cells[l];
//                                     hidden_triple_object.p_cell2 = p_cells[m];
//                                     hidden_triple_object.p_cell3 = p_cells[n];
//                                     hidden_triple_object.p_cells = p_cells;
//                                     hidden_triple_object.value1 = hidden_triple_value_array[i];
//                                     hidden_triple_object.value2 = hidden_triple_value_array[j];
//                                     hidden_triple_object.value3 = hidden_triple_value_array[k];
//                                     p_hidden_triple[(*p_counter)++] = hidden_triple_object;
//                                 }
//                             }
//                         }                
//                     }                  
//                 }
//             }
//         }
//     }
// }


int is_hidden_triple_set(Cell **p_cells, int value1, int value2, int value3){
    int count = 0;
    for (int i =0; i < BOARD_SIZE; i++){
        if (p_cells[i]->num_candidates >= 2){
            if((is_candidate(p_cells[i], value1) || is_candidate(p_cells[i], value2) || is_candidate(p_cells[i], value3))){
            count ++;
            }
        }
    }
    return (count ==3);
}

bool is_in_hidden_triple_list(HiddenTriple *p_array, Cell *p){
    for (int i = 0; i < BOARD_SIZE * BOARD_SIZE; i++){
        if ((p_array[i].p_cell1 == p)||(p_array[i].p_cell2 == p)|| (p_array[i].p_cell3 == p) ){
            return true;
        }
    }
    return false;
}

int is_hidden_triple_cell(Cell *p_cell, int value1, int value2, int value3){
    if (p_cell->num_candidates >= 2){
        return ((is_candidate(p_cell, value1)) || (is_candidate(p_cell, value2)) || (is_candidate(p_cell, value3))); 
    }
    return 0;
}

int find_hidden_triple_values(Cell **p_cells, int *hidden_triple_values)
{
    int hidden_triple_count = 0;
    int hidden_triple_array[BOARD_SIZE];
    for (int i = 0; i < BOARD_SIZE; i++){
        hidden_triple_array[i] = 0;
    }
    for (int i = 0; i < BOARD_SIZE; i++){
        if (p_cells[i]->num_candidates >= 2){
            int* candidate_array = get_candidates(p_cells[i]); 
            for (int j = 0; j < p_cells[i]->num_candidates; j++){
                hidden_triple_array[candidate_array[j]-1] += 1; 
            }
            free(candidate_array);
        }
    }
    for (int i = 0; i < BOARD_SIZE; i++){
        if (hidden_triple_array[i] == 2 || hidden_triple_array[i] == 3){
            hidden_triple_values[hidden_triple_count++] = i+1;                  
        }
    }
    return hidden_triple_count;
}



void find_hidden_triple(Cell **p_cells, HiddenTriple *p_hidden_triple,
                        int *p_counter)
{       
    int hidden_triple_value_array[BOARD_SIZE];
    int num_value = find_hidden_triple_values(p_cells, hidden_triple_value_array);

    for (int i = 0; i < num_value-2; i++){
        for (int j = i+1; j < num_value-1; j++){
            for (int k = j+1; k < num_value; k++){
                if(is_hidden_triple_set(p_cells, hidden_triple_value_array[i], hidden_triple_value_array[j], hidden_triple_value_array[k])){
                    for (int l = 0; l < BOARD_SIZE-2; l++){
                        for (int m = l+1; m < BOARD_SIZE-1; m++){
                            for (int n = m+1; n < BOARD_SIZE; n++){
                                if ((is_hidden_triple_cell(p_cells[l], hidden_triple_value_array[i], hidden_triple_value_array[j], hidden_triple_value_array[k])) && (is_hidden_triple_cell(p_cells[m], hidden_triple_value_array[i], hidden_triple_value_array[j], hidden_triple_value_array[k])) && (is_hidden_triple_cell(p_cells[n], hidden_triple_value_array[i], hidden_triple_value_array[j], hidden_triple_value_array[k]))) {
                                    HiddenTriple hidden_triple_object;
                                    hidden_triple_object.p_cell1 = p_cells[l];
                                    hidden_triple_object.p_cell2 = p_cells[m];
                                    hidden_triple_object.p_cell3 = p_cells[n];
                                    hidden_triple_object.p_cells = p_cells;
                                    hidden_triple_object.value1 = hidden_triple_value_array[i];
                                    hidden_triple_object.value2 = hidden_triple_value_array[j];
                                    hidden_triple_object.value3 = hidden_triple_value_array[k];
                                    p_hidden_triple[(*p_counter)++] = hidden_triple_object;
                                }
                            }
                        }                
                    }                  
                }
            }
        }
    }
}

int hidden_triples(SudokuBoard *p_board)
{
    HiddenTriple p_hidden_triple[BOARD_SIZE*BOARD_SIZE];
    int p_counter = 0;
    for (int i = 0; i< BOARD_SIZE; i++){
        find_hidden_triple(p_board->p_cols[i], p_hidden_triple, &p_counter);
        find_hidden_triple(p_board->p_rows[i], p_hidden_triple, &p_counter);
        find_hidden_triple(p_board->p_boxes[i], p_hidden_triple, &p_counter);
    }
    int overlap = 0;
    HiddenTriple solved_cell[BOARD_SIZE*BOARD_SIZE];
    int solved_cell_count = 0;
    for (int i = 0; i < p_counter; i++){
        if (is_in_hidden_triple_list(solved_cell, p_hidden_triple[i].p_cell1))
        {
            overlap += 1;
            continue;
        }

        solved_cell[solved_cell_count++] = p_hidden_triple[i];

        int is_naked = 1;

        int* candidate_array1 = get_candidates(p_hidden_triple[i].p_cell1);
        int num_candidates = p_hidden_triple[i].p_cell1->num_candidates;
        for (int k = 0; k < num_candidates; k++){
            if ((candidate_array1[k] != p_hidden_triple[i].value1) && (candidate_array1[k]!= p_hidden_triple[i].value2) && (candidate_array1[k]!= p_hidden_triple[i].value3)){
                unset_candidate(p_hidden_triple[i].p_cell1, candidate_array1[k]);
                is_naked = 0;
            }
            
        }
        int* candidate_array2 = get_candidates(p_hidden_triple[i].p_cell2);
        num_candidates = p_hidden_triple[i].p_cell2->num_candidates;
        for (int k = 0; k < num_candidates; k++){
            if ((candidate_array2[k] != p_hidden_triple[i].value1) && (candidate_array2[k]!= p_hidden_triple[i].value2) && (candidate_array2[k]!= p_hidden_triple[i].value3)){
                unset_candidate(p_hidden_triple[i].p_cell2, candidate_array2[k]);
                is_naked = 0;
            }
            
        }
        int* candidate_array3 = get_candidates(p_hidden_triple[i].p_cell3);
        num_candidates = p_hidden_triple[i].p_cell3->num_candidates;
        for (int k = 0; k < num_candidates; k++){
            if ((candidate_array3[k] != p_hidden_triple[i].value1) && (candidate_array3[k]!= p_hidden_triple[i].value2) && (candidate_array3[k]!= p_hidden_triple[i].value3)){
                unset_candidate(p_hidden_triple[i].p_cell3, candidate_array3[k]);
                is_naked = 0;
            }
            
        }
        if (is_naked == 1){
            overlap += 1;
        }
             
        free(candidate_array1);
        free(candidate_array2);
        free(candidate_array3);
            
    }
    return p_counter - overlap;
}