#include<iostream>
using namespace std;
class Cal{
	private:
		int x,y;
	public:
		Cal() {
			x=0;
			y=0;
		}
		int add(int,int);
		int sub(int,int);
		int mul(int,int);
		int div(int,int);
};
int Cal::add(int x, int y){
	return x+y;
}
int Cal::sub(int x, int y){
        return x-y;
}
int Cal::mul(int x, int y){
        return x*y;
}
int Cal::div(int x, int y){
	if (y>0)
        return x/y;
}

int main()
{       Cal obj;
	cout<<"add is "<<obj.add(4,6)<<endl;
	cout<<"add is "<<obj.sub(4,6)<<endl;
	cout<<"add is "<<obj.mul(4,6)<<endl;
	cout<<"add is "<<obj.div(4,6)<<endl;
	cout<<"sailu "<<endl;
	return 0;
}
