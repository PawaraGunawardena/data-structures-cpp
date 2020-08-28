#include <gtest/gtest.h>
#include "DynamicTemplateArray.h"
#include <string>

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

class DTemplateIntArrayTests : public ::testing::Test
{
protected:
    DynamicTemplateArray<int> dynamicIntTemplateArray;
};

TEST_F(DTemplateIntArrayTests, CanInstantiateDTempArrayWithSize) { 
    DynamicTemplateArray<int> dynamicIntTemplateArrayWithCapacity(20);
}

TEST_F(DTemplateIntArrayTests, CanThrowExceptionForNegativeCapacity)
{        
    EXPECT_NO_THROW(DynamicTemplateArray<int> dynamicIntTemplateArrayPossible(20));
    EXPECT_ANY_THROW(DynamicTemplateArray<int> dynamicIntTemplateArrayImpossible(-1));
}

TEST_F(DTemplateIntArrayTests, CanReturnTotalSize) { 
    int size = dynamicIntTemplateArray.size();
    ASSERT_EQ(0, size);

    int temp=0;
    dynamicIntTemplateArray.insert(temp);
    size = dynamicIntTemplateArray.size();
    ASSERT_EQ(1, size);
}

TEST_F(DTemplateIntArrayTests, CanGrowingArrayReturnTotalSize) { 
    int temp=0;
    dynamicIntTemplateArray.insert(temp);
    dynamicIntTemplateArray.insert(temp);
    dynamicIntTemplateArray.insert(temp);
    dynamicIntTemplateArray.insert(temp);
    dynamicIntTemplateArray.insert(temp);
    dynamicIntTemplateArray.insert(temp);
    dynamicIntTemplateArray.insert(temp);
    dynamicIntTemplateArray.insert(temp);
    dynamicIntTemplateArray.insert(temp);
    dynamicIntTemplateArray.insert(temp);
    dynamicIntTemplateArray.insert(temp);
    dynamicIntTemplateArray.insert(temp);
    dynamicIntTemplateArray.insert(temp);
    dynamicIntTemplateArray.insert(temp);
    dynamicIntTemplateArray.insert(temp);

    int size = dynamicIntTemplateArray.size();
    ASSERT_EQ(15, size);

    dynamicIntTemplateArray.insert(temp);
    size = dynamicIntTemplateArray.size();
    ASSERT_EQ(16, size);
}

TEST_F(DTemplateIntArrayTests, CanProcessValueByIndex) { 
    
    int temp=50;
    dynamicIntTemplateArray.insert(temp);
    temp=150;
    dynamicIntTemplateArray.insert(temp);
    temp=250;
    dynamicIntTemplateArray.insert(temp);
    temp=350;
    dynamicIntTemplateArray.insert(temp);
    

    int elementByIndex = dynamicIntTemplateArray.getAt(1);
    int size = dynamicIntTemplateArray.size();
    ASSERT_EQ(150, elementByIndex);
    ASSERT_EQ(4, size);

    temp=300;
    dynamicIntTemplateArray.insertAt(temp, 2);
    elementByIndex = dynamicIntTemplateArray.getAt(2);
    size = dynamicIntTemplateArray.size();
    ASSERT_EQ(300, elementByIndex);
    ASSERT_EQ(5, size);

    temp=1000;
    dynamicIntTemplateArray.insertAt(temp, 5);
    elementByIndex = dynamicIntTemplateArray.getAt(5);
    size = dynamicIntTemplateArray.size();
    ASSERT_EQ(1000, elementByIndex);
    ASSERT_EQ(6, size);

    temp=450;
    dynamicIntTemplateArray.insert(temp);
    temp=550;
    dynamicIntTemplateArray.insert(temp);
    temp=650;
    dynamicIntTemplateArray.insert(temp);
    temp=750;
    dynamicIntTemplateArray.insert(temp);
    temp = 2000;
    dynamicIntTemplateArray.insertAt(temp, 7);

    elementByIndex = dynamicIntTemplateArray.getAt(7);
    size = dynamicIntTemplateArray.size();
    ASSERT_EQ(2000, elementByIndex);
    ASSERT_EQ(11, size);

    elementByIndex = dynamicIntTemplateArray.getAt(1);
    ASSERT_EQ(150, elementByIndex);
}

