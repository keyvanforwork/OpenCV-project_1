#include <iostream>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/core/utils/logger.hpp>

int main() {
	std::cout << "Open_cv version:" << CV_VERSION;
	cv::utils::logging::setLogLevel(cv::utils::logging::LogLevel::LOG_LEVEL_SILENT);
	// Read image
	std::string img_path = "directory address";
	cv::Mat img = cv::imread(img_path);
	cv::imshow("Image", img);
	cv::waitKey(0);

	// Read_video
	std::string vid_path = "directory address";
	cv::VideoCapture cap(vid_path);
	cv::Mat frame;
	while (true) {
		cap.read(frame);
		if (frame.empty())
			break;
		cv::imshow("Video", frame);
		cv::waitKey(20);
	}
	cv::waitKey(0);

	// Read_webcam
	cv::VideoCapture cap(0);
	cv::Mat frame;
	while (true) {
		cap.read(frame);
		if (frame.empty())
			break;
		cv::imshow("Webcam", frame);
		cv::waitKey(0);
	}
	cv::waitKey(0);

	return 0;
}