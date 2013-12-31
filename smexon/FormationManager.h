#ifndef FORMATIONMANAGER_H
#define FORMATIONMANAGER_H
#include <vector>
using namespace std;
// const int DXfactor = 5;
// const int DYfactor = 5;
// const float Dalpha = -5;
// const float Dangle = 0;


struct postion
{
public:
	float x,y;
};

enum Shape
{
	RECTANGLE,FWEDGE,BWEDGE
};



struct FormationData
{
public:
	int numOfUnits;
	float xFactor,yFactor,alpha,angle,width;
	Shape desiredShape;
	postion leaderPostion;

	FormationData(int p_NumberOfUnits,float p_xFactor,float p_yFactor,float p_alpha,float p_angle,float p_width,Shape p_DesiredShape,postion p_leaderPostion )
	{
		numOfUnits = p_NumberOfUnits;
		xFactor = p_xFactor;
		yFactor = p_yFactor;
		alpha = p_alpha;
		angle = p_angle;
		width = p_width;
		desiredShape = p_DesiredShape;
		leaderPostion = p_leaderPostion;
	}
	FormationData()
	{
		numOfUnits = 0;
		xFactor = 0;
		yFactor = 0;
		alpha = 0;
		angle = 0;
		width = 0;
		desiredShape = RECTANGLE;
	}
};

class FormationManager
{
public:
	FormationManager(void);
	FormationManager(FormationData p_Data);
	~FormationManager(void);
	vector<postion>& formUnits ();	
	void setParametars(FormationData p_Data);
	void setDesiredShape(Shape shape);
	void setXfactor(float x);
	void setYfactor(float y);
private:
	vector <postion> m_postions;
	int m_unitsPerLine;
	int m_numOfLines;

	FormationData m_Data;

};
#endif //!FORMATIONMANAGER_H
