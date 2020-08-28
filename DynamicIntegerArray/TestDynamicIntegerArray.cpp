#include <gtest/gtest.h>
#include "DynamicIntegerArray.cpp"

class DynamicIntegerArrayTests : public ::testing::Test
{
protected:
    DynamicIntegerArray dynamicIntArray;
};

TEST_F(DynamicIntegerArrayTests, CanInstantiateDIntArrayWithSize) { 
    DynamicIntegerArray dynamicIntArrWithSize(20);
}

TEST_F(DynamicIntegerArrayTests, CanThrowExceptionForNegativeCapacity)
{        
    EXPECT_NO_THROW(DynamicIntegerArray dynamicIntArrWithSize(20));
    EXPECT_ANY_THROW(DynamicIntegerArray dynamicIntArrWithSize(-1));
}

TEST_F(DynamicIntegerArrayTests, CanReturnTotalSize) { 
    int size = dynamicIntArray.size();
    ASSERT_EQ(0, size);

    dynamicIntArray.insert(50);
    size = dynamicIntArray.size();
    ASSERT_EQ(1, size);
}

TEST_F(DynamicIntegerArrayTests, CanGrowingArrayReturnTotalSize) { 
    dynamicIntArray.insert(50);
    dynamicIntArray.insert(50);
    dynamicIntArray.insert(50);
    dynamicIntArray.insert(50);
    dynamicIntArray.insert(50);
    dynamicIntArray.insert(50);
    dynamicIntArray.insert(50);
    dynamicIntArray.insert(50);
    dynamicIntArray.insert(50);
    dynamicIntArray.insert(50);
    dynamicIntArray.insert(50);

    int size = dynamicIntArray.size();
    ASSERT_EQ(11, size);

    dynamicIntArray.insert(50);
    size = dynamicIntArray.size();
    ASSERT_EQ(12, size);
}

TEST_F(DynamicIntegerArrayTests, CanProcessValueByIndex) { 

    dynamicIntArray.insert(50);
    dynamicIntArray.insert(150);
    dynamicIntArray.insert(250);
    dynamicIntArray.insert(350);

    int elementByIndex = dynamicIntArray.getAt(1);
    int size = dynamicIntArray.size();
    ASSERT_EQ(150, elementByIndex);
    ASSERT_EQ(4, size);

    dynamicIntArray.insertAt(300, 2);
    elementByIndex = dynamicIntArray.getAt(2);
    size = dynamicIntArray.size();
    ASSERT_EQ(300, elementByIndex);
    ASSERT_EQ(5, size);

    dynamicIntArray.insertAt(1000, 5);
    elementByIndex = dynamicIntArray.getAt(5);
    size = dynamicIntArray.size();
    ASSERT_EQ(1000, elementByIndex);
    ASSERT_EQ(6, size);

    dynamicIntArray.insert(450);
    dynamicIntArray.insert(550);
    dynamicIntArray.insert(650);
    dynamicIntArray.insert(750);
    dynamicIntArray.insertAt(2000, 7);

    elementByIndex = dynamicIntArray.getAt(7);
    size = dynamicIntArray.size();
    ASSERT_EQ(2000, elementByIndex);
    ASSERT_EQ(11, size);
}

TEST_F(DynamicIntegerArrayTests, CanThrowExceptionATInvalidIndex)
{ 
    EXPECT_ANY_THROW(dynamicIntArray.getAt(1));

    dynamicIntArray.insert(50);
    dynamicIntArray.insert(150);
    dynamicIntArray.insert(250);
  
    EXPECT_ANY_THROW(dynamicIntArray.insertAt(1000, -1));
    EXPECT_NO_THROW(dynamicIntArray.insertAt(1000, 1));
    EXPECT_NO_THROW(dynamicIntArray.getAt(2));

    EXPECT_ANY_THROW(dynamicIntArray.getAt(-1));
    EXPECT_ANY_THROW(dynamicIntArray.getAt(4));

    EXPECT_NO_THROW(dynamicIntArray.insertAt(1000, 4));
    EXPECT_ANY_THROW(dynamicIntArray.insertAt(1000, 6));
    EXPECT_ANY_THROW(dynamicIntArray.insertAt(1000, -4));
}

TEST_F(DynamicIntegerArrayTests, CanSearchValueByIndex) { 

    dynamicIntArray.insert(50);
    dynamicIntArray.insert(150);
    dynamicIntArray.insert(250);
    dynamicIntArray.insert(350);
    dynamicIntArray.insert(450);
    dynamicIntArray.insert(550);
    dynamicIntArray.insert(650);
    dynamicIntArray.insert(750);
    dynamicIntArray.insert(850);
    dynamicIntArray.insert(950);
    dynamicIntArray.insertAt(2000, 7);

    int elementIndex = dynamicIntArray.find(250);
    ASSERT_EQ(2, elementIndex);

    elementIndex = dynamicIntArray.find(2000);
    ASSERT_EQ(7, elementIndex);
}

TEST_F(DynamicIntegerArrayTests, CanDeleteByIndex) { 

    dynamicIntArray.insert(50);
    dynamicIntArray.insert(150);
    dynamicIntArray.insert(250);
    dynamicIntArray.insert(350);
    dynamicIntArray.insert(450);
    dynamicIntArray.insert(550);
    dynamicIntArray.insert(650);
    dynamicIntArray.insert(750);
    dynamicIntArray.insert(850);
    dynamicIntArray.insert(950);
    dynamicIntArray.insert(1050);

    dynamicIntArray.deleteAt(10);
    ASSERT_EQ(10, dynamicIntArray.size());
    EXPECT_ANY_THROW(dynamicIntArray.getAt(10));
    ASSERT_EQ(-1, dynamicIntArray.find(1050));

    dynamicIntArray.deleteAt(0);
    ASSERT_EQ(9, dynamicIntArray.size());
    ASSERT_EQ(150, dynamicIntArray.getAt(0));
     EXPECT_NO_THROW(dynamicIntArray.getAt(0));

    dynamicIntArray.deleteAt(4);
    ASSERT_EQ(8, dynamicIntArray.size());
    ASSERT_EQ(650, dynamicIntArray.getAt(4));
    EXPECT_NO_THROW(dynamicIntArray.getAt(4));
}

TEST_F(DynamicIntegerArrayTests, CanDeleteByIndexWithShrinking) { 

    dynamicIntArray.insert(50);
    dynamicIntArray.insert(150);
    dynamicIntArray.insert(250);
    dynamicIntArray.insert(350);
    dynamicIntArray.insert(450);
    dynamicIntArray.insert(550);
    dynamicIntArray.insert(650);
    dynamicIntArray.insert(750);
    dynamicIntArray.insert(850);
    dynamicIntArray.insert(950);
    dynamicIntArray.insert(1050);
    dynamicIntArray.insert(1150);
    dynamicIntArray.insert(1250);
    dynamicIntArray.insert(1350);
    dynamicIntArray.insert(1450);
    dynamicIntArray.insert(1550);
    dynamicIntArray.insert(1650);
    dynamicIntArray.insert(1750);
    dynamicIntArray.insert(1850);
    dynamicIntArray.insert(1950);
    dynamicIntArray.insert(2050);
    dynamicIntArray.insert(2150);

    dynamicIntArray.deleteAt(2);

    ASSERT_EQ(21, dynamicIntArray.size());
    ASSERT_EQ(350, dynamicIntArray.getAt(2));
    ASSERT_EQ(-1, dynamicIntArray.find(250));

    dynamicIntArray.deleteAt(2);
    dynamicIntArray.deleteAt(2);
    dynamicIntArray.deleteAt(2);
    dynamicIntArray.deleteAt(2);
    dynamicIntArray.deleteAt(2);
    dynamicIntArray.deleteAt(2);
    dynamicIntArray.deleteAt(2);
    dynamicIntArray.deleteAt(2);
    dynamicIntArray.deleteAt(2);

    dynamicIntArray.deleteAt(2);
    ASSERT_EQ(1350, dynamicIntArray.getAt(2));
    ASSERT_EQ(11, dynamicIntArray.size());

    dynamicIntArray.deleteAt(2);
    ASSERT_EQ(1450, dynamicIntArray.getAt(2));
    ASSERT_EQ(10, dynamicIntArray.size());

    dynamicIntArray.deleteAt(2);
    ASSERT_EQ(1550, dynamicIntArray.getAt(2));
    ASSERT_EQ(9, dynamicIntArray.size());

    dynamicIntArray.deleteAt(2);
    dynamicIntArray.deleteAt(2);
    dynamicIntArray.deleteAt(2);

    ASSERT_EQ(6,  dynamicIntArray.size());
    ASSERT_EQ(1850, dynamicIntArray.getAt(2));
    ASSERT_EQ(2, dynamicIntArray.find(1850));
    ASSERT_EQ(-1, dynamicIntArray.find(750));
}

TEST_F(DynamicIntegerArrayTests, CanThrowExceptionInvalidDeleteAtIndex)
{ 
    EXPECT_ANY_THROW(dynamicIntArray.deleteAt(1));

    dynamicIntArray.insert(650);
    dynamicIntArray.insert(750);
    dynamicIntArray.insert(850);

    EXPECT_NO_THROW(dynamicIntArray.deleteAt(1));

    EXPECT_ANY_THROW(dynamicIntArray.deleteAt(-1));
    EXPECT_ANY_THROW(dynamicIntArray.deleteAt(2));
}

TEST_F(DynamicIntegerArrayTests, CanSubscriptOperator) { 

    dynamicIntArray.insert(50);
    dynamicIntArray.insert(150);
    dynamicIntArray.insert(250);
    dynamicIntArray.insert(350);
    dynamicIntArray.insert(450);
    
    int element = dynamicIntArray[2];
    ASSERT_EQ(250, element);

    dynamicIntArray.insert(550);
    dynamicIntArray.insert(650);
    dynamicIntArray.insert(750);
    dynamicIntArray.insert(850);
    dynamicIntArray.insert(950);
    dynamicIntArray.insert(1050);

    element = dynamicIntArray[7];
    ASSERT_EQ(750, element);

    ASSERT_EQ(dynamicIntArray.getAt(4), dynamicIntArray[4]);
}

TEST_F(DynamicIntegerArrayTests, CanThrowExceptionSubscriptAtInvalidIndex)
{ 
    EXPECT_ANY_THROW(dynamicIntArray[1]);

    dynamicIntArray.insert(650);
    dynamicIntArray.insert(750);
    dynamicIntArray.insert(850);

    EXPECT_NO_THROW(dynamicIntArray[1]);

    EXPECT_ANY_THROW(dynamicIntArray[-1]);
    EXPECT_ANY_THROW(dynamicIntArray[3]);

    dynamicIntArray.insert(50);
    dynamicIntArray.insert(50);
    dynamicIntArray.insert(50);
    dynamicIntArray.insert(50);
    dynamicIntArray.insert(50);
    dynamicIntArray.insert(50);
    dynamicIntArray.insert(50);
    dynamicIntArray.insert(50);
    dynamicIntArray.insert(50);
    dynamicIntArray.insert(50);
    dynamicIntArray.insert(50);
    dynamicIntArray.insert(50);

    EXPECT_NO_THROW(dynamicIntArray[14]);
    EXPECT_ANY_THROW(dynamicIntArray[15]);
}

TEST_F(DynamicIntegerArrayTests, CanUpdateByIndex)
{ 
    dynamicIntArray.insert(650);
    dynamicIntArray.insert(750);
    dynamicIntArray.insert(850);
    
    EXPECT_NO_THROW(dynamicIntArray.updateAt(10000, 2));
    ASSERT_EQ(10000, dynamicIntArray.getAt(2));

    EXPECT_NO_THROW(dynamicIntArray.updateAt(20000, 0));
    ASSERT_EQ(20000, dynamicIntArray.getAt(0));
}

TEST_F(DynamicIntegerArrayTests, CanUpdateByIndexWithoutException)
{ 
    EXPECT_ANY_THROW(dynamicIntArray.updateAt(10000, 0));

    dynamicIntArray.insert(650);
    dynamicIntArray.insert(750);
    dynamicIntArray.insert(850);

    EXPECT_NO_THROW(dynamicIntArray.updateAt(10000, 2));

    EXPECT_ANY_THROW(dynamicIntArray.updateAt(20000, -1));
    EXPECT_ANY_THROW(dynamicIntArray.updateAt(20000, 3));
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}