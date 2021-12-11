#include <iostream>
#include <cmath>
using namespace std;
void checkValidInput(){
	if(cin.fail()){
		throw "Incorrect Input";
	}
}
void checkValidParams(int n){
	if(n<3) throw "Input Correct Data";
}
int calculate(int x,int n){
	float sum, prod;
	
	sum = 0;
	prod = 1;
	if (x < 0) {
		for (int j = 2; j <= n - 2;j++) {
			prod *= j + x;
		}
		return prod;
	}
	else {
		for (int i = 0; i <= n ; i++) {
			for (int j = 0; j <= n; j++) {
				prod *= x + i +pow(j,2);
			}
			sum += prod;
			prod = 1;
		}
		return sum;
	}
}
int main()
{
	try{
	int n;
	float x;
	cout << "input n=>3\n";
	checkValidInput();
	checkValidParams(n);
	cout<< "input x\n";
	cin >> x >> n;
	checkValidInput();
	cout<<"y = "<<calculate(x,n);
	}
	catch(const char* ex){
		cout<<ex<<endl;
		return -1;
	}
	catch(...){
	 	cout<<""Uknown expression";
		return -2;
	}
}
