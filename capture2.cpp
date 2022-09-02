#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <opencv2/opencv.hpp>
 using namespace std;
 using namespace cv;

int main (int argc, char** argv) 
{
	VideoCapture capture("/home/manavi/Documents/ass4/Dark-Room-Laser-Spot-with-Clutter.mpeg");
	if (!capture.isOpened())
        {
            cout<<"No camera or video input!\n"<<endl;
            return -1;
        }
	Mat frame,gray,mat_diff,mat_gray_prev;
	unsigned int diffsum,maxdiff;
	double percent_diff;
	namedWindow("end image", WINDOW_NORMAL);
	namedWindow("original image", WINDOW_NORMAL);
	resizeWindow("end image",640,480);
	resizeWindow("original image",640,480);
	char difftext [50];
	while(!capture.read(frame)) {
	cout << "No frame" <<endl;
	waitKey(33);
    }	

	cvtColor(frame, gray, COLOR_BGR2RGB);
        mat_diff = gray.clone();
	mat_gray_prev = gray.clone();
        maxdiff = (mat_diff.cols)*(mat_diff.rows)*255;
	

while(1)
	{
	capture>>frame;
	imshow("original image",frame);
	cvtColor(frame,gray, COLOR_BGR2RGB);
	absdiff(mat_gray_prev,gray,mat_diff);
	diffsum = (unsigned int) sum(mat_diff)[0]; // single channel sum
	percent_diff = ((double)diffsum / (double)maxdiff)*100.0;
        printf("percent diff=%lf\n", percent_diff);
        sprintf(difftext, "%8d",  diffsum);
	if(percent_diff > 0.5) 
	{
		putText(mat_diff, difftext, Point(30,30), FONT_HERSHEY_COMPLEX_SMALL, 0.8, Scalar(200,200,250), 1, false);
	}
	imshow("end image",mat_diff);
	char c = waitKey(33);
	if( c ==27) break;
	}
destroyAllWindows();
}
