#pragma once

#include "sudoku.h"

typedef struct HiddenPair_impl
{
    Cell *p_cell; //this is a pointer to a cell
    int value;
} HiddenPair;

int hidden_pairs(SudokuBoard *p_board);

int find_hidden_pairs_values(Cell **p_cells, int *hidden_pairs_values);

void find_hidden_pairs(Cell **p_cells, HiddenPair *p_hidden_pairs, int *p_counter);