TEST_F(DTemplateIntArrayTests, CanThrowExceptionATInvalidIndex)
{ 
    EXPECT_ANY_THROW(dynamicIntTemplateArray.getAt(1));
    int temp=50;
    dynamicIntTemplateArray.insert(temp);
    dynamicIntTemplateArray.insert(temp);
    dynamicIntTemplateArray.insert(temp);
  
    EXPECT_ANY_THROW(dynamicIntTemplateArray.insertAt(temp, -1));
    EXPECT_NO_THROW(dynamicIntTemplateArray.insertAt(temp, 1));
    EXPECT_NO_THROW(dynamicIntTemplateArray.getAt(2));

    EXPECT_ANY_THROW(dynamicIntTemplateArray.getAt(-1));
    EXPECT_ANY_THROW(dynamicIntTemplateArray.getAt(4));

    EXPECT_NO_THROW(dynamicIntTemplateArray.insertAt(temp, 4));
    EXPECT_ANY_THROW(dynamicIntTemplateArray.insertAt(temp, 6));
    EXPECT_ANY_THROW(dynamicIntTemplateArray.insertAt(temp, -4));
}

TEST_F(DTemplateIntArrayTests, CanSearchValueByIndex) { 

    int temp=50;
    dynamicIntTemplateArray.insert(temp);
    temp=150;
    dynamicIntTemplateArray.insert(temp);
    temp=250;
    dynamicIntTemplateArray.insert(temp);
    temp=350;
    dynamicIntTemplateArray.insert(temp);
    temp=450;
    dynamicIntTemplateArray.insert(temp);
    temp=550;
    dynamicIntTemplateArray.insert(temp);
    temp=650;
    dynamicIntTemplateArray.insert(temp);
    temp=750;
    dynamicIntTemplateArray.insert(temp);
    temp = 2000;
    dynamicIntTemplateArray.insertAt(2000, 7);

    int pTemp=250;
    int elementIndex = dynamicIntTemplateArray.find(pTemp);
    ASSERT_EQ(2, elementIndex);

    pTemp=2000;
    elementIndex = dynamicIntTemplateArray.find(pTemp);
    ASSERT_EQ(7, elementIndex);
}

TEST_F(DTemplateIntArrayTests, CanDeleteByIndex) { 

    dynamicIntTemplateArray.insert(50);
    dynamicIntTemplateArray.insert(150);
    dynamicIntTemplateArray.insert(250);
    dynamicIntTemplateArray.insert(350);
    dynamicIntTemplateArray.insert(450);
    dynamicIntTemplateArray.insert(550);
    dynamicIntTemplateArray.insert(650);
    dynamicIntTemplateArray.insert(750);
    dynamicIntTemplateArray.insert(850);
    dynamicIntTemplateArray.insert(950);
    dynamicIntTemplateArray.insert(1050);

    dynamicIntTemplateArray.deleteAt(10);
    ASSERT_EQ(10, dynamicIntTemplateArray.size());
    EXPECT_ANY_THROW(dynamicIntTemplateArray.getAt(10));
    ASSERT_EQ(-1, dynamicIntTemplateArray.find(1050));

    dynamicIntTemplateArray.deleteAt(0);
    ASSERT_EQ(9, dynamicIntTemplateArray.size());
    ASSERT_EQ(150, dynamicIntTemplateArray.getAt(0));
     EXPECT_NO_THROW(dynamicIntTemplateArray.getAt(0));

    dynamicIntTemplateArray.deleteAt(4);
    ASSERT_EQ(8, dynamicIntTemplateArray.size());
    ASSERT_EQ(650, dynamicIntTemplateArray.getAt(4));
    EXPECT_NO_THROW(dynamicIntTemplateArray.getAt(4));
}

