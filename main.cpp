/*
    Start shape drawing file
*/

#include <iostream>
#include "Framework.h"

// Variables with global scope - do not rename them, feel free to change values though

// Screen dimensions
int gScreenWidth{800};
int gScreenHeight{600};

// Delay to slow things down
int gTimeDelayMS{10};

using namespace std;

const int kNumCircles = 30;

int main()
{
	srand(time(0));
	
    cout << "Hello circles" << endl;

	//int radius{ 20 };
	
	
	
	//int x = rand() % (gScreenWidth - radius * 2);
	//int y = rand() % (gScreenHeight - radius * 2);

	
	//create arrays for each
	int x[kNumCircles];
	int y[kNumCircles];
	int xDir[kNumCircles];
	int yDir[kNumCircles];
	int radius[kNumCircles];
	unsigned char r[kNumCircles];
	unsigned char g[kNumCircles];
	unsigned char b[kNumCircles];
	unsigned char a[kNumCircles];


	//setup initial values
	for (int i = 0; i < kNumCircles; ++i)
	{
		radius[i] = rand() % 10 + 4;

		x[i] = rand() % (gScreenWidth - radius[i] * 2);
		y[i] = rand() % (gScreenHeight - radius[i] * 2);


		//TODO check if both directions are 0
		xDir[i] = rand() % 4+1;
		yDir[i] = rand() % 4+1;

		r[i] = rand() % 256;
		g[i] = rand() % 256;
		b[i] = rand() % 256;
		a[i] = 255;
		
	}

	while (UpdateFramework())
    {
		//Checking circles collisions with others
		for (int i = 0; i < kNumCircles; i++)
		{
			for (int j = i + 1; j < kNumCircles; j++)
			{
				float dx = x[i] - x[j];
				float dy = y[i] - y[j];

				//pythagoras
				float sum = (dx * dx) + (dy * dy);
				//float dist = sqrt(sum);

				float collisionDist = radius[i] + radius[j];
				collisionDist = collisionDist * collisionDist;

				//if (dist < radius[i] + radius[j])
				if (sum < collisionDist)
				{
					xDir[i] = -xDir[i];
					yDir[i] = -yDir[i];

					xDir[j] = -xDir[j];
					yDir[j] = -yDir[j];

					cout << "Collision!" << endl;
				
				}
			}


		for (int i = 0; i < kNumCircles; ++i)
		{   
			ChangeColour(r[i],g[i],b[i],a[i]);

			DrawCircle(x[i], y[i], radius[i]);


			//Bounce 
			x[i] = x[i] + xDir[i] / 2;
			if (x[i] >= gScreenWidth - radius[i] % 2 || x[i] < 0)
				xDir[i] = -xDir[i];


			y[i] = y[i] + yDir[i] / 2;
			if (y[i] >= gScreenHeight - radius[i] % 2 || y[i] < 0)
				yDir[i] = -yDir[i];


			//Random Direction
			/*int rd = rand() % 100;
			if (rd == 0)
			{
				xDir[i] = rand() % 4 + 1;
				yDir[i] = rand() % 4 + 1;

				radius[i] = rand() % 20 + 2;*/

				
			}
			//r[i] = r[i] + 1;
			//a[i] = a[i] - 1;
			//if (a[i] <= 20)
			//	a[i] = 50 + rand() % 50;

			/*radius[i]++;
			if (radius[i] > 50)
				radius[i] = 4;*/


			// Draws a circle at 100,200 with radius 20

		}
	}

	cout << "Bye bye" << endl;

	return 0;
}
