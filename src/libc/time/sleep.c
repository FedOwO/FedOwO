void sleep(unsigned int milliseconds) {
    for (unsigned int i = 0; i < milliseconds; ++i) {
        for(int s = 0; s < 100000; s++);
    }
}
