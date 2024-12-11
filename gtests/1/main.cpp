#include <gtest/gtest.h>

int task(char *arr, int i1)
{
    int num_char[i1];
    for (int i = 0; i < i1; i++)
    {
        num_char[i] = 0;
    }
    int i2 = 0;
    for (int i = 0; i < i1; i++)
    {
        if (arr[i] != ' ' && arr[i] != '\n')
        {
            num_char[i2]++;
        }
        else
        {
            i2++;
        }
    }
    int i4 = 0;
    for (int i = 0; i <= i2; i++)
    {
        if (num_char[i] != 0)
            i4++;
    }
    int min = 80;
    for (int i = 0; i < i4; i++)
    {
        if (num_char[i] <= min)
        {
            min = num_char[i];
        }
    }
    return min;
}

TEST(Task1, Test1)
{
   char arr[] = "hi hello bye";
    ASSERT_EQ(task(arr, 12), 2);
}

TEST(Task1, Test2)
{
   char arr[] = "hi";
    ASSERT_EQ(task(arr, 2), 2);
}

TEST(Task1, Test3)
{
   char arr[] = ".";
    ASSERT_EQ(task(arr, 1), 1);
}

TEST(Task1, Test4)
{
   char arr[] = "..........";
    ASSERT_EQ(task(arr, 10), 10);
}

TEST(Task1, Test5)
{
   char arr[] = "";
    ASSERT_EQ(task(arr, 1), 1);
}

TEST(Task1, Test6)
{
   char arr[] = "a b c d e f g";
    ASSERT_EQ(task(arr, 13), 1);
}

TEST(Task1, Test7)
{
   char arr[] = "привет";
    ASSERT_EQ(task(arr, 12), 12);
}

TEST(Task1, Test8)
{
   char arr[] = "12345";
    ASSERT_EQ(task(arr, 5), 5);
}

TEST(Task1, Test9)
{
   char arr[] = "\n";
    ASSERT_EQ(task(arr, 1), 0);
}

TEST(Task1, Test10)
{
   char arr[] = "// /";
    ASSERT_EQ(task(arr, 4), 1);
}

int main()
{

    testing::InitGoogleTest();

    return RUN_ALL_TESTS();
}