TEST_F(DTemplateIntArrayTests, CanDeleteByIndexWithShrinking) { 

    dynamicIntTemplateArray.insert(50);
    dynamicIntTemplateArray.insert(150);
    dynamicIntTemplateArray.insert(250);
    dynamicIntTemplateArray.insert(350);
    dynamicIntTemplateArray.insert(450);
    dynamicIntTemplateArray.insert(550);
    dynamicIntTemplateArray.insert(650);
    dynamicIntTemplateArray.insert(750);
    dynamicIntTemplateArray.insert(850);
    dynamicIntTemplateArray.insert(950);
    dynamicIntTemplateArray.insert(1050);
    dynamicIntTemplateArray.insert(1150);
    dynamicIntTemplateArray.insert(1250);
    dynamicIntTemplateArray.insert(1350);
    dynamicIntTemplateArray.insert(1450);
    dynamicIntTemplateArray.insert(1550);
    dynamicIntTemplateArray.insert(1650);
    dynamicIntTemplateArray.insert(1750);
    dynamicIntTemplateArray.insert(1850);
    dynamicIntTemplateArray.insert(1950);
    dynamicIntTemplateArray.insert(2050);
    dynamicIntTemplateArray.insert(2150);

    dynamicIntTemplateArray.deleteAt(2);

    ASSERT_EQ(21, dynamicIntTemplateArray.size());
    ASSERT_EQ(350, dynamicIntTemplateArray.getAt(2));
    ASSERT_EQ(-1, dynamicIntTemplateArray.find(250));

    dynamicIntTemplateArray.deleteAt(2);
    dynamicIntTemplateArray.deleteAt(2);
    dynamicIntTemplateArray.deleteAt(2);
    dynamicIntTemplateArray.deleteAt(2);
    dynamicIntTemplateArray.deleteAt(2);
    dynamicIntTemplateArray.deleteAt(2);
    dynamicIntTemplateArray.deleteAt(2);
    dynamicIntTemplateArray.deleteAt(2);
    dynamicIntTemplateArray.deleteAt(2);

    dynamicIntTemplateArray.deleteAt(2);
    ASSERT_EQ(1350, dynamicIntTemplateArray.getAt(2));
    ASSERT_EQ(11, dynamicIntTemplateArray.size());

    dynamicIntTemplateArray.deleteAt(2);
    ASSERT_EQ(1450, dynamicIntTemplateArray.getAt(2));
    ASSERT_EQ(10, dynamicIntTemplateArray.size());

    dynamicIntTemplateArray.deleteAt(2);
    ASSERT_EQ(1550, dynamicIntTemplateArray.getAt(2));
    ASSERT_EQ(9, dynamicIntTemplateArray.size());

    dynamicIntTemplateArray.deleteAt(2);
    dynamicIntTemplateArray.deleteAt(2);
    dynamicIntTemplateArray.deleteAt(2);

    ASSERT_EQ(6,  dynamicIntTemplateArray.size());
    ASSERT_EQ(1850, dynamicIntTemplateArray.getAt(2));
    ASSERT_EQ(2, dynamicIntTemplateArray.find(1850));
    ASSERT_EQ(-1, dynamicIntTemplateArray.find(750));
}

TEST_F(DTemplateIntArrayTests, CanThrowExceptionInvalidDeleteAtIndex)
{ 
    EXPECT_ANY_THROW(dynamicIntTemplateArray.deleteAt(1));

    dynamicIntTemplateArray.insert(650);
    dynamicIntTemplateArray.insert(750);
    dynamicIntTemplateArray.insert(850);

    EXPECT_NO_THROW(dynamicIntTemplateArray.deleteAt(1));

    EXPECT_ANY_THROW(dynamicIntTemplateArray.deleteAt(-1));
    EXPECT_ANY_THROW(dynamicIntTemplateArray.deleteAt(2));
}

TEST_F(DTemplateIntArrayTests, CanSubscriptOperator) { 

    dynamicIntTemplateArray.insert(50);
    dynamicIntTemplateArray.insert(150);
    dynamicIntTemplateArray.insert(250);
    dynamicIntTemplateArray.insert(350);
    dynamicIntTemplateArray.insert(450);
    
    int element = dynamicIntTemplateArray[2];
    ASSERT_EQ(250, element);

    dynamicIntTemplateArray.insert(550);
    dynamicIntTemplateArray.insert(650);
    dynamicIntTemplateArray.insert(750);
    dynamicIntTemplateArray.insert(850);
    dynamicIntTemplateArray.insert(950);
    dynamicIntTemplateArray.insert(1050);

    element = dynamicIntTemplateArray[7];
    ASSERT_EQ(750, element);

    ASSERT_EQ(dynamicIntTemplateArray.getAt(4), dynamicIntTemplateArray[4]);
}

