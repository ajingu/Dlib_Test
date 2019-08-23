#include "dlib_detector.hpp"

DlibDetector::DlibDetector(std::string shapePredictorPath)
{
	face_detector = get_frontal_face_detector();
	deserialize(shapePredictorPath) >> face_parts_predictor;
}

void DlibDetector::Detect(const cv::Mat& img)
{
	cv::Mat gray;

	cv::cvtColor(img, gray, cv::COLOR_BGR2GRAY);

	array2d<unsigned char> dlibImage;
	assign_image(dlibImage, cv_image<unsigned char>(gray));
	std::vector<dlib::rectangle> faces = face_detector(dlibImage);

	if (faces.size() > 0)
	{

		for (int i = 0; i < faces.size(); i++)
		{
			dlib::rectangle f = faces[i];
			int x1 = f.left();
			int y1 = f.top();
			int x2 = f.right();
			int y2 = f.bottom();

			cv::rectangle(img, cv::Point(x1, y1), cv::Point(x2, y2), cv::Scalar(0, 255, 0), 3);

			dlib::rectangle faceRoi(x1, y1, x2, y2);
			full_object_detection shape = face_parts_predictor(dlibImage, faceRoi);
			for (int j = 0; j < shape.num_parts(); j++)
			{
				dlib::point part = shape.part(j);
				cv::circle(img, cv::Point(part.x(), part.y()), 2, cv::Scalar(255, 255, 0), 1);
			}
		}

	}

}