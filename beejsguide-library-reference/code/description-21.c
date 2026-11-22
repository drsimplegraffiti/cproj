int handler(int sig)
{
    // Handle the signal
}

int main(void)
{
    signal(SIGINT, handler);
