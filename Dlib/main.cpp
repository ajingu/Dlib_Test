#include <iostream>
#include <opencv2/opencv.hpp>

#include "dlib_detector.hpp"

using namespace std;
using namespace cv;

const string SHAPE_PREDICTOR_PATH = "data/shape_predictor_68_face_landmarks.dat";

int main()
{
	Mat img, roi, tmp, gray;

	VideoCapture cam(0);

	DlibDetector detector = DlibDetector(SHAPE_PREDICTOR_PATH);

	if (!cam.isOpened())
	{
		cerr << "Camera is not opened." << endl;
		return -1;
	}


	while (true) 
	{
		cam >> img;

		detector.Detect(img);

		imshow("Face", img);

		if (waitKey(10) == 'q')
		{
			cam.release();
			break;
		}
	}


	return 0;
}