TEST_F(DTemplateIntArrayTests, CanThrowExceptionSubscriptAtInvalidIndex)
{ 
    EXPECT_ANY_THROW(dynamicIntTemplateArray[1]);

    dynamicIntTemplateArray.insert(650);
    dynamicIntTemplateArray.insert(750);
    dynamicIntTemplateArray.insert(850);

    EXPECT_NO_THROW(dynamicIntTemplateArray[1]);

    EXPECT_ANY_THROW(dynamicIntTemplateArray[-1]);
    EXPECT_ANY_THROW(dynamicIntTemplateArray[3]);

    dynamicIntTemplateArray.insert(50);
    dynamicIntTemplateArray.insert(50);
    dynamicIntTemplateArray.insert(50);
    dynamicIntTemplateArray.insert(50);
    dynamicIntTemplateArray.insert(50);
    dynamicIntTemplateArray.insert(50);
    dynamicIntTemplateArray.insert(50);
    dynamicIntTemplateArray.insert(50);
    dynamicIntTemplateArray.insert(50);
    dynamicIntTemplateArray.insert(50);
    dynamicIntTemplateArray.insert(50);
    dynamicIntTemplateArray.insert(50);

    EXPECT_NO_THROW(dynamicIntTemplateArray[14]);
    EXPECT_ANY_THROW(dynamicIntTemplateArray[15]);
}

TEST_F(DTemplateIntArrayTests, CanUpdateByIndex)
{ 
    dynamicIntTemplateArray.insert(650);
    dynamicIntTemplateArray.insert(750);
    dynamicIntTemplateArray.insert(850);
    
    EXPECT_NO_THROW(dynamicIntTemplateArray.updateAt(10000, 2));
    ASSERT_EQ(10000, dynamicIntTemplateArray.getAt(2));

    EXPECT_NO_THROW(dynamicIntTemplateArray.updateAt(20000, 0));
    ASSERT_EQ(20000, dynamicIntTemplateArray.getAt(0));
}

TEST_F(DTemplateIntArrayTests, CanUpdateByIndexWithoutException)
{ 
    EXPECT_ANY_THROW(dynamicIntTemplateArray.updateAt(10000, 0));

    dynamicIntTemplateArray.insert(650);
    dynamicIntTemplateArray.insert(750);
    dynamicIntTemplateArray.insert(850);

    EXPECT_NO_THROW(dynamicIntTemplateArray.updateAt(10000, 2));

    EXPECT_ANY_THROW(dynamicIntTemplateArray.updateAt(20000, -1));
    EXPECT_ANY_THROW(dynamicIntTemplateArray.updateAt(20000, 3));
}

//Custom Person class object tests

class DTemplatePersonArrayTests : public ::testing::Test
{
protected:
    DynamicTemplateArray<Person> dynamicPersonTemplateArray;
};

TEST_F(DTemplatePersonArrayTests, CanInstantiateDTempArrayWithSize) { 
    DynamicTemplateArray<Person> dynamicPersonTemplateArrayWithCapacity(20);
}

TEST_F(DTemplatePersonArrayTests, CanThrowExceptionForNegativeCapacity)
{        
    EXPECT_NO_THROW(DynamicTemplateArray<Person> dynamicPersonTemplateArrayPossible(20));
    EXPECT_ANY_THROW(DynamicTemplateArray<Person> dynamicPersonTemplateArrayImpossible(-1));
}

TEST_F(DTemplatePersonArrayTests, CanReturnTotalSize) { 
    int size = dynamicPersonTemplateArray.size();
    ASSERT_EQ(0, size);

    Person tempPerson;
    dynamicPersonTemplateArray.insert(tempPerson);
    size = dynamicPersonTemplateArray.size();
    ASSERT_EQ(1, size);
}

TEST_F(DTemplatePersonArrayTests, CanGrowingArrayReturnTotalSize) { 
    Person tempPerson("temp");
    dynamicPersonTemplateArray.insert(tempPerson);
    dynamicPersonTemplateArray.insert(tempPerson);
    dynamicPersonTemplateArray.insert(tempPerson);
    dynamicPersonTemplateArray.insert(tempPerson);
    dynamicPersonTemplateArray.insert(tempPerson);
    dynamicPersonTemplateArray.insert(tempPerson);
    dynamicPersonTemplateArray.insert(tempPerson);
    dynamicPersonTemplateArray.insert(tempPerson);
    dynamicPersonTemplateArray.insert(tempPerson);
    dynamicPersonTemplateArray.insert(tempPerson);
    dynamicPersonTemplateArray.insert(tempPerson);
    dynamicPersonTemplateArray.insert(tempPerson);
    dynamicPersonTemplateArray.insert(tempPerson);
    dynamicPersonTemplateArray.insert(tempPerson);
    dynamicPersonTemplateArray.insert(tempPerson);

    int size = dynamicPersonTemplateArray.size();
    ASSERT_EQ(15, size);

    dynamicPersonTemplateArray.insert(tempPerson);
    size = dynamicPersonTemplateArray.size();
    ASSERT_EQ(16, size);
}

