#pragma once
#include "HeightMapGenerator.h"
#include <stdlib.h>
#include <time.h>

HeightMapGenerator::HeightMapGenerator(unsigned int rows, unsigned int columns, unsigned int deltaHeight)
	: m_Rows(rows), m_Columns(columns), m_DeltaHeight(deltaHeight), m_HeightOffset(deltaHeight/2)
{
	m_HeightMap = new int*[rows];
	m_ObjectMap = new int* [rows];
	for (unsigned int i = 0; i < rows; i++) {
		m_HeightMap[i] = new int[columns];
		m_ObjectMap[i] = new int[columns];
 	}
}

HeightMapGenerator::~HeightMapGenerator()
{
	for (int i = 0; i < m_Rows; i++) {
			delete m_HeightMap[i];
	}
	delete m_HeightMap;
}

void HeightMapGenerator::generateHeightMap(unsigned int seed) {
	srand(seed);

	if (m_DeltaHeight == 0) {
		generateFlat();
		return;
	}
	
	unsigned int goUpChance = 5;
	unsigned int goDownChance = 10;
	unsigned int stayAtLowerChance = 55;
	unsigned int stayAtUpper = 100;

	int lowBound = -m_HeightOffset;
	int highBound = m_DeltaHeight - m_HeightOffset;

	// top left height
	m_HeightMap[0][0] = rand() % m_DeltaHeight - m_HeightOffset;
	
	setTopRow(goUpChance, goDownChance, lowBound, highBound);
	setLeftColumn(goUpChance, goDownChance, lowBound, highBound);

	int roll;
	int top;
	int bottom;

	for (int i = 1; i < m_Rows; i++) {
		for (int j = 1; j < m_Columns; j++) {
			top = m_HeightMap[i][j - 1] > m_HeightMap[i - 1][j] ? m_HeightMap[i][j - 1] : m_HeightMap[i - 1][j];
			bottom = m_HeightMap[i][j - 1] < m_HeightMap[i - 1][j] ? m_HeightMap[i][j - 1] : m_HeightMap[i - 1][j];
			roll = rand() % 100;

			if (top == bottom) {
				if (roll < goUpChance)
				{
					if (top < highBound)
						m_HeightMap[i][j] = top + 1;
					else
						m_HeightMap[i][j] = top;
				}
				else if (roll < goDownChance)
				{
					if (bottom > lowBound)
						m_HeightMap[i][j] = bottom - 1;
					else
						m_HeightMap[i][j] = bottom;
				}
				else {
					m_HeightMap[i][j] = top;
				}
			}
			else {
				if (roll < 50) {
					m_HeightMap[i][j] = top;
				}
				else {
					m_HeightMap[i][j] = bottom;
				}
			}
		}
	}

	generateObjectMap();
}



void HeightMapGenerator::setTopRow(int goUpChance, int goDownChance, int lowBound, int highBound)
{
	int roll;
	for (int i = 1; i < m_Columns; i++) {
		roll = rand() % 100;
		if (roll < goUpChance && m_HeightMap[0][i - 1] < highBound)
		{
			m_HeightMap[0][i] = m_HeightMap[0][i - 1] + 1;
		}
		else if (roll < goDownChance && m_HeightMap[0][i - 1] > lowBound)
		{
			m_HeightMap[0][i] = m_HeightMap[0][i - 1] - 1;
		}
		else
		{
			m_HeightMap[0][i] = m_HeightMap[0][i - 1];
		}
	}
}

void HeightMapGenerator::setLeftColumn(int goUpChance, int goDownChance, int lowBound, int highBound)
{
	int roll;
	for (int i = 1; i < m_Rows; i++) {
		roll = rand() % 100;
		if (roll < goUpChance && m_HeightMap[i - 1][0] < highBound)
		{
			m_HeightMap[i][0] = m_HeightMap[i - 1][0] + 1;
		}
		else if (roll < goDownChance && m_HeightMap[i - 1][0] > lowBound)
		{
			m_HeightMap[i][0] = m_HeightMap[i - 1][0] - 1;
		}
		else
		{
			m_HeightMap[i][0] = m_HeightMap[i - 1][0];
		}
	}
}

void HeightMapGenerator::generateFlat()
{
	for (int i = 0; i < m_Rows; i++) {
		for (int j = 0; j < m_Columns; j++) {
			m_HeightMap[i][j] = 0;
			if (i > 1 && i < m_Rows - 2 && j > 1 && j < m_Rows - 2)
				m_ObjectMap[i][j] = 2;
			else 
				m_ObjectMap[i][j] = 0;
		}
	}
}

void HeightMapGenerator::generateObjectMap()
{
	bool canHoldLarge = false;
	for (int i = 0; i < m_Rows; i++) {
		for (int j = 0; j < m_Columns; j++) {
			if (canPlaceLarge(i, j)) {
				m_ObjectMap[i][j] = 2;
			}
			else if (canPlaceMedium(i, j)) {
				m_ObjectMap[i][j] = 1;
			}
			else {
				m_ObjectMap[i][j] = 0;
			}
		}
	}
}

bool HeightMapGenerator::canPlaceLarge(int row, int col) {
	if (row < 2 || row > m_Rows - 3 || col < 2 || col > m_Columns - 3)
		return false;
	int height = m_HeightMap[row][col];

	for (int i = row - 2; i <= row + 2; i++) {
		for (int j = col - 2; j <= col + 2; j++) {
			if (m_HeightMap[i][j] != height)
				return false;
		}
	}
	return true;
}

bool HeightMapGenerator::canPlaceMedium(int row, int col) {
	if (row < 1 || row > m_Rows - 2 || col < 1 || col > m_Columns - 2)
		return false;

	int height = m_HeightMap[row][col];

	for (int i = row - 1; i <= row + 1; i++) {
		for (int j = col - 1; j <= col + 1; j++) {
			if (m_HeightMap[i][j] != height)
				return false;
		}
	}
	return true;
}



int** HeightMapGenerator::getHeightMap()
{
	return m_HeightMap;
}

int** HeightMapGenerator::getObjectMap()
{
	return m_ObjectMap;
}

void HeightMapGenerator::occupyPosition(int row, int col)
{
	int offset = m_ObjectMap[row][col];

	for (int i = row - offset; i <= row + offset; i++) {
		for (int j = col - offset; j <= col + offset; j++) {
			if (m_ObjectMap[i][j] == offset)
				m_ObjectMap[i][j]--;
		}
	}
}

unsigned int HeightMapGenerator::getRows()
{
	return m_Rows;
}

unsigned int HeightMapGenerator::getColumns()
{
	return m_Columns;
}
