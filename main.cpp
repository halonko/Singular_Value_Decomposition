#include <stdio.h>
#include <iostream>
#include <thread>
#include "my_matrix.h"
#include "functions.h"
#include "time_count.h"
#include "read_functions.h"

using std::cout;
using std::find;
using std::endl;
using std::vector;
using std::string;
using cv::imwrite;
using std::ifstream;
using std::ofstream;

int main(int argc, char **argv) {
    if (argc != 2) {
        cout << "usage: image: <path to image>" << endl;
        return -1;
    }
    auto start_time = get_current_time_fenced();
    cv::Mat image;
    string image_name = argv[1];
    vector<vector<vector<double>>> array;

    read_from_image(image_name, image);

    convert_image_to_vector(image, array);

    std::thread Thread1(run_SVD_on_matrix, std::ref(array[0]), 1, 1e-10),
                Thread2(run_SVD_on_matrix, std::ref(array[1]), 1, 1e-10),
                Thread3(run_SVD_on_matrix, std::ref(array[2]), 1, 1e-10);
    Thread1.join();
    Thread2.join();
    Thread3.join();

    convert_vector_to_image(image, array);

    write_image("123.jpeg", image);
    auto end_time = get_current_time_fenced();
    cout << to_us(end_time-start_time) << endl;
    return 0;
}