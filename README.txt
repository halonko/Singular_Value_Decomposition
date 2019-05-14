This project implements SVD (Singular Value Decomposition) in the programming language C ++

You can read about the implementation of SVD in our report.
Our implementation is realized by two different methods, more precisely classes:
	- The first one - we realized fully our own class, which is a matrix class,
and gives the opportunity to use basic operations on them. However, due to its slowness and
great logarithmic complexity, use it is not wise.
	- The second one is the wrapper over the Eigen library, which greatly accelerated our code.

To run the program you need to download the program itself, as well as the C ++ language compiler and the Eigen and OpenCv libraries.

To run it is necessary to enter from the folder of one of the algorithms the following:
mkdir build && cd build && cmake .. -DCMAKE_BUILD_TYPE = Release && make && ./curs_work image_in image_out number_of_singular_values ​​&& cd .. && rm -R build

Run example:
	mkdir build && cd build && cmake .. -DCMAKE_BUILD_TYPE = Release && make && ./curs_work ./photos/2.jpeg ./results/result_2.jpeg 25 && cd .. && rm -R build

A number of tests were also written that allow you to test this class:
	mkdir build && cd build && cmake .. -DCMAKE_BUILD_TYPE = Release && make && ./tests ./photos/2.jpeg ./results/result_2.jpeg 25 && cd .. && rm -R build
	
Also in the project you can find graphs of the dependence of the size of the picture on the time of work, as well as the graph from the number of singular values to the time of work.
