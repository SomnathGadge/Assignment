// Geometry.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<cstdlib>
#include<cmath>
using namespace std;
class Projection
{
	float point1[2], point2[2], point3[2];
public:
	void accept(float *);
	void accept_points();
	void calculate_proj_b_on_a();
	float calculate_magnitude(float *);
};
class Min_Distance
{
	float point1[2], point2[2],array[50][2];
	int n;
public:
	void accept(float *a);
	void accept_points();
	void calculate_Min_distance();
};
class Rotate
{
	float point1[2], point2[2], theta;
public:
	void accept(float *a);
	void accept_points();
	void calculate_rotated_point();
};
class Distance
{
	float point1[3], point2[3], distance;
public:void accept_points();
	   void accept(float *);
	   void calculate_distance();
};
class MidPoint
{
	float point1[3], point2[3];
public:void accept_points();
	   void accept(float *);
	   void calculate_mid_point();

};
class Intersection
{
private:
	float point1[2], point2[2], point3[2], point4[2];
public:	
	void accept_points();
	void accept(float []);
	void calculate_intersection();
};
//logic to accept points
void Intersection::accept_points()
{
	cout << "Enter first Point:" << endl;
	accept(point1);
	cout << "Enter second point:" << endl;
	accept(point2);
	cout << "Enter third point:" << endl;
	accept(point3);
	cout << "Enter forth point:" << endl;
	accept(point4);
}
void Intersection::accept(float a[])
{
	for (int i = 0; i < 2; i++)
	{
		cin >> a[i];
	}
}
void Intersection::calculate_intersection()
{
	float slope1, slope2,x,y,c1,c2;
	slope1 = (float)(point2[1] - point1[1]) / (point2[0] - point1[0]);
	slope2 = (float)(point4[1] - point3[1]) / (point4[0] - point3[0]);
	c1 = point1[1] - slope1*point1[0];
	c2 = point3[1] - slope2*point3[0];
	if (slope1!=slope2&&c1!=c2)
	{
		x = (c2 - c1) / (slope1 - slope2);
		y = slope1*x + c1;
		cout << "intersection point is:" << x << "\t" << y << endl;

	}
	else
	{
		cout << "lines are parallel" << endl;
	}
}
void MidPoint::accept_points()
{
	cout << "Enter First Point:" << endl;
	accept(point1);
	cout << "Enter second point:" << endl;
	accept(point2);


}
void MidPoint::accept(float *a)
{
	for (int i = 0; i < 3; i++)
	{
		cin >> a[i];

	}
}
void MidPoint::calculate_mid_point()
{
	float mid[3];
	for (int i = 0; i < 3; i++)
	{
		mid[i] = (point1[i] + point2[i]) / 2;
	}
	for (int i = 0; i < 3; i++)
	{
		cout << mid[i] << "\t";
	}
	cout << endl;
}
void Distance::accept_points()
{

	cout << "Enter First Point:" << endl;
	accept(point1);
	cout << "Enter second point:" << endl;
	accept(point2);

}
void Distance::accept(float *a)
{
	for (int i = 0; i < 3; i++)
	{
		cin >> a[i];
	}
}
void Distance::calculate_distance()
{
	float sum = 0.0f;
	for (int i = 0; i < 3; i++)
	{
		sum = sum + (point2[i] - point1[i])*(point2[i] - point1[i]);
	}
	distance =sqrt(sum);
	cout << "distance between two point is:" << distance << endl;
}
void Rotate::accept(float a[])
{
	for (int i = 0; i < 2; i++)
	{
		cin >> a[i];
	}
}
void Rotate::accept_points()
{
	cout << "Enter First Point:" << endl;
	accept(point1);
	cout << "Enter second point:" << endl;
	accept(point2);

}
void Rotate::calculate_rotated_point()
{
	cout << "Enter value theta:\n";
	cin >> theta;
	float new_x = point2[0] * cosf(theta) - point2[1] * sinf(theta);
	float new_y= point2[0] * sinf(theta) + point2[1] * cosf(theta);
	cout << "\nrotated point is:" << round(new_x) << "\t" << round(new_y) << endl;
}
void Min_Distance::accept(float *a)
{
	for (int i = 0; i < 2; i++)
	{
		cin >> a[i];
	}
}
void Min_Distance::accept_points()
{
	cout << "Enter First Point:" << endl;
	accept(point1);
	cout << "Enter second point:" << endl;
	accept(point2);
	cout << "Enter how many points to be checked:" << endl;
	cin >> n;

	for (int i = 0; i< n; i++)
	{
		cout << "Enter" << i + 1 << "point:" << endl;
		for (int j = 0; j < 2; j++)
		{
			cin >> array[i][j];
		}
	}


}
void Min_Distance::calculate_Min_distance()
{
	float d,min=5698.0f;
	int j=0;
	for (int i = 0; i < n; i++)
	{
		d = abs((point2[1] - point1[1])*array[i][0] + (point2[0] - point1[0])*array[i][1] + point2[0] * point1[1] - point1[0] * point2[1]) / sqrt((point2[1]-point1[1])*(point2[1] - point1[1])+(point2[0]-point1[0])*(point2[0] - point1[0]));
		if (d < min)
		{
			min = d;
			j = i;
		}
	}
	cout << "point closest to a line:" <<array[j][0]<<"\t"<<array[j][1]<< endl;

}
void Projection::accept_points()
{	
	cout << "Enter first point:" << endl;
	accept(point1);
	cout << "Enter second point:" << endl;
	accept(point2);
	cout << "Enter any point :" << endl;
	accept(point3);

}
void Projection::accept(float *a)
{
	for (int i = 0; i < 2; i++)
	{
		cin >> a[i];
	}
}
float Projection::calculate_magnitude(float *a)
{
	float sum = 0.0f;
	float mg;
	for (int i = 0; i < 2; i++)
	{
		sum = sum + a[i] * a[i];
	}
	mg = sqrt(sum);
	return mg;

}
void Projection::calculate_proj_b_on_a()
{
	float dot=0.0f;
	float magnitude,ans;
	
	for (int i = 0; i < 2; i++)
	{
		dot = dot + point3[i] * point2[i];
	}
	magnitude=calculate_magnitude(point2);
	ans = dot / magnitude;
	
	float x_new=(point2[0] / magnitude)*ans;
	float y_new = (point2[1] / magnitude)*ans;
	cout << "coordinate of new point is:" << x_new << "\t" << y_new;
}

int main()
{
	
	int ch;
	Intersection obj;
	MidPoint mid;
	Distance distance;
	Rotate rotate;
	Min_Distance mindistance;
	Projection proj;
	do
	{
		
		cout << endl<<"***********************menu***************************\n";
		cout << endl << "1:calculate Intersection\n2:calculate mid point\n3:calculate distance between points\n4:rotate point\n5:point closest to a line\n6:projection\n7:exit" << endl;
		cout << "\nEnter your choice:" << endl;
		cin >> ch;
		//Intersection obj;
		switch (ch)
		{
		case 1:obj.accept_points();
				obj.calculate_intersection();
			break;
		case 2:mid.accept_points();
			mid.calculate_mid_point();
			break;
		case 3:distance.accept_points();
			distance.calculate_distance();
			break;
		case 4:rotate.accept_points();
			rotate.calculate_rotated_point();
			break;
		case 5:mindistance.accept_points();
			mindistance.calculate_Min_distance();
			break;
		case 6:proj.accept_points();
			proj.calculate_proj_b_on_a();
			break;
		case 7:exit(0);
			break;
		}

	} while (ch != 7);
    return 0;
}

