#pragma once

#include "sudoku.h"

typedef struct NakedPair_impl
{
    Cell *p_cell; //this is a pointer to a cell
    int value;
} NakedPair;

int naked_pairs(SudokuBoard *p_board);

int find_naked_pairs_values(Cell **p_cells, int *naked_pairs_values);

void find_naked_pairs(Cell **p_cells, NakedPair *p_naked_pairs, int *p_counter);