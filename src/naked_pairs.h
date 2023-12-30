#pragma once

#include "sudoku.h"

typedef struct NakedPair_impl
{
    Cell *p_cell1;
    Cell *p_cell2; //this is a pointer to a cell
    int value1;
    int value2;
    Cell **p_cell;
}NakedPair;

// bool is_naked_pair(Cell **p_cells, int value1, int value2);
// bool is_in_cells(Cell *p_cell, int value1, int value2);
// int find_naked_pairs_values(Cell **p_cells, int *naked_pairs_values);
// void find_naked_pairs(Cell **p_cells, NakedPair *p_naked_pairs, int *p_counter);
// int naked_pairs(SudokuBoard *p_board);




bool is_naked_pair(Cell **p_cells, int value1, int value2);
bool is_in_naked_pair_cell(NakedPair *p_array, Cell *p);
int is_naked_cell(Cell *p_cell, int value1, int value2);
int find_naked_double_values(Cell **p_cells, int *naked_double_values);
void find_naked_double(Cell **p_cells, NakedPair *p_naked_double, int *p_counter);
int naked_pairs(SudokuBoard *p_board);

