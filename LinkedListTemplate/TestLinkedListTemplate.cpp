#include <gtest/gtest.h>
#include "LinkedListTemplate.h"

class Person
{
private:
	std::string name;
public:
	Person(){}

	Person(std::string name)
	{
		this->name = name;
	}

	std::string getName() const
	{
		return this->name;
	}

    std::string getName()
	{
		return this->name;
	}

    void setName(std::string name)
	{
		this->name = name;
	}

    bool operator==(const Person &rhs) const {
        return ((rhs.getName()) == (this->name));
    }
};

//int tests

class LinkedListTemplateTests : public ::testing::Test
{
protected:
    LinkedListTemplate<int> linkedListTemplate;
};

TEST_F(LinkedListTemplateTests, CanCheckEmpty)
{        
    ASSERT_EQ(true, linkedListTemplate.empty());
    linkedListTemplate.addElementBack(10);
    ASSERT_NE(true, linkedListTemplate.empty());
}

TEST_F(LinkedListTemplateTests, CanCheckSize)
{        
    ASSERT_EQ(0, linkedListTemplate.size());
    linkedListTemplate.addElementBack(10);
    ASSERT_EQ(1, linkedListTemplate.size());
}

TEST_F(LinkedListTemplateTests, CanInsertBack)
{        
    linkedListTemplate.addElementBack(10);
    int element = linkedListTemplate.getElementAt(0);
    ASSERT_EQ(10, element);

    linkedListTemplate.addElementBack(100);
    linkedListTemplate.addElementBack(1000);
    ASSERT_EQ(1000, linkedListTemplate.getElementAt(2));
    ASSERT_EQ(10, linkedListTemplate.getElementAt(0));
}

TEST_F(LinkedListTemplateTests, CanInsertAt)
{        
    linkedListTemplate.addElementAt(10, 0);
    ASSERT_EQ(10, linkedListTemplate.getElementEnd());

    linkedListTemplate.addElementAt(20, 1);
    linkedListTemplate.addElementAt(30, 2);
    linkedListTemplate.addElementAt(40, 3);
    linkedListTemplate.addElementAt(50, 4);
    ASSERT_EQ(50, linkedListTemplate.getElementAt(4));
}

TEST_F(LinkedListTemplateTests, CanInsertAtHandleInvalidIndex)
{        
    EXPECT_ANY_THROW(linkedListTemplate.addElementAt(10, -1));
    EXPECT_ANY_THROW(linkedListTemplate.addElementAt(10, 1));
    linkedListTemplate.addElementAt(10, 0);
    
    EXPECT_NO_THROW(linkedListTemplate.addElementAt(100, 1));
}

TEST_F(LinkedListTemplateTests, CanInsertFront)
{        
    linkedListTemplate.addElementFront(10);
    int element = linkedListTemplate.getElementAt(0);
    ASSERT_EQ(10, element);

    linkedListTemplate.addElementFront(100);
    linkedListTemplate.addElementFront(1000);
    ASSERT_EQ(10, linkedListTemplate.getElementAt(2));
    ASSERT_EQ(1000, linkedListTemplate.getElementAt(0));
}

TEST_F(LinkedListTemplateTests, CanUpdateElementAt)
{        
    linkedListTemplate.addElementBack(10);
    linkedListTemplate.addElementBack(20);
    linkedListTemplate.addElementBack(30);
    linkedListTemplate.addElementBack(40);
    linkedListTemplate.addElementBack(50);
    
    ASSERT_EQ(30, linkedListTemplate.getElementAt(2));

    linkedListTemplate.updateElementAt(100, 2);
    ASSERT_EQ(100, linkedListTemplate.getElementAt(2));
    ASSERT_EQ(40, linkedListTemplate.getElementAt(3));
    ASSERT_EQ(20, linkedListTemplate.getElementAt(1));
}

TEST_F(LinkedListTemplateTests, CanUpdateAtHandleInvalidIndex)
{        
    EXPECT_ANY_THROW(linkedListTemplate.updateElementAt(10, -1));
    EXPECT_ANY_THROW(linkedListTemplate.updateElementAt(10, 1));
    linkedListTemplate.addElementAt(10, 0);
    
    EXPECT_NO_THROW(linkedListTemplate.updateElementAt(100, 0));
}

