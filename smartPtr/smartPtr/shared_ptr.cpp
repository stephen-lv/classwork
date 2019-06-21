#include<iostream>

#include<memory>
using namespace std;
class A
{
public:
	A() 
	{
		cout << "默认构造" << endl;
	};
	A(string a)
	{
		cout << "构造" << endl;
		this->data = a;
	}
	~A()
	{
		cout << "析构" << endl;
	}
	string data;
	static void func(void);
};
void A::func()
{
	cout << "helloworld" << endl;
}

void sharedPtr()
{
	string str("hello");

	shared_ptr<A> ptr(new A(str));
	cout << ptr.use_count() << endl;
	{
		shared_ptr<A> ptr2 = ptr;
		cout << ptr.use_count() << endl;
	}
	A * ss = ptr.get();
	cout << ss->data.data() << endl;
	shared_ptr<A> ptr3 = ptr;
	cout << ptr.use_count() << endl;



	shared_ptr<A> ptr4(new A[10], [](A* a) {delete[] a; });
	cout << ptr3.get()->data.data() << endl;
	cout << ptr.use_count() << endl;
	shared_ptr<A> ptr5 = make_shared<A>("hello world");



}

void uniquePtr()
{
	cout << "unique_ptr start" << endl;
	unique_ptr<A> ptr1(new A("HELLOW WORLD"));
	cout << ptr1.get()->data.data() << endl;
	unique_ptr<A> ptr2 = move(ptr1);//使用move函数转移所有权，原指针置为空
}



int main()
{
	cout << "main start..." << endl;
	sharedPtr();
	cout << "main end..." << endl;
	uniquePtr();
	system("pause");
	return 0;
}