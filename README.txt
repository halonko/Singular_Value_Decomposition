Даний проект реалізовує SVD(Singular Value Decomposition) на мові програмування C++

Про реалізацію SVD ви можете прочитати в нашому репорті.
Наша реалізація реалізована двома різними методами, а точніше класами:
	- Перший - ми реалізували повністю власний клас, який представляє собою клас Матриці, 
		та дає можливість використовувати базові операції наж ними. Проте через її повільність та 
		велику логарифмічну складність, вкористовувати її не є мудро.
	- Другий - це клас-обгортка над бібліотекою Eigen, яка значно пришвидшила наш код.
	
Для запуску програми Вам необхідно завантажити саму програму, а також компілятор мови C++ та бібліотеки Eigen та OpenCv

Щоб запустити необхідно ввести, з папки з одного з алгоритмів наступне:
	mkdir build && cd build && cmake .. -DCMAKE_BUILD_TYPE=Release && make &&  ./curs_work image_in image_out number_of_singular_values && cd .. && rm -R build

Приклад запуску:
	mkdir build && cd build && cmake .. -DCMAKE_BUILD_TYPE=Release && make &&  ./curs_work ./photos/2.jpeg ./results/result_2.jpeg 25 && cd .. && rm -R build
	
Також був написаний ряд тестів, які дозволяють відтестувати цей клас:
	mkdir build && cd build && cmake .. -DCMAKE_BUILD_TYPE=Release && make &&  ./tests ./photos/2.jpeg ./results/result_2.jpeg 25 && cd .. && rm -R build
