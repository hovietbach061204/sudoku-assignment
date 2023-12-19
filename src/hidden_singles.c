#include "hidden_singles.h"
#include <stdio.h>
#include <stdlib.h>
// auto grader -> hidden singles
// hidden single -> find hidden single values
// trong hàm hidden single e chưa gọi hàm find hidden single values
//bâyh em bỏ hàm hidden_single thế bằng find_hidden_single đc kh thầy?
// ko phải, hàm hidden singles là hàm chính, như main vậy 
// nó sẽ gọi hàm find values...
// hiện giờ hidden singles chưa làm gì cả, nó chỉ print thôi, em phải sửa nó
//

// //Solutions:
// int hidden_singles(SudokuBoard *p_board)
// {
//     int *candidates = get_candidates(&(p_board->data[0][0]));
//     int hidden_single_cells_counter = 0;
//     HiddenSingle hidden_single_cells[BOARD_SIZE * BOARD_SIZE];

//     for(int i = 0; i < BOARD_SIZE; i++)
//     {
//         find_hidden_single(p_board->p_rows[i], hidden_single_cells, &hidden_single_cells_counter);
//         // find_hidden_single(p_board->p_cols[i], hidden_single_cells, &hidden_single_cells_counter);
//         // find_hidden_single(p_board->p_boxes[i], hidden_single_cells, &hidden_single_cells_counter);
//     }

//     // for(int i = 0; i < hidden_single_cells_counter; i++)
//     // {
//     //     set_candidates(hidden_single_cells[i].p_cell,(int *)(int[])(hidden_single_cells[i].value), 1);
//     // }
//     return hidden_single_cells_counter;
// }



// // find hidden single values (the value that is unique among all the candidates for a row, a collumn, or a box)
// // cai nay la text ko dich dc nên báo lỗi, em phai comment nó
// //dạ ok ạ, dich ok roi, echay debug thu xem


// int find_hidden_single_values(Cell **p_cells, int *possible_values) 
// {
//     int number_of_hidden_singles = 0;
//     int candidate_counter[BOARD_SIZE];


//     for(int i = 0; i < 9; i++)
//     {
//         candidate_counter[i] = 0; //currently the candidate_counter = [0,0,0,0,0,0,0,0,0].
//     }
//      for(int i = 0; i < 9; i++)
//     {
//          if(p_cells[i]->num_candidates > 1) //if the number of candidates of ith cell is greater than 1, then return an array of possible candidates in that row. For example num_cadidates = 3
//          {
//             int* candidates = get_candidates(p_cells[i]); //return an array of possible candidates, say for example 3,5,7.
//             for(int j = 0; j < p_cells[i]->num_candidates; j ++) // j < 3, j = 0,1,2
//             {
//                 candidate_counter[candidates[j] - 1] += 1; //ex j = 0, candidates[0] = 3, -> candidates[3] - 1 = 2 -> candidate_counter[2] will be set as 1. candidate_counter = [0,0,1,0,1,0,0,1,0]
//             }
             
//          }
//     }
    
//     for(int i = 0; i < 9; i++)
//     {
//         if (candidate_counter[i] == 1) // i = 2,4,6
//         {
//             //for(int j = 0; j < BOARD_SIZE; j++)
//             possible_values[number_of_hidden_singles] = i + 1;//is an array of hidden single values.
//             number_of_hidden_singles += 1; 
//         }
//     }
//     return number_of_hidden_singles;
// }


// bool is_in_list_hidden_single(HiddenSingle *p_array, int size, Cell *a)
// {
//     for (int i = 0; i < size; i++) //this size is the number of hidden single values in that hidden_single_values array.
//     {
//         if (p_array[i].p_cell == a) //p_array[i] is an array contains pointer p_cell which points to cell
//             return true;
//     }
//     return false;
// }

// // find hidden single cells in a row, in a collumn or in a box
// void find_hidden_single(Cell **p_cells, HiddenSingle *p_hidden_singles,int *p_counter)
// {
//     int hidden_single_values[BOARD_SIZE];
//     for(int i = 0; i < BOARD_SIZE; i ++)
//     {
//         hidden_single_values[i] = 0;
    
