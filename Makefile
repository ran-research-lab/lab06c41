p1: p1.cpp
	g++ -o p1 p1.cpp -std=c++20
p2: p2.cpp
	clang++ -o p2 p2.cpp -std=c++20 -lncurses -I/opt/conda/include
p3: p3.cpp
	g++ -o p3 p3.cpp -std=c++20 
clean:
	rm -f p1 p2 p3

installcompi: 
	conda install -y --solver=classic -c conda-forge gxx
	conda install -y --solver=classic -c conda-forge libffi
	conda install -y --solver=classic conda-forge::conda-libmamba-solver conda-forge::libmamba conda-forge::libmambapy conda-forge::libarchive