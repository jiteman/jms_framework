#pragma once


#include "jmsf/cule/asserting/Assertion.hin"
#include "jmsf/cule/asserting/native_Assertion.hin"
#include "jmsf/cule/asserting/stl_Assertion.hin"


#define This( actual_value ) \
	::jmsf::cule::asserting::create_assertion( ( actual_value ), JMSF_FILE_AND_LINE )

#define This_native( actual_value ) \
	::jmsf::cule::asserting::create_native_assertion( ( actual_value ), JMSF_FILE_AND_LINE )

#define This_stl( actual_value ) \
	::jmsf::cule::assering::create_stl_assertion( ( actual_value ), JMSF_FILE_AND_LINE )
