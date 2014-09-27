#ifndef __SCREEN_H__
#define __SCREEN_H__

#include <iostream>
#include <string>

template<int h, int w>
class Screen;

template<int h, int w>
std::ostream& operator<<(std::ostream &os, const Screen<h, w> &obj);

template<int h, int w>
std::istream& operator>>(std::istream &in, Screen<h, w> &obj);

template<int h, int w>
class Screen
{
public:
	Screen()
		: screen(h * w, '#'), cursor(0), height(h), weight(w) { }
	friend std::ostream& operator<< <h, w>(std::ostream &os, const Screen &obj);
	friend std::istream& operator>> <h, w>(std::istream &in, Screen &obj);
	
private:
	std::string screen;
	size_t 		cursor;
	size_t 		height;
	size_t 		weight;
};

template<int h, int w>
std::ostream& operator<<(std::ostream &os, const Screen<h, w> &obj)
{
	os << obj.screen << "\t" << obj.cursor << "\t"
	   << obj.height << "\t" << obj.weight << std::endl;
}

template<int h, int w>
std::istream& operator>>(std::istream &in, Screen<h, w> &obj)
{
	in >> obj.cursor >> obj.height >> obj.weight;
}

#endif