#include <iostream>
#include <cstdio>

using namespace std;

int main(int argc, char**argv)
{
	//freopen("../sample-input.txt", "r", stdin);
	//freopen("../output.txt", "w", stdout);

	for (int nCase = 1; ; nCase++)
	{
		double H, U, D, F;
		// H is the height of the well in feet
		// U is the distance in feet that the snail can climb during the day
		// D is the distance in feet that the snail slides down during the night
		// F is the fatigue factor expressed as a percentage

		cin >> H >> U >> D >> F;
		if (H <= 0)
			break;
		
		int eplasedDay = 0;
		double completedHeight = 0;
		double fatigueFactor = U * F/100;

		double prevDayClimb = U;
		double todayClimb = 0;
		double fatigueValue = 0;
		while (completedHeight >= 0 && completedHeight <= H)
		{
			eplasedDay++;
			if (eplasedDay > 1)
			{
				fatigueValue = fatigueFactor;
			}

			todayClimb = prevDayClimb - fatigueValue; // Today's climbing distance
			if (todayClimb > 0) {
				prevDayClimb = todayClimb;
				completedHeight += todayClimb; // Climb
				if (completedHeight > H)
					break;
			}
			else {
				prevDayClimb = 0; // No climb on negetive distance
			}

			completedHeight -= D; // Slide
			//if (completedHeight < 0)
			//	break;							
		}

		if (completedHeight < 0)
			cout << "failure on day " << eplasedDay << endl;

		if(completedHeight > H)
			cout << "success on day " << eplasedDay << endl;
	}

	return 0;
}