// MobileFactory.cpp : ÄÜ¼Ö ÀÀ¿ë ÇÁ·Î±×·¥¿¡ ´ëÇÑ ÁøÀÔÁ¡À» Á¤ÀÇÇÕ´Ï´Ù.
//

#include "stdafx.h"
#include <iostream>
using namespace std;


int _tmain(int argc, _TCHAR* argv[])
{
	Time *time = new Time();
	int nInput = 0;
	
	while(1)
	{
		while(1)
		{
			cout << "Input Random Time  : " ;
			cin >> nInput;
			time->SetRandomTime(nInput);
			time->GetRandomTime();
			if (cin.fail())
			{
				cin.clear();
				cin.ignore(256,'\n');
				cout << "Please enter numbers only."<<endl;
			}
			else
			{
				break;
			}
		}
		while(1)
		{
			cout <<  "Input Start Time (0~23) : " ;
			cin >> nInput;
			time->SetStartTime(nInput);
			time->GetStartTime();
			if (time->GetStartTime() > 23)
			{
				time->PrintErrorMessage();			
			}
			else if (cin.fail())
			{
				cin.clear();
				cin.ignore(256,'\n');
				time->PrintErrorMessage();
			}
			else
			{
				break;
			}			
		}
		while(1)
		{
			cout << "Input End Time (0~23) : " ;
			cin >> nInput;
			time->SetEndTime(nInput);
			time->GetEndTime();
			if (time->GetEndTime() >23)
			{
				time->PrintErrorMessage();
			}
			else if (cin.fail())
			{
				cin.clear();
				cin.ignore(256,'\n');
				time->PrintErrorMessage();
			}
			else if (time->GetStartTime() == time->GetEndTime())
			{
				cout << "ËÒã·ãÁÊ¾ªÈğûÖõãÁÊ¾ªòÜ¬ªÎãÁÊ¾ªËìıÕôª·ªÆª¯ªÀªµª¤" <<endl;
				
			}
			else
			{
				break;
			}
		}
	
		time->Update();

		time->RealizeTime();
	}
	
	time->~Time();


	return 0;
}


