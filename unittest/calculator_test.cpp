#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../inc/calculator.h"

using namespace testing;

class MockCalculator_1 : public Calculator 
{
public:
    MOCK_METHOD(int, add, (int a, int b));
    MOCK_METHOD(int, subtract, (int a, int b));
    MOCK_METHOD(int, multiply, (int a, int b));
    MOCK_METHOD(int, divide, (int a, int b));
    MOCK_METHOD(int, complex_operator, (int a, int b));
};

class MockCalculator_2 : public Calculator 
{
public:
    MOCK_METHOD(int, add, (int a, int b));
    MOCK_METHOD(int, subtract, (int a, int b));
    MOCK_METHOD(int, multiply, (int a, int b));
};

TEST(CalculatorTest, Add_TC_001) 
{
    Calculator calc;

    EXPECT_EQ(calc.add(3, 4), 7);
    EXPECT_EQ(calc.add(-1, 5), 4);
    EXPECT_EQ(calc.add(0, 0), 0);
}

TEST(CalculatorTest, Subtract_TC_001)
{
    Calculator calc;

    EXPECT_EQ(calc.subtract(10, 4), 6);
    EXPECT_EQ(calc.subtract(-3, -2), -1);
    EXPECT_EQ(calc.subtract(0, 0), 0);
}

TEST(CalculatorTest, Divide_TC_001)
{
    Calculator calc;

    EXPECT_EQ(calc.divide(6, 2), 3);
    EXPECT_EQ(calc.divide(-4, 2), -2);
}

TEST(CalculatorTest, Divide_TC_002)
{
    Calculator calc;

    // Check if divide by zero throws an exception
    EXPECT_THROW(calc.divide(10, 0), std::invalid_argument);
}
    
TEST(CalculatorTest, Multiply_TC_001)
{
    Calculator calc;

    EXPECT_EQ(calc.multiply(3, 4), 12);
    EXPECT_EQ(calc.multiply(-2, 5), -10);
    EXPECT_EQ(calc.multiply(0, 100), 0);
}


TEST(CalculatorTest, ComplexOperation_TC_001)
{
    MockCalculator_2 mockCalc;

    // Setting expectations for the mocked methods
    EXPECT_CALL(mockCalc, add(_, _)).WillOnce(Return(15)); // Simulate add call returns 15
    EXPECT_CALL(mockCalc, subtract(_, _)).WillOnce(Return(5));  // Simulate subtract call returns 5
    EXPECT_CALL(mockCalc, multiply(_, _)).WillOnce(Return(75)); // Simulate multiply call returns 75

    // Call complex_operator with inputs that will trigger the mocked methods
    int result = mockCalc.complex_operator(1, 0); // This should call the mocked methods

    // Validate the final result
    EXPECT_EQ(result, 15 * 5); // Expect result to be 75 based on mocked return values
}

TEST(CalculatorTest, MyFunc_TC_001)
{
    MockCalculator_1 mockCalc;

    // Setting expectations for the mocked methods
    EXPECT_CALL(mockCalc, complex_operator(_, _))
        .Times(2)
        .WillOnce(Return(30)) // First call returns 30
        .WillOnce(Return(20)); // Second call returns 20

    // Mocking the add method
    EXPECT_CALL(mockCalc, add(_, _))
        .WillOnce(Return(50)); // Simulate add call returns 50

    // Call MyFunc with inputs a = 10 and b = 20
    int result = mockCalc.MyFunc(mockCalc, 10, 20);

    // Validate the final result: Since result1 (30) > result2 (20),
    // We expect add(30, 20) which returns 50
    EXPECT_EQ(result, 50);
}

TEST(CalculatorTest, MyFunc_TC_002)
{
    MockCalculator_1 mockCalc;

    // Setting expectations for the mocked methods
    EXPECT_CALL(mockCalc, complex_operator(_, _))
        .Times(2)
        .WillOnce(Return(10)) // First call returns 10
        .WillOnce(Return(20)); // Second call returns 20

    // Mocking the multiply method
    EXPECT_CALL(mockCalc, multiply(_, _))
        .WillOnce(Return(200)); // Simulate multiply call returns 200

    // Call MyFunc with inputs a = 10 and b = 20
    int result = mockCalc.MyFunc(mockCalc, 10, 20);

    // Validate the final result: Since result1 (10) < result2 (20),
    // We expect multiply(10, 20) which returns 200
    EXPECT_EQ(result, 200);
}
