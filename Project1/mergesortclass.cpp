////#include <iostream>
////
////using namespace std;
////
////
////
////const int number = 9;
////int sorted[9]; //정렬 배열은 반드시 전역 변수로 ;
////int count = 0;
////
////void merge(int a[], int m, int middle, int n);
////void mergeSort(int a[], int m, int n);
////int main() {
////
////	int array[number] = { 7,6,5,8,3,5,9,1,4 };
////	mergeSort(array, 0, number - 1);
////	for (int i = 0; i < number; i++)
////	{
////		cout << array[i] << " ";
////	}
////	return 0;
////}
////
////void merge(int a[], int m, int middle, int n)
////{
////	int i = m;
////	int j = middle + 1;
////	int k = m;
////
////	//m middle n
////	// ㅁㅁㅁㅁ
////	while (i <= middle && j <= n)
////	{
////		// iㅁ jㅁ
////		// kㅁㅁㅁ
////		if (a[i] <= a[j])
////		{
////			sorted[k] = a[i];
////			i++;
////		}
////		else {
////			sorted[k] = a[j];
////			j++;
////		}
////		k++;
////	}
////	//남은 데이터 삽입 뒤에다가
////	//  (middle)
////	// i,  i2, ㅁ ㅁ
////	if (i > middle)
////	{
////		for (int t = j; t <= n; t++)
////		{
////			sorted[k] = a[t];
////			k++;
////		}
////	}
////	else {
////		for (int t = i; t <= n; t++)
////		{
////			sorted[k] = a[t];
////			k++;
////		}
////	}
////
////	for (int t = m; t <= n; t++)
////	{
////		a[t] = sorted[t];
////	}
////
////}
////
////void mergeSort(int a[], int m, int n)
////{
////	// 크기가 1보다 큰 경우
////	if (m < n)
////	{
////		// 0 + 8 / 2 = 4
////		int middle = (m + n) / 2;
////		mergeSort(a, m, middle);
////		mergeSort(a, middle + 1, n);
////		merge(a, m, middle, n);
////	}
////}
//
//#include <iostream>
//
//using namespace std;
//
//
//
//const int number = 8;
//int sorted[8]; //빈 배열 
//
//void mergeSort(int a[], int start, int end);
//void merge(int a[], int start, int middle, int end);
//int main() {
//
//	int array[number] = { 7,6,5,8,3,5,9,1 };
//
//	mergeSort(array, 0, number - 1);
//	for (int i = 0; i < number; i++)
//	{
//		cout << array[i] << " ";
//	}
//	return 0;
//}
//
//void mergeSort(int a[], int start, int end)
//{
//	if (start < end)
//	{
//		int middle = (start + end) / 2;
//		mergeSort(a, start, middle);
//		mergeSort(a, middle + 1, end);
//		merge(a, start, middle, end);
//	}
//}
//
//void merge(int a[], int start, int middle, int end)
//{
//	int right = start;
//	int left = middle + 1;
//	int sortIndex = start;
//
//	//작은거 부터 넣어주기, right가 center 까지, left가 end 지점 까지 가기전 까지만
//	while (right <= middle && left <= end)
//	{
//		if (a[right] < a[left])
//		{
//			sorted[sortIndex] = a[right];
//			right++;
//			sortIndex++;
//		}
//		else {
//			sorted[sortIndex] = a[left];
//			left++;
//			sortIndex++;
//		}
//	}
//	// 만약 right쪽이 middle을 초과할 경우 left쪽은 이미 다 정렬되었다고 가정되므로 정리만 해주면 됨
//	if (right > middle)
//	{
//		for (int i = left; i <= end; i++)
//		{
//			sorted[sortIndex] = a[i];
//			sortIndex++;
//		}
//	}
//	else
//	{
//		for (int i = right; i <= end; i++)
//		{
//			sorted[sortIndex] = a[i];
//			sortIndex++;
//		}
//	}
//	for (int i = start; i <= end; i++)
//	{
//		a[i] = sorted[i];
//	}
//}
//v.push_back(Edge(1, 7, 12));
//v.push_back(Edge(1, 4, 28));
//v.push_back(Edge(1, 2, 67));
//v.push_back(Edge(1, 5, 17));
//v.push_back(Edge(2, 4, 24));
//v.push_back(Edge(2, 5, 62));
//v.push_back(Edge(3, 5, 20));
//v.push_back(Edge(3, 6, 37));
//v.push_back(Edge(4, 7, 13));
//v.push_back(Edge(5, 6, 45));
//v.push_back(Edge(5, 7, 73));

#pragma region bfs
// 유니온->크루스칼  -> 힙 -> bfs -> dfs
//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <queue>
//using namespace std;
//
////bfs
//// 배열 vector
//// 체이닝
//// bool 배열 
//// 오름차순 bfs
//const int Size = 8;
//void Channig(vector<int> v[], int a, int b) {
//	if (Size <= b) return;
//	v[a].push_back(b);
//	v[b].push_back(a);
//}
//void bfs(vector<int> v[], bool closer[], int start)
//{
//	queue<int> q;
//	q.push(start);
//	closer[start] = true;
//	while (!q.empty())
//	{
//		int x = q.front();
//		q.pop();
//		cout << x << " ";
//		for (int i = 0; i < v[x].size(); i++)
//		{
//			int y = v[x][i];
//			if (closer[y] == false)
//			{
//				q.push(y);
//				closer[y] = true;
//			}
//		}
//	}
//}
//
//int main() {
//
//	vector<int> v[Size];
//	bool closer[Size] = { };
//
//	for (int i = 0; i < Size / 2; i++)
//	{
//		Channig(v, i, (i * 2) + 1);
//		Channig(v, i, (i * 2) + 2);
//	}
//
//	bfs(v, closer, 0);
//
//	return 0;
//}
#pragma endregion

#pragma region dfsData
// 1과 2을 연결합니다. 
//a[1].push_back(2);
//a[2].push_back(1);
//// 1과 3를 연결합니다.
//a[1].push_back(3);
//a[3].push_back(1);
//// 2과 3를 연결합니다.
//a[2].push_back(3);
//a[3].push_back(2);
//// 2과 4을 연결합니다. 
//a[2].push_back(4);
//a[4].push_back(2);
//// 2과 5를 연결합니다.
//a[2].push_back(5);
//a[5].push_back(2);
//// 3와 6를 연결합니다.
//a[3].push_back(6);
//a[6].push_back(3);
//// 3와 7을 연결합니다.
//a[3].push_back(7);
//a[7].push_back(3);
//// 4와 5를 연결합니다.
//a[4].push_back(5);
//a[5].push_back(4);
//// 6과 7을 연결합니다.
//a[6].push_back(7);
//a[7].push_back(6);
#pragma endregion

#pragma region CruscalData
//v.push_back(Edge(1, 7, 12));
//v.push_back(Edge(1, 4, 28));
//v.push_back(Edge(1, 2, 67));
//v.push_back(Edge(1, 5, 17));
//v.push_back(Edge(2, 4, 24));
//v.push_back(Edge(2, 5, 62));
//v.push_back(Edge(3, 5, 20));
//v.push_back(Edge(3, 6, 37));
//v.push_back(Edge(4, 7, 13));
//v.push_back(Edge(5, 6, 45));
//v.push_back(Edge(5, 7, 73));
#pragma endregion
