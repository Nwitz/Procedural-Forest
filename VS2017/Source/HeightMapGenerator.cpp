#pragma once
#include "HeightMapGenerator.h"
#include <stdlib.h>
#include <time.h>

HeightMapGenerator::HeightMapGenerator(unsigned int rows, unsigned int columns, unsigned int deltaHeight)
	: m_Rows(rows), m_Columns(columns), m_DeltaHeight(deltaHeight), m_HeightOffset(deltaHeight/2)
{
	m_HeightMap = new int*[rows];
	for (unsigned int i = 0; i < rows; i++) {
		m_HeightMap[i] = new int[columns];
 	}
}

HeightMapGenerator::~HeightMapGenerator()
{
}

void HeightMapGenerator::generateHeightMap(unsigned int seed) {
	srand(seed);

	if (m_DeltaHeight == 0) {
		generateFlat();
		return;
	}
	
	unsigned int goUpChance = 10;
	unsigned int goDownChance = 20;
	unsigned int stayAtLowerChance = 60;
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
		}
	}
}

int** HeightMapGenerator::getHeightMap()
{
	return m_HeightMap;
}

unsigned int HeightMapGenerator::getRows()
{
	return m_Rows;
}

unsigned int HeightMapGenerator::getColumns()
{
	return m_Columns;
}
