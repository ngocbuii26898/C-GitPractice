
#include<iostream>
#include <math.h>
using namespace std;
class Mypoint
{
private:

	int mPosX;
	int mPosY;

public:



	Mypoint(int x, int y) {
		mPosX = x;
		mPosY = y;
	}
	void setmPosX(int x) {
		mPosX = x;
	}
	int getmPosX() {
		return mPosX;
	}
	void setmPosY(int y) {
		mPosY = y;
	}
	int getmPosY() {
		return mPosY;
	}
	void Display() {
		cout << "(" << mPosX << "," << mPosY << ")";
	}
	float Distance(Mypoint P) {
		float kc = sqrt((mPosX - P.mPosX) * (mPosX - P.mPosX) + (mPosY - P.mPosY) * (mPosY - P.mPosY));
		return kc;
	}
};



int main() {
	Mypoint* p1 = new Mypoint(4, 5);
	Mypoint* p2 = new Mypoint(2, 3);
	cout << p1->Distance(*p2);
	return 0;
}