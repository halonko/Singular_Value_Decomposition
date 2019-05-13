// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com
#include <stdio.h>
#include <iostream>
#include <thread>
#include "my_matrix.h"
#include "functions.h"
#include "time_count.h"
#include "read_functions.h"

using std::stoi;
using std::cout;
using std::find;
using std::endl;
using std::vector;
using std::string;
using cv::imwrite;
using cv::cvtColor;
using std::ifstream;
using std::ofstream;
using cv::COLOR_BGR2Lab;
using cv::COLOR_Lab2BGR;

int main(int argc, char **argv) {
    if (argc != 4) {
        cout << "usage: image, result_image k: <path to image> <path to result image><number_of_singular_value>"
             << endl;
        return -1;
    }
    auto start_time = get_current_time_fenced();
    cv::Mat image, lab_image;
    string image_name = argv[1];
    string result_image_name = argv[2];
    int k = stoi(argv[3]);
    vector<vector<vector<double>>> array;

    read_from_image(image_name, image);
    cvtColor(image, lab_image, COLOR_BGR2Lab);

    convert_image_to_vector(lab_image, array);

    std::thread Thread1(run_SVD_on_matrix, std::ref(array[0]), k, std::numeric_limits<double>::min()),
                Thread2(run_SVD_on_matrix, std::ref(array[1]), k, std::numeric_limits<double>::min()),
                Thread3(run_SVD_on_matrix, std::ref(array[2]), k, std::numeric_limits<double>::min());

    Thread1.join();
    Thread2.join();
    Thread3.join();

    convert_vector_to_image(lab_image, array);
    cvtColor(lab_image, image, COLOR_Lab2BGR);
    write_image(result_image_name, image);

    auto end_time = get_current_time_fenced();
    cout << "Total time: " << to_us(end_time - start_time) << endl;

    return 0;
}