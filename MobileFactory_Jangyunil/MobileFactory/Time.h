#pragma once
#include <list>
using namespace std;
class Time
{
private:
	int m_inputStart;
	int m_inputEnd;
	int m_inputTime;
	int *m_ptimeArray;
	int m_timeArraySize;
	bool m_bcheckTime;
public:
	Time(void);
	~Time(void);

	void Update();
	void SetRandomTime(int _nRandomTime);
	void SetStartTime(int _nStartTime);
	void SetEndTime(int _nFinalTime);	
	void InputRandomTime();
	void InputStartTime();
	void InputEndTime();
	void SearchTime();
	void PrintTime();
	int GetEndTime();
	int GetStartTime();	
	int GetRandomTime();
	void RealizeTime();
	void PrintErrorMessage();

};