TEST_F(LinkedListTemplateTests, CanRemoveElementAt)
{        
    EXPECT_ANY_THROW(linkedListTemplate.removeElementAt(-1));
    EXPECT_ANY_THROW(linkedListTemplate.removeElementAt(0));

    linkedListTemplate.addElementBack(10);
    linkedListTemplate.addElementBack(20);
    linkedListTemplate.addElementBack(30);
    linkedListTemplate.addElementBack(40);
    linkedListTemplate.addElementBack(50);
    linkedListTemplate.removeElementAt(2);
    ASSERT_EQ(40, linkedListTemplate.getElementAt(2));
    ASSERT_EQ(20, linkedListTemplate.getElementAt(1));
    ASSERT_EQ(4, linkedListTemplate.size());
}

TEST_F(LinkedListTemplateTests, CanGetElementFront)
{        
    EXPECT_ANY_THROW(linkedListTemplate.getElementFront());

    linkedListTemplate.addElementBack(10);
    linkedListTemplate.addElementBack(20);
    linkedListTemplate.addElementBack(30);
    linkedListTemplate.addElementBack(40);
    linkedListTemplate.addElementBack(50);

    ASSERT_EQ(10, linkedListTemplate.getElementFront());
    EXPECT_NO_THROW(linkedListTemplate.getElementFront());
}

TEST_F(LinkedListTemplateTests, CanGetElementEnd)
{        
    EXPECT_ANY_THROW(linkedListTemplate.getElementEnd());
    linkedListTemplate.addElementBack(10);
    ASSERT_EQ(10, linkedListTemplate.getElementEnd());

    linkedListTemplate.addElementBack(20);
    linkedListTemplate.addElementBack(30);
    linkedListTemplate.addElementBack(40);
    linkedListTemplate.addElementBack(50);
    ASSERT_EQ(50, linkedListTemplate.getElementEnd());
    
    EXPECT_NO_THROW(linkedListTemplate.getElementEnd());
}

TEST_F(LinkedListTemplateTests, CanFindElementValueIndex)
{        
    ASSERT_EQ(-1, linkedListTemplate.find(10));
    linkedListTemplate.addElementBack(10);
    ASSERT_EQ(0, linkedListTemplate.find(10));

    linkedListTemplate.addElementBack(20);
    linkedListTemplate.addElementBack(30);
    linkedListTemplate.addElementBack(40);
    linkedListTemplate.addElementBack(50);

     ASSERT_EQ(4, linkedListTemplate.find(50));
}

//Custom Person class object tests

class LinkedListPersonTemplateTests : public ::testing::Test
{
protected:
    LinkedListTemplate<Person> linkedListTemplatePerson;
};

TEST_F(LinkedListPersonTemplateTests, CanCheckEmpty)
{        
    ASSERT_EQ(true, linkedListTemplatePerson.empty());
    Person tempPerson("temp");
    linkedListTemplatePerson.addElementBack(tempPerson);
    ASSERT_NE(true, linkedListTemplatePerson.empty());
}

TEST_F(LinkedListPersonTemplateTests, CanCheckSize)
{        
    Person tempPerson("temp");
    ASSERT_EQ(0, linkedListTemplatePerson.size());
    linkedListTemplatePerson.addElementBack(tempPerson);
    ASSERT_EQ(1, linkedListTemplatePerson.size());
}

TEST_F(LinkedListPersonTemplateTests, CanInsertBack)
{        
    Person tempPerson0("temp0");
    
    linkedListTemplatePerson.addElementBack(tempPerson0);
    Person element = linkedListTemplatePerson.getElementAt(0);

    ASSERT_EQ(tempPerson0, element);

    Person tempPerson1("temp1");
    linkedListTemplatePerson.addElementBack(tempPerson1);
    Person tempPerson2("temp2");
    linkedListTemplatePerson.addElementBack(tempPerson2);

    ASSERT_EQ(tempPerson2, linkedListTemplatePerson.getElementAt(2));

    ASSERT_EQ(tempPerson0, linkedListTemplatePerson.getElementAt(0));
}

