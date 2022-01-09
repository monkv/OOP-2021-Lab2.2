#include "gtest/gtest.h"
#include "binary.h"

TEST(Constructertest, test1){
    std::string hello("1242");
    char hello2[3] = {0, 1, 0};
    binary_num num1;
    binary_num num2 = binary_num(143) ;
    binary_num num3 = binary_num(hello);
    binary_num num4 = binary_num(hello2, 3);
}

TEST(Functions, test2){
    //EXPECT_EQ((*it).second, "One");
}

int main(int argc, char *argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
