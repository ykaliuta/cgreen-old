#include "../cgreen.h"
#include <stdlib.h>
#include <stdio.h>

void these_should_be_true() {
    assert_true(1);
}

void these_should_be_false() {
    assert_false(0);
}

void these_should_be_equal() {
    assert_equal(1, 1);
}

void these_should_not_be_equal() {
    assert_not_equal(0, 1);
}

void these_strings_should_match() {
    assert_string_equal("Hello", "Hello");
}

void these_strings_should_not_match() {
    assert_string_not_equal("Hello", "hello");
}

TestSuite *assertion_tests() {
    TestSuite *suite = create_test_suite();
    add_test(suite, these_should_be_true);
    add_test(suite, these_should_be_false);
    add_test(suite, these_should_be_equal);
    add_test(suite, these_should_not_be_equal);
    add_test(suite, these_strings_should_match);
    add_test(suite, these_strings_should_not_match);
    return suite;
}