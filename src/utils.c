#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

#include "sudoku.h"

void init_sudoku(SudokuBoard *p_board)
{
    p_board->data = malloc(BOARD_SIZE * sizeof(Cell *)); //data is Cell**. Cấp phát cho data thành mảng 2 chiều, nó là một con chỏ chỉ tới 1 cái array, mỗi phần tử trong araray đó là một Cell*.
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        p_board->data[i] = malloc(BOARD_SIZE * sizeof(Cell));
        p_board->p_rows[i] = malloc(BOARD_SIZE * sizeof(Cell *)); 
        p_board->p_cols[i] = malloc(BOARD_SIZE * sizeof(Cell *));
        p_board->p_boxes[i] = malloc(BOARD_SIZE * sizeof(Cell *));
        //box[0] -> data[0][0], data[0][1],...data[2][2].
        //box[0][0] -> data[0][0]
        //box[0][1] -> data[0][1]
        //box[0][2] -> data[0][2]
        //box[0][3] -> data[1][0]
        //box[0][4] -> data[1][1]
    }

    // assign rows, cols, boxes constraint
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            p_board->p_rows[i][j] = &p_board->data[i][j]; //this line of code is assigning the address of an element in the data array to an element in the p_rows array. So p_board->p_rows[i][j] is a pointer to a cell has index[i][j] in the data array.
            p_board->p_cols[j][i] = &p_board->data[i][j];
            p_board->p_boxes[(i / 3) * 3 + j / 3][(i % 3) * 3 + j % 3] = &p_board->data[i][j]; //the index of boxes and the index from 0 to 8 in that box. Example: that element is in box 6 and the index is 7 -> the index of that element in the box is 7.

            // set row index and col index
            p_board->data[i][j].row_index = i;
            p_board->data[i][j].col_index = j;
            p_board->data[i][j].box_index = (i / 3) * 3 + j / 3; 
            
        }
    }

    p_board->solved_counter = 0;
}

void free_sudoku(SudokuBoard *p_board)
{
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        free(p_board->data[i]);
        free(p_board->p_rows[i]);
        free(p_board->p_cols[i]);
        free(p_board->p_boxes[i]);
    }
    free(p_board->data);
}

bool is_solved(SudokuBoard *p_board) //So, this function is checking if the number of solved cells (solved_counter) is equal to the total number of cells in the board. If they are equal, it means all cells are solved, and the function returns true. If they are not equal, it means there are still unsolved cells, and the function returns false.
{
    return p_board->solved_counter == BOARD_SIZE * BOARD_SIZE; 
}


void print_solution(SudokuBoard *p_board)
{
    assert(is_solved(p_board)); //This assert check whether the board is solved or not. If it is solved, then the function will print out the solution. If it is not solved, then the function will not be executed, i

    for (int i = 0; i < BOARD_SIZE; i++)
    {
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            int *candidates = get_candidates(&p_board->data[i][j]);
            printf("%d", candidates[0]);
            free(candidates);
        }
    }
}

void set_candidate(Cell *cell, int value) { //add a value to the list of possible values (candidates) that a particular cell can take.
    cell->candidates[value - 1] = 1;  // Cell: [3, 5, 7], set candidate: value = 3 -> Cell: [3, 5, 7]
    cell->num_candidates += 1;
}

void unset_candidate(Cell *cell, int value) //remove a value from the list of possible values (candidates) that a particular cell can take.
{
    cell->candidates[value - 1] = 0;
    cell->num_candidates -= 1;
}

//hàm này dùng để check xem liệu trong cell đó có cadidates đó không, giả sử cell->candidates là array có phần từ 3,5,7 thì ví dụ value = 3 vào nó sẽ return true.
bool is_candidate(Cell *cell, int value) { // Cell: [3, 5, 7], value = 3 -> true
    return cell->candidates[value - 1] == 1; // cell->candidates = [0, 0, 1, 0, 1, 0, 1, 0, 0]
}

void set_candidates(Cell *cell, int *candidates, int size) //int *candidates is a pointer to an array of possible values (candidates) that a particular cell can take. int * candidates là pointer đến array của cell đó. mà pointer đến array thì ko thể lấy kích thước được nên phải truyền thêm size vào

