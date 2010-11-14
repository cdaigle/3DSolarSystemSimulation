/**
 * supportingClasses.cpp - all the supporting classes being used
 *  this includes vectors, points, and other classes/functions
 */

class Point3{ 
public: 
	float x,y,z;
	void set(float dx, float dy, float dz){x = dx; y = dy; z = dz;}
	void set(Point3& p){x = p.x; y = p.y; z = p.z;} 	
 	Point3(float xx, float yy, float zz){x = xx; y = yy; z = zz;}
	Point3(){x = y = z = 0;}
	void build4tuple(float v[])
	{// load 4-tuple with this color: v[3] = 1 for homogeneous
		v[0] = x; v[1] = y; v[2] = z; v[3] = 1.0f;
	}	
};

class Vector3{ 
public: 
	float x,y,z;
	void set(float dx, float dy, float dz){ x = dx; y = dy; z = dz;} 
	void set(Vector3& v){ x = v.x; y = v.y; z = v.z;}
	void set(const Vector3& v){ x = v.x; y = v.y; z = v.z;}
	void flip(){x = -x; y = -y; z = -z;} // reverse this vector
	void setDiff(Point3& a, Point3& b)//set to difference a - b
	{ x = a.x - b.x; y = a.y - b.y; z = a.z - b.z;}
	void normalize()//adjust this vector to unit length
	{		
		double sizeSq = x * x + y * y + z * z;
		if(sizeSq < 0.0000001)
		{
			cerr << "\nnormalize() sees vector (0,0,0)!";
			return; // does nothing to zero vectors;
		}
		float scaleFactor = 1.0/(float)sqrt(sizeSq);
		x *= scaleFactor; y *= scaleFactor; z *= scaleFactor;
	}
	Vector3(float xx, float yy, float zz){x = xx; y = yy; z = zz;}
	Vector3(const Vector3& v){x = v.x; y = v.y; z = v.z;}
	Vector3(){x = y = z = 0;} //default constructor
	Vector3 cross(Vector3 b) //return this cross b
	{
	   Vector3 c(y*b.z - z*b.y, z*b.x - x*b.z, x*b.y - y*b.x);
	   return c;
	}
	Vector3 dividedby(float d) //return this divided by d
	{
	   Vector3 c(x/d, y/d, z/d);
	   return c;
	}
	Vector3 multipliedby(float d) //return this multiplied by d
	{
	   Vector3 c(x*d, y*d, z*d);
	   return c;
	}
	Vector3 add(Vector3 b) //return this plus b
	{
	   Vector3 c(x+b.x, y+b.y, z+b.z);
	   return c;
	}
	Vector3 minus(Vector3 b) //return this minus b
	{
	   Vector3 c(x-b.x, y-b.y, z-b.z);
	   return c;
	}	
	float dot(Vector3 b) // return this dotted with b
           {return x * b.x + y * b.y + z * b.z;}
};
