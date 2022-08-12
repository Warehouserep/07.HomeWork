#include "list.hpp"
#include <list>
#include <vector>
#include <iterator>
#include <gtest/gtest.h>


// 0 - create list
TEST(list, Empty) {
    // Arrange
    std::list<int> list;

    // Act (empty for this test)

    // Assert
    ASSERT_EQ(list.size(), 0);
    ASSERT_TRUE(list.empty());
}

// 1 - insert to the end
TEST(list, PushBack) {
    // Arrange
    const size_t count = 10;
    std::list<size_t> list;

    // Act
    for (size_t i = 0; i < count; ++i) {
        list.push_back(i);
    }

    // Assert
    ASSERT_EQ(list.back(), 9);
    ASSERT_EQ(list.size(), count);
    ASSERT_FALSE(list.empty());
}

// 2 - insert to the begin
TEST(list, PushFront) {
    // Arrange
    const size_t count = 10;
    std::list<size_t> list;

    // Act
    for (size_t i = 0; i < count; ++i) {
        list.push_front(i);
    }

    // Assert
    ASSERT_EQ(list.front(), 9);
    ASSERT_EQ(list.size(), count);
    ASSERT_FALSE(list.empty());
}



// 3 - insert to the middle
TEST(list, PushMiddle) {
    // Arrange
    const size_t count = 10;
    otus::List<int> lst;

    // Act
    for (size_t i = 0; i < count - 1; ++i) {
        lst.push_front(i);
    }
    lst.insert(5, 20);

    // Assert
    ASSERT_EQ(lst[5], 20);
    ASSERT_EQ(lst.size(), count);
    ASSERT_FALSE(lst.empty());
}

// 4 - Remove from the end
TEST(list, PopBack) {
    // Arrange 
    const size_t count = 10;
    std::list<size_t> list;

    for (size_t i = 0; i < count; ++i) {
        list.push_back(i);
    }

    // Act
    list.pop_back();

    // Assert
    auto it = list.begin();
    std::advance(it, 8);

    ASSERT_EQ(*it, 8);
    ASSERT_EQ(list.size(), count - 1);
    ASSERT_FALSE(list.empty());
}

// 5 - Remove from the begin
TEST(list, PopFront) {
    // Arrange 
    const size_t count = 10;
    std::list<size_t> list;

    for (size_t i = 0; i < count; ++i) {
        list.push_back(i);
    }

    // Act
    list.pop_front();

    // Assert
    auto it = list.begin();

    ASSERT_EQ(*it, 1);
    ASSERT_EQ(list.size(), count - 1);
    ASSERT_FALSE(list.empty());
}

// 6 - Remove from the middle
TEST(list, PopMiddle) {
    // Arrange 
    const size_t count = 10;
    otus::List<size_t> list;

    for (size_t i = 0; i < count; ++i) {
        list.push_back(i);
    }

    // Act
    list.erase(5);

    // Assert
    ASSERT_EQ(list[5], 6);
    ASSERT_EQ(list.size(), count - 1);
    ASSERT_FALSE(list.empty());
}

// 7 - Get Element
TEST(list, GetElement) {
    // Arrange 
    const size_t count = 10;
    otus::List<size_t> list;

    for (size_t i = 0; i < count; ++i) {
        list.push_back(i);
    }

    // Act
    int elem = list[3];

    // Assert
    ASSERT_EQ(elem, 3);
    ASSERT_EQ(list.size(), count);
    ASSERT_FALSE(list.empty());
}

// 8 - Get Size
TEST(list, GetSize) {
    // Arrange 
    const size_t count = 10;
    std::list<size_t> list;

    for (size_t i = 0; i < count; ++i) {
        list.push_back(i);
    }

    // Act

    // Assert
    ASSERT_EQ(list.size(), count);
    ASSERT_FALSE(list.empty());
}

// 9 - Copy
TEST(list, listCopy) {
    // Arrange 
    const size_t count = 10;
    std::list<int> list;

    for (size_t i = 0; i < count; ++i) {
        list.push_back(i);
    }

    // Act
    std::list<int> list2(list);

    // Assert
    ASSERT_EQ(list2.size(), list.size());
    ASSERT_EQ(list2.front(), list.front());
    ASSERT_EQ(list.back(), list.back());
}

// 10 - Remove
TEST(list, listRemove) {
    // Arrange 
    const size_t count = 10;
    std::list<int> list;

    for (size_t i = 0; i < count; ++i) {
        list.push_back(i);
    }

    // Act
    list.clear();

    // Assert
    ASSERT_EQ(list.size(), 0);
}

// 11 - Assignment
TEST(list, listAssignment) {
    // Arrange 
    const size_t count = 10;
    std::list<int> lst;

    for (size_t i = 0; i < count; ++i) {
        lst.push_back(i);
    }

    // Act
    std::list<int> lst2 = lst;

    // Assert
    ASSERT_EQ(lst2.size(), lst.size());
    lst2.pop_back();
    ASSERT_EQ(lst2.size(), lst.size() - 1);

}



////////////////// vector /////////////

