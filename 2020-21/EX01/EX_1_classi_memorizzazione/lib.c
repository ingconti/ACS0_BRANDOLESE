// lib.c

int twice = 0;

static int global = 0;

static void inc(void)
{
    global++;
    twice = global * 2;
}

void f(void)
{
    inc();
}

int g(void)
{
    return global;
}
