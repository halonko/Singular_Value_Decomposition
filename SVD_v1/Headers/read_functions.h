// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com
#ifndef CURS_WORK_READ_FUNCTIONS_H
#define CURS_WORK_READ_FUNCTIONS_H

#include <vector>
#include <opencv2/opencv.hpp>

void read_from_image(const std::string &name_of_image, cv::Mat &image);

void convert_image_to_vector(const cv::Mat &image, std::vector<std::vector<std::vector<double>>> &array);

void convert_vector_to_image(cv::Mat &image, const std::vector<std::vector<std::vector<double>>> &array);

void write_image(const std::string &name_of_image, cv::Mat &image);

#endif //CURS_WORK_READ_FUNCTIONS_H
