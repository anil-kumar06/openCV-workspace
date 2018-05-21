/**************************************************************************
A simple program to read a video file from disk and play it in a window.
***************************************************************************/

#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main(int argc, char* argv[])
{
  //Load and read the video file stored on disk.
  VideoCapture cap("Demo_video.mp4");
  //Change the video file name (Demo_video.mp4) to your video name with full path.

  //Validation for opening the video file.
  if (cap.isOpened() == false)
  {
    cout << "Cannot open the video file" << endl;
    cin.get(); //Waiting for any event.
    return -1;
  }

  //Rename the windo for the video
  String window_name = "My First Video";

  //Create the window with default size.
  namedWindow(window_name, WINDOW_NORMAL);

  //loop through the video frames.
  while (true)
  {
    Mat frame;

    //Reaading a fresh/new frame
    bool bSuccess = cap.read(frame);

    //if video is completed, break the loop.
    if (bSuccess == false)
    {
      cout << "Video Completed !!" << endl;
      break;
    }
    //Displaying the frame in the window created.
    imshow(window_name, frame);

    /* Waiting for 10 milliseconds in each iteration. Checking whether Esc is pressed or not.
       Since ASCII value of Esc is 27, the validation is ont the basis of 27. */
    if (waitKey(10) == 27)
    {
      cout << "You just pressed Esc key. Video Stopped !!!" << endl;
      break;
    }
  }

  return 0;
}
