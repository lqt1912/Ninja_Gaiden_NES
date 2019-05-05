#include "Grid.h"



void Grid::LoadResources()
{
}

void Grid::setRow(int row)
{
	this->number_of_rows = row;
}

void Grid::setColumn(int column)
{
	this->number_of_columns = column;
}

void Grid::setNumberOfCell(int num)
{
	this->number_of_cell = num;
}

int Grid::getColumn()
{
	return number_of_columns;
}

int Grid::getRow()
{
	return number_of_rows;
}

void Grid::AddCell(Cell* cell)
{
	listGrid.push_back(cell);
}

Cell* Grid::getCell(int id)
{
	return listGrid[id];
}

void Grid::Render(D3DXVECTOR2 trans, Camera* camera)
{
	int c = 0;
	for (int i = 0; i < listGrid.size(); i++)
	{
		if (isCollision(camera->GetBound(), listGrid[i]->getBound()) == 1)
		{
			listGrid[i]->Render(trans);
			//DebugOut((wchar_t*)L"\nLoad + %d ", c++);
		}
	}

	//DebugOut((wchar_t*)L"\n\n\n\n\n\n\n");
}

void Grid::Update(float dt, Camera* camera)
{
	int c = 0;
	for (int i = 0; i < listGrid.size(); i++)
	{
		if (isCollision(camera->GetBound(), listGrid[i]->getBound()) == 1)
		{
			listGrid[i]->Update(dt, camera);
			DebugOut((wchar_t*)L"\nUpdate + %d ", c++);
		}
	}
}

Grid::Grid()
{
}


Grid::~Grid()
{
}
