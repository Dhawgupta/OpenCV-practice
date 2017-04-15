#include <iostream>
#include <opencv2/opencv.hpp>

#include <opencv2/highgui/highgui.hpp>
using namespace std;
using namespace cv;

int main(int argc, char **argv)
{
	Mat im = imread("lena.jpeg",CV_LOAD_IMAGE_COLOR);
	namedWindow("hello");
	imshow("hello", im);
	Mat im2;
	cvtColor(im,im2,CV_RGB2GRAY); // converting from rgb to gray
	namedWindow("hello gray");
	imshow("hello gray",im2);
	
	
	cout<<"Press 'q' to quit .. "<<endl;
	while(char(waitKey(1))!= 'q'){}
	return 0;
}


