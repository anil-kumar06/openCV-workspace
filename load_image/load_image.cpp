/**************************************************************************
A simple program to read an image file from disk and display it in a window.
***************************************************************************/

#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main(int argc, char** argv)
{
   // Read the image file -> please provide the image name with full path here.
   Mat image = imread("Demo_image.jpeg");

  // Check wether the image is loaded or not
  if (image.empty())
  {
    cout << "Could not open or find the image." << endl;
    cin.get(); //wait for any key press
    return -1;
  }

  // Rename the windo for the image
  String windowName = "Demo Image";

  //Create the window with default size.
  namedWindow(windowName, WINDOW_NORMAL);

  //Display the image inside the window.
  imshow(windowName, image);

  //wait for any key press 
  waitKey(0);

  if(getWindowProperty(windowName, 1) == -1)
    exit(-1);
    
  //Close the window.
  destroyWindow(windowName);

  return 0;
}
