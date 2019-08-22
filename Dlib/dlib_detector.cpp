#include "dlib_detector.hpp"

DlibDetector::DlibDetector()
{
	detector = get_frontal_face_detector();
}

void DlibDetector::Detect(const cv::Mat& img)
{
	cv::Mat gray;

	cv::cvtColor(img, gray, cv::COLOR_BGR2GRAY);

	array2d<unsigned char> dlibImage;
	assign_image(dlibImage, cv_image<unsigned char>(gray));
	std::vector<dlib::rectangle> faces = detector(dlibImage);

	if (faces.size() > 0)
	{

		for (int i = 0; i < faces.size(); i++)
		{
			int x1 = faces[i].left();
			int y1 = faces[i].top();
			int x2 = faces[i].right();
			int y2 = faces[i].bottom();
			cv::rectangle(img, cv::Point(x1, y1), cv::Point(x2, y2), cv::Scalar(0, 255, 0), 3);
		}

	}

}