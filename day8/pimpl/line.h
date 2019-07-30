#pragma once

#include <stdio.h>
#include <iostream>

class Line{
	class LineImpl;
public:
	Line(int, int, int, int);
	~Line();

	void printLine() const;
private:
	LineImpl *_pimpl;
};
