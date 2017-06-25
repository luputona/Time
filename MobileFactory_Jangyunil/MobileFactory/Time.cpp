#include "StdAfx.h"
#include "Time.h"
#include <iostream>

using namespace std;



Time::Time(void):
m_inputStart(0),
m_inputEnd(0),
m_timeArraySize(0),
m_inputTime(0),
m_bcheckTime(false)
{	
	m_ptimeArray = new int[24];
	for (int i = 0; i< 24; i++)
	{
		m_ptimeArray[i] = NULL;
	}
}

Time::~Time(void)
{	
	for (int i = 0; i< 24; i++)
	{
		if (m_ptimeArray[i] == NULL)
		{
			delete [] m_ptimeArray;
		}
	}	
}

void Time::SetStartTime(int _nStartTime)
{
	m_inputStart = _nStartTime;
}

void Time::SetEndTime(int _nFinalTime)
{
	m_inputEnd = _nFinalTime;
}

void Time::SetRandomTime(int _nRandomTime)
{
	m_inputTime = _nRandomTime;
}

int Time::GetEndTime()
{
	return m_inputEnd;
}

int Time::GetStartTime()
{
	return m_inputStart;
}
int Time::GetRandomTime()
{
	return m_inputTime;
}

void Time::PrintTime()
{
	if (m_bcheckTime)
	{
		cout << "Find Data"<< endl;
	}
	else
	{
		cout << "Can't Find Data"<< endl;			
	}	
}

void Time::SearchTime()
{	
	if (m_inputStart < m_inputEnd)
	{
		for (int i = m_inputStart; i <= m_inputEnd; i++)
		{			
			m_ptimeArray[m_timeArraySize] = i;
			cout <<"high" << m_ptimeArray[m_timeArraySize] << ' ';
			m_timeArraySize++;			
		}			
	}
	else if(m_inputStart > m_inputEnd)
	{		
		for (int i = m_inputStart; i < 24; i++)
		{			
			m_ptimeArray[m_timeArraySize] = i;			
			cout << "low"<< m_ptimeArray[m_timeArraySize] << ' ';
			if (m_ptimeArray[m_timeArraySize] >= 23)
			{
				for (int i = 0; i <= m_inputEnd; i++)
				{
					m_ptimeArray[m_timeArraySize] = i;
					cout << "low"<< m_ptimeArray[m_timeArraySize] << ' ';
					m_timeArraySize++;
				}				
			}			
			m_timeArraySize++;
		}			
	}
	
	for (int i = 0;  i < m_timeArraySize; i++)
	{
		if (m_ptimeArray[i] == m_inputTime)
		{			
			m_bcheckTime = true;	
			break;
		}
		else
		{
			m_bcheckTime = false;
		}
	}	
}

void Time::Update()
{
	SearchTime();
	PrintTime();
}

void Time::RealizeTime()
{
	for (int i = 0; i < 24; i++)
	{
		m_ptimeArray[i] = NULL;
	}
}

void Time::PrintErrorMessage()
{
	cout << "Please enter numbers 0~23."<< endl;	
}