// Cell:  candidates = [3, 5, 7], size = 3 
// reset candidates: Cell -> candidates = [0, 0, 0, 0, 0, 0, 0, 0, 0]
{
    // reset candidates - set all candidates to 0 first
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        cell->candidates[i] = 0;
    }

    cell->num_candidates = 0;

    // set candidate list
    for (int i = 0; i < size; i++) //size này là kích thước của cái array candidates truyền vào 
    {
        set_candidate(cell, candidates[i]); //set the candidates at the index of the value in the list of candidates to 1.
    }

    if (size == 1) //if size of that cell is equal to one, then it will be the value of that cell.
    {
        cell->value = candidates[0]; //if the size is = 1, then cell will take the value of the candidate index 0 of the array candidates as the value of that cell. 
    }
}

int *get_candidates(Cell *cell) //return an array of possible values (candidates) that a particular cell can take.
{
    int *out = malloc(cell->num_candidates * sizeof(int));
    int counter = 0;
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        if (cell->candidates[i])  //if cell->candidates[i] is not 0, then it will be a possible value of that cell.
        {
            out[counter++] = i + 1;
        }
    }
    return out; //trả về một pointer đến 1 array gồm các possible candidates của cell đó.
}

void load_sudoku(SudokuBoard *p_board, char *textData)
{
    for (int i = 0; i < BOARD_SIZE * BOARD_SIZE; i++) //9*9 = 81 cells
    {
        if (textData[i] - '0') // if the char of the string is not 0, then it will be the value of the cell
        {
            int candidates[] = {textData[i] - '0'};
            int num_candidates = 1;
            set_candidates(&(p_board->data[i / BOARD_SIZE][i % BOARD_SIZE]), candidates, num_candidates);
        }
        else
        {
            int candidates[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
            int num_candidates = BOARD_SIZE;
            set_candidates(&(p_board->data[i / BOARD_SIZE][i % BOARD_SIZE]), candidates, num_candidates);
        }
    }
}

bool apply_constraint(Cell **p_cells, int value)
{
    bool ret = false;

    for (int i = 0; i < BOARD_SIZE; i++)
    {
        if (p_cells[i]->num_candidates > 1)
        {
            if (is_candidate(p_cells[i], value))
            {
                unset_candidate(p_cells[i], value);
                ret = true;
            }
        }
    }
    return ret;
}

bool show_possible(SudokuBoard *p_board, Cell **p_solved_cells, int counter)
{
    bool ret = false;
    for (int i = 0; i < counter; i++)
    {
        Cell *solved_cell = p_solved_cells[i];
        ret |= apply_constraint(p_board->p_rows[solved_cell->row_index],
                                solved_cell->value);
        ret |= apply_constraint(p_board->p_cols[solved_cell->col_index],
                                solved_cell->value);
        ret |= apply_constraint(p_board->p_boxes[solved_cell->box_index],
                                solved_cell->value);
    }
    return ret;
}

bool is_in_list(Cell **p_array, int size, Cell *p)
{
    for (int i = 0; i < size; i++)
    {
        if (p == p_array[i])
            return true;
    }
    return false;
}

int check_solved_cells(SudokuBoard *p_board, Cell ***p_solved_cells) //function to check the number candidates solved in that step. For example, at this step the number of candidates solved are is 7 -> it will return 7
{
    int counter = p_board->solved_counter;

    for (int i = 0; i < BOARD_SIZE; i++)
    {
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            if (p_board->data[i][j].num_candidates == 1 &&
                !is_in_list(p_board->solved_cells, counter,
                            &p_board->data[i][j]))
            {
                int *candidates = get_candidates(&p_board->data[i][j]);
                p_board->data[i][j].value = candidates[0];
                free(candidates);
                p_board->solved_cells[p_board->solved_counter++] =
                    &p_board->data[i][j];
            }
        }
    }
    *p_solved_cells = &p_board->solved_cells[counter];
    return p_board->solved_counter - counter;
}

void print_candidate_num(SudokuBoard *p_board)
{
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            printf("%d ", p_board->data[i][j].num_candidates);
        }
        printf("\n");
    }
}
