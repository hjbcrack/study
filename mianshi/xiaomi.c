

#if 0
// 设计算法，把一个数字看成字符串,问它是不是一个回文数？

#include <iostream>

using namespace std;

// 自编代码
bool isPalindromeNumber(long num)
{
	int h = 10;

	if (num < 0) {
		return false;
	}

	while (num / h >= 10) {
		h *= 10;
	}

	while (h >= 10) {
		if (num % 10 != num / h) {
			return false;
		}
		num %= h;
		num /= 10;
		h /= 100;
	}

	return true;
}

// 参考代码
bool isPalindrome(int x)
{
    if (x < 0)
    {
        return false;
    }
    int temp = x;
    int y = 0;
    while (temp != 0)
    {
        y = y * 10 + temp % 10;
        temp = temp / 10;
    }
    return x == y;
}
 

int main()
{
	long num = 12344321;

	cout << (isPalindromeNumber(num) ? "YES" : "NOT") << endl;

	cout << (isPalindrome(num) ? "YES" : "NOT") << endl;

	return 0;
}

#endif

// 字符串A和字符串B，请将A中在B中存在的字符删除，比如A="This is the world"，B="abcdefghi"，则返回A为"Ts s t worl" 

#include <iostream>
#include <cstring>

using namespace std;

// 自编代码
char* deleteSameCh(char* strA, char* strB)
{
    if (strA == NULL || strB == NULL) {
		return NULL;
	}

	char* strC = new char(strlen(strA)+1);
	char tmp[256] = {0};

    for (int i = 0; i < strlen(strB)+1; ++i) {
		tmp[strB[i]] = 1;
    }
    
	int j = 0;
	for (int i = 0; i < strlen(strA)+1; ++i) {
		if (tmp[strA[i]] == 0) {
			strC[j++] = strA[i];
		}
    }
	
	return strC;
}

int main()
{
	char strA[] = "This is the world";
	char strB[] = "abcdefghi";

	cout << deleteSameCh(strA, strB) << endl;

	return 0;
}