//     } //an array with 9 elements
//     int num_values = find_hidden_single_values(p_cells, hidden_single_values); //num_values = num_of_hidden_singles

//     for(int i = 0; i < num_values; i++) 
//     {
//         for(int j = 0 ; j < BOARD_SIZE; j ++)
//         {
//             if (p_cells[j]->num_candidates > 1) //p_cells[j] is pointer to jth cell in that ith row
//             {
//                 int *candidates = get_candidates(p_cells[j]); //candidates is an array of possible candidates in that cell
//                 for(int k = 0; k < p_cells[i]->num_candidates; k ++)
//                 {
//                     if((candidates[k] == hidden_single_values[i]) && (!is_in_list_hidden_single(p_hidden_singles, *p_counter, p_cells[j])))
//                     {
//                         p_hidden_singles[(*p_counter)++] = (HiddenSingle){p_cells[j], hidden_single_values[i]};
//                     }
//                 }
//                 free(candidates);
//             }
//         }
//     }
// }






#include "hidden_singles.h"
#include <stdio.h>
#include <stdlib.h>

int hidden_singles(SudokuBoard *p_board)
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

    int hidden_single_values[BOARD_SIZE];
    for(int i = 0; i < BOARD_SIZE; i ++)
    {
        hidden_single_values[i] = 0;
    }

    int num_hidden_in_rows;
    int num_hidden_in_cols = 0;
    int num_hidden_in_boxes = 0;
    // for(int i = 0; i < BOARD_SIZE; i ++)
    // {
    //     num_hidden_in_rows += find_hidden_single_values(p_board->p_rows[i], hidden_single_values);
    //     num_hidden_in_cols += find_hidden_single_values(p_board->p_cols[i], hidden_single_values);
    //     num_hidden_in_boxes += find_hidden_single_values(p_board->p_boxes[i], hidden_single_values);
    // }

    int *p_hidden_singles;

    num_hidden_in_rows = find_hidden_single_values(p_board->p_rows[4], hidden_single_values);
    find_hidden_single(p_board->p_rows[4], p_hidden_singles, &num_hidden_in_rows);
}

int find_hidden_single_values(Cell **p_cells, int *hidden_single_values)
{
    int number_of_hidden_single_values = 0;
    int candidate_counter[BOARD_SIZE];
    for(int i = 0; i < BOARD_SIZE; i ++)
    {
        candidate_counter[i] = 0;
    }

    for(int i = 0;i < BOARD_SIZE; i ++)
    {
        if(p_cells[i]->num_candidates > 1)
        {
            int * candidate  = get_candidates(p_cells[i]);
            for(int j = 0; j < p_cells[i]->num_candidates; j ++)
            {
                candidate_counter[candidate[j] - 1] += 1;
            }
        }
    }
    for(int i = 0 ; i < BOARD_SIZE; i ++)
    {
        if(candidate_counter[i] == 1)
        {
            hidden_single_values[number_of_hidden_single_values] = i + 1;
            number_of_hidden_single_values += 1;
        }
    }
    return number_of_hidden_single_values;
}

void find_hidden_single(Cell **p_cells, HiddenSingle *p_hidden_singles,int *p_counter)
{
    int hidden_single_values[BOARD_SIZE]; //an array with 9 elements
    int num_values = find_hidden_single_values(p_cells, hidden_single_values); //num_values = num_of_hidden_singles

    for(int i = 0; i < num_values; i++) 
    {
        for(int j = 0 ; j < BOARD_SIZE; j ++)
        {
            if (p_cells[j]->num_candidates > 1) //p_cells[j] is pointer to jth cell in that ith row
            {
                int *candidates = get_candidates(p_cells[j]); //candidates is an array of possible candidates in that cell
                for(int k = 0; k < p_cells[i]->num_candidates; k ++)
                {
                    if((candidates[k] == hidden_single_values[i]))
                    {
                        p_hidden_singles[*p_counter].p_cell = p_cells[j];
                        p_hidden_singles[*p_counter].value = hidden_single_values[i];
                        
                    }
                }
                free(candidates);
            }
        }
    }
}