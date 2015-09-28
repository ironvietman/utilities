#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>

using namespace cv;
using namespace std;

/*
* Function: readImage
* Usage: bool s = readImage(imageName, image);
* ----------------------------------------
* Returns true if image was read successfully. Reads it as grayscale
*/
bool readImage(string imageName, Mat& image);

/*
* Function: displayImg
* Usage:  displayImg(image, name);
* ----------------------------------------
* Displays the image with <code>name</code> as title
*/
void displayImg(Mat image, string name);

/*
* Function: addBoundingBox
* Usage:  addBoundingBox(image, mask);
* ----------------------------------------
* Displays the bounding boxes from mask on the image. Returns vector of
* <code>Rect's</code>
*/
vector<Rect> addBoundingBox(Mat& frame, Mat& mask, bool draw);