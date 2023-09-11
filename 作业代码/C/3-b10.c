/*2151294 信11 马威*/
#include <stdio.h>
#include <windows.h> //取系统时间

int main()
{
	LARGE_INTEGER tick, begin, end;

	QueryPerformanceFrequency(&tick);	//获得计数器频率
	QueryPerformanceCounter(&begin);	//获得初始硬件计数器计数

	/* 此处是你的程序开始 */
	int i11, i12, i13, i21, i22, i23, i31, i32, i33, x1, x2, x3, j;     /*定义所需变量，i为各个位数，x1是左边的数，x2是中间的数，x3是右边的数*/
	j = 1;     /*计数器j初始化为1，找到一个符合条件的情况，j自增*/

	/*寻找符合条件的情况*/
	/*主要思路：将每个位数从1到9依次尝试，且每一位都要与前面已取的所有位数都不等，每取完三位计算一个数，最后判断三位数和是否为1953*/
	for (i11 = 1; i11 <= 9; i11++) {
		for (i12 = 1; i12 <= 9; i12++) {
			if (i12 != i11) {
				for (i13 = 1; i13 <= 9; i13++) {
					if (i13 != i12 && i13 != i11) {
						x1 = i11 * 100 + i12 * 10 + i13;     /*取了三位数，计算x1*/
						for (i21 = 1; i21 <= 9; i21++) {
							if (i21 != i13 && i21 != i12 && i21 != i11) {
								for (i22 = 1; i22 <= 9; i22++) {
									if (i22 != i21 && i22 != i13 && i22 != i12 && i22 != i11) {
										for (i23 = 1; i23 <= 9; i23++) {
											if (i23 != i22 && i23 != i21 && i23 != i13 && i23 != i12 && i23 != i11) {
												x2 = i21 * 100 + i22 * 10 + i23;     /*又取了三位数，计算x2*/
												for (i31 = 1; i31 <= 9; i31++) {
													if (i31 != i23 && i31 != i22 && i31 != i21 && i31 != i13 && i31 != i12 && i31 != i11) {
														for (i32 = 1; i32 <= 9; i32++) {
															if (i32 != i31 && i32 != i23 && i32 != i22 && i32 != i21 && i32 != i13 && i32 != i12 && i32 != i11) {
																for (i33 = 1; i33 <= 9; i33++) {
																	if (i33 != i32 && i33 != i31 && i33 != i23 && i33 != i22 && i33 != i21 && i33 != i13 && i33 != i12 && i33 != i11) {
																		x3 = i31 * 100 + i32 * 10 + i33;     /*再取了三位数，计算x1*/

																		/*如果三个数升序排列，各个位数都不同，且和为1953，按规定格式打印序数与算式*/
																		if (x1 < x2 && x2 < x3 && x1 + x2 + x3 == 1953) {
																			printf("No.%3d : %d+%d+%d=1953\n", j, x1, x2, x3);
																			j = j + 1;

																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}

	printf("total=%d\n", j - 1);  /*按计数器的值，按规定格式打印情况总数*/
	/* 此处是你的程序结束 */

	QueryPerformanceCounter(&end);		//获得终止硬件计数器计数

	printf("计数器频率 : %lldHz\n", tick.QuadPart);
	printf("计数器计数 : %lld\n", end.QuadPart - begin.QuadPart);
	printf("%.6f秒\n", (double)(end.QuadPart - begin.QuadPart) / tick.QuadPart);

	return 0;
}