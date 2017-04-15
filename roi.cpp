#include <iostream>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

using namespace std;
using namespace cv;

bool ldown = false, lup = false;

// originla image
Mat img;

// starting ending points of the user selection

//Point type data
Point corner1, corner2;

// rect type data type
Rect box;

// callback for mouse events

static void mouse_callback(int event, int x, int y, int,void *)
{
	// when left button presed measue coordinate and save in corner
	if (event == EVENT_LBUTTONDOWN)
	{
		ldown = true;
		corner1.x = x;
		corner2.y = y;
		cout<<"Corner 1 recorded at" <<corner1<<endl;
	}
	// when left button is releases
	if(event == EVENT_LBUTTONUP)
	{
		if(abs(x - corner1.x) > 20 && abs(y - corner1.y) > 20){
		lup  = true;
		corner2.x = x;
		corner2.y = y;
		cout <<"Corner 2 recorded at"<<corner2<<endl;
	}
		else

		{
			cout <<"select a bigger rooi"<<endl;
			ldown = false;
		}
	}
	

	// update the box showing the selected regio as the user drag the mouse 
	//
	

	if(ldown = true && lup == false){
		Point pt;
		pt.x = x;
		pt.y = y;
		Mat local_img = img.clone();
		rectangle(local_img, corner1 , pt, Scalar(0,0,255));
		imshow("Cropapp",local_img);
	}

	// define roi and crop out when both have been selected
	if(ldown == true && lup  == true)
	{
		box.width = abs(corner1.x - corner2.x);
		box.height = abs(corner1.y - corner2.y);
		box.x  = min(corner1.x, corner2.x);
		box.y = min(corner1.y , corner2.y);
		Mat crop(img,box);
		namedWindow("crop");
		imshow("crop",crop);

		ldown = false;
		lup = false;
	}
}

int main()
{
	img = imread("lena.jpeg");
	namedWindow("Cropapp");
	imshow("Cropapp",img);
	 
	setMouseCallback("Cropapp",mouse_callback);

	// exit by oresng 'q'
	while(char(waitKey(1))!='q'){}
	return 0;
}

