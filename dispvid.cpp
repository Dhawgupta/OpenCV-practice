#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace cv;
using namespace std;

int main(){
  // 0 is the id of inbuilt laptop camera
  VideoCapture cap(0);
  // check if the file was opened probpely

  if(!cap.isOpened()){
    cout<<"Capture could not be opened successfully"<<endl;
    return -1;

  }

  namedWindow("Video");
  // play the video unitl loop ends

  while(char(waitKey(1))!= 'q' && cap.isOpened())
  {
    Mat frame;
    cap >>frame;
    // check if the video is over
    if(frame.empty())
    {
      cout <<"Video Over"<<endl;
      break;

    }
    imshow("Video",frame);
  }
  return 0;
  
}
