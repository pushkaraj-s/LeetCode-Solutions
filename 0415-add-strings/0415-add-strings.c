char* addStrings(char* num1, char* num2) {
    size_t len1 = strlen(num1);
    size_t len2 = strlen(num2);
    size_t maxLen = (len1 > len2 ? len1 : len2);

    char* arr = malloc(maxLen + 2);
    if (arr == NULL) {
        return NULL;
    }

    size_t i = len1;
    size_t j = len2;
    size_t k = maxLen + 1;

    arr[k] = '\0';
    int carry = 0;

    while (i > 0 || j > 0 || carry) {
        int sum = carry;

        if (i > 0) sum += num1[--i] - '0';
        if (j > 0) sum += num2[--j] - '0';

        arr[--k] = (sum % 10) + '0';
        carry = sum / 10;
    }

    memmove(arr, arr + k, maxLen + 2 - k);
    return arr;
}