TEST_F(LinkedListPersonTemplateTests, CanInsertAt)
{        
    Person tempPerson0("temp0");
    linkedListTemplatePerson.addElementAt(tempPerson0, 0);
    ASSERT_EQ(tempPerson0, linkedListTemplatePerson.getElementEnd());

    Person tempPerson1("temp1");
    Person tempPerson2("temp2");
    Person tempPerson3("temp3");
    Person tempPerson4("temp4");

    linkedListTemplatePerson.addElementAt(tempPerson1, 1);
    linkedListTemplatePerson.addElementAt(tempPerson2, 2);
    linkedListTemplatePerson.addElementAt(tempPerson3, 3);
    linkedListTemplatePerson.addElementAt(tempPerson4, 4);

    ASSERT_EQ(tempPerson4, linkedListTemplatePerson.getElementAt(4));
}

TEST_F(LinkedListPersonTemplateTests, CanInsertAtHandleInvalidIndex)
{        
    Person tempPerson("temp");
    EXPECT_ANY_THROW(linkedListTemplatePerson.addElementAt(tempPerson, -1));
    EXPECT_ANY_THROW(linkedListTemplatePerson.addElementAt(tempPerson, 1));
    linkedListTemplatePerson.addElementAt(tempPerson, 0);
    
    EXPECT_NO_THROW(linkedListTemplatePerson.addElementAt(tempPerson, 1));
}

TEST_F(LinkedListPersonTemplateTests, CanInsertFront)
{        
    Person tempPerson0("temp0");
    linkedListTemplatePerson.addElementFront(tempPerson0);
    Person element = linkedListTemplatePerson.getElementAt(0);
    ASSERT_EQ(tempPerson0, element);

    Person tempPerson1("temp1");
    Person tempPerson2("temp2");
    linkedListTemplatePerson.addElementFront(tempPerson1);
    linkedListTemplatePerson.addElementFront(tempPerson2);
    ASSERT_EQ(tempPerson0, linkedListTemplatePerson.getElementAt(2));
    ASSERT_EQ(tempPerson2, linkedListTemplatePerson.getElementAt(0));
}

TEST_F(LinkedListPersonTemplateTests, CanUpdateElementAt)
{        
    Person tempPerson0("temp0");
    Person tempPerson1("temp1");
    Person tempPerson2("temp2");
    Person tempPerson3("temp3");
    Person tempPerson4("temp4");

    linkedListTemplatePerson.addElementBack(tempPerson0);
    linkedListTemplatePerson.addElementBack(tempPerson1);
    linkedListTemplatePerson.addElementBack(tempPerson2);
    linkedListTemplatePerson.addElementBack(tempPerson3);
    linkedListTemplatePerson.addElementBack(tempPerson4);
    
    ASSERT_EQ(tempPerson2, linkedListTemplatePerson.getElementAt(2));

    Person tempUpdatePerson("tempUpdatePerson");
    linkedListTemplatePerson.updateElementAt(tempUpdatePerson, 2);
    ASSERT_EQ(tempUpdatePerson, linkedListTemplatePerson.getElementAt(2));
    ASSERT_EQ(tempPerson3, linkedListTemplatePerson.getElementAt(3));
    ASSERT_EQ(tempPerson1, linkedListTemplatePerson.getElementAt(1));
}

TEST_F(LinkedListPersonTemplateTests, CanUpdateAtHandleInvalidIndex)
{        
    Person tempPerson("temp");
    EXPECT_ANY_THROW(linkedListTemplatePerson.updateElementAt(tempPerson, -1));
    EXPECT_ANY_THROW(linkedListTemplatePerson.updateElementAt(tempPerson, 1));
    linkedListTemplatePerson.addElementAt(tempPerson, 0);
    
    tempPerson.setName("tempNameUpdatePerson");
    EXPECT_NO_THROW(linkedListTemplatePerson.updateElementAt(tempPerson, 0));
}

