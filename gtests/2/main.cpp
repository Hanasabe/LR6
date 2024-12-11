#include <gtest/gtest.h>

void isort1(char *arr[], int num)
{
    int j;
    char *w;
    for (int i = 1; i < num; ++i)
    {
        w = arr[i];
        j = i - 1;
        while ((j >= 0) && (strcmp(arr[j], w) > 0))
        {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = w;
    }
}

int task(char* arr)
{
    int k = 0, i, cnt = 0;
    char *p;

    const char ds[] = " \t\n,";
    const char ps[] = "!?.";
    char **ws = new char *[50];
    for (arr = strtok(arr, ps); arr != NULL; arr = strtok(NULL, ps))
    {
        k = 0;
        while (*arr)
        {
            i = strspn(arr, ds);
            arr += i;
            if (!*arr)
                break;
            p = arr;
            i = strcspn(arr, ds);
            arr += i;
            if (*arr)
                *arr++ = '\0';
            ws[k++] = p;
        }
        int j;
        char *w;
        for (int i = 1; i < k; ++i)
        {
            w = ws[i];
            j = i - 1;
            while ((j >= 0) && (strcmp(ws[j], w) > 0))
            {
                arr[j + 1] = arr[j];
                --j;
            }
            ws[j + 1] = w;
        }
        for (i = 1; i < k; ++i)
        {
            if (!strcmp(ws[i], ws[i - 1]))
            {
                ++cnt;
                break;
            }
        }
    }
    delete[] ws;
    return cnt;
}

TEST(Task2, Test1)
{
   char arr[] = "hi hi hi.";
    ASSERT_EQ(task(arr), 1);
}

TEST(Task2, Test2)
{
   char arr[] = "hi";
    ASSERT_EQ(task(arr), 0);
}

TEST(Task2, Test3)
{
   char arr[] = "...";
    ASSERT_EQ(task(arr), 0);
}

TEST(Task2, Test4)
{
   char arr[] = "vdiwoanbwabnr brqnboiqn rt bnpqbn rt rbqn rt. rwbqnipbn rt. rbwqbq rt rt.";
    ASSERT_EQ(task(arr), 1);
}

TEST(Task2, Test5)
{
   char arr[] = "";
    ASSERT_EQ(task(arr), 0);
}

TEST(Task2, Test6)
{
   char arr[] = "a b c d e f g";
    ASSERT_EQ(task(arr), 0);
}

TEST(Task2, Test7)
{
   char arr[] = "привет привет. пока пока. пока привет. привет пока.";
    ASSERT_EQ(task(arr), 3);
}

TEST(Task2, Test8)
{
   char arr[] = "12345";
    ASSERT_EQ(task(arr), 0);
}

TEST(Task2, Test9)
{
   char arr[] = "\n";
    ASSERT_EQ(task(arr), 0);
}

TEST(Task2, Test10)
{
   char arr[] = "//./";
    ASSERT_EQ(task(arr), 0);
}

int main()
{

    testing::InitGoogleTest();

    return RUN_ALL_TESTS();
}