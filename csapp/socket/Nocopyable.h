#ifndef __BLINK_NOCOPYABLE_H__
#define __BLINK_NOCOPYABLE_H__

namespace blink
{

// Empty base class emphasis the objects of derived class are nocopyable
class Nocopyable
{
protected:
	Nocopyable()
	{
	}

	~Nocopyable()
	{
	}

private:
	Nocopyable(const Nocopyable&);
	Nocopyable& operator=(const Nocopyable&);
};

}

#endif
