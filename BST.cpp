#include "BST.h"

std::ostream& operator<<(std::ostream& out, const Color& color)
{
	if (color == Color::Black)
	{
		out << "Black";
	}
	else
	{
		out << "Red";
	}
	return out;
}
