/**
 * Unit Test suite
**/

#include <gtest/gtest.h>
#include "tappity.h"
 
class tappityTest : public ::testing::Test
{
	protected:
		tappityTest(){} 
		virtual ~tappityTest(){} 
		virtual void SetUp(){}
		virtual void TearDown(){}
};

TEST(tappity, sanityTest){
	ASSERT_TRUE(true);
}
TEST(tappity, constructorCheck){
	tappity tap("HelloWorld");
	ASSERT_TRUE(true);
}
TEST(tappity, entryCheck){
	tappity tap("Hello World");
	string input = "Hello World";
	tap.entry(input);
	ASSERT_EQ(1, 1);
}
TEST(tappity, length_difference_SameStr){
	tappity tap("Hello World");
	string input = "Hello World";
	tap.entry(input);
	ASSERT_EQ(0, tap.length_difference());
}
TEST(tappity, length_difference_SameLen_DiffStr){
	tappity tap("Hello World");
	string input = "ABCDEFGHIJK";
	tap.entry(input);
	ASSERT_EQ(0, tap.length_difference());
}
TEST(tappity, length_difference_DiffLen_InpSmaller_SimiStr){
	tappity tap("Hello World");
	string input = "Hello Wo";
	tap.entry(input);
	ASSERT_EQ(3, tap.length_difference());
}
TEST(tappity, length_difference_DiffLen_InpLarger_SimiStr){
	tappity tap("Hello World");
	string input = "hello world i am";
	tap.entry(input);
	ASSERT_EQ(5, tap.length_difference());
}
TEST(tappity, length_difference_DiffLen_InpLarger_DiffStr){
	tappity tap("Hello World");
	string input = "ABCDEFGHIJKLM";
	tap.entry(input);
	ASSERT_EQ(2, tap.length_difference());
}
TEST(tappity, length_difference_DiffLen_InpSmaller_DiffStr){
	tappity tap("Hello World");
	string input = "ABCDEFGH";
	tap.entry(input);
	ASSERT_EQ(3, tap.length_difference());
}
TEST(tappity, accuracy_SameStr){
	tappity tap("HelloWorld");
	string input = "HelloWorld";
	tap.entry(input);
	ASSERT_EQ(100, tap.accuracy());
}
TEST(tappity, accuracy_InpSmaller_SimiStr){
	tappity tap("HelloWorld");
	string input = "HelloWorl";
	tap.entry(input);
	ASSERT_EQ(90.00, tap.accuracy());
}
TEST(tappity, accuracy_InpLarger_SimiStr){
	tappity tap("HelloWorl");
	string input = "HelloWorld";
	tap.entry(input);
	ASSERT_EQ(90.00, tap.accuracy());
}
TEST(tappity, accuracy_UpCaseInp_SameStr){
	tappity tap("HelloWorld");
	string input = "HeLLOWORld";
	tap.entry(input);
	ASSERT_EQ(050.00, tap.accuracy());
}
TEST(tappity, accuracy_LowerCaseInp_SameStr){
	tappity tap("HeLLOWORld");
	string input = "HelloWorld";
	tap.entry(input);
	ASSERT_EQ(50, tap.accuracy());
}
TEST(tappity, accuracy_SameLen_DiffStr){
	tappity tap("HelloWorld");
	string input = "mynameisdd";
	tap.entry(input);
	ASSERT_EQ(10, tap.accuracy());
}
TEST(tappity, accuracy_SmallerInp_DiffStr){
	tappity tap("HelloWorld");
	string input = "menameisd";
	tap.entry(input);
	ASSERT_EQ(10, tap.accuracy());
}
TEST(tappity, accuracy_LargerInp_DiffStr){
	tappity tap("HelloWord");
	string input = "mynameisdd";
	tap.entry(input);
	ASSERT_EQ(10, tap.accuracy());
}