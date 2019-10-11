#! /usr/bin/env python

import os
import subprocess

from fnmatch import fnmatch

test_exe_pattern = 'List_test_*.exe'

test_exes = [filename for filename in os.listdir('.')
             if fnmatch(filename, test_exe_pattern)]

num_tests_run = 0
num_tests_passed = 0

num_valgrind_errors = 0

for test in test_exes:
    return_code = subprocess.call(['./' + test])
    num_tests_run += 1
    if return_code == 0:
        num_tests_passed += 1

for test in test_exes:
    valgrind_return_code = subprocess.call(
        ['valgrind', '--leak-check=full', '--error-exitcode=1', './' + test])
    if valgrind_return_code != 0:
        num_valgrind_errors += 1
        print('valgrind error in test: ' + test)


print('''Out of {0} tests run:
{1} tests passed,
{2} tests failed.
{3} valgrind errors
'''.format(
    num_tests_run,
    num_tests_passed,
    num_tests_run - num_tests_passed,
    num_valgrind_errors))
