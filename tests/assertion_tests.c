#include <cgreen/cgreen.h>
#include <stdlib.h>
#include <stdio.h>

Ensure integer_one_should_assert_true() {
    assert_true(1);
}

Ensure integer_zero_should_assert_false() {
    assert_false(0);
}

Ensure one_should_assert_equal_to_one() {
    assert_equal(1, 1);
}

Ensure zero_should_assert_not_equal_to_one() {
    assert_not_equal(0, 1);
}

Ensure one_should_assert_double_equal_to_one() {
	TestAsserts *a = create_assert();
    assert_double_equal(1, 1);
    destroy_assert(a);
}

Ensure zero_should_assert_double_not_equal_to_one() {
	TestAsserts *a = create_assert();
    assert_double_not_equal(0, 1);
    destroy_assert(a);
}

Ensure a_double_with_four_digits() {
//	TestAsserts *a = create_assert();
	set_significant_figures(0.0001);
	assert_double_equal(1.1234, 1.1234);
//	destroy_assert(a);
}

Ensure a_double_with_eigth_digits() {
	set_significant_figures(0.001);
	assert_double_equal(1.12345678, 1.12345678);
}

Ensure a_double_with_classic_value() {
	TestAsserts *a = create_assert();
	set_significant_figures(0.0001);
	assert_double_equal(1.7976931348623157e+307, 1.797693e+307);
	set_significant_figures(0.01);
	assert_double_equal(2.0, 1.9999999f);
	assert_double_equal(2.0, 1.9);
	set_significant_figures(0.001);
	assert_double_equal(4.0, 8.0);
	destroy_assert(a);
}

Ensure identical_string_copies_should_match() {
    assert_string_equal("Hello", "Hello");
}

Ensure case_different_strings_should_not_match() {
    assert_string_not_equal("Hello", "hello");
}

Ensure null_string_should_only_match_another_null_string() {
    assert_string_equal(NULL, NULL);
    assert_string_equal("", "");
    assert_string_not_equal(NULL, "");
    assert_string_not_equal("", NULL);
}

Ensure null_string_should_only_match_another_null_string_even_with_messages() {
    assert_string_equal_with_message(NULL, NULL, "Oh dear");
    assert_string_equal_with_message("", "", "Oh dear");
    assert_string_not_equal_with_message(NULL, "", "Oh dear");
    assert_string_not_equal_with_message("", NULL, "Oh dear");
}

TestSuite *assertion_tests() {
    TestSuite *suite = create_test_suite();
    add_test(suite, integer_one_should_assert_true);
    add_test(suite, integer_zero_should_assert_false);
    add_test(suite, one_should_assert_equal_to_one);
    add_test(suite, zero_should_assert_not_equal_to_one);
    add_test(suite, one_should_assert_double_equal_to_one);
    add_test(suite, zero_should_assert_double_not_equal_to_one);
    add_test(suite, a_double_with_four_digits);
    add_test(suite, a_double_with_eigth_digits);
    add_test(suite, a_double_with_classic_value);
    add_test(suite, identical_string_copies_should_match);
    add_test(suite, case_different_strings_should_not_match);
    add_test(suite, null_string_should_only_match_another_null_string);
    add_test(suite, null_string_should_only_match_another_null_string_even_with_messages);
    return suite;
}

// add_tests(suite, stuff);
