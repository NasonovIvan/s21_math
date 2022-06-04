CC = gcc
FLAG_C = -c
FLAG_O = -o
# ASAN = -g -fsanitize=address
FLAG_COV = --coverage
FLAG_ER = -Wall -Werror -Wextra -std=c11
s21_MATH_C = s21_*.c 
s21_MATH_O = s21_*.o
SUITE_CASES_C = suite_*.c
SUITE_CASES_O = suite_*.o

all: clean gcov_report
# --- СОЗДАНИЕ БИБЛИОТЕКИ ФУНКЦИЙ ---

s21_math.a:
	$(CC) $(FLAG_C) $(FLAG_ER) $(s21_MATH_C) 
	ar rc s21_math.a $(s21_MATH_O)
	ranlib s21_math.a
# --- СОЗДАНИЕ БИБЛИОТЕКИ ТЕСТОВ И ИСПОЛНЕНИЕ ---

test: s21_math.a
	$(CC) $(FLAG_C) $(FLAG_ER) $(SUITE_CASES_C) main.c
	ar rc suite_cases.a $(SUITE_CASES_O)
	ranlib suite_cases.a
	$(CC) $(FLAG_ER) $(FLAG_COV) $(FLAG_O) tests s21_math.a suite_cases.a $(s21_MATH_C) main.o -lcheck
	./tests
# --- ФОРМИРОВАНИЕ ОТЧЕТА О ПОКРЫТИИ ---

gcov_report: test
	gcov s21_*.gcda	
	gcovr -b 
	gcovr
	gcovr --html-details -o report.html

check:
	cppcheck --enable=all --force *.h *.c
	cp ../materials/linters/CPPLINT.cfg CPPLINT.cfg
	python3 ../materials/linters/cpplint.py --extension=c *.c *.h
	CK_FORK=no leaks --atExit -- ./tests
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose --log-file=RESULT_VALGRIND.txt ./tests

clean:
	-rm -rf *.o *.html *.gcda *.gcno *.css *.a *.gcov *.info *.out *.cfg *.txt
	-rm -f tests
	-rm -f report
	find . -type d -name 'tests.dSYM' -exec rm -r {} +
