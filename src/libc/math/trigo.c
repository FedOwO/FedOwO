int float_pow(float, int);
int factorial(int);

float cos(float x, int precision) {
    float result = 1;
    float sign[] = {(float)1, (float)(-1)};
    for (int i = 0; i < precision; i++) {
        result -= sign[i % 2] * (float_pow(x, i * 2) / (float)factorial(i * 2));
    } return result;
}
