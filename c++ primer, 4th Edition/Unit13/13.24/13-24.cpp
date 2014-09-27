#include <iostream>
#include <string>

class smart_ptr
{
public:
	friend class HasPtr;
	smart_ptr(int *p): ip(p), count(1) {}
	~smart_ptr() {delete ip;}

private:
	int *ip;
	size_t count;
};

class HasPtr
{
public:
	HasPtr(int *p): ptr(new smart_ptr(p)), val(0) {}
	HasPtr(const HasPtr & obj): ptr(obj.ptr), val(obj.val) {++ptr->ip;}
	HasPtr& operator=(const HasPtr &obj)
	{
		++obj.ptr->count;
		if (--ptr->count == 0)
		{
			delete ptr;
		}
		ptr = obj.ptr;
		val = obj.val;
		return *this;
	}
	~HasPtr()
	{
		if (--ptr->ip)
		{
			delete ptr;
		}
	}
	int* get_ptr() {return ptr->ip;}
	int get_val() {return val;}
	int get_ptr_val() {return *ptr->ip;}
	void set_ptr_val() {*ptr->ip;} 

private:
	smart_ptr *ptr;
	int val;
};

int main(int argc, char const *argv[])
{
	HasPtr obj1(new int);
	int *p = new int;
	*p = 2;
	HasPtr obj2(p);
	obj1 = obj2;
	HasPtr obj3 = obj1;
	return 0;
}