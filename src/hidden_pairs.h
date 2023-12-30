#pragma once

#include "sudoku.h"

typedef struct HiddenPair_impl
{
    //Cell *p_cell1;
    //Cell *p_cell2; //this is a pointer to a cell
    int value1;
    int value2;
    Cell *p_cell;
} HiddenPair;

int hidden_pairs(SudokuBoard *p_board);

int find_hidden_pairs_values(Cell **p_cells, int *hidden_pairs_values);

void find_hidden_pairs(Cell **p_cells, HiddenPair *p_hidden_pairs, int *p_counter);

//bool is_in_list_hidden_pairs(HiddenPair *pHiddenPairs, int counter, Cell *p_cell1, Cell *p_cell2);

bool is_hidden_pair(Cell **p_cells, int value1, int value2);
bool is_in_cell(Cell *p_cell, int value1, int value2);
