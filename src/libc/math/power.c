int fast_pow(int x, int p)
{
    int result = 1;
    while (p > 0) {
        if (p % 2 == 0) {
            p /= 2;
            x *= x; 
        } else {
            p -= 1;
            result *= x;
            p /= 2;
            x *= x;
        }
    } return result;
}

float float_pow(float x, int p)
{
    float result = 1;
    while (p > 0) {
        if (p % 2 == 0) {
            p /= 2;
            x *= x; 
        } else {
            p -= 1;
            result *= x;
            p /= 2;
            x *= x;
        }
    } return result;
}