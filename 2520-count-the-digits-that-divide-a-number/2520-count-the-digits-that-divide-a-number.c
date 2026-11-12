int countDigits(int num) {
    // First I need to get al the digits
    // Then get a count variable

    int temp = num;
    int count = 0;
    int digits[10] = {0};
    int i = 0;

    while(temp){
        digits[i++] = temp % 10;
        temp = temp / 10;
    }

    for(int j=0; j < i; j++){
        if((num % digits[j]) == 0){
            count++;
        }
        printf("%d ", digits[j]);
    }

    return count;
}