CC = g++  # use g++ compiler

FLAGS = -std=c++11  # compile with C++ 11 standard
FLAGS += -Wall      # compile with all warnings

INCLUDE = -I inc  # add include and test dirs to include path
FLAGS += $(INCLUDE)

LINK = $(CC) $(FLAGS) -o  # final linked build to binary executable

COMPILE = $(CC) $(FLAGS) -c  # compilation to intermediary .o files

# Added by Ibrahim, Use at your own RISK. Non-official version
default : clean print test_constructor test_get test_assign test_mul_assign test_add
	@echo Running All Tests
	@echo
	@./test_constructor
	@echo
	@./test_get
	@echo
	@./test_assign
	@echo
	@./test_mul_assign
	@echo
	@./test_add	
	@echo
	@echo "Press Enter if you want to test for memory leaks, else, Enter 'CTRL + C': "
	@read empty 
	@clear	
	@echo "testing 'test_constructor' for memory leaks: "
	@valgrind --leak-check=full --show-leak-kinds=all ./test_constructor 
	@echo "Press Enter if you want to test 'test_add' for memory leaks, else, Enter 'CTRL + C': "
	@read empty 
	@clear
	@echo "testing 'test_get' for memory leaks: "
	@valgrind --leak-check=full --show-leak-kinds=all ./test_get 
	@echo "Press Enter if you want to test 'test_assign' for memory leaks, else, Enter 'CTRL + C': "
	@read empty 
	@clear
	@echo "testing 'test_assign' for memory leaks: "
	@valgrind --leak-check=full --show-leak-kinds=all ./test_assign
	@echo "Press Enter if you want to test 'test_mul_assign' for memory leaks, else, Enter 'CTRL + C': "
	@read empty 
	@clear
	@echo "testing 'test_mul_assign' for memory leaks: "
	@valgrind --leak-check=full --show-leak-kinds=all ./test_mul_assign 
	@echo "Press Enter if you want to test 'test_add' for memory leaks, else, Enter 'CTRL + C': "
	@read empty 
	@clear
	@echo "testing 'test_add' for memory leaks: "
	@valgrind --leak-check=full --show-leak-kinds=all ./test_add 
	@echo
	@echo Done Testing!!! Good Luck
	@echo
print:
	clear
	@echo NON-OFFICIAL. MODIFIED BY IBRAHIM
	@echo
	@echo Compilining Code ...............
	@echo

# Ending of Added by Ibrahim, Use at your own RISK. Non-official version

test_constructor : test_matrix_constructor.o matrix.o
	@$(LINK) $@ $^

test_get : test_matrix_get.o matrix.o
	@$(LINK) $@ $^

test_assign : test_matrix_assign.o matrix.o
	@$(LINK) $@ $^

test_mul_assign : test_matrix_mul_assign.o matrix.o
	@$(LINK) $@ $^

test_add : test_matrix_add.o matrix.o
	@$(LINK) $@ $^

test_matrix_constructor.o : src/test_matrix_constructor.cc \
                            inc/test_matrix.h inc/matrix.h
	@$(COMPILE) $<

test_matrix_get.o : src/test_matrix_get.cc inc/test_matrix.h inc/matrix.h
	@$(COMPILE) $<

test_matrix_assign.o : src/test_matrix_assign.cc inc/test_matrix.h inc/matrix.h
	@$(COMPILE) $<

test_matrix_mul_assign.o : src/test_matrix_mul_assign.cc \
                           inc/test_matrix.h inc/matrix.h
	@$(COMPILE) $<

test_matrix_add.o : src/test_matrix_add.cc inc/test_matrix.h inc/matrix.h
	@$(COMPILE) $<

matrix.o : src/matrix.cc inc/matrix.h
	@$(COMPILE) $<

clean:
	@rm -f *.o test_constructor test_get test_assign test_mul_assign test_add
	@echo Executable files removed

valgrind:
	sudo apt install valgrind