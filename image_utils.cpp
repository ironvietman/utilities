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
* Function: readImage
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