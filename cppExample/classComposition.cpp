#include <iostream.h>
#include <math.h>
class Point	//Point�ඨ��
{
public:
	Point(int xx=0, int yy=0) {X=xx;Y=yy;}
	Point(Point &p);
	int GetX() {return X;}
	int GetY() {return Y;}
private:
	int X,Y;
};
Point::Point(Point &p)	//�������캯����ʵ��
{
	X=p.X;
	Y=p.Y;
	cout<<"Point�������캯��������"<<endl;
}
//��ľۼ�
class Distance	//Distance��Ķ���
{
public:	//�ⲿ�ӿ�
	Distance(Point xp1, Point xp2);
	double GetDis(){return dist;}
private:	//˽�����ݳ�Ա
	Point p1,p2;	//Point��Ķ���p1,p2
	double dist;	
};
//��ľۼ��Ĺ��캯��
Distance::Distance(Point xp1, Point xp2)
:p1(xp1),p2(xp2)
{
	cout<<"Distance���캯��������"<<endl;
	double x=double(p1.GetX()-p2.GetX());
	double y=double(p1.GetY()-p2.GetY());
	dist=sqrt(x*x+y*y);
}
//������
void main()
{
	Point myp1(1,1),myp2(4,5);	//����Point��Ķ���
	Distance myd(myp1,myp2);	//����Distance��Ķ���
	cout<<"The distance is:";
	cout<<myd.GetDis()<<endl;
}
