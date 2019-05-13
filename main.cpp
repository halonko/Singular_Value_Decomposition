#include <stdio.h>
#include <iostream>
#include "Matrix.h"
#include "functions.h"
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
//    cv::Mat image;
//    string image_name = argv[1];
//    vector<vector<vector<double>>> array;
//
//    read_from_image(image_name, image);
//
//    convert_image_to_vector(image, array);
//
//    convert_vector_to_image(image, array);
//
//    write_image(image_name, image);
    Matrix matrix(3, 2);
    matrix.set_data(0, 0, 4);
    matrix.set_data(0, 1, 11);
    matrix.set_data(2, 0, 14);
    matrix.set_data(1, 0, 8);
    matrix.set_data(1, 1, 7);
    matrix.set_data(2, 1, -2);
    vector<double> owner_double;
    vector<Matrix> owner_u;
    vector<Matrix> owner_v;
    SVD(matrix, owner_double, owner_u, owner_v);
    for(auto &douler:owner_double){
        cout << douler << endl;
    }
    for(auto &own_u:owner_u){
        own_u.transpose().print();
        cout << "=============" << endl;
    }
    for(auto &own_v:owner_v){
        own_v.print();
        cout << "=============" << endl;
    }
    return 0;
}