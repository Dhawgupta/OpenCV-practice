#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main()
{
  VideoCapture cap(0);
  if(!cap.isOpened())
  {
    cout << "Capture failed to open the video stream"<<endl;
    return -1;
  }
  Size s = Size((int)cap.get(CV_CAP_PROP_FRAME_WIDTH),(int)cap.get(CV_CAP_PROP_FRAME_HEIGHT));

  // Make a video writer object and initialize it with 30 fps
  VideoWriter put("output.mpg",CV_FOURCC('M','P','E','G'),30,s);
  // put contains the file name with the codec of mpeg 30 fps speed and S size
  if(!put.isOpened())
  {
    cout<<"FIle could not be created for writing . Check Permission" <<endl;
    return -1;

  }
  namedWindow("Video");
  // play the video in a loop till it ends
  while(char(waitKey(1))!='q' && cap.isOpened())
  {
    Mat frame;
    cap >> frame;
    //  check if video is empty
    if(frame.empty())
    {
      cout<<"Video Khatam Paisa Haazm";
      break;

    }
    imshow("Video",frame);
    put <<frame;
  }
  return 0;
}