TEST_F(DTemplatePersonArrayTests, CanProcessValueByIndex) { 
    
    Person tempPerson0("temp0");
    dynamicPersonTemplateArray.insert(tempPerson0);
    Person tempPerson1("temp1");
    dynamicPersonTemplateArray.insert(tempPerson1);
    Person tempPerson2("temp2");
    dynamicPersonTemplateArray.insert(tempPerson2);
    Person tempPerson3("temp3");
    dynamicPersonTemplateArray.insert(tempPerson3);
    

    Person personElementByIndex = dynamicPersonTemplateArray.getAt(1);
    int size = dynamicPersonTemplateArray.size();
    ASSERT_EQ(tempPerson1, personElementByIndex);
    ASSERT_EQ(4, size);

    Person tempPersonNewAt2("tempNew2");
    dynamicPersonTemplateArray.insertAt(tempPersonNewAt2, 2);
    personElementByIndex = dynamicPersonTemplateArray.getAt(2);
    size = dynamicPersonTemplateArray.size();
    ASSERT_EQ(tempPersonNewAt2, personElementByIndex);
    ASSERT_EQ(5, size);

    Person tempPersonNewAt5("tempNew5");
    dynamicPersonTemplateArray.insertAt(tempPersonNewAt5, 5);
    personElementByIndex = dynamicPersonTemplateArray.getAt(5);
    size = dynamicPersonTemplateArray.size();
    ASSERT_EQ(tempPersonNewAt5, personElementByIndex);
    ASSERT_EQ(6, size);

    Person tempPerson("temp7");
    dynamicPersonTemplateArray.insert(tempPerson);
    tempPerson.setName("temp8");
    dynamicPersonTemplateArray.insert(tempPerson);
    tempPerson.setName("temp9");
    dynamicPersonTemplateArray.insert(tempPerson);
    tempPerson.setName("temp10");
    dynamicPersonTemplateArray.insert(tempPerson);

    tempPerson.setName("temp8");
    personElementByIndex = dynamicPersonTemplateArray.getAt(7);
    size = dynamicPersonTemplateArray.size();
    ASSERT_EQ(tempPerson, personElementByIndex);
    ASSERT_EQ(10, size);

    tempPerson.setName("temp1");
    personElementByIndex = dynamicPersonTemplateArray.getAt(1);
    ASSERT_EQ(tempPerson, personElementByIndex);
}

TEST_F(DTemplatePersonArrayTests, CanThrowExceptionATInvalidIndex)
{ 
    EXPECT_ANY_THROW(dynamicPersonTemplateArray.getAt(1));
    Person tempPerson("temp0");
    dynamicPersonTemplateArray.insert(tempPerson);
    tempPerson.setName("temp1");
    dynamicPersonTemplateArray.insert(tempPerson);
    tempPerson.setName("temp2");
    dynamicPersonTemplateArray.insert(tempPerson);

    EXPECT_ANY_THROW(dynamicPersonTemplateArray.insertAt(tempPerson, -1));
    EXPECT_NO_THROW(dynamicPersonTemplateArray.insertAt(tempPerson, 1));
    EXPECT_NO_THROW(dynamicPersonTemplateArray.getAt(2));

    EXPECT_ANY_THROW(dynamicPersonTemplateArray.getAt(-1));
    EXPECT_ANY_THROW(dynamicPersonTemplateArray.getAt(4));

    EXPECT_NO_THROW(dynamicPersonTemplateArray.insertAt(tempPerson, 4));
    EXPECT_ANY_THROW(dynamicPersonTemplateArray.insertAt(tempPerson, 6));
    EXPECT_ANY_THROW(dynamicPersonTemplateArray.insertAt(tempPerson, -4));
}

TEST_F(DTemplatePersonArrayTests, CanSearchValueByIndex) { 

    Person tempPerson("temp0");
    dynamicPersonTemplateArray.insert(tempPerson);
    tempPerson.setName("temp1");
    dynamicPersonTemplateArray.insert(tempPerson);
    tempPerson.setName("temp2");
    dynamicPersonTemplateArray.insert(tempPerson);
    tempPerson.setName("temp3");
    dynamicPersonTemplateArray.insert(tempPerson);
    tempPerson.setName("temp4");
    dynamicPersonTemplateArray.insert(tempPerson);
    tempPerson.setName("temp5");
    dynamicPersonTemplateArray.insert(tempPerson);
    tempPerson.setName("temp6");
    dynamicPersonTemplateArray.insert(tempPerson);
    tempPerson.setName("temp7");
    dynamicPersonTemplateArray.insert(tempPerson);
    tempPerson.setName("temp8");
    dynamicPersonTemplateArray.insertAt(tempPerson, 7);

    tempPerson.setName("temp2");
    int  personIndex = dynamicPersonTemplateArray.find(tempPerson);
    ASSERT_EQ(2, personIndex);

    tempPerson.setName("temp8");
    personIndex = dynamicPersonTemplateArray.find(tempPerson);
    ASSERT_EQ(7, personIndex);
}

