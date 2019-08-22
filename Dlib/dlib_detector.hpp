#pragma once

#include <opencv2/opencv.hpp>

#include <dlib/opencv.h>
#include <dlib/image_processing/frontal_face_detector.h>
#include <dlib/image_processing/shape_predictor.h>

using namespace dlib;

class DlibDetector
{
private:
	frontal_face_detector detector;

public:
	DlibDetector();
	void Detect(const cv::Mat& img);
};