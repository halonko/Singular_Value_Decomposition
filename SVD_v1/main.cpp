#include <stdio.h>
#include <iostream>
#include <thread>
#include "Matrix.h"
#include "functions.h"
#include "time_count.h"
#include "read_functions.h"

using std::cout;
using std::find;
using std::endl;
using std::vector;
using std::string;
using cv::imwrite;
using cv::cvtColor;
using std::ifstream;
using std::ofstream;
using cv::COLOR_BGR2RGB;
using cv::COLOR_Lab2BGR;

int main(int argc, char **argv) {
    if (argc != 2) {
        cout << "usage: image: <path to image>" << endl;
        return -1;
    }
    auto start_time = get_current_time_fenced();
    cv::Mat image, lab_image;
    string image_name = argv[1];
    vector<vector<vector<double>>> array;

    read_from_image(image_name, image);
    cvtColor(image, lab_image, CV_BGR2Lab);

    convert_image_to_vector(lab_image, array);

    std::thread Thread1(run_SVD_on_matrix, std::ref(array[0]), 1, std::numeric_limits<double>::min()),
            Thread2(run_SVD_on_matrix, std::ref(array[1]), 1, std::numeric_limits<double>::min()),
            Thread3(run_SVD_on_matrix, std::ref(array[2]), 1, std::numeric_limits<double>::min());
    Thread1.join();
    Thread2.join();
    Thread3.join();

    convert_vector_to_image(lab_image, array);
    cvtColor(lab_image, image, CV_Lab2BGR);
    write_image("123.jpeg", image);
    auto end_time = get_current_time_fenced();
    cout << "Total time: " << to_us(end_time - start_time) << endl;
    return 0;
}