TEST_F(DTemplatePersonArrayTests, CanDeleteByIndex) { 

    Person tempPerson("temp0");
    dynamicPersonTemplateArray.insert(tempPerson);
    tempPerson.setName("temp1");
    dynamicPersonTemplateArray.insert(tempPerson);
    tempPerson.setName("temp2");
    dynamicPersonTemplateArray.insert(tempPerson);
    tempPerson.setName("temp3");
    dynamicPersonTemplateArray.insert(tempPerson);
    tempPerson.setName("temp4");
    dynamicPersonTemplateArray.insert(tempPerson);
    tempPerson.setName("temp5");
    dynamicPersonTemplateArray.insert(tempPerson);
    tempPerson.setName("temp6");
    dynamicPersonTemplateArray.insert(tempPerson);
    tempPerson.setName("temp7");
    dynamicPersonTemplateArray.insert(tempPerson);
    tempPerson.setName("temp8");
    dynamicPersonTemplateArray.insert(tempPerson);
    tempPerson.setName("temp9");
    dynamicPersonTemplateArray.insert(tempPerson);
    tempPerson.setName("temp10");
    dynamicPersonTemplateArray.insert(tempPerson);

    dynamicPersonTemplateArray.deleteAt(10);
    ASSERT_EQ(10, dynamicPersonTemplateArray.size());
    EXPECT_ANY_THROW(dynamicPersonTemplateArray.getAt(10));
    ASSERT_EQ(-1, dynamicPersonTemplateArray.find(tempPerson));

    dynamicPersonTemplateArray.deleteAt(0);
    ASSERT_EQ(9, dynamicPersonTemplateArray.size());
    tempPerson.setName("temp1");
    ASSERT_EQ(tempPerson, dynamicPersonTemplateArray.getAt(0));
    EXPECT_NO_THROW(dynamicPersonTemplateArray.getAt(0));

    dynamicPersonTemplateArray.deleteAt(4);
    ASSERT_EQ(8, dynamicPersonTemplateArray.size());
    tempPerson.setName("temp6");
    ASSERT_EQ(tempPerson, dynamicPersonTemplateArray.getAt(4));
    EXPECT_NO_THROW(dynamicPersonTemplateArray.getAt(4));
}