// 0 - create vector
TEST(vector, Empty) {
    // Arrange
    std::vector<int> vector;

    // Act (empty for this test)

    // Assert
    ASSERT_EQ(vector.size(), 0);
    ASSERT_TRUE(vector.empty());
}

// 1 - insert to the end
TEST(vector, PushBack) {
    // Arrange
    const size_t count = 10;
    std::vector<int> vector;

    // Act
    for (size_t i = 0; i < count; ++i) {
        vector.push_back(i);
    }

    // Assert
    ASSERT_EQ(vector.back(), 9);
    ASSERT_EQ(vector.size(), count);
    ASSERT_FALSE(vector.empty());
}

// 2 - insert to the begin
TEST(vector, PushFront) {
    // Arrange
    const size_t count = 10;
    std::vector<int> vector;

    // Act
    for (size_t i = 0; i < count; ++i) {
        vector.push_back(i);
    }
    vector.insert(vector.begin(), 20);

    // Assert
    ASSERT_EQ(vector.front(), 20);
    ASSERT_EQ(vector.size(), count + 1);
    ASSERT_FALSE(vector.empty());
}



// 3 - insert to the middle
TEST(vector, PushMiddle) {
    // Arrange
    const size_t count = 10;
    std::vector<int> vector;

    // Act
    for (size_t i = 0; i < count - 1; ++i) {
        vector.push_back(i);
    }
    auto it = vector.begin();
    std::advance(it, 5);
    vector.insert(it, 20);

    // Assert
    ASSERT_EQ(vector[5], 20);
    ASSERT_EQ(vector.size(), count);
    ASSERT_FALSE(vector.empty());
}

// 4 - Remove from the end
TEST(vector, PopBack) {
    // Arrange 
    const size_t count = 10;
    std::vector<int> vector;

    for (size_t i = 0; i < count; ++i) {
        vector.push_back(i);
    }

    // Act
    vector.pop_back();

    // Assert
    auto it = vector.begin();
    std::advance(it, 8);

    ASSERT_EQ(*it, 8);
    ASSERT_EQ(vector.size(), count - 1);
    ASSERT_FALSE(vector.empty());
}

// 5 - Remove from the begin
TEST(vector, PopFront) {
    // Arrange 
    const size_t count = 10;
    std::vector<int> vector;

    for (size_t i = 0; i < count; ++i) {
        vector.push_back(i);
    }

    // Act
    auto it = vector.begin();
    vector.erase(it);

    // Assert
    ASSERT_EQ(vector.size(), count - 1);
    ASSERT_FALSE(vector.empty());
}

// 6 - Remove from the middle
TEST(vector, PopMiddle) {
    // Arrange 
    const size_t count = 10;
    std::vector<int> vector;

    for (size_t i = 0; i < count; ++i) {
        vector.push_back(i);
    }

    // Act
    auto it = vector.begin();
    std::advance(it, 5);
    vector.erase(it);

    // Assert
    ASSERT_EQ(vector.size(), count - 1);
    ASSERT_FALSE(vector.empty());
}

// 7 - Get Element
TEST(vector, GetElement) {
    // Arrange 
    const size_t count = 10;
    std::vector<int> vector;

    for (size_t i = 0; i < count; ++i) {
        vector.push_back(i);
    }

    // Act
    int elem = vector[3];

    // Assert
    ASSERT_EQ(elem, 3);
    ASSERT_EQ(vector.size(), count);
    ASSERT_FALSE(vector.empty());
}

// 8 - Get Size
TEST(vector, GetSize) {
    // Arrange 
    const size_t count = 10;
    std::vector<int> vector;

    for (size_t i = 0; i < count; ++i) {
        vector.push_back(i);
    }

    // Act

    // Assert
    ASSERT_EQ(vector.size(), count);
    ASSERT_FALSE(vector.empty());
}

// 9 - Copy
TEST(vector, vectorCopy) {
    // Arrange 
    const size_t count = 10;
    std::vector<int> vector;

    for (size_t i = 0; i < count; ++i) {
        vector.push_back(i);
    }

    // Act
    std::vector<int> vector2(vector);

    // Assert
    ASSERT_EQ(vector2.size(), vector.size());
    ASSERT_EQ(vector2.front(), vector.front());
    ASSERT_EQ(vector2.back(), vector.back());
}

// 10 - Remove
TEST(vector, vectorRemove) {
    // Arrange 
    const size_t count = 10;
    std::vector<int> vector;

    for (size_t i = 0; i < count; ++i) {
        vector.push_back(i);
    }

    // Act
    vector.clear();

    // Assert
    ASSERT_EQ(vector.size(), 0);
}

// 11 - Assignment
TEST(vector, vectorAssignment) {
    // Arrange 
    const size_t count = 10;
    std::vector<int> vector;

    for (size_t i = 0; i < count; ++i) {
        vector.push_back(i);
    }

    // Act
    std::vector<int> vector2 = vector;

    // Assert
    ASSERT_EQ(vector2.size(), vector.size());
    vector2.pop_back();
    ASSERT_EQ(vector2.size(), vector.size() - 1);

}


int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}