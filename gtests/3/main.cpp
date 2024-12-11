#include <gtest/gtest.h>
void task(char *arr, int i1)
{
    int num = 0, q, q2;
    int qw;
    for (int i6 = 0; i6 < i1;)
    {
        for (int i = i6; i < i1; i++)
        {
            if (arr[i + 1] == '#')
                num++;
            qw = i;
            if ((arr[i] == '#' && arr[i + 1] != '#') || i == i1)
                break;
        }
        q = num * 2;
        bool we = true;
        q2 = i6;
        int i9 = 0;
        if (q == 0)
            break;
        for (int i = q2; i < i1;)
        {
            we = true;
            if (arr[i + 1] == '#' && num != 0)
            {
                arr[i] = '#';
                i9 = i;
                num--;
                if (i != i6)
                {
                    i--;
                }
                we = false;
            }
            if (num == 0)
            {
                i6 = i9 + q;
                break;
            }
            if (num != 0 && we)
                i++;
        }
    }
}

TEST(Task3, Test1)
{
    char arr[] = "d#er";
    task(arr, 4);
    char arr2[] = "##er";
    bool taskk = true;
    for (int i = 0; i < 4; i++) {
        if (arr[i] != arr2[i])
        {
            taskk = false;
            break;
        }

    }

    ASSERT_TRUE(taskk);
}

TEST(Task3, Test2)
{
    char arr[] = "dd##er";
    task(arr, 6);
    char arr2[] = "####er";
    bool taskk = true;
    for (int i = 0; i < 6; i++) {
        if (arr[i] != arr2[i])
        {
            taskk = false;
            break;
        }

    }

    ASSERT_TRUE(taskk);
}

TEST(Task3, Test3)
{
    char arr[] = "dd#er";
    task(arr, 5);
    char arr2[] = "d##er";
    bool taskk = true;
    for (int i = 0; i < 5; i++) {
        if (arr[i] != arr2[i])
        {
            taskk = false;
            break;
        }

    }

    ASSERT_TRUE(taskk);
}

TEST(Task3, Test4)
{
    char arr[] = "#####";
    task(arr, 5);
    char arr2[] = "#####";
    bool taskk = true;
    for (int i = 0; i < 5; i++) {
        if (arr[i] != arr2[i])
        {
            taskk = false;
            break;
        }

    }

    ASSERT_TRUE(taskk);
}

TEST(Task3, Test5)
{
    char arr[] = "vr##v#helo#lo";
    task(arr, 13);
    char arr2[] = "######hel##lo";
    bool taskk = true;
    for (int i = 0; i < 13; i++) {
        if (arr[i] != arr2[i])
        {
            taskk = false;
            break;
        }

    }

    ASSERT_TRUE(taskk);
}

TEST(Task3, Test6)
{
    char arr[] = "hello";
    task(arr, 5);
    char arr2[] = "hello";
    bool taskk = true;
    for (int i = 0; i < 5; i++) {
        if (arr[i] != arr2[i])
        {
            taskk = false;
            break;
        }

    }

    ASSERT_TRUE(taskk);
}

TEST(Task3, Test7)
{
    char arr[] = "abcdefg#### h i tj#k";
    task(arr, 20);
    char arr2[] = "abc######## h i t##k";
    bool taskk = true;
    for (int i = 0; i < 20; i++) {
        if (arr[i] != arr2[i])
        {
            taskk = false;
            break;
        }

    }

    ASSERT_TRUE(taskk);
}

TEST(Task3, Test8)
{
    char arr[] = "#a";
    task(arr, 2);
    char arr2[] = "#a";
    bool taskk = true;
    for (int i = 0; i < 2; i++) {
        if (arr[i] != arr2[i])
        {
            taskk = false;
            break;
        }

    }

    ASSERT_TRUE(taskk);
}

TEST(Task3, Test9)
{
    char arr[] = " ";
    task(arr, 1);
    char arr2[] = " ";
    bool taskk = true;
    for (int i = 0; i < 1; i++) {
        if (arr[i] != arr2[i])
        {
            taskk = false;
            break;
        }

    }

    ASSERT_TRUE(taskk);
}

TEST(Task3, Test10)
{
    char arr[] = "e#####";
    task(arr, 6);
    char arr2[] = "######";
    bool taskk = true;
    for (int i = 0; i < 6; i++) {
        if (arr[i] != arr2[i])
        {
            taskk = false;
            break;
        }

    }

    ASSERT_TRUE(taskk);
}



int main()
{

    testing::InitGoogleTest();

    return RUN_ALL_TESTS();
}