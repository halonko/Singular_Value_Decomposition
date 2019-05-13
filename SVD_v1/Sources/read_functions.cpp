// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com
#include "read_functions.h"


using cv::Mat;
using cv::Vec3b;
using std::cout;
using std::endl;
using cv::imread;
using cv::imwrite;
using std::string;
using std::vector;

void read_from_image(const string &name_of_image, Mat &image) {
    image = imread(name_of_image, 1);
    if (!image.data) {
        cout << "No image data." << endl;
        exit(-1);
    }
}

void convert_image_to_vector(const Mat &image, vector<vector<vector<double>>> &array) {
    array.clear();
    array.resize(3);
    for (size_t i = 0; i < image.rows; ++i) {
        for (size_t j = 0; j < image.cols; ++j) {
            auto &rgb = image.at<Vec3b>(i, j);
            for (int k = 0; k < 3; k++) {
                array.at(k).resize(image.rows);
                array.at(k).at(i).resize(image.cols);
                array.at(k).at(i).at(j) = static_cast<double>(rgb[k]);
            }
        }
    }
}

double normalize_value(const double &value) {
    return value < 0 ? 0 : value > 255 ? 255 : value;
}

void convert_vector_to_image(Mat &image, const vector<vector<vector<double>>> &array) {
    for (size_t i = 0; i < image.rows; ++i) {
        for (size_t j = 0; j < image.cols; ++j) {
            auto &rgb = image.at<Vec3b>(i, j);
            rgb[0] = static_cast<uchar>(normalize_value(array.at(0).at(i).at(j)));
            rgb[1] = static_cast<uchar>(normalize_value(array.at(1).at(i).at(j)));
            rgb[2] = static_cast<uchar>(normalize_value(array.at(2).at(i).at(j)));
        }
    }
}

void write_image(const string &name_of_image, Mat &image) {
    imwrite(name_of_image, image);
}
