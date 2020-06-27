#pragma once
class Box
{
public:
	int getRow();
	int getCol();
	Box();
	Box(int,int);
	bool highlighted();
	void toggleHighlight();
	void render();
private:
	int row;
	int col;
	int currentColor[3];
	int originalColor[3];
	bool isHighlighted;
};

