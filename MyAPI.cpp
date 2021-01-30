#define ABS(A) (A) > (0) ? (A) : -(A)
#define MIN(A,B) (A) < (B) ? (A) : (B)
#define MAX(A,B) (A) > (B) ? (A) : (B)
int gcd(int a, int b){
	return b == 0 ? a : gcd(b, a%b);
}
int lcm(int a, int b){
	return a * b / gcd(a,b);
}

//문자열 비교
int myStrcmp(const char* a, const char* b){
	int i = 0;
    while (a[i] != 0)
		if(a[i] != b[i])
			return a[i] - b[i];
        i++;
	return a[i] - b[i];
}
//문자열 비교(num개 만큼 같은지)
int myStrncmp(const char* str1, const char* str2, size_t num){

}

int binarySearch(vector<int>& arr, int target, int start, int end){
	while(start <= end){
		int mid = (start + end) / 2;
		if(arr[mid] == target) return mid;
		else if (arr[mid] > target) end = mid - 1;
		else start = mid + 1;
	}
	return -1;
}

//값이 [left_value, right_value]인 데이터의 개수를 반환하는 개수
int countByRange(vector<int>& v, int leftValue, int rightValue){
	vector<int>::iterator rightIndex = upper_bound(v.begin(), v.end(), rightValue);
	vector<int>::iterator leftIndex = upper_bound(v.begin(), v.end(), leftValue);
	return rightIndex - leftIndex;
}

//hash key
unsigned int getHashKey(char str[]){
	unsigned int key = 0, p = 1;
	for (int i = 0; str[i] != 0; i++){
		key += (str[i] * p);
		p *= 23;
	}

	return (key % MAX);
}

void hashAdd(char str[]){
	unsigned int key = getHashKey(str);
	int &len = table[key][0];
	table[key][++len] = hash_size++;
}

void mergeSort(int arr[], int len){
	if (len < 2) return;
	
	int i, j, k, mid;
	j = mid = (len / 2);
	i = k = 0;
	
	merge_sort(arr, mid);
	merge_sort(arr + mid, len - mid);
	
	while (i < mid && j < len){
		if (my_strcmp(ans[arr[i]], ans[arr[j]]) < 0)
			buf[k++] = arr[i++];
		
		else 
			buf[k++] = arr[j++];
	}
	
	while (i < mid)
		buf[k++] = arr[i++];
	while (j < len)
		buf[k++] = arr[j++];
	
	for (int i = 0; i < len; i++)
		arr[i] = buf[i];
}

//문자열 getline으로 짜르는법
string stringBuffer;
istringstream ssPages(pages[i]);
while (getline(ssPages, stringBuffer, '\n')) {
	if (stringBuffer.find("  <meta property=\"og:url\" content=\"") == 0) {
		contentIdx[stringBuffer.substr(35, stringBuffer.size() - 38)] = i;
	}
	else if (stringBuffer.find("<a href=\"") == 0) {
		int last = stringBuffer.find("\">");
		link[i].push_back(stringBuffer.substr(9, last - 9));
	}
}

//string의 find으로 찾는법
string metaString = pages[i];
int startMeta = metaString.find("https://");
metaString = metaString.substr(startMeta);
int lastMeta = metaString.find("\"/>");
metaString.substr(startMeta, lastMeta);