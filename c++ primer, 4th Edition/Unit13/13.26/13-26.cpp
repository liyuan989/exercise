#include <iostream>
#include <string>

class HasPtr
{
public:
	HasPtr(int *p, int iv): ptr(new int(*p)), val(iv) {}
	HasPtr(const HasPtr &obj): ptr(new int(*obj.ptr)), val(obj.val) {}
	HasPtr& operator=(const HasPtr &obj)
	{
		*ptr = *obj.ptr;
		val = obj.val;
		return *this;
	}
	int* get_ptr() {return ptr;}
	int get_val() {return val;}
	int get_ptr_val() {return *ptr;}
	void set_ptr_val(int *p) {*ptr = *p;}
	~HasPtr(){delete ptr;}

private:
	int *ptr;
	int val;
};

int main(int argc, char const *argv[])
{
	HasPtr obj1(new int, 1);
	HasPtr obj2 = obj1;
	HasPtr obj3(NULL, 1);
	obj3 = obj1;
	return 0;
}