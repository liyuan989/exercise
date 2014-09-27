#include <iostream>
#include <string>

class Screen
{
public:
	typedef Screen& (Screen::*Action)();
	enum cm {HOME, FRONT, BACK, UP, DOWN};

	void move(cm num)
	{
		(this->*array[num])();
	}

	Screen& home()
	{
 	}

	Screen& front()
	{
	}

	Screen& back()
	{
	}

	Screen& up()
	{
	}

	Screen& down()
	{
	}

private:
	static Action array[];
};

Screen::Action Screen::array[] = {&home, &front, &back, &up, &down};