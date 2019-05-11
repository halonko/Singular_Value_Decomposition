#include <stdio.h>
#include <opencv2/opencv.hpp>

using std::cout;
using std::find;
using std::endl;
using std::vector;
using std::string;
using std::ifstream;
using std::ofstream;

int main(int argc, char **argv) {
    if (argc != 2) {
        cout << "usage: config.txt: <config.txt path>" << endl;
        return -1;
    }
    string in_file;
    vector<string> conf;
    ifstream file(argv[1]);
    while(file >> in_file){
        if(in_file != "="){
            conf.push_back(in_file);
        }
    }
    cout << *(find(conf.begin(), conf.end(), "1")) << endl;
//    out_file << "Result will be here";
    return 0;
}