TEST_F(LinkedListPersonTemplateTests, CanRemoveElementAt)
{        
    EXPECT_ANY_THROW(linkedListTemplatePerson.removeElementAt(-1));
    EXPECT_ANY_THROW(linkedListTemplatePerson.removeElementAt(0));

    Person tempPerson("temp0");
    linkedListTemplatePerson.addElementBack(tempPerson);
    tempPerson.setName("temp1");
    linkedListTemplatePerson.addElementBack(tempPerson);
    tempPerson.setName("temp2");
    linkedListTemplatePerson.addElementBack(tempPerson);
    tempPerson.setName("temp3");
    linkedListTemplatePerson.addElementBack(tempPerson);
    tempPerson.setName("temp4");
    linkedListTemplatePerson.addElementBack(tempPerson);

    linkedListTemplatePerson.removeElementAt(2);

    tempPerson.setName("temp3");
    ASSERT_EQ(tempPerson, linkedListTemplatePerson.getElementAt(2));

    tempPerson.setName("temp1");
    ASSERT_EQ(tempPerson, linkedListTemplatePerson.getElementAt(1));

    ASSERT_EQ(4, linkedListTemplatePerson.size());
}

TEST_F(LinkedListPersonTemplateTests, CanGetElementFront)
{        
    EXPECT_ANY_THROW(linkedListTemplatePerson.getElementFront());

    Person tempPerson("temp0");
    linkedListTemplatePerson.addElementBack(tempPerson);
    tempPerson.setName("temp1");
    linkedListTemplatePerson.addElementBack(tempPerson);
    tempPerson.setName("temp2");
    linkedListTemplatePerson.addElementBack(tempPerson);
    tempPerson.setName("temp3");
    linkedListTemplatePerson.addElementBack(tempPerson);
    tempPerson.setName("temp4");
    linkedListTemplatePerson.addElementBack(tempPerson);

    tempPerson.setName("temp0");
    ASSERT_EQ(tempPerson, linkedListTemplatePerson.getElementFront());
    EXPECT_NO_THROW(linkedListTemplatePerson.getElementFront());
}

TEST_F(LinkedListPersonTemplateTests, CanGetElementEnd)
{        
    EXPECT_ANY_THROW(linkedListTemplatePerson.getElementEnd());
    Person tempPerson0("temp0");
    linkedListTemplatePerson.addElementBack(tempPerson0);
    ASSERT_EQ(tempPerson0, linkedListTemplatePerson.getElementEnd());

    Person tempPerson1("temp1");
    Person tempPerson2("temp2");
    Person tempPerson3("temp3");
    Person tempPerson4("temp4");

    linkedListTemplatePerson.addElementBack(tempPerson1);
    linkedListTemplatePerson.addElementBack(tempPerson2);
    linkedListTemplatePerson.addElementBack(tempPerson3);
    linkedListTemplatePerson.addElementBack(tempPerson4);
    ASSERT_EQ(tempPerson4, linkedListTemplatePerson.getElementEnd());
    
    EXPECT_NO_THROW(linkedListTemplatePerson.getElementEnd());
}

TEST_F(LinkedListPersonTemplateTests, CanFindElementValueIndex)
{        
    Person tempPerson0("temp0");
    ASSERT_EQ(-1, linkedListTemplatePerson.find(tempPerson0));
    linkedListTemplatePerson.addElementBack(tempPerson0);
    ASSERT_EQ(0, linkedListTemplatePerson.find(tempPerson0));

    Person tempPerson1("temp1");
    Person tempPerson2("temp2");
    Person tempPerson3("temp3");
    Person tempPerson4("temp4");

    linkedListTemplatePerson.addElementBack(tempPerson1);
    linkedListTemplatePerson.addElementBack(tempPerson2);
    linkedListTemplatePerson.addElementBack(tempPerson3);
    linkedListTemplatePerson.addElementBack(tempPerson4);

     ASSERT_EQ(4, linkedListTemplatePerson.find(tempPerson4));
}
 
int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}