TEST_F(DTemplatePersonArrayTests, CanDeleteByIndexWithShrinking) { 

    Person tempPerson0("temp0");
    dynamicPersonTemplateArray.insert(tempPerson0);
    Person tempPerson1("temp1");
    dynamicPersonTemplateArray.insert(tempPerson1);
    Person tempPerson2("temp2");
    dynamicPersonTemplateArray.insert(tempPerson2);
    Person tempPerson3("temp3");
    dynamicPersonTemplateArray.insert(tempPerson3);
    Person tempPerson4("temp4");
    dynamicPersonTemplateArray.insert(tempPerson4);
    Person tempPerson5("temp5");
    dynamicPersonTemplateArray.insert(tempPerson5);
    Person tempPerson6("temp6");
    dynamicPersonTemplateArray.insert(tempPerson6);
    Person tempPerson7("temp7");
    dynamicPersonTemplateArray.insert(tempPerson7);
    Person tempPerson8("temp8");
    dynamicPersonTemplateArray.insert(tempPerson8);
    Person tempPerson9("temp9");
    dynamicPersonTemplateArray.insert(tempPerson9);
    Person tempPerson10("temp10");
    dynamicPersonTemplateArray.insert(tempPerson10);
    Person tempPerson11("temp11");
    dynamicPersonTemplateArray.insert(tempPerson11);
    Person tempPerson12("temp12");
    dynamicPersonTemplateArray.insert(tempPerson12);
    Person tempPerson13("temp13");
    dynamicPersonTemplateArray.insert(tempPerson13);
    Person tempPerson14("temp14");
    dynamicPersonTemplateArray.insert(tempPerson14);
    Person tempPerson15("temp15");
    dynamicPersonTemplateArray.insert(tempPerson15);
    Person tempPerson16("temp16");
    dynamicPersonTemplateArray.insert(tempPerson16);
    Person tempPerson17("temp17");
    dynamicPersonTemplateArray.insert(tempPerson17);
    Person tempPerson18("temp18");
    dynamicPersonTemplateArray.insert(tempPerson18);
    Person tempPerson19("temp19");
    dynamicPersonTemplateArray.insert(tempPerson19);
    Person tempPerson20("temp20");
    dynamicPersonTemplateArray.insert(tempPerson20);
    Person tempPerson21("temp21");
    dynamicPersonTemplateArray.insert(tempPerson21);

    dynamicPersonTemplateArray.deleteAt(2);

    ASSERT_EQ(21, dynamicPersonTemplateArray.size());
    ASSERT_EQ(tempPerson3, dynamicPersonTemplateArray.getAt(2));
    ASSERT_EQ(-1, dynamicPersonTemplateArray.find(tempPerson2));

    dynamicPersonTemplateArray.deleteAt(2);
    dynamicPersonTemplateArray.deleteAt(2);
    dynamicPersonTemplateArray.deleteAt(2);
    dynamicPersonTemplateArray.deleteAt(2);
    dynamicPersonTemplateArray.deleteAt(2);
    dynamicPersonTemplateArray.deleteAt(2);
    dynamicPersonTemplateArray.deleteAt(2);
    dynamicPersonTemplateArray.deleteAt(2);
    dynamicPersonTemplateArray.deleteAt(2);

    dynamicPersonTemplateArray.deleteAt(2);
    ASSERT_EQ(tempPerson13, dynamicPersonTemplateArray.getAt(2));
    ASSERT_EQ(11, dynamicPersonTemplateArray.size());

    dynamicPersonTemplateArray.deleteAt(2);
    ASSERT_EQ(tempPerson14, dynamicPersonTemplateArray.getAt(2));
    ASSERT_EQ(10, dynamicPersonTemplateArray.size());

    dynamicPersonTemplateArray.deleteAt(2);
    ASSERT_EQ(tempPerson15, dynamicPersonTemplateArray.getAt(2));
    ASSERT_EQ(9, dynamicPersonTemplateArray.size());

    dynamicPersonTemplateArray.deleteAt(2);
    dynamicPersonTemplateArray.deleteAt(2);
    dynamicPersonTemplateArray.deleteAt(2);

    ASSERT_EQ(6,  dynamicPersonTemplateArray.size());
    ASSERT_EQ(tempPerson18, dynamicPersonTemplateArray.getAt(2));
    ASSERT_EQ(2, dynamicPersonTemplateArray.find(tempPerson18));
    ASSERT_EQ(-1, dynamicPersonTemplateArray.find(tempPerson12));
}

TEST_F(DTemplatePersonArrayTests, CanThrowExceptionInvalidDeleteAtIndex)
{ 
    EXPECT_ANY_THROW(dynamicPersonTemplateArray.deleteAt(1));

    Person tempPerson("temp0");
    dynamicPersonTemplateArray.insert(tempPerson);
    tempPerson.setName("temp1");
    dynamicPersonTemplateArray.insert(tempPerson);
    tempPerson.setName("temp2");
    dynamicPersonTemplateArray.insert(tempPerson);

    EXPECT_NO_THROW(dynamicPersonTemplateArray.deleteAt(1));

    EXPECT_ANY_THROW(dynamicPersonTemplateArray.deleteAt(-1));
    EXPECT_ANY_THROW(dynamicPersonTemplateArray.deleteAt(2));
}

TEST_F(DTemplatePersonArrayTests, CanSubscriptOperator) { 
    Person tempPerson("temp0");
    dynamicPersonTemplateArray.insert(tempPerson);
    tempPerson.setName("temp1");
    dynamicPersonTemplateArray.insert(tempPerson);
    tempPerson.setName("temp2");
    dynamicPersonTemplateArray.insert(tempPerson);
    tempPerson.setName("temp3");
    dynamicPersonTemplateArray.insert(tempPerson);
    tempPerson.setName("temp4");
    dynamicPersonTemplateArray.insert(tempPerson);
    
    Person element = dynamicPersonTemplateArray[2];
    tempPerson.setName("temp2");
    ASSERT_EQ(tempPerson, element);

    tempPerson.setName("temp5");
    dynamicPersonTemplateArray.insert(tempPerson);
    tempPerson.setName("temp6");
    dynamicPersonTemplateArray.insert(tempPerson);
    tempPerson.setName("temp7");
    dynamicPersonTemplateArray.insert(tempPerson);
    tempPerson.setName("temp8");
    dynamicPersonTemplateArray.insert(tempPerson);
    tempPerson.setName("temp9");
    dynamicPersonTemplateArray.insert(tempPerson);
    tempPerson.setName("temp10");
    dynamicPersonTemplateArray.insert(tempPerson);

    tempPerson.setName("temp7");
    element = dynamicPersonTemplateArray[7];
    ASSERT_EQ(element, element);

    ASSERT_EQ(dynamicPersonTemplateArray.getAt(4), dynamicPersonTemplateArray[4]);
}

TEST_F(DTemplatePersonArrayTests, CanThrowExceptionSubscriptAtInvalidIndex)
{ 
    EXPECT_ANY_THROW(dynamicPersonTemplateArray[1]);

    Person tempPerson("temp0");
    dynamicPersonTemplateArray.insert(tempPerson);
    tempPerson.setName("temp1");
    dynamicPersonTemplateArray.insert(tempPerson);
    tempPerson.setName("temp2");
    dynamicPersonTemplateArray.insert(tempPerson);

    EXPECT_NO_THROW(dynamicPersonTemplateArray[1]);

    EXPECT_ANY_THROW(dynamicPersonTemplateArray[-1]);
    EXPECT_ANY_THROW(dynamicPersonTemplateArray[3]);

    dynamicPersonTemplateArray.insert(tempPerson);
    dynamicPersonTemplateArray.insert(tempPerson);
    dynamicPersonTemplateArray.insert(tempPerson);
    dynamicPersonTemplateArray.insert(tempPerson);
    dynamicPersonTemplateArray.insert(tempPerson);
    dynamicPersonTemplateArray.insert(tempPerson);
    dynamicPersonTemplateArray.insert(tempPerson);
    dynamicPersonTemplateArray.insert(tempPerson);
    dynamicPersonTemplateArray.insert(tempPerson);
    dynamicPersonTemplateArray.insert(tempPerson);
    dynamicPersonTemplateArray.insert(tempPerson);
    dynamicPersonTemplateArray.insert(tempPerson);

    EXPECT_NO_THROW(dynamicPersonTemplateArray[14]);
    EXPECT_ANY_THROW(dynamicPersonTemplateArray[15]);
}

TEST_F(DTemplatePersonArrayTests, CanUpdateByIndex)
{ 
    Person tempPerson0("temp0");
    Person tempPerson1("temp1");
    Person tempPerson2("temp2");

    dynamicPersonTemplateArray.insert(tempPerson0);
    dynamicPersonTemplateArray.insert(tempPerson1);
    dynamicPersonTemplateArray.insert(tempPerson2);

    Person tempPersonUpdate0("tempPersonUpdate0");
    EXPECT_NO_THROW(dynamicPersonTemplateArray.updateAt(tempPersonUpdate0, 2));
    ASSERT_EQ(tempPersonUpdate0, dynamicPersonTemplateArray.getAt(2));

    Person tempPersonUpdate1("tempPersonUpdate1");
    EXPECT_NO_THROW(dynamicPersonTemplateArray.updateAt(tempPersonUpdate1, 0));
    ASSERT_EQ(tempPersonUpdate1, dynamicPersonTemplateArray.getAt(0));
}

TEST_F(DTemplatePersonArrayTests, CanUpdateByIndexWithoutException)
{ 
    Person tempPerson0("temp0");
    Person tempPerson1("temp1");
    Person tempPerson2("temp2");

    EXPECT_ANY_THROW(dynamicPersonTemplateArray.updateAt(tempPerson0, 0));

    dynamicPersonTemplateArray.insert(tempPerson0);
    dynamicPersonTemplateArray.insert(tempPerson1);
    dynamicPersonTemplateArray.insert(tempPerson2);

    Person tempPersonUpdate0("tempPersonUpdate0");
    EXPECT_NO_THROW(dynamicPersonTemplateArray.updateAt(tempPersonUpdate0, 2));

    EXPECT_ANY_THROW(dynamicPersonTemplateArray.updateAt(tempPersonUpdate0, -1));
    EXPECT_ANY_THROW(dynamicPersonTemplateArray.updateAt(tempPersonUpdate0, 3));
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}