#include <iostream>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/opencv.hpp>


using namespace std;
using namespace cv;

// global variables

const int slider_max = 1	;
int slider;
Mat img;

// calback for trackbar

void on_trackbar(int pos, void *)
{
	Mat img_converted;
	if(pos > 0) cvtColor(img, img_converted,CV_RGB2GRAY);
	else img_converted = img;

	imshow("app",img_converted);

}

int main()
{
	img = imread("lena.jpeg");
	namedWindow("app");
	imshow("app",img);
	slider = 0;

	createTrackbar("RGB <-> Grayscale " ,"app",&slider, slider_max,on_trackbar);
	while (char(waitKey(1)) != 'q'){}
			return 0;
			}

