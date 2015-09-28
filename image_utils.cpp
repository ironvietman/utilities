/* Functions to help with Opencv images*/

#include "image_utils.h"


/*
* Function: readImage
* Usage: bool s = readImage(imageName, image);
* ----------------------------------------
* Returns true if image was read successfully. Reads it as grayscale
*/

bool readImage(string imageName, Mat& image)
{
	image = imread(imageName, IMREAD_GRAYSCALE); // Read the file

	if (!image.data) // Check for invalid input
	{
		cout << "Could not open or find the image" << std::endl;
		return false;
	}

	return true;
}
/*
* Function: displayImg
* Usage:  displayImg(image, name);
* ----------------------------------------
* Displays the image with <code>name</code> as title
*/
void displayImg(Mat image, string name)
{
	image.convertTo(image, CV_8U);
	namedWindow(name, WINDOW_AUTOSIZE); // Create a window for display.
	imshow(name, image); // Show our image inside it.
	cout << image(Range(0, 10), Range(0, 10)) << endl;
	return;
}
/*
* Function: addBoundingBox
* Usage:  addBoundingBox(image, mask,draw);
* ----------------------------------------
* Displays the bounding boxes from mask on the image. Returns vector of
* <code>Rect's</code> 
*/
vector<Rect> addBoundingBox(Mat& frame, Mat& mask, bool draw)
{
	vector< vector< cv::Point> > contours;
	Mat threshout = mask.clone();
	//cvtColor(threshout, threshout, COLOR_BGR2GRAY);
	//threshold(threshout, threshout, 1, 255, CV_THRESH_BINARY);
	//findContours will get the outer contours. any holes are not unique contours.
	findContours(threshout, contours, CV_RETR_EXTERNAL, CV_CHAIN_APPROX_SIMPLE, Point(0, 0)); //Use in Release mode only!!!

	/// Approximate contours to polygons + get bounding rects and circles
	vector<vector<Point> > contours_poly(contours.size());
	vector<Rect> boundRect(contours.size());
	for (int i = 0; i < contours.size(); i++)
	{
		//approxPolyDP(Mat(contours[i]), contours_poly[i], 3, true);
		boundRect[i] = boundingRect(Mat(contours[i]));
	}

	/// Draw polygonal contour + bonding rects + circles
	//cvtColor(frame, frame, CV_GRAY2RGB);
	if (draw)
	{
		RNG rng(12345);
		for (int i = 0; i < contours.size(); i++)
		{
			Scalar color = Scalar(rng.uniform(0, 255), rng.uniform(0, 255), rng.uniform(0, 255));
			rectangle(frame, boundRect[i].tl(), boundRect[i].br(), color, 2, 8, 0);
		}
	}
	return boundRect;
}