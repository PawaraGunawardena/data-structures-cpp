#include <gtest/gtest.h>
#include "LinkedListInt.cpp"

class LinkedListIntTests : public ::testing::Test
{
protected:
    LinkedListInt linkedListInt;
};

TEST_F(LinkedListIntTests, CanCheckEmpty)
{        
    ASSERT_EQ(true, linkedListInt.empty());
    linkedListInt.addElementBack(10);
    ASSERT_NE(true, linkedListInt.empty());
}

TEST_F(LinkedListIntTests, CanCheckSize)
{        
    ASSERT_EQ(0, linkedListInt.size());
    linkedListInt.addElementBack(10);
    ASSERT_EQ(1, linkedListInt.size());
}

TEST_F(LinkedListIntTests, CanInsertBack)
{        
    linkedListInt.addElementBack(10);
    int element = linkedListInt.getElementAt(0);
    ASSERT_EQ(10, element);

    linkedListInt.addElementBack(100);
    linkedListInt.addElementBack(1000);
    ASSERT_EQ(1000, linkedListInt.getElementAt(2));
    ASSERT_EQ(10, linkedListInt.getElementAt(0));
}

TEST_F(LinkedListIntTests, CanInsertAt)
{        
    linkedListInt.addElementAt(10, 0);
    ASSERT_EQ(10, linkedListInt.getElementEnd());

    linkedListInt.addElementBack(20);
    linkedListInt.addElementBack(30);
    linkedListInt.addElementBack(40);
    linkedListInt.addElementBack(50);
    ASSERT_EQ(50, linkedListInt.getElementAt(4));
}

TEST_F(LinkedListIntTests, CanInsertAtHandleInvalidIndex)
{        
    EXPECT_ANY_THROW(linkedListInt.addElementAt(10, -1));
    EXPECT_ANY_THROW(linkedListInt.addElementAt(10, 1));
    linkedListInt.addElementAt(10, 0);
    
    EXPECT_NO_THROW(linkedListInt.addElementAt(100, 1));
}

TEST_F(LinkedListIntTests, CanInsertFront)
{        
    linkedListInt.addElementFront(10);
    int element = linkedListInt.getElementAt(0);
    ASSERT_EQ(10, element);

    linkedListInt.addElementFront(100);
    linkedListInt.addElementFront(1000);
    ASSERT_EQ(10, linkedListInt.getElementAt(2));
    ASSERT_EQ(1000, linkedListInt.getElementAt(0));
}

TEST_F(LinkedListIntTests, CanUpdateElementAt)
{        
    linkedListInt.addElementBack(10);
    linkedListInt.addElementBack(20);
    linkedListInt.addElementBack(30);
    linkedListInt.addElementBack(40);
    linkedListInt.addElementBack(50);
    
    ASSERT_EQ(30, linkedListInt.getElementAt(2));

    linkedListInt.updateElementAt(100, 2);
    ASSERT_EQ(100, linkedListInt.getElementAt(2));
    ASSERT_EQ(40, linkedListInt.getElementAt(3));
    ASSERT_EQ(20, linkedListInt.getElementAt(1));
}

TEST_F(LinkedListIntTests, CanUpdateAtHandleInvalidIndex)
{        
    EXPECT_ANY_THROW(linkedListInt.updateElementAt(10, -1));
    EXPECT_ANY_THROW(linkedListInt.updateElementAt(10, 1));
    linkedListInt.addElementAt(10, 0);
    
    EXPECT_NO_THROW(linkedListInt.updateElementAt(100, 0));
}

TEST_F(LinkedListIntTests, CanRemoveElementAt)
{        
    EXPECT_ANY_THROW(linkedListInt.removeElementAt(-1));
    EXPECT_ANY_THROW(linkedListInt.removeElementAt(0));

    linkedListInt.addElementBack(10);
    linkedListInt.addElementBack(20);
    linkedListInt.addElementBack(30);
    linkedListInt.addElementBack(40);
    linkedListInt.addElementBack(50);
    linkedListInt.removeElementAt(2);
    ASSERT_EQ(40, linkedListInt.getElementAt(2));
    ASSERT_EQ(20, linkedListInt.getElementAt(1));
    ASSERT_EQ(4, linkedListInt.size());
}

TEST_F(LinkedListIntTests, CanGetElementFront)
{        
    EXPECT_ANY_THROW(linkedListInt.getElementFront());

    linkedListInt.addElementBack(10);
    linkedListInt.addElementBack(20);
    linkedListInt.addElementBack(30);
    linkedListInt.addElementBack(40);
    linkedListInt.addElementBack(50);

    ASSERT_EQ(10, linkedListInt.getElementFront());
    EXPECT_NO_THROW(linkedListInt.getElementFront());
}

TEST_F(LinkedListIntTests, CanGetElementEnd)
{        
    EXPECT_ANY_THROW(linkedListInt.getElementEnd());
    linkedListInt.addElementBack(10);
    ASSERT_EQ(10, linkedListInt.getElementEnd());

    linkedListInt.addElementBack(20);
    linkedListInt.addElementBack(30);
    linkedListInt.addElementBack(40);
    linkedListInt.addElementBack(50);
    ASSERT_EQ(50, linkedListInt.getElementEnd());
    
    EXPECT_NO_THROW(linkedListInt.getElementEnd());
}

TEST_F(LinkedListIntTests, CanFindElementValueIndex)
{        
    ASSERT_EQ(-1, linkedListInt.find(10));
    linkedListInt.addElementBack(10);
    ASSERT_EQ(0, linkedListInt.find(10));

    linkedListInt.addElementBack(20);
    linkedListInt.addElementBack(30);
    linkedListInt.addElementBack(40);
    linkedListInt.addElementBack(50);

     ASSERT_EQ(4, linkedListInt.find(50));
}
 
int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}