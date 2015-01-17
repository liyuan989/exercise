#ifndef __BLINK_TYPES_H__
#define __BLINK_TYPES_H__

namespace blink
{

template<typename To, typename From>
inline To implicit_cast(const From& f)
{
	return f;
}

}  // namespace blink

#endif
