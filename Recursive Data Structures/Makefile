all: filter_test simple_test tree_insert_test p2-tests

test: filter_test simple_test tree_insert_test p2-tests
	./simple_test > simple_test.out
	sdiff simple_test.out simple_test.out.correct
	./filter_test
	./tree_insert_test
	./p2-tests
	@echo "---All tests passed---"

simple_test: simple_test.cpp p2.cpp Recursive_list.cpp Binary_tree.cpp \
	      recursive.cpp test_helpers.cpp
	g++ -Wall -Werror -pedantic -O2 \
	      simple_test.cpp p2.cpp Recursive_list.cpp Binary_tree.cpp \
	      recursive.cpp test_helpers.cpp -o simple_test

filter_test: filter_test.cpp p2.cpp Recursive_list.cpp Binary_tree.cpp \
	      recursive.cpp test_helpers.cpp
	g++ -Wall -Werror -pedantic -O2 \
	      filter_test.cpp p2.cpp Recursive_list.cpp Binary_tree.cpp \
	      recursive.cpp test_helpers.cpp -o filter_test

tree_insert_test: tree_insert_test.cpp p2.cpp Recursive_list.cpp Binary_tree.cpp \
	      recursive.cpp test_helpers.cpp
	g++ -Wall -Werror -pedantic -O2 \
	      tree_insert_test.cpp p2.cpp Recursive_list.cpp Binary_tree.cpp \
	      recursive.cpp test_helpers.cpp -o tree_insert_test

p2-tests: p2-tests.cpp p2.cpp Recursive_list.cpp Binary_tree.cpp \
	      recursive.cpp test_helpers.cpp
	g++ -Wall -Werror -pedantic -O2 \
	      p2-tests.cpp p2.cpp Recursive_list.cpp Binary_tree.cpp \
	      recursive.cpp test_helpers.cpp -o p2-tests

clean:
	rm -vf p2-tests filter_test simple_test tree_insert_test *.out
