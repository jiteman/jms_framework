#include "jmsf/cule/macroses_Test.h"


#include "jmsf/typeing/Comparison_result.h"


namespace jmsf {
namespace typeing {


CULE_TEST( Comparison_result, should_be_empty_if_created_by_default ) {
	This( Comparison_result() ).should_be_empty();
}

CULE_TEST( Comparison_result, should_not_be_empty_if_not_created_by_default ) {
	This( Comparison_result::create_equal() ).should_not_be_empty();
	This( Comparison_result::create_greater() ).should_not_be_empty();
	This( Comparison_result::create_less() ).should_not_be_empty();
}

CULE_TEST( Comparison_result, should_not_return_any_true_if_empty ) {
	const Comparison_result empty;

	This( empty.is_equal() ).should_not_be();
	This( empty.is_not_equal() ).should_not_be();
	This( empty.is_greater() ).should_not_be();
	This( empty.is_not_greater() ).should_not_be();
	This( empty.is_less() ).should_not_be();
	This( empty.is_not_less() ).should_not_be();
}

CULE_TEST( Comparison_result, should_be_equal_if_created_as_equal ) {
	Comparison_result equal_result = Comparison_result::create_equal();

	This( equal_result ).should_not_be_empty();
	This( equal_result.is_equal() ).should_be();
	This( equal_result.is_not_equal() ).should_not_be();
}

CULE_TEST( Comparison_result, should_be_greater_if_created_as_greater ) {
	Comparison_result greater_result = Comparison_result::create_greater();

	This( greater_result ).should_not_be_empty();
	This( greater_result.is_greater() ).should_be();
	This( greater_result.is_not_greater() ).should_not_be();
}

CULE_TEST( Comparison_result, should_be_less_if_created_as_less ) {
	Comparison_result less_result = Comparison_result::create_less();

	This( less_result ).should_not_be_empty();
	This( less_result.is_less() ).should_be();
	This( less_result.is_not_less() ).should_not_be();
}

CULE_TEST( Comparison_result, should_be_neither_greater_nor_less_if_created_as_equal ) {
	Comparison_result equal_result = Comparison_result::create_equal();

	This( equal_result.is_greater() ).should_not_be();
	This( equal_result.is_less() ).should_not_be();
}

CULE_TEST( Comparison_result, should_be_neither_equal_nor_less_if_created_as_greater ) {
	Comparison_result greater_result = Comparison_result::create_greater();

	This( greater_result.is_equal() ).should_not_be();
	This( greater_result.is_less() ).should_not_be();
}

CULE_TEST( Comparison_result, should_be_neither_equal_nor_greater_if_created_as_less ) {
	Comparison_result less_result = Comparison_result::create_less();

	This( less_result.is_equal() ).should_not_be();
	This( less_result.is_greater() ).should_not_be();
}


} // namespace typeing
} // namespace jmsf
