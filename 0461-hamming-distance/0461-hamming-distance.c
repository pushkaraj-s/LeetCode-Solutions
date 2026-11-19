int hammingDistance(int x, int y) {
    // Run a while/for loop, Check every bit
    // Increment counter if bit is mismatched

    int count = 0;
    int xbit = 0;
    int ybit = 0;

    while(x | y){
        xbit = x != 0 ? (x & 0x00000001) : 0;
        ybit = y != 0 ? (y & 0x00000001) : 0;

        if(xbit != ybit){
            count++;
        }

        x >>= 1;
        y >>= 1;
    }

    return count;
}