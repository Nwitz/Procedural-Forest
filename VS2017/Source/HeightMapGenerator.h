#pragma once
#include <time.h>
#include <vector>

class HeightMapGenerator {
public: 
	HeightMapGenerator(unsigned int rows, unsigned int columns, unsigned int deltaHeight);
	~HeightMapGenerator();
	void generateHeightMap(unsigned int seed = time(NULL));
	void generateFlat();
	int** getHeightMap();
	int** getObjectMap();
	unsigned int getRows();
	unsigned int getColumns();

private: 
	unsigned int m_Rows;
	unsigned int m_Columns;
	unsigned int m_DeltaHeight;
	unsigned int m_HeightOffset;
	
	int** m_HeightMap;
	int** m_ObjectMap;

	void generateObjectMap();

	void setTopRow(int goUpChance, int goDownChance, int lowBound, int highBound);
	void setLeftColumn(int goUpChance, int goDownChance, int lowBound, int highBound);

	bool canPlaceLarge(int, int);
	bool  canPlaceMedium(int, int);
};