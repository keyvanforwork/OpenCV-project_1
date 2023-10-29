#include <iostream>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/core/utils/logger.hpp>

int main() {
	std::cout << "Open_cv version:" << CV_VERSION << '\n';
	cv::utils::logging::setLogLevel(cv::utils::logging::LogLevel::LOG_LEVEL_SILENT);
	// Read image
	std::string img_path = "C:\\Users\\k1\\source\\repos\\OpenCV-project_1\\OpenCV-project_1\\Resources\\pic.png";
	cv::Mat img = cv::imread(img_path);
	cv::Mat img_resize, img_crop;
	cv::Rect roi(200, 300, 300, 200);

	cv::resize(img, img_resize, cv::Size(), 0.5, 0.5);
	img_crop = img(roi);

	std::cout << img.size() << '\n';
	std::cout << img_resize.size() << '\n';
	std::cout << img_crop.size() << '\n';

	cv::imshow("Image", img);
	cv::imshow("Resized image", img_resize);
	cv::imshow("Crop image", img_crop);

	cv::waitKey(0);
	return 0;
}