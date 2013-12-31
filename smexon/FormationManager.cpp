#include "FormationManager.h"

FormationManager::FormationManager(void)
{

}

FormationManager::~FormationManager(void)
{

}

void FormationManager:: setXfactor(float x)
{
	m_Data.xFactor = x;
}

void FormationManager:: setYfactor(float y)
{
	m_Data.yFactor = y;
}

vector<postion>& FormationManager:: formUnits ()
{
	//declarations 
	vector	<float> axis;
	int ratio = m_unitsPerLine/2, tmp = m_unitsPerLine/2;
	//==================================================================
	//units on the left to leader ... set x m_postions....................

	for(int i=0; i <= tmp -1 ;i++)
	{		
		axis.push_back(m_Data.leaderPostion.x - (ratio * m_Data.xFactor)); // push x m_postions to vector...
		ratio --;
	}
	ratio = 0;
	//---------------------------------------------------------------------------------------
	//units on the right to leader ... set x m_postions....................
	for(int i = tmp ; i < m_unitsPerLine; i++)
	{
		axis.push_back( m_Data.leaderPostion.x + (ratio * m_Data.xFactor));
		ratio ++;
	}	
	//--------------------------------------------------------------------------------------
	//set the m_postions x to axis repeatedly......
	int count = 0;
	postion temp;
	for (int i = 0 ; i < m_Data.numOfUnits ; i++)
	{
		if (count == m_unitsPerLine)
			count = 0;
		temp.x = axis [count];
		m_postions.push_back(temp);
		count ++;
	}
	//---------------------------------------------------------------------------------------
	int T1 = m_unitsPerLine/2;
	axis.clear();
	//=================================================================
	//units on the left to leader ... set y m_postions....................
	for(int i=0; i <= (m_unitsPerLine/2)-1 ;i++)
	{
		axis.push_back( m_Data.leaderPostion.y  + (T1 * m_Data.alpha));
		T1 --;  
	}
	//units on the right to leader ... set y m_postions....................
	T1 = 0;   
	for(int i = m_unitsPerLine/2 ; i < m_unitsPerLine; i++)
	{
		axis.push_back( m_Data.leaderPostion.y+ (T1 * m_Data.alpha));
		T1 ++;
	}	
	//=================================================================
	//set the m_postions y to axis repeatedly......
	count = 0;
	int count2 = 0;
	for (int i = 0 ; i < m_Data.numOfUnits ; i ++)
	{
		if (count == m_unitsPerLine)
		{
			count = 0;
			count2 ++;
		}
		m_postions[i].y = axis[count]+ (count2 * m_Data.yFactor);
		count ++; 
	}
	//angle...........................................................
	int size = m_postions.size();
	for (int i = 0 ; i < size ; i++ )
	{
		m_postions[i].x = m_Data.leaderPostion.x + cos(m_Data.angle) * (m_postions[i].x - m_Data.leaderPostion.x) - sin(m_Data.angle) * (m_postions[i].y - m_Data.leaderPostion.y);
		m_postions[i].y = m_Data.leaderPostion.y + sin(m_Data.angle) * (m_postions[i].x - m_Data.leaderPostion.x) + cos(m_Data.angle) * (m_postions[i].y - m_Data.leaderPostion.y);
	}
	axis.clear(); 
	return m_postions;
}

void FormationManager:: setParametars(FormationData param)
{
		m_Data.leaderPostion = param.leaderPostion;
		m_Data.alpha = param.alpha;
		m_Data.angle = param.angle;
		m_Data.desiredShape = param.desiredShape;
		m_Data.numOfUnits = param.numOfUnits;
		m_Data.width = param.width;
		m_Data.xFactor = param.xFactor;
		m_Data.yFactor = param.yFactor;
		m_unitsPerLine = m_Data.width / m_Data.xFactor;
		switch (m_Data.desiredShape)
		{
		case RECTANGLE:
			m_Data.alpha = 0;
			break;
		case FWEDGE:
			m_Data.alpha = -m_Data.alpha;
			break;
		case BWEDGE:
			m_Data.alpha = m_Data.alpha;
			break;
		}
}

void FormationManager:: setDesiredShape(Shape shape)
{
	m_Data.desiredShape